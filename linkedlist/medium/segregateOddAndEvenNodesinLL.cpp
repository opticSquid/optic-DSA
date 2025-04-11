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

void printLinkedList(ListNode *head);

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }
        ListNode *temp = head->next;
        ListNode *insertPos = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            ListNode *current = temp;
            ListNode *next = current->next;
            ListNode *firstEven = insertPos->next;

            temp = temp->next->next;
            current->next = next->next;
            insertPos->next = next;
            next->next = firstEven;
            insertPos = next;
        }
        return head;
    }
};

int main()
{
    ListNode *six = new ListNode(6);
    ListNode *five = new ListNode(5, six);
    ListNode *four = new ListNode(4, five);
    ListNode *three = new ListNode(3, four);
    ListNode *two = new ListNode(2, three);
    ListNode *one = new ListNode(1, two);
    cout << "printing before segregating" << endl;
    printLinkedList(one);
    Solution obj;
    ListNode *newHead = obj.oddEvenList(one);
    cout << "printing after segregating" << endl;
    printLinkedList(newHead);
    return 0;
}
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