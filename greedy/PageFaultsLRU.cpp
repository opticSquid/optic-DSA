#include <bits/stdc++.h>
using namespace std;
class LRU
{
private:
    vector<int> store;
    int cntr;
    int findIndex(int x)
    {
        for (int i = 0; i < store.size(); i++)
        {
            if (store[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
    void removeLast()
    {
        for (int i = 0; i < store.size() - 1; i++)
        {
            store[i] = store[i + 1];
        }
        cntr--;
    }

public:
    LRU(int capacity)
    {
        store.resize(capacity, INT_MIN);
        cntr = 0;
    }
    bool find(int x)
    {
        for (int i = 0; i < store.size(); i++)
        {
            if (store[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    /**
     *if capacity is left
     * Item is pushed to the front
     * if capacity not left
     * Last item is removed and then new item is added
     */
    void insert(int x)
    {
        if (cntr < store.size())
        {
            store[cntr] = x;
            cntr++;
        }
        else
        {
            removeLast();
            store[cntr] = x;
            cntr++;
        }
    }
    void update(int x)
    {
        int idx = findIndex(x);
        for (int i = idx; i < store.size() - 1; i++)
        {
            store[i] = store[i + 1];
        }
        store[cntr - 1] = x;
    }
};
class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        int flts = 0;
        LRU q(C);
        for (int i = 0; i < N; i++)
        {
            if (!q.find(pages[i]))
            {
                q.insert(pages[i]);
                flts++;
            }
            else
            {
                q.update(pages[i]);
            }
        }
        return flts;
    }
};
int main()
{
    int n, c;
    cin >> n >> c;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    Solution obj;
    cout << obj.pageFaults(n, c, pages) << endl;
    return 0;
}