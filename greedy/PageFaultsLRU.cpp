#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        // this represents the memory
        unordered_set<int> s;
        unordered_map<int, int> indexes;
        int flts = 0;
        for (int i = 0; i < N; i++)
        {
            // memory capacity left
            if (s.size() < C)
            {
                // check if item is already in the memory
                if (s.find(pages[i]) == s.end())
                {
                    // if not store the item in the memory
                    s.insert(pages[i]);
                    flts++;
                }
            }
            // memory is full
            else
            {
                // check if item is already in the memory
                if (s.find(pages[i]) == s.end())
                {
                    // if not delete the lest recently used item from memory the create space
                    int lru = INT_MAX, val;
                    for (int it : s)
                    {
                        if (indexes[it] < lru)
                        {
                            lru = indexes[it];
                            val = it;
                        }
                    }
                    s.erase(val);
                    s.insert(pages[i]);
                    flts++;
                }
            }
            // store the index of item in map
            indexes[pages[i]] = i;
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