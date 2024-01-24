#include <stdio.h>
#include <iostream>
using namespace std;
int x[1000];
int y[1000];
/**
   用来判断叉积是否大于0
*/
int mul(int i, int j, int k)
{
    int x1, x2, y1, y2;
    x1 = x[j] - x[i];
    x2 = x[k] - x[j];
    y1 = y[j] - y[i];
    y2 = y[k] - y[j];
    if (x1 * y2 - y1 * x2 > 0)
        return 1;
    else
        return 0;
}
int main()
{
    int n, i;
    n = 4;
    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int flag = 1;
    for (i = 0; i < n; i++)
    {
        if (!mul(i, (i + 1) % n, (i + 2) % n))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}