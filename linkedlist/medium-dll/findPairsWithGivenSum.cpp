#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> vec;
        Node *left, *right;
        left = head;
        right = head;
        while (right->next != nullptr)
        {
            right = right->next;
        }
        while (left->data < right->data)
        {
            if (left->data + right->data == target)
            {
                vec.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (left->data + right->data < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return vec;
    }
};

int main()
{
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    one->next = two;
    two->prev = one;
    two->next = three;
    three->prev = two;
    three->next = four;
    four->prev = three;
    int target = 5;
    Solution obj;
    for (pair<int, int> p : obj.findPairsWithGivenSum(one, target))
    {
        cout << p.first << ", " << p.second << endl;
    }
    return 0;
}