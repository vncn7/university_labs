export module Worker;
import "Employee";

export class Worker : public Employee
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string f_n, const string l_n, double h_e = 0.0, double h = 0.0) : Employee(f_n, l_n)
    {
                hourly_earnings = h_e;
        _hours = h;
    }

    double get_income() const
    {
        return _hourly_earnings * _hours;
    }

    void print() const
    {
        cout << "Worker: ";
        Employee::print();
    }
};