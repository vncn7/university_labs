#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	double d = 1.234;
	cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++)
	{
        cout << setw(3) << right << dec << noshowpos << k;
        cout << setw(4) << right << oct << showbase << k;
        cout << setw(5) << right << nouppercase << hex << k << " ";
        cout << setw(7) << left  << setfill('+') << string(k % 5 + 1, '*') << " ";
        cout << setfill(' ') << showpos << internal << setw(9) << fixed << setprecision(3) << d;
        cout << setw(11) << right << noshowpos << uppercase << scientific << setprecision(3) << d;
        d = d * -2;

		cout << endl;
	}
	return 0;
}
