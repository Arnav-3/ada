#include <bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2)
{

    int m, n;
    m = s1.length();
    n = s2.length();
    int matrix[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
            {
                if (matrix[i - 1][j] <= matrix[i][j - 1])
                {
                    matrix[i][j] = matrix[i][j - 1];
                }
                else
                {
                    matrix[i][j] = matrix[i - 1][j];
                }
            }
        }
    }
    string result;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            result += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (matrix[i - 1][j] <= matrix[i][j - 1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(result.begin(), result.end());
        cout<<"length of lcs = "<<result.length()<<endl;

    return result;
}

int main()
{
    cout << "enter string 1 and 2 \n";
    string s1, s2;
    cin >> s1 >> s2;
    cout<<"longest common subsequence is "<< lcs(s1, s2);

}



