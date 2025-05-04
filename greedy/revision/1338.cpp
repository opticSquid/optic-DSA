#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static bool compare_hash(int a, int b)
    {
        return a > b;
    }

public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> hash;
        sort(arr.begin(), arr.end());
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && arr[j] == arr[j - 1])
            {
                j++;
            }

            hash.push_back(j - i);
            i = j;
        }
        sort(hash.begin(), hash.end(), compare_hash);
        int count = 0, sum = 0;
        for (int i : hash)
        {
            sum += i;
            count++;
            if (sum >= n / 2)
            {
                return count;
            }
        }
        return -1;
    }
};
int main()
{
    Solution obj;
    vector<int> arr = {1, 9};
    cout << obj.minSetSize(arr) << endl;
    return 0;
}