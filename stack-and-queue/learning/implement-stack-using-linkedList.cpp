#include <bits/stdc++.h>
using namespace std;
template <typename T>
class DoubleLinkedListStack
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
    DoublyLinkedListStack()
    {
        head = new Node();
        current = head;
    }
    ~DoublyLinkedListStack()
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
template <typename A>
class SingleLinkedListStack
{
private:
    struct Node
    {
        A val;
        Node *next;
        Node(A x) : val(x), next(nullptr) {}
    };
    Node *current;

public:
    SingleLinkedListStack()
    {
        current = nullptr;
    }
    ~SingleLinkedListStack()
    {
        while (!isEmpty())
        {
            pop();
        }
        delete current;
    }
    void push(A x)
    {
        Node *node = new Node(x);
        node->next = current;
        current = node;
    }

    A pop()
    {
        if (isEmpty())
            throw std::runtime_error("Stack underflow");
        Node *node = current;
        Node *temp = node;
        current = current->next;
        A val = temp->val;
        delete temp;
        return val;
    }

    A top()
    {
        if (isEmpty())
            throw std::runtime_error("Stack is empty");
        return current->val;
    }

    bool isEmpty()
    {
        return current = nullptr;
    }
};
int main()
{
    SingleLinkedListStack<int> obj;
    return 0;
}