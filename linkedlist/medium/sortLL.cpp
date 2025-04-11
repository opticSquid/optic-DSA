#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
private:
    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *mergeLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *temp = dummyHead;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1 != nullptr)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }
        return dummyHead->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next;
        middle->next = nullptr;
        ListNode *left = head;
        left = sortList(left);
        right = sortList(right);
        return mergeLists(left, right);
    }
};
void printLinkedList(ListNode *head);
int main()
{
    int length = 10000;
    int *arr = createRandomArray(length, 0, 100);
    ListNode *prev = nullptr;
    for (int i = 3; i >= 0; i--)
    {
        ListNode *node = new ListNode(arr[i], prev);
        prev = node;
    }
    Solution obj;
    obj.sortList(prev);
    return 0;
}

int *createRandomArray(int length, int minValue = 0, int maxValue = 100)
{
    if (length <= 0)
    {
        return nullptr; // Return nullptr for invalid length
    }

    int *arr = new int[length]; // Dynamically allocate array
    std::srand(std::time(0));   // Seed the random number generator

    for (int i = 0; i < length; ++i)
    {
        arr[i] = minValue + std::rand() % (maxValue - minValue + 1); // Generate random number in range
    }

    return arr;
}