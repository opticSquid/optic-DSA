#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int *arr, int len);
void display(int *arr, int len);
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    // gives the size as if the arr index is 1 based
    // i.e., for arr it is 10
    int len = sizeof(arr) / sizeof(*arr);
    cout << "Before sorting:" << endl;
    display(arr, len);
    bubbleSort(arr, len);
    cout << "After Sorting:" << endl;
    display(arr, len);
    return 0;
}
void bubbleSort(int *arr, int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
void display(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}