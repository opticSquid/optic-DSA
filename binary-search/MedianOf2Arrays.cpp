#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double find_median_by_pseudo_merge_sort(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size(), n = n1 + n2;
        int med_idx1 = (n1 + n2) / 2, med_idx2 = med_idx1 - 1;
        int i = 0, j = 0, third_idx = 0;
        int med_idx_el_1 = -1, med_idx_el_2 = -1;
        while (i < n1 && j < n2)
        {
            if (a[i] < b[j])
            {
                if (third_idx == med_idx1)
                    med_idx_el_1 = a[i];
                if (third_idx == med_idx2)
                    med_idx_el_2 = a[i];
                i++;
                third_idx++;
            }
            else
            {
                if (third_idx == med_idx1)
                    med_idx_el_1 = b[j];
                if (third_idx == med_idx2)
                    med_idx_el_2 = b[j];
                j++;
                third_idx++;
            }
        }
        while (i < n1)
        {
            if (third_idx == med_idx1)
                med_idx_el_1 = a[i];
            if (third_idx == med_idx2)
                med_idx_el_2 = a[i];
            i++;
            third_idx++;
        }
        while (j < n2)
        {
            if (third_idx == med_idx1)
                med_idx_el_1 = b[j];
            if (third_idx == med_idx2)
                med_idx_el_2 = b[j];
            j++;
            third_idx++;
        }
        // calculate median
        if (n % 2 == 0)
        {
            return (double)((double)(med_idx_el_1 + med_idx_el_2) / 2.0);
        }
        else
        {
            return (double)(med_idx_el_1);
        }
    }
    double find_median_by_binary_search(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2)
            return find_median_by_binary_search(b, a);
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // length of left half
        int l = 0, r = n1;
        while (l <= r)
        {
            // this is a bitwise operation depicts (l+r)/2
            int mid1 = (l + r) >> 1;
            int mid2 = left - mid1;
            // calculate l1,r1, l2,r2
            int l1 = INT_MIN, r1 = INT_MAX;
            int l2 = INT_MIN, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];

            // diagonal check
            // if this check passes means array is sorted
            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
            }
            // eliminate the halves
            else if (l1 > r2)
                r = mid1 - 1;
            else
                l = mid1 + 1;
        }
        // dummy return
        return 0;
    }
};
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    Solution obj;
    cout << obj.find_median_by_binary_search(arr1, arr2) << endl;
    return 0;
}
