#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Stack
{
private:
    unique_ptr<T[]> arr;
    int size;
    int top;

public:
    Stack() : size(1000), top(-1), arr(make_unique<T[]>(this->size)) {}

    Stack(int size)
    {
        if (size <= 0)
        {
            throw invalid_argument("Stack capacity must be positive.");
        }
        else
        {
            this->top = -1;
            this->size = size;
            arr = make_unique<T[]>(this->size);
            cout << "Stack created with capacity: " << this->size << endl;
        }
    }

    // Copying is not allowed (unique_ptr can't be copied)
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    // Allow moving
    Stack(Stack &&) = default;
    Stack &operator=(Stack &&) = default;

    int current_size() const
    {
        return this->top + 1;
    }
    bool isEmpty() const
    {
        return top == -1;
    }
    bool isFull() const
    {
        return top + 1 == size;
    }

    void push(T x)
    {
        if (isFull())
        {
            throw runtime_error("Error: Stack overflow! Cannot push more elements.");
        }
        else
        {
            this->top++;
            this->arr[this->top] = x;
        }
    }
    T pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Error: Stack underflow! Cannot pop more elements.");
        }
        else
        {
            T x = arr[this->top];
            this->top--;
            return x;
        }
    }

    T peek() const
    {
        if (isEmpty())
        {
            throw runtime_error("Error: Stack is empty.");
        }
        else
        {
            return arr[this->top];
        }
    }
};
int main()
{
    Stack<int> s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    // to copy stack to another stack we need to do:
    // s1 = std::move(s);
    return 0;
}