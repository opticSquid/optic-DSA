#include <bits/stdc++.h>
using namespace std;
struct Item
{
  int value;
  int weight;
};
class Solution
{
private:
  bool static comp(Item a, Item b)
  {
    // vpw = value per weight
    float vpw_a = a.value / (double)a.weight;
    float vpw_b = b.value / (double)b.weight;
    return vpw_a > vpw_b;
  }

public:
  // Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(int w, Item arr[], int n)
  {
    // sort the elements in terms of value per weight
    // so most valuable item comes first
    sort(arr, arr + n, comp);
    int curr_wt = 0;
    double value = 0;
    for (int i = 0; i < n; i++)
    {
      // if adding the current item fully would still be in the weight range
      if (curr_wt + arr[i].weight <= w)
      {
        curr_wt += arr[i].weight;
        value += arr[i].value;
      }
      else
      {
        // keep this line other wise
        // the int and float multiplication in value+= line will happen i weird ways
        int remain = w - curr_wt;
        curr_wt += remain;
        value += (arr[i].value / (double)arr[i].weight) * (double)remain;
        break;
      }
    }
    return value;
  }
};
int main()
{
  int n, w;
  cin >> n >> w;
  Item arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].value >> arr[i].weight;
  }
  Solution obj;
  cout << obj.fractionalKnapsack(w, arr, n) << endl;
}
