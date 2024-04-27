#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int count_students_for_pages(vector<int> &pages, int page_per_student)
    {
        int n = pages.size(), num_students = 1;
        long long num_pages = 0;
        for (int i = 0; i < n; i++)
        {
            // if number of pages for that student
            // after addition is less than target pages
            // add more pages to him
            if (num_pages + pages[i] <= page_per_student)
            {
                num_pages += pages[i];
            }
            // or assign the pages to next student
            else
            {
                num_students++;
                num_pages = pages[i];
            }
        }
        return num_students;
    }

public:
    int min_of_max_pages_assigned(vector<int> &pages, int students)
    {
        int l = *max_element(pages.begin(), pages.end());
        int r = accumulate(pages.begin(), pages.end(), 0);
        // total books is less than number of students
        if (pages.size() < students)
        {
            return -1;
        }
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // if number of students couted is less than target students
            // we have to increase the number of students
            // to do that we need to decrase our value of page per students
            // this also can be a possible answer
            // so we need to seek for more smaller value to find the min
            if (count_students_for_pages(pages, mid) <= students)
            {
                r = mid - 1;
            }
            // if number of students couted is less than target students
            // we have to increase the number of students
            // to do that we need to decrase our value of page per students
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.min_of_max_pages_assigned(arr, k) << endl;
}