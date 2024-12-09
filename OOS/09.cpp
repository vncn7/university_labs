
#include <iostream>
using namespace std;

class Date
{

    int _day, _month, _year;

public:
    Date(int day = 0, int month = 0, int year = 0)
    {
        _day = day;
        _month = month;
        _year = year;
    }

    // Überladung des Operators + für die Klasse Date
    // Der Operator ermöglicht die Addition eines ganzzahligen Wertes zu einem Datum
    Date operator+(int days)
    {
        int total_days = _day + days;
        int month = _month;
        int year = _year;


        // Umrechnung der Tage in Monate und Jahre
        while (total_days > 30)
        {
            if (total_days > 360)
            {
                year++;
                total_days -= 360;
            }
            if (total_days > 30)
            {
                month++;
                total_days -= 30;
            }
        }
        return Date(total_days, month, year);
    }
    // friend -> auch private Variablen
    // Parameter -> Ausgabestream als Referenz und ein Date-Objekt als Referenz
    // Schreiben der privaten Variablen in den Ausgabestream
    // Rückgabe einer Referenz auf den Ausgabestream
    friend ostream& operator<<(ostream& s, const Date& date)
    {
        return s << date._day << "." << date._month << "." << date._year;
    }
};

int main(int argc, char *argv[])
{
    Date begin_task = Date(13, 04, 2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 7;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_five_months_later = begin_task + 1230;
    cout << "Drei Jahre und 5 Monate nach Aufgabenbeginn ist der " << three_years_and_five_months_later << endl;
}
