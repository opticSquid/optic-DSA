#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
private:
    Node *reverse_list(Node *head)
    {
        if (head == nullptr | head->next == nullptr)
        {
            return head;
        }
        Node *prev = nullptr;
        while (head != nullptr)
        {
            Node *front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }

public:
    Node *addOne(Node *head)
    {
        head = reverse_list(head);
        Node *temp = head;
        int carry = 1;
        while (temp != nullptr && carry != 0)
        {
            int res = temp->data + carry;
            temp->data = res % 10;
            carry = res / 10;
            temp = temp->next;
        }
        head = reverse_list(head);
        // for cases when addition of 1 increases the number of digits like 9 or 99 or 999 where addition of +1 will increase the number of digits
        if (carry > 0)
        {
            Node *extra = new Node(carry);
            extra->next = head;
            head = extra;
        }
        return head;
    }
};
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    // Node *one = new Node(1);
    // Node *five = new Node(5);
    Node *nine = new Node(9);
    // one->next = five;
    // five->next = nine;
    cout << "original" << endl;
    printLinkedList(nine);
    Solution obj;
    Node *head = obj.addOne(nine);
    cout << "after addition of +1" << endl;
    printLinkedList(head);
    return 0;
}