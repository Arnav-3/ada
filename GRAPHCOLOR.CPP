#include <iostream>
using namespace std;
#define N 4
int NextValue(int k, int x[], int G[][4], int n, int m)
{
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return 0;
        int j;
        for (j = 0; j < n; j++)
        {
            if (G[k][j] && x[k] == x[j])
                break;
        }
        if (j == n)
            return x[k];
    } while (true);
}

void mColoringUtil(int k, int x[], int G[][4], int n, int m)
{
    do
    {
        x[k] = NextValue(k, x, G, n, m);
        if (x[k] == 0)
            return;
        if (k == n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        else
        {
            mColoringUtil(k + 1, x, G, n, m);
        }
    } while (true);
}

void mColoring(int G[][4], int n, int m)
{
    int x[N];
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    mColoringUtil(0, x, G, n, m);
}

int main()
{
    int  m;
    cout << "Enter the maximum number of colors: ";
    cin >> m;

    int G[N][N] =
        {{0, 1, 1, 0},
         {1, 0, 1, 1},
         {1, 1, 0, 1},
         {0, 1, 1, 0}};

    mColoring(G, N, m);

    return 0;
}
