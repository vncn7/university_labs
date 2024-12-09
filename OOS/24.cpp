#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>

using namespace std;

// Hier Exception implementieren
class OutOfStockException : public exception
{
    string msg;
public:
    OutOfStockException(unsigned int productAvailability, string product, unsigned int amount)
    {
        msg = "Es sind " + to_string(productAvailability) + " Artikel vom Typ " + product + " verfügbar. Es können nicht " + to_string(amount) + " Artikel verkauft werden.";
    }

    const char *what() const throw() 
    {
        return msg.c_str();
    }
};

// Hier Interface implementieren
class ISubscriber
{
public:
    virtual void update(string s) = 0;
};

// Hier Klassen Customer und GoldCustomer implementieren
class Customer : public ISubscriber
{
    int _id;
    static int _id_generator;

public:
    Customer()
    {
        _id = ++_id_generator;
    }
    void update(string s) override
    {
        cout << "Customer " << _id << ": neue Nachricht verfügbar --> " << s << endl;
    }
};

class GoldCustomer : public ISubscriber
{
    int _id;
    static int _id_generator;

public:
    GoldCustomer()
    {
        _id = ++_id_generator;
    }
    void update(string s) override
    {
        cout << "GoldCustomer " << _id << ": neue Nachricht verfügbar --> " << s << endl;
    }
};

class Store
{
public:
    // Hier Methoden implementieren
    void subscribe(ISubscriber *customer)
    {
        _subscribers.push_back(customer);
    }

    void unsubscribe(ISubscriber *customer)
    {
        _subscribers.remove(customer);
    }

    void notify_subscribers(const string &msg)
    {
        for (ISubscriber *subscriber : _subscribers)
        {
            subscriber->update(msg);
        }
    }

    void deliver_products(string product, unsigned int amount = 0)
    {

            cout << "Vorrätige Artikel vom Typ " << product << ": " << _product_availability[product] << endl;
            cout << "Ausgelieferte Artikel vom Typ " << product << ": " << amount << endl;
            cout << "Neuer Bestand: " << _product_availability[product] + amount << endl;
            if (_product_availability[product] == 0)
            {
                notify_subscribers("Neue Artikel vom Typ " + product + " verfügbar.");
            }
            _product_availability[product] = _product_availability[product] + amount;
    }

    void sell_products(string product, unsigned int amount)
    {
        if (_product_availability[product] >= amount)
        {
            _product_availability[product] = _product_availability[product] - amount;
            cout << "Vorrätige Artikel vom Typ " << product << ": " << _product_availability[product] + amount << endl;
            cout << "Verkaufte Artikel vom Typ " << product << ": " << amount << endl;
            cout << "Neuer Bestand: " << _product_availability[product] << endl;
            if (_product_availability[product] == 0)
            {
                notify_subscribers("Artikel vom Typ " + product + " nicht mehr verfügbar");
            }
        }
        else
        {
            throw OutOfStockException(_product_availability[product], product, amount);
        }
        
    }

private:
    list<ISubscriber *> _subscribers;
    map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};
};

int Customer::_id_generator = 100;
int GoldCustomer::_id_generator = 0;

void manage_store()
{
    try
    {
        Store *store = new Store;
        ISubscriber *customer_1 = new Customer();
        store->subscribe(customer_1);
        ISubscriber *customer_2 = new GoldCustomer();
        store->subscribe(customer_2);
        ISubscriber *customer_3 = new GoldCustomer();
        store->subscribe(customer_3);
        store->deliver_products("iPhone", 5);
        store->unsubscribe(customer_3);
        store->sell_products("iPhone", 3);
        ISubscriber *customer_4 = new Customer();
        store->subscribe(customer_4);
        store->deliver_products("iPhone", 5);
        store->sell_products("iPhone", 7);
        store->unsubscribe(customer_1);
        ISubscriber *customer_5 = new GoldCustomer();
        store->subscribe(customer_5);
        store->deliver_products("iPhone", 15);
        store->sell_products("Galaxy", 8);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main(int argc, char *argv[])
{
    manage_store();
    return 0;
}
