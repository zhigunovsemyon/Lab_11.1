/*
	SUM[i = 1, n] of (-1)^i * (x / i)

	Тестовые данные
	i	x		Значение
	5	1		-0,783
	0			Неправильное значение i
	3	0		0.000
	10	-1		1.291
	4	-1000	583.333
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TRUE 1
#define FALSE 0

void getnums(int* num, double* x);
double part(int i, double x);

int main(void)
{
	//Добавление переменных и ввод чисел
	int n;
	double x, sum = 0;
	//Ввод чисел
	getnums(&n, &x);

	//Цикл перебирает значения от 1 до n
	for (int i = 1; i <= n; i++)
	{
		double partOfSum = part(i, x);
		printf("%d-й член ряда равен %lf\n", i, partOfSum);
		sum += partOfSum;
	}
	printf("\nРезультат: %lf", sum);	//Вывод
	return 0;
}

/*Ввод числа витков num и коэффициента x
с проверкой на корректность*/
void getnums(int* num, double* x)
{
	//Ввод числа витков
	do
	{
		printf("Введите i большее или равное 1: ");
		scanf("%d", num);
		if (*num > 0)
			break;
		printf("Число i должно быть больше или равно 1\n");
	} while (TRUE);

	//Ввод числа x
	do
	{
		printf("Введите x : ");
		scanf("%lf", x);
		if (0.0 != *x)
			return;
		printf("Неправильное число x!\n");
	} while (TRUE);
}

//Функция вычисления i-го члена ряда с параметром x
double part(int i, double x)
{	//При чётном значении i (-1)^i = 1, при нечётном = -1  
	return	((i % 2 == 0) ? 1.0 : -1.0) * (x / i);//Это значение умножается на x/i
}
