#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
private:
    class Node
    {
    private:
        int key;
        int value;

    public:
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
        int get_key() const
        {
            return this->key;
        }
        int get_value() const
        {
            return this->value;
        }
        void set_value(int v)
        {
            this->value = v;
        }
    };
    Node *head;
    Node *tail;
    int max_size;
    unordered_map<int, Node *> m;

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        delNode->prev = nullptr;
        delNode->next = nullptr;
    }

public:
    LRUCache(int capacity) : head(new Node(-1, -1)), tail(new Node(-1, -1)), max_size(capacity)
    {
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int res = resNode->get_value();
            deleteNode(resNode);
            addNode(resNode);
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *existingNode = m[key];
            deleteNode(existingNode);
            existingNode->set_value(value);
            addNode(existingNode);
        }
        else
        {
            if (m.size() == this->max_size)
            {
                Node *lruNode = tail->prev;
                m.erase(lruNode->get_key());
                deleteNode(lruNode);
                delete lruNode;
            }
            addNode(new Node(key, value));
            m[key] = head->next;
        }
    }
};
int main()
{
    LRUCache *cache;
    vector<string> command = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    vector<vector<int>>::iterator values_it = values.begin();
    for (string c : command)
    {
        const vector<int> &current_values = *values_it;
        if (c == "LRUCache")
        {
            cache = new LRUCache(current_values[0]);
        }
        else if (c == "put")
        {
            cache->put(current_values[0], current_values[1]);
        }
        else
        {
            cout << cache->get(current_values[0]) << endl;
        }
        values_it++;
    }
    return 0;
}