#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void strip(string &str, char to_remove = ' ')
    {
        // remove: rearrages the non matching characters to the last of the string
        // erase: erases from remove index to last
        str.erase(remove(str.begin(), str.end(), to_remove), str.end());
    }
    vector<string> split(string &str, char delimeter)
    {
        vector<string> tokens;
        size_t start = 0;
        size_t pos;
        while ((pos = str.find(delimeter, start)) != string::npos)
        {
            tokens.push_back(str.substr(start, pos - start));
            start = pos + 1;
        }
        tokens.push_back(str.substr(start));
        return tokens;
    }
    pair<string, string> split(string &str)
    {
        pair<string, string> kv;
        int pos = 0, n = str.size();
        for (char c : str)
        {
            if (c == ':')
            {
                break;
            }
            pos++;
        }
        kv.first = str.substr(0, pos);
        pos++;
        kv.second = str.substr(pos, n);
        return kv;
    }
    unordered_map<string, string> json_parser(string &json_str)
    {
        std::unordered_map<std::string, std::string> data;
        strip(json_str, '{');
        strip(json_str, '}');
        vector<string> pairs = split(json_str, ',');
        for (string s : pairs)
        {
            strip(s, '"');
            pair<string, string> p = split(s);
            data.insert(p);
        }
        return data;
    }

public:
    vector<string> find_diff(string json_str1, string json_str2)
    {
        unordered_map<string, string> json1 = json_parser(json_str1);
        unordered_map<string, string> json2 = json_parser(json_str2);
        vector<string> diff;
        for (auto [k, v] : json1)
        {
            if (json2.find(k) != json2.end() && json1[k] != json2[k])
            {
                diff.push_back(k);
            }
        }
        sort(diff.begin(), diff.end());
        return diff;
    }
};
int main()
{
    string json1_str = "{\"hello\":\"world\",\"hi\":\"hello\",\"you\": \"me\"}";
    string json2_str = "{\"hello\": \"india\",\"hi\":\"hello\",\"you\":\"they\"}";
    string json3_str = "{\"hacker\":\"rank\",\"input\":\"output\"}";
    string json4_str = "{\"hacker\": \"ranked\",\"input\":\"wrong\"}";
    Solution obj;
    for (auto rec : obj.find_diff(json1_str, json2_str))
    {
        cout << rec << endl;
    }
    for (auto rec : obj.find_diff(json3_str, json4_str))
    {
        cout << rec << endl;
    }
    return 0;
}