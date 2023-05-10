#include <iostream>
using namespace std;

void sumOfSubsets(int weights[], int target, int current_sum, bool taken[], int n, int index)
{
    if (current_sum == target)
    {
        cout << "Subset found: ";
        for (int i = 0; i < n; i++)
        {
            if (taken[i])
            {
                cout << weights[i] << " ";
            }
        }
        cout << endl;
        return;
    }

    if (index == n)
    {
        return;
    }

    taken[index] = true;
    if (current_sum + weights[index] <= target)
    {
        sumOfSubsets(weights, target, current_sum + weights[index], taken, n, index + 1);
    }

    taken[index] = false;
    sumOfSubsets(weights, target, current_sum, taken, n, index + 1);
}

int main()
{
    cout<<"Enter n";
    int n,target;
    cin>>n;
    int weights[n];
    for (int i = 0; i < n; i++)
    {
        cin>>weights[i];
    }
    cout<<"enter target";
    cin>>target;
    bool taken[n] = {false};

    sumOfSubsets(weights, target, 0, taken, n, 0);

    return 0;
}
