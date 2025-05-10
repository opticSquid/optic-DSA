#include <bits/stdc++.h>
using namespace std;
template <typename T>
class LinkedListStack
{
private:
    class Node
    {
    public:
        Node *prev;
        T data;
        Node *next;

        Node() : prev(nullptr), next(nullptr)
        {
        }

        Node(T value)
        {
            prev = nullptr;
            data = value;
            next = nullptr;
        }
    };
    Node *head;
    Node *current;

public:
    LinkedListStack()
    {
        head = new Node();
        current = head;
    }
    ~LinkedListStack()
    {
        while (!isEmpty())
        {
            pop();
        }
        delete head;
    }

    void push(T x)
    {
        Node *node = new Node(x);
        node->prev = current;
        current->next = node;
        current = node;
    }

    T pop()
    {
        if (isEmpty())
            throw std::runtime_error("Stack underflow");
        Node *node = current;
        current = current->prev;
        T val = node->data;
        delete node;
        return val;
    }

    T top()
    {
        if (isEmpty())
            throw std::runtime_error("Stack is empty");
        return current->data;
    }

    bool isEmpty()
    {
        return current == head;
    }
};
int main()
{
    LinkedListStack<int> obj;
    return 0;
}