#include <bits/stdc++.h>
using namespace std;
struct Item {
  int value;
  int weight;
};
class Solution {
private:
  bool static comp(Item a, Item b) {
    float vpw_a = (float)a.value / (float)a.weight;
  }

public:
  // Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(int w, Item arr[], int n) {
    // Your code here
  }
};
int main() {
  int n, w;
  cin >> n >> w;
  Item arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].value >> arr[i].weight;
  }
  Solution obj;
  cout << obj.fractionalKnapsack(w, arr, n) << endl;
}
