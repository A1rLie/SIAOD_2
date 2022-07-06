#include <iostream>

using namespace std;

bool Belong(int x1, int y1, int x2, int y2, int x3, int y3, int x0, int y0)
{
    int res1 = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int res2 = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int res3 = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);

    //cout << res1 << " " << res2<< " " << res3;

    if ((res1 > 0 && res2 > 0 && res3 > 0)|| (res1 < 0 && res2 < 0 && res3 < 0)) return true;
    else return false;
}

int main()
{
    cout << Belong(3,0,0,4,0,0,1,1);
}
