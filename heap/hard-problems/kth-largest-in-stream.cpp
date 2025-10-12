#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int lim;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->lim = k;
        for (const int &n : nums)
        {
            pq.push(n);
            if (pq.size() > this->lim)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > this->lim)
        {
            pq.pop();
        }
        return pq.top();
    }
};
int main()
{
    vector<int> ini_nums = {4, 5, 8, 2};
    KthLargest *obj = new KthLargest(3, ini_nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    delete obj;
    return 0;
}