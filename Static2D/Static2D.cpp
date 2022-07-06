#include <iostream>
#include <time.h>

using namespace std;

const int ROWS = 2;
const int COLS = 2;

//Заполнение пользователем
void FillUser(int array[][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> array[i][j];
		}
	}
}

//Заполнение рандомайзером
void FillRand(int array[][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 10;
		}
	}
}

//Вывод массива
void Print(int array[][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

//Вывод спиралью
void Spiral(int array[][COLS], int rows, int cols)
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

	int arr[ROWS][COLS]; //Объявление массива

	int chose;
	cout << "Спобос ввода:\n1. Пользовательский\n0. Автоматический\n>> ";
	cin >> chose;
	if (chose) FillUser(arr, ROWS, COLS);//Инициализация 
	else FillRand(arr, ROWS, COLS);

	Print(arr, ROWS, COLS); //Вывод введенного массива
	cout << endl;
	
	Spiral(arr, ROWS, COLS);
}
