#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    int val;

public:
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
    int getVal() const
    {
        return this->val;
    }
};
class Solution
{
private:
    struct NodeComparator
    {
        // * Min heap
        // * return true if a > b
        // * opposite of what heap you want
        bool operator()(const Node *a, const Node *b) const
        {
            return a->getVal() > b->getVal();
        }
    };

public:
    Node *combineAndSort(vector<Node *> &lls)
    {
        priority_queue<Node *, vector<Node *>, NodeComparator> pq;
        for (const auto node : lls)
        {
            if (node != nullptr)
            {
                pq.push(node);
            }
        }
        Node *dummyHead = new Node(0);
        Node *tail = dummyHead;
        while (!pq.empty())
        {
            Node *min_ele = pq.top();
            pq.pop();
            tail->next = min_ele;
            tail = tail->next;
            if (min_ele->next != nullptr)
            {
                pq.push(min_ele->next);
            }
        }
        Node *realHead = dummyHead->next;
        delete dummyHead;
        return realHead;
    }
};
Node *createNodeList(vector<int> &);
int main()
{
    vector<int> arr1 = {1, 7, 3, 9};
    vector<int> arr2 = {9, 2, 5, 7, 0, 6};
    vector<int> arr3 = {4, 1, 7, 3, 0, 8, 3, 7, 4, 5};
    vector<Node *> lls;
    lls.push_back(createNodeList(arr1));
    lls.push_back(createNodeList(arr2));
    lls.push_back(createNodeList(arr3));
    Solution obj;
    Node *combined_ll = obj.combineAndSort(lls);
    while (combined_ll != nullptr)
    {
        cout << combined_ll->getVal() << ", ";
        Node *prev = combined_ll;
        combined_ll = combined_ll->next;
        delete prev;
    }
    cout << endl;
    return 0;
}

Node *createNodeList(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    Node *dummyHead = new Node(0);
    Node *tail = dummyHead;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *node = new Node(arr[i]);
        tail->next = node;
        tail = tail->next;
    }
    Node *realHead = dummyHead->next;
    delete dummyHead;
    return realHead;
}