#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Queue
{
private:
    unique_ptr<T[]> arr;
    int start, end, curr_size, max_size;

public:
    Queue() : max_size(8), start(-1), end(-1), curr_size(0), arr(make_unique<T[]>(this->max_size)) {}

    Queue(int max_size)
    {
        if (max_size <= 0)
        {
            throw invalid_argument("Queue capacity must be positive.");
        }
        else
        {
            this->max_size = max_size;
            this->start = -1;
            this->end = -1;
            this->curr_size = 0;
            arr = make_unique<T[]>(this->max_size);
            cout << "Queue created with max capacity: " << this->max_size << endl;
        }
    }

    // Copying is not allowed (unique_ptr can't be copied)
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    // Allow moving
    Queue(Queue &&) = default;
    Queue &operator=(Queue &&) = default;

    int size() const
    {
        return this->curr_size + 1;
    }
    bool isEmpty() const
    {
        return this->curr_size == 0;
    }
    bool isFull() const
    {
        return this->curr_size == max_size;
    }

    void push(T x)
    {
        if (isFull())
        {
            throw runtime_error("Error: Queue overflow! Cannot push more elements.");
        }
        else
        {
            if (this->end == -1)
            {
                this->start = 0;
                this->end = 0;
            }
            else
            {
                this->end = (this->end + 1) % this->max_size;
            }
            arr[this->end] = x;
            this->curr_size++;
        }
    }
    T pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Error: Queue underflow! Cannot pop more elements.");
        }
        else
        {
            T x = arr[this->start];
            if (this->curr_size == 1)
            {
                this->start = -1;
                this->end = -1;
            }
            else
            {
                this->start = (this->start + 1) % this->max_size;
            }
            this->curr_size--;
            return x;
        }
    }

    T peek() const
    {
        if (isEmpty())
        {
            throw runtime_error("Error: Queue is empty.");
        }
        else
        {
            return arr[this->start];
        }
    }
};
int main()
{
    Queue<int> q(3);
    q.push(10);
    q.push(20);
    q.push(30);
    while (!q.isEmpty())
    {
        cout << q.pop() << endl;
    }
    return 0;
}