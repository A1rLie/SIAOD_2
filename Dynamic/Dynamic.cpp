#include <iostream>
#include <time.h>

using namespace std;

//Заполнение пользователем
void FillUser(int** array, int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cin >> array[i][j];
		}
	}
}

//Заполнение рандомайзером
void FillRand(int** array, int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}

//Вывод массива
void Print(int** array, int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

//Вывод спиралью
void Spiral(int** array, int rows, int cols)
{
	int x = 0, y = 0;
	int wallLOW = cols - 1, wallHIGHT = 0, wallRIGHT = rows - 1, wallLEFT = 0; //Коридоры передвижения
	string goal = "hr"; //Цель угол
	for (int i = 1; i <= rows * cols; i++)
	{
		cout << array[y][x] << " ";

		//Левая верхняя точка
		if (x == wallLEFT && y == wallHIGHT && goal == "hl")
		{
			wallLEFT++;
			x++;
			goal = "hr";
		}

		//Верхняя правая точка
		else if (x == wallRIGHT && y == wallHIGHT && goal == "hr")
		{
			wallHIGHT++;
			y++;
			goal = "lr";
		}

		//Нижняя правая точка
		else if (x == wallRIGHT && y == wallLOW && goal == "lr")
		{
			wallRIGHT--;
			x--;
			goal = "ll";
		}

		//Нижняя левая точка
		else if (x == wallLEFT && y == wallLOW && goal == "ll")
		{
			wallLOW--;
			y--;
			goal = "hl";
		}

		//Движение направо
		else if (x < wallRIGHT && y == wallHIGHT)
		{
			x++;
		}

		//Движение вниз
		else if (x == wallRIGHT && y < wallLOW)
		{
			y++;
		}

		//Движение влево
		else if (x > wallLEFT && y == wallLOW)
		{
			x--;
		}

		//Движение вверх
		else if (x == wallLEFT && y > wallHIGHT)
		{
			y--;
		}
	}
}

int main()
{
	srand(time(NULL)); //Установка рандомайзера
	setlocale(LC_ALL, "rus");
	int rows, cols;
	cout << "Размер матрицы nxn, n >> ";
	cin >> rows;
	cols = rows;
	int** array = new int*[rows]; //Объявление массива
	for (int i = 0; i < cols; i++)
	{
		array[i] = new int[rows];
	}

	int chose;
	cout << "Спобос ввода:\n1. Пользовательский\n0. Автоматический\n>> ";
	cin >> chose;
	if (chose) FillUser(array, rows, cols); //Инициализация массива
	else FillRand(array, rows, cols); 

	Print(array, cols, cols); //Вывод введенного массива
	cout << endl;

	Spiral(array, rows, cols); //Вывод спиралью

	for (int i = 0; i < cols; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
