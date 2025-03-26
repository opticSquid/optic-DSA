#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverseLL(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *prev = nullptr;
        while (head != nullptr)
        {
            ListNode *front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode *middle = findMiddle(head);
        ListNode *newHead = reverseLL(middle->next);
        while (newHead != nullptr)
        {
            if (head->val != newHead->val)
            {
                reverseLL(middle->next);
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }
        reverseLL(middle->next);
        return true;
    }
};
int main()
{
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    one->next = two;
    Solution obj;
    cout << obj.isPalindrome(one) << endl;
    return 0;
}