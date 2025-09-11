#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        const int n = cardPoints.size();
        int maxSum = 0;
        for (int l = 0; l < k; l++)
        {
            maxSum += cardPoints[l];
        }
        int sum = maxSum;
        for (int l = k - 1, r = n - 1; l >= 0; l--, r--)
        {
            sum -= cardPoints[l];
            sum += cardPoints[r];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    Solution obj;
    cout << obj.maxScore(cardPoints, k) << endl;
    return 0;
}