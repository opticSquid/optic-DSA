#include <bits/stdc++.h>
using namespace std;
class StockSpanner
{
private:
    // price, index
    stack<pair<int, int>> st;
    int nxt_idx;

public:
    StockSpanner() : nxt_idx(0)
    {
    }
    int next(int price)
    {
        // previous greater element condition
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        int prev_grtr_idx = !st.empty() ? st.top().second : -1;
        st.push({price, nxt_idx});
        int res = nxt_idx - prev_grtr_idx;
        nxt_idx++;
        return res;
    }
};
int main()
{
    vector<int> vec = {7, 2, 1, 3, 3, 1, 8};
    StockSpanner *obj = new StockSpanner();
    for (int i : vec)
    {
        cout << obj->next(i) << endl;
    }
    delete obj;
    return 0;
}