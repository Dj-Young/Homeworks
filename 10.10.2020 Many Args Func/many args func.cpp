#include <iostream>
#include <stdarg.h>

using namespace std;

int even_count(int n, ...)
{
	int counter = 0;
	for (int* ptr = &n; n > 0; --n)
		if (*(ptr) % 2 == 0)
			++counter;
	return counter;
}

double srednee(int n, ...)
{
	double midle = 0.0;
	double sum = 0.0;
	int counter = 0;
	double argum = n;
	va_list args;
	va_start(args, n);

	do
	{
		sum += argum;
		argum = va_arg(args, int);
		++counter;
	} while (argum != -1);
	va_end(args);
	return sum / counter;
}

void main()
{
	cout << "even_counter(7,1,2,3,4,3,2,1) = " << even_count(7, 1, 2, 3, 4, 3, 2, 1) << endl;
	cout << "srednee(4, 5, 1, 3, 0, 6, 3, -1) = " << srednee(4, 5, 1, 3, 0, 6, 3, -1) << endl;;
}