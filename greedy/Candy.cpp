#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n);
        // cosider left neighs
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                candies[i] = 1;
                continue;
            }
            else if (ratings[i] > ratings[i - 1])
            {
                // increase candy by +1 of previous
                candies[i] = candies[i - 1] + 1;
            }
            else if (ratings[i] <= ratings[i - 1])
            {
                candies[i] = 1;
            }
        }
        int sum = 0;
        // cosider right neighs
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                candies[i] = max(candies[i], 1);
                sum += candies[i];
                continue;
            }
            else if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            else if (ratings[i] <= ratings[i + 1])
            {
                candies[i] = max(candies[i], 1);
            }
            sum += candies[i];
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }
    Solution obj;
    cout << obj.candy(ratings) << endl;
}