#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
private:
    priority_queue<int> mxHp;
    priority_queue<int, vector<int>, greater<int>> mnHp;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        mxHp.push(num);
        mnHp.push(mxHp.top());
        mxHp.pop();
        if (mnHp.size() > mxHp.size())
        {
            mxHp.push(mnHp.top());
            mnHp.pop();
        }
    }

    double findMedian()
    {
        if (mxHp.size() == mnHp.size())
        {
            return (mxHp.top() + mnHp.top()) / 2.0;
        }
        else
        {
            return mxHp.top();
        }
    }
};
int main()
{
    MedianFinder *obj = new MedianFinder();
    vector<pair<int, int>> inp = {{0, -1}, {1, 1}, {1, 2}, {0, -1}, {1, 3}, {0, -1}};
    for (const auto &it : inp)
    {
        switch (it.first)
        {
        case 0:
            cout << obj->findMedian() << endl;
            break;
        case 1:
            obj->addNum(it.second);
            break;
        default:
            break;
        }
    }
    delete obj;
    return 0;
}