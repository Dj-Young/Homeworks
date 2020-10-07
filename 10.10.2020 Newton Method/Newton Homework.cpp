#include <iostream>
#include <cmath>

using namespace std;

typedef double(*pfun)(double);

//Функции взяты с сайта:
//https://smekni.com/a/113645/nakhozhdenie-korney-uravneniya-metodom-nyutona-lisp-realizatsiya/

double f(double x)
{
	return x - cos(x);
}

double g(double x)
{
	return x * x + 2 * x;
}


double Neuton_Method(pfun activation_fun, double a, double b, double fallibility = 0.001)
{
	double x = 0;
	double mid = 0;
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a*(-1) == b)
		++b;

	do
	{
		mid = (a + b) / 2;
		x = activation_fun(mid);
		if (mid > 0)
		{
			if (x > 0 + fallibility)
				b = mid;
			if (x < 0 + fallibility)
				a = mid;
		}
		if (mid < 0)
		{
			if (x > 0 + fallibility)
				a = mid;
			if (x < 0 + fallibility)
				b = mid;
		}
		if (x <= 0 + fallibility && x >= 0 - fallibility)
			return mid;
	} while (true);
}


void main()
{
	setlocale(LC_ALL, "Rus");
	int fun_num = 0;
	double a = 0.0, b = 0.0;
	pfun FuncArray[] = { f, g };
	do
	{
		cout << "1. f " << endl;
		cout << "2. g " << endl;
		cout << "Введите номер функции, которую вы хотите передать в программу: ";
		cin >> fun_num;
		if (fun_num < 0 || fun_num > 2)
			cout << "Неверно введённые данные, попробуйте ещё раз!" << endl;
	} while (fun_num < 0 || fun_num > 2);

	cout << "Введите в каком отрезке находится решение" << endl << "a: "; cin >> a; cout << "b: "; cin >> b;
	cout << "Корень уравнения = " << Neuton_Method(FuncArray[fun_num - 1], a, b) << endl;
	delete[] FuncArray;
	
}