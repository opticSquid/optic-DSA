// https://leetcode.com/discuss/post/483660/google-phone-currency-conversion-by-anon-upqo/
#include <bits/stdc++.h>
using namespace std;
struct ConversionRate
{
    string from;
    string to;
    float conversion_rate;
};
class Solution
{
private:
    unordered_map<string, vector<pair<string, float>>> grph;
    void init_graph(vector<ConversionRate> &rates)
    {
        // to ensure the object is not copied again to create r we use const pointer
        for (const auto &r : rates)
        {
            this->grph[r.from].push_back({r.to, r.conversion_rate});
        }
    }

public:
    float solve(vector<ConversionRate> &rates, vector<string> &output)
    {
        init_graph(rates);
    }
};
int main()
{
    int n;
    cin >> n;
    // this places converstion_rate objects contiguously in memory resulting in faster look ups and better memory utilization for caching. this is fine until n is in reasonable range
    vector<ConversionRate> rates(n);
    string f, t;
    float c;
    for (int i = 0; i < n; i++)
    {
        cin >> f >> t >> c;
        rates[i] = {f, t, c};
    }
    vector<string> op(2);
    for (int i = 0; i < 2; i++)
    {
        cin >> op[i];
    }
    Solution obj;
    cout << obj.solve(rates, op) << endl;
    return 0;
}