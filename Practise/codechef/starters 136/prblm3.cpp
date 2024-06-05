#include <bits/stdc++.h>
using namespace std;
void countCellsTravelled_BruteForce(string &s)
{
    int travel = 1, count1 = 0;
    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '1')
        {
            count1++;
        }
    }
    if (count1 == 1)
    {
        cout << 11 << endl;
    }
    else if (count1 == 2)
    {
        if ((s[0] == '1' && s[1] == '1') || (s[2]) == '1' && s[3] == '1')
        {
            cout << 21 << endl;
        }
        else
        {
            cout << 121 << endl;
        }
    }
    else if (count1 == 3)
    {
        cout << 231 << endl;
    }
    else
    {
        cout << 441 << endl;
    }
}
void countCellsTravelled_BestApproach(string &S)
{
    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;

    if (S[0] == '1')
        min_x = -10; // left
    if (S[1] == '1')
        max_x = 10; // right
    if (S[2] == '1')
        max_y = 10; // up
    if (S[3] == '1')
        min_y = -10; // down

    int cells = (max_x - min_x + 1) * (max_y - min_y + 1);
    cout << cells << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        countCellsTravelled_BruteForce(s);
    }
    return 0;
}
