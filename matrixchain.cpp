#include <bits/stdc++.h>
using namespace std;

void print_matrix_order(int **s, int i, int j)
{
    if (i == j)
        cout << "A" << i + 1;
    else
    {
        cout << "(";
        print_matrix_order(s, i, s[i][j]);
        print_matrix_order(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int matrix_chain_multiplication(int array[], int n)
{
    int x = n - 1;
    int m[n][n];
    int **s = new int *[n];
    for (int i = 0; i < n; ++i)
        s[i] = new int[n];

    int i, j, k, l, q;

    for (i = 0; i < n; i++)
        m[i][i] = 0;

    for (l = 2; l <= n; l++)
    {
        for (i = 0; i <= n - l; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + array[i] * array[k + 1] * array[j + 1];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "\nMINIMUM NUMBER OF MULTIPLICATIONS ARE : " << m[0][n - 1] << endl;
    i = 0;
    j = n - 1;
    print_matrix_order(s, i, j);
}

int main()
{
    int n;
    cout << "ENTER NUMBER OF MATRICES :\t";
    cin >> n;
    int array[n + 1];
    cout << "ENTER MATRIX VALUES\n";
    for (int a = 0; a < n + 1; a++)
        cin >> array[a];
    matrix_chain_multiplication(array, n);

    return 0;
}
