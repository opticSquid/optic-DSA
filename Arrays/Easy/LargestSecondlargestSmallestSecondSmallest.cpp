#include <bits/stdc++.h>
using namespace std;
struct result
{
    int largest;
    int smallest;
    int second_largest;
    int second_smallest;
};
result sortArray(int arr[], int size);
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 0, 8, 6, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    result r = sortArray(arr, size);
    cout << "l: " << r.largest << ",s: " << r.smallest << ",s_l:" << r.second_largest << ",s_s: " << r.second_smallest << endl;
}
result sortArray(int arr[], int size)
{
    int largest = INT32_MIN, smallest = INT32_MAX, scnd_lrgst = INT32_MIN, scnd_smllst = INT32_MAX;
    // edge case where only one element is present
    if (size == 0)
    {
        return {-1, -1, -1, -1};
    }
    // finding largest & second largest
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            scnd_lrgst = largest;
            largest = arr[i];
        }
        else if (arr[i] > scnd_lrgst && arr[i] != largest)
        {
            scnd_lrgst = arr[i];
        }
    }
    // finding smallest and second smallest element
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            scnd_smllst = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < scnd_smllst && arr[i] != smallest)
        {
            scnd_smllst = arr[i];
        }
    }
    return {largest, smallest, scnd_lrgst, scnd_smllst};
}