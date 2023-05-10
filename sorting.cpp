#include <bits/stdc++.h>
using namespace std;

void selection(int array[], int n)
{
    int i, j, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(array[i], array[min]);
        }
    }
}
void merge(int array[], int first, int mid, int last)
{
    int size1, size2;
    size1 = mid - first + 1;
    size2 = last - mid;

    int sub1[size1], sub2[size2];

    for (int a = 0; a < size1; a++)
        sub1[a] = array[a + first];

    for (int b = 0; b < size2; b++)
        sub2[b] = array[b + mid + 1];

    int i = 0;
    int j = 0;
    int k = first;

    while (i < size1 && j < size2)
    {
        if (sub1[i] <= sub2[j])
        {
            array[k] = sub1[i];
            i++;
        }
        else
        {
            array[k] = sub2[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        array[k] = sub1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        array[k] = sub2[j];
        j++;
        k++;
    }
}
void merge_sort(int array[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        merge_sort(array, first, mid);
        merge_sort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}
void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int j = partition(array, low, high);
        quicksort(array, low, j - 1);
        quicksort(array, j + 1, high);
    }
}
void insertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main()
{

    cout << "enter value of n : ";
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = rand();
    }

    cout << "unsorted - ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    selection(array, n);
    
    /*     merge_sort(array,0,n-1);
     */
    /*     quicksort(array,0,n-1);
     */
/*     insertionSort(array, n);
 */    cout << "\nsorted - ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}