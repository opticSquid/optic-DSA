#include <bits/stdc++.h>
using namespace std;
class LFUCache
{
    // key: frequency, value: list of original key-value pairs that have the
    // same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator
    // corresponding key in the frequencies map's list.
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value)
    {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key)
    {
        const auto it = cache.find(key);
        if (it == cache.end())
        {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty())
        {
            frequencies.erase(f);

            if (minf == f)
            {
                ++minf;
            }
        }

        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
        {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end())
        {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size())
        {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();

            if (frequencies[minf].empty())
            {
                frequencies.erase(minf);
            }
        }

        minf = 1;
        insert(key, 1, value);
    }
};

int main()
{
    LFUCache *cache;
    vector<string> command = {"LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"};
    vector<vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {3}, {4, 4}, {1}, {3}, {4}};
    vector<vector<int>>::iterator values_it = values.begin();
    for (string c : command)
    {
        const vector<int> &current_values = *values_it;
        if (c == "LFUCache")
        {
            cache = new LFUCache(current_values[0]);
        }
        else if (c == "put")
        {
            cache->put(current_values[0], current_values[1]);
        }
        else
        {
            cout << cache->get(current_values[0]) << endl;
        }
        values_it++;
    }
    return 0;
}