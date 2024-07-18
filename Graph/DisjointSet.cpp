#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
      a[i] = i;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
      string s;
      cin >> s;
      if (s == "UNION")
      {
        int z, x;
        cin >> x >> z;
        unionSet(a, x, z);
      }
      else
      {
        int x;
        cin >> x;
        int parent = find(a, x);
        cout << parent << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

/*Complete the functions below*/
int find(int A[], int X)
{
  // if ultimate parent return
  if (A[X] == X)
    return X;
  // otherwise, find this node's parent
  // and also do path compression
  return A[X] = find(A, A[X]);
}

void unionSet(int A[], int X, int Z)
{
  // find the ultimate parent of X
  int u_px = find(A, X);
  // find the ultimate parent of X
  int u_pz = find(A, Z);
  // Assign parent of Z to parent of X
  A[u_px] = u_pz;
}
