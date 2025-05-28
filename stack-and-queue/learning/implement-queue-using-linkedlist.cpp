#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListQueue
{
private:
    struct Node
    {
        T val;
        Node *next;
        Node(T x) : val(x), next(nullptr) {}
    };

    Node *front, *back;
    int capacity;

public:
    LinkedListQueue() : back(nullptr), front(nullptr), capacity(0) {}
    ~LinkedListQueue()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    void push(T x)
    {
        Node *node = new Node(x);
        if (back == nullptr)
        {
            back = node;
            front = back;
        }
        else
        {
            back->next = node;
            back = node;
        }
        capacity++;
    }

    T pop()
    {
        if (front == nullptr)
        {
            throw runtime_error("Queue underflow");
        }
        else
        {
            Node *node = front;
            front = front->next;
            if (front == nullptr)
            {
                back = nullptr;
            }
            T val = node->val;
            delete node;
            capacity--;
            return val;
        }
    }

    T peek() const
    {
        if (front == nullptr)
        {
            throw runtime_error("Queue underflow");
        }
        else
        {
            return front->val;
        }
    }

    bool isEmpty() const
    {
        return capacity == 0;
    }

    int size() const
    {
        return capacity;
    }
};
int main()
{
    LinkedListQueue<int> obj;
    return 0;
}