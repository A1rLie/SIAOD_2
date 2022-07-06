#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
};

//Ввод элементов
void Fill(vector<Point>& setPoints1, vector<Point>& setPoints2)
{
    for (int i = 0; i < setPoints1.size(); i++)
    {
        cout << "Введи координаты [" << i + 1 << "] точки первого множества >> ";
        cin >> setPoints1[i].x >> setPoints1[i].y;
    }

    cout << endl;

    for (int i = 0; i < setPoints2.size(); i++)
    {
        cout << "Введи координаты [" << i + 1 << "] точки второго множества >> ";
        cin >> setPoints2[i].x >> setPoints2[i].y;
    }
}

//Вывод 
void Print(vector<Point>& setPoints1, vector<Point>& setPoints2)
{
    cout << "\nМножество 1:" << endl;
    for (int i = 0; i < setPoints1.size(); i++)
    {
        cout << "[" << i + 1 << "]: (" << setPoints1[i].x << ";" << setPoints1[i].y << "), ";
    }
    cout << endl << endl;

    cout << "Множество 2:" << endl;
    for (int i = 0; i < setPoints2.size(); i++)
    {
        cout << "[" << i + 1 << "]: (" << setPoints2[i].x << ";" << setPoints2[i].y << "), ";
    }
    cout << endl;
}

//Проверка принадлежности точки к треугольнику
bool Belong(int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0)
{
    int res1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int res2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int res3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);

    if ((res1 >= 0 && res2 >= 0 && res3 >= 0) || (res1 <= 0 && res2 <= 0 && res3 <= 0)) return true;
    else return false;
}

//Поисковик
void Searcher(vector<Point>& setPoints1, vector<Point>& setPoints2, vector<Point[3]>& triangle)
{
    int numTriangle = 0;
    for (int i = 0; i < setPoints1.size(); i++) //Перебор первой точки
    {
        for (int j = i + 1; j < setPoints1.size(); j++) //Перебор второй точки
        {
            for (int k = j + 1; k < setPoints1.size(); k++) //Перебор третьей точки
            {
                int counter1 = 0; //Счетчик чисел для первого множества
                int counter2 = 0; //Счетчик чисел для второго множества
                for (int z = 0; z < setPoints1.size(); z++) //Счетчик для прогона оставшихся координат из первого множества
                {
                    if (z != i && z != j && z != k) //Проверка на совпадение координат
                    {
                        if (Belong(setPoints1[i].x, setPoints1[i].y, setPoints1[j].x, setPoints1[j].y, setPoints1[k].x, setPoints1[k].y, setPoints1[z].x, setPoints1[z].y)) counter1++;
                    }
                }

                for (int z = 0; z < setPoints2.size(); z++) //Перебор точек из второго множества
                {
                    if (setPoints2[z].x != setPoints1[i].x || setPoints2[z].y != setPoints1[i].y &&
                        setPoints2[z].x != setPoints1[j].x || setPoints2[z].y != setPoints1[j].y &&
                        setPoints2[z].x != setPoints1[k].x || setPoints2[k].y != setPoints1[k].y)
                    {
                        if (Belong(setPoints1[i].x, setPoints1[i].y, setPoints1[j].x, setPoints1[j].y, setPoints1[k].x, setPoints1[k].y, setPoints2[z].x, setPoints2[z].y)) counter2++;
                    }
                }

                if (counter1 == counter2 && counter1 != 0)
                {
                    triangle.resize(triangle.size() + 1);
                    triangle[numTriangle][0].x = setPoints1[i].x, triangle[numTriangle][0].y = setPoints1[i].y;
                    triangle[numTriangle][1].x = setPoints1[j].x, triangle[numTriangle][1].y = setPoints1[j].y;
                    triangle[numTriangle][2].x = setPoints1[k].x, triangle[numTriangle][2].y = setPoints1[k].y;
                    numTriangle++;
                    /*cout << "Точки: (" << setPoints1[i][0] << ";" << setPoints1[i][1] << "), (" << setPoints1[j][0] << ";" << setPoints1[j][1] << "), (" << setPoints1[k][0] << ";" << setPoints1[k][1] << ") " <<
                        "равное количество точек первого и второго множества, их количество - " << counter1;
                    return;*/
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    vector<Point> points1;
    vector<Point> points2;
    int size1, size2;
    cout << "Количество точек первого множества >> ";
    cin >> size1;
    points1.resize(size1);

    cout << "Количество точек второго множества >> ";
    cin >> size2;
    points2.resize(size2);


    Fill(points1, points2);
    Print(points1, points2);
    cout << endl;

    vector<Point[3]> triangle;
    Searcher(points1, points2, triangle);
    for (int i = 0; i < triangle.size(); i++)
    {
        cout << "Треугольник [" << i + 1 << "]: (" << triangle[i][0].x << ";" << triangle[i][0].y << "), ("
            << triangle[i][1].x << ";" << triangle[i][1].y << "), ("
            << triangle[i][2].x << ";" << triangle[i][2].y << "), (" << endl;
    }
}