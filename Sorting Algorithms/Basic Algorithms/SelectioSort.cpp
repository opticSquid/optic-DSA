#include <bits/stdc++.h>
using namespace std;
void selectionSort(int *arr, int length);
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    cout << "Before sort:" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    cout << "After Sort" << endl;
    selectionSort(arr, sizeof(arr) / sizeof(*arr));
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
void selectionSort(int *arr, int length)
{
    // length-1 to save the last iteration
    // where only 1 element will be left
    for (int lock = 0; lock < length - 1; lock++)
    {
        int min_ele_index = lock;
        int tmp;
        for (int i = lock + 1; i < length; i++)
        {
            if (arr[i] < arr[min_ele_index])
            {
                min_ele_index = i;
            }
        }
        tmp = arr[lock];
        arr[lock] = arr[min_ele_index];
        arr[min_ele_index] = tmp;
    }
}