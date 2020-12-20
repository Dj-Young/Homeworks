#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int num_of_rombs = 0;
	cout << "¬ведите какое количество ромбов вы хотите увидеть на экране: ";
	cin >> num_of_rombs;
	int tmp = num_of_rombs;

	while (num_of_rombs > 0)
	{
		cout << "  *  ";
		--num_of_rombs;
	}
	cout << endl;
	num_of_rombs = tmp;
	while (num_of_rombs > 0)
	{
		cout << " *** ";
		--num_of_rombs;
	}
	cout << endl;
	num_of_rombs = tmp;
	while (num_of_rombs > 0)
	{
		cout << "*****";
		--num_of_rombs;
	}
	cout << endl;
	num_of_rombs = tmp;
	while (num_of_rombs > 0)
	{
		cout << " *** ";
		--num_of_rombs;
	}
	cout << endl;
	num_of_rombs = tmp;
	while (num_of_rombs > 0)
	{
		cout << "  *  ";
		--num_of_rombs;
	}
	cout << endl;
	num_of_rombs = tmp;
}