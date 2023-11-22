#include <bits/stdc++.h>

using namespace std;

// Function to flip a character (0 to 1 or vice versa)
char flip(char c)
{
    return (c == '0') ? '1' : '0';
}
int count(const std::string &binary_string)
{
    int count = 0;
    for (char c : binary_string)
    {
        count += c & 1;
    }
    return count;
}
string findSmallest(const string &s, int k)
{
    int n = s.size();
    string smallest = s;

    // Iterate through each character
    for (int i = 0; i < n && k > 0; i++)
    {
        // Check if flipping the current character can improve the string
        string flipped = s;
        flipped[i] = flip(s[i]);

        // Compare lexicographically with the current smallest
        if (flipped < smallest)
        {
            smallest = flipped;
            k--; // Decrement remaining operations
        }

        // Early termination if remaining operations cannot create a smaller string
        if (smallest[i] == '0')
        {
            break;
        }
    }

    // Use remaining operations to delete leading 1s
    int deletions = min(k, count(smallest));
    smallest.erase(0, deletions);

    return smallest;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string smallest = findSmallest(s, k);
        cout << smallest << endl;
    }

    return 0;
}