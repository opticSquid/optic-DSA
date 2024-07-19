#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0, tens = 0;
        for (auto bill : bills)
        {
            switch (bill)
            {
            case 5:
                fives++;
                break;
            case 10:
                if (fives)
                {
                    tens++;
                    fives--;
                }
                else
                {
                    return false;
                }
                break;
            default:
                if (tens && fives)
                {
                    tens--;
                    fives--;
                }
                else if (fives >= 3)
                {
                    fives -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    return 0;
}