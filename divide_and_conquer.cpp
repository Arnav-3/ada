#include <iostream>
#include <climits>

using namespace std;
int comp=0;
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
void divide_conquer(int array[], int low, int high, int &max, int &min)
{
    int mid, max1, max2, min1, min2;

    if (high == low)
    {
        min = max = array[low];
        return;
    }

    if (high == low + 1)
    {
        comp++;
        if (array[low] > array[high])
        {
            max = array[low];
            min = array[high];
   
        }
        else
        {
            max = array[high];
            min = array[low];
        }
        return;
    }

    mid = (low + high) / 2;
    divide_conquer(array, low, mid, max1, min1);
    divide_conquer(array, mid + 1, high, max2, min2);

    comp += 2;
    if (max1 > max2)
    {   
        max = max1;
    }
    else
    {   
        max = max2;
    }

    comp += 2;
    if (min1 < min2)
    {   
        min = min1;
    }
    else
    {   
        min = min2;
    }
}


void min_(int array[], int n)
{
    int min = array[0];
    for (int j = 1; j < n; j++)
    {
        if (array[j] < min)
        {
            min = array[j];
        }
    }
    cout << "\nmin = " << min;
}

void max_(int array[], int n)
{
    int max = array[0];
    for (int j = 1; j < n; j++)
    {
        if (array[j] > max)
        {
            max = array[j];
        }
    }
    cout << "\nmax = " << max;
}

int main()
{
    int n;
    cout << "enter number of elemnts in array : ";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i]=rand();
    }
    cout << endl;

    int max, min;
    cout << "using divide and conquer method : \n";
    divide_conquer(array, 0, n - 1, max, min);
    cout << "max = " << max << endl;
    cout << "min = " << min << endl;
    cout << "using normal method : \n";
    max_(array, n);
    min_(array, n);
    cout<<"\n"<<comp;
    return 0;
}