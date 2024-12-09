#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Meal
{
public:
    virtual void add_topping(string s) = 0;
    virtual void prepare() = 0;
};
class Pizza : public Meal
{
    string name;
    vector<string> topping;

public:
    Pizza(string name) : name(name) {}
    void add_topping(string s) override
    {
        topping.push_back(s);
    }
    void prepare() override
    {
        cout << "Pizza " << name << ". Pizzaboden, belegt mit:" << endl;
        for (size_t i = 0; i < topping.size(); i++)
        {
            cout << "- " << topping[i] << endl;
        }
    }
};

class Burger : public Meal
{
    string name;
    vector<string> topping;

public:
    Burger(string name) : name(name) {}
    void add_topping(string s) override
    {
        topping.push_back(s);
    }
        void prepare() override
    {
        cout << name << ". Brötchen mit:" << endl;
        for (size_t i = 0; i < topping.size(); i++)
        {
            cout << "- " << topping[i] << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal *, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : menu)
    {
        g->prepare(); //*[1]
    }
    return 0;
}
