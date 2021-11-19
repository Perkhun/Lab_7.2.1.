#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Change(int** a, const int rowCount, const int colCount);
int SearchMinOdd(int** a, const int rowCount, const int colCount);
int SearchMaxOdd(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));                    //Написати програму, яка міняє місцями максимальний елемент кожного парного рядка
	                                                //з мінімальним елементом попереднього непарного рядка матриці(k  n).Пояснити
		                                            //призначення змінних
	int rowCount;
	int colCount;
	int Low = -30;
	int High = 35;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Change(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;

}
void Change(int** a, const int rowCount, const int colCount)
{
	int min, max, imin, imax;
	for (int i = 2; i < rowCount; i +=2)
	{		
			imax = SearchMaxOdd(a, i, colCount);
			max = a[i][imax];
			imin = SearchMinOdd(a, i - 1, colCount);
			min = a[i - 1][imin];
		
	
		a[i][imax] = min;
		a[i-1][imin] = max;
		
	}
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int SearchMinOdd(int** a, const int rowNo, const int colCount)
{
	int min = a[rowNo][0];
	int jmin = 0;
	for (int j = 0; j < colCount; j++)
	{
		if (a[rowNo][j] < min)
		{
			min = a[rowNo][j];
			jmin = j;
		}
	}
	return jmin;

}

int SearchMaxOdd(int** a, const int rowNo, const int colCount)
{
	int max = a[rowNo][0];
	int jmax = 0;
	for (int j = 1; j < colCount; j++)
	{
		if (a[rowNo][j] > max )
		{
			max = a[rowNo][j];
			jmax = j;
		}
	}
	return jmax;
}

