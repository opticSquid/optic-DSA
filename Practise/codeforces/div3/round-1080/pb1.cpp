#include <iostream>

using namespace std;

int main()
{
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // For problems with multiple test cases
    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool sixty_seven = false;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x == 67)
            {
                cout << "YES" << "\n";
                sixty_seven = true;
            }
        }
        if (!sixty_seven)
        {
            cout << "NO" << "\n";
        }
    }
    cout << endl;
    return 0;
}
