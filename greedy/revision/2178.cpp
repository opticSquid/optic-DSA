#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum & 1 == 1)
        {
            return {};
        }
        else
        {
            long long current_sum = 0ll;
            long long next_item = 2ll;
            vector<long long> set;
            while (current_sum + next_item <= finalSum)
            {
                current_sum += next_item;
                set.push_back(next_item);
                next_item += 2;
            }
            set[set.size() - 1] += finalSum - current_sum;
            return set;
        }
    }
};
int main()
{
    Solution obj;
    vector<long long> res = obj.maximumEvenSplit(7ll);
    for (long long i : res)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}