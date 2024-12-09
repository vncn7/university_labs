
#include <string>
#include <iostream>
using namespace std;

struct ListElement
{
    int id;
    ListElement *p_next;
};

ListElement *p_root = nullptr;

void add_new_head_element(int id)
{
    ListElement *p_new_element = new ListElement();
    p_new_element->id = id;
    p_new_element->p_next = p_root;
    p_root = p_new_element;
}

void add_new_tail_element(int id)
{
    // HIER programmieren:
    // Neues listenElement erzeugen.
    // Ans Ende der Liste navigieren und neues listenElement anhängen.
    ListElement *p_new_element = new ListElement(); // Neues Element erzeugen, Speicher allokiert mit new
    p_new_element->id = id;                         // Wert übergeben

    if (p_root == nullptr) // Abfrage ob Liste noch leer
    {
        p_new_element->p_next = nullptr; // Next-Pointer des Elements wird auf NULL gesetzt
        p_root = p_new_element; // Root Pointer wird Listenelement
    }
    else // Es existiert bereits ein Listenelement
    {
        ListElement *p_tmp = p_root; // Pointer wird auf das erste Element der Liste gesetzt
        while (p_tmp->p_next != nullptr) // Durch die Liste iterieren
        {
            p_tmp = p_tmp->p_next;
        }
        p_tmp->p_next = p_new_element; // Der Next-Pointer des vorherigen Elements zeigt nun auf das neue (letzte) Listenelement
        p_new_element->p_next = nullptr; // Next-Pointer zeigt auf das neue Ende der Liste
    }
}

void delete_element(int id)
{
    ListElement *p_tmp = p_root;
    ListElement *p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id)
    {
        p_predecessor = p_tmp;
        p_tmp = p_tmp->p_next;
    }
    if (p_tmp != nullptr)
    {
        if (p_tmp == p_root)
        {
            p_root = p_tmp->p_next;
        }
        else
        {
            p_predecessor->p_next = p_tmp->p_next;
        }
    }
    delete p_tmp;
}

void print_list()
{
    // Hier programmieren:
    // Die Liste durchlaufen und jeweils die id des listenElements ausgeben.
    ListElement *p_tmp = p_root; // p_tmp wird auf root ptr gesetzt
    while (p_tmp != nullptr) // Durch Liste iterieren
    {
        cout << p_tmp->id << endl;
        p_tmp = p_tmp->p_next; // Pointer wird auf den jeweiligen Next-Pointer gesetzt
    }
    
}

int main(int argc, char *argv[])
{
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};
