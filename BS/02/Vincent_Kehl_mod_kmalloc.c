// Header
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>

// Module Description
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vincent Kehl, Güney Özcan");
MODULE_DESCRIPTION("Betriebssysteme Labor 02, SS23");

// Module Parameter with Default-Values
static unsigned int loop_cnt = 100; 
static unsigned int alloc_size = 256;
module_param(loop_cnt, uint, S_IRUGO);
module_param(alloc_size, uint, S_IRUGO);

// Global Pointer to char*
char **ptr;

// Init Function
int __init init_module(void)
{
        // Timestamp Variables
        static unsigned int start, end; 
        
	// Allocate memory for char-Pointers
        ptr = kmalloc(loop_cnt * sizeof(char *), GFP_KERNEL);  
        if (ptr == NULL) {
            printk(KERN_INFO "Memory Allocation failed!\n");
            return -1;
        }
	
	for (size_t i = 0; i < loop_cnt; i++)
	{
	start = get_cycles(); // Timer Start
        ptr[i] = kmalloc(alloc_size, GFP_KERNEL); // Memory Allocation
	end = get_cycles(); // Timer End
        
        // Check Memory
        if (ptr[i] == NULL) {
            printk(KERN_INFO "Memory Allocation failed!\n");
            return -1;
        }

	// Output
	printk(KERN_INFO "kmalloc %zu Allocation of %d bytes took %d cycles.\n", i+1, alloc_size, end - start);
        }
	return 0;
}

// Exit Function
void __exit cleanup_module(void)
{
	printk(KERN_INFO "Module exiting!\n");
	
	// Free allocated Memory
	for (size_t i = 0; i < loop_cnt; i++)
	{
        kfree(ptr[i]);
	}
}