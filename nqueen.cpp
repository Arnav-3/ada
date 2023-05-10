#include<bits/stdc++.h>
using namespace std;
bool Place(int k, int i, int x[])
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || (abs(j - k) == abs(x[j] - i)))
        {
            return false;
        }
    }
    return true;
}

void NQueens(int k, int n, int x[])
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i, x))
        {
            x[k] = i;
            if (k == n)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << endl;
            }
            else
            {
                NQueens(k + 1, n, x);
            }
        }
    }
}
int main() {
    cout<<"ENTER THE VALUE OF N : ";
    int n;
    cin>>n;
    int x[n + 1];
    NQueens(1, n, x);
 
    
    return 0;
}