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
    ListNode *reverse_list(ListNode *head)
    {
        if (head == nullptr | head->next == nullptr)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while ((l1 != nullptr || l2 != nullptr) || carry)
        {
            int sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Solution obj;
    return 0;
}