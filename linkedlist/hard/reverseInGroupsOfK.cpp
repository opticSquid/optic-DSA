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
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while (temp != nullptr)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode *getKthNode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != nullptr && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevLast = nullptr;
        while (temp != nullptr)
        {
            ListNode *kthNode = getKthNode(temp, k);
            if (kthNode == nullptr)
            {
                if (prevLast)
                {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode *nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLL(temp);
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}