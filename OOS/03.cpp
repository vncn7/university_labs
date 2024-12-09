#include <iostream>

void print_rectangle(int x = 0, int y = 0)
{
    // Bei Übergabe von nur einem Parameter wird der auf null gesetzte Wert auf den anderen Wert gesetzt
    if (x == 0) x = y;
    else if (y == 0) y = x;
    
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            std::cout << "X ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);

	std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);

	std::cout << "x = 4: " << std::endl;
	print_rectangle(4);

	return 0;
};