#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void deleteFirst2(vector<int> &nums, int &target, int &counter)
    {

        // cout << nums[0] << " + " << nums[1] << endl;
        if (nums[0] + nums[1] == target)
        {
            counter++;
            // delete first 2
            nums.erase(nums.begin(), nums.begin() + 2);
        }
    }
    void deleteLast2(vector<int> &nums, int &target, int &counter)
    {
        // cout << nums[nums.size() - 1] << " + " << nums[nums.size() - 2] << endl;
        if (nums[nums.size() - 1] + nums[nums.size() - 2] == target)
        {
            counter++;
            // delete last 2
            nums.erase(nums.end() - 2, nums.end());
        }
    }
    void deleteFirstAndLast(vector<int> &nums, int &target, int &counter)
    {
        // cout << nums[0] << " + " << nums[nums.size() - 1] << endl;
        if (nums[0] + nums[nums.size() - 1] == target)
        {
            counter++;
            // delete first
            nums.erase(nums.begin());
            // delete last
            nums.erase(nums.end());
        }
    }
    void f1(vector<int> &v, int &target, int &c)
    {
        deleteFirst2(v, target, c);
        deleteLast2(v, target, c);
        deleteFirstAndLast(v, target, c);
    }

    void f2(vector<int> &v, int &target, int &c)
    {
        deleteFirst2(v, target, c);
        deleteFirstAndLast(v, target, c);
        deleteLast2(v, target, c);
    }

    void f3(vector<int> &v, int &target, int &c)
    {
        deleteFirstAndLast(v, target, c);
        deleteLast2(v, target, c);
        deleteFirst2(v, target, c);
    }
    void f4(vector<int> &v, int &target, int &c)
    {
        deleteLast2(v, target, c);
        deleteFirst2(v, target, c);
        deleteFirstAndLast(v, target, c);
    }

public:
    int maxOperations(vector<int> &nums)
    {
        int counter = 0;
        int target = nums[0] + nums[1];
        for (int i = 0; i < nums.size(); i++)
        {
            int c1 = counter, c2 = counter, c3 = counter, c4 = counter;
            vector<int> v1(nums);
            vector<int> v2(nums);
            vector<int> v3(nums);
            vector<int> v4(nums);
            thread t1(&Solution::f1, this, ref(v1), ref(target), ref(c1));
            thread t2(&Solution::f2, this, ref(v2), ref(target), ref(c2));
            thread t3(&Solution::f3, this, ref(v3), ref(target), ref(c3));
            thread t4(&Solution::f4, this, ref(v4), ref(target), ref(c4));
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            counter = max({c1, c2, c3, c4});
            if (counter == c1)
            {
                nums = v1;
            }
            else if (counter == c2)
            {
                nums = v2;
            }
            else if (counter == c3)
            {
                nums = v3;
            }
            else
            {
                nums = v4;
            }
        }
        return counter;
    }
};
int main()
{
    vector<int> nums1 = {3, 2, 1, 2, 3, 4};
    Solution obj;
    cout << obj.maxOperations(nums1) << endl;
    return 0;
}