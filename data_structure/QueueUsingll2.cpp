#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{
    Node *head;
    Node *tail;
    int len;

public:
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->len = 0;
    }
    void pushFront(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        if (tail == NULL)
            tail = temp;
        len++;
    }
    void pushBack(int val)
    {
        Node *temp = new Node(val);
        if (tail != NULL)
            tail->next = temp;
        else
        {
            tail = temp;
            head = temp;
        }
        len++;
    }
    void popFront()
    {
        if (head != NULL)
        {
            head = head->next;
            len--;
        }
        if (head == NULL)
            tail = NULL;
    }
    int front()
    {
        if (head == NULL)
            return -1;
        else
            return head->val;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    int size()
    {
        return this->len;
    }
};
class iQueue
{
private:
    LinkedList list;

public:
    void push(int val)
    {
        list.pushBack(val);
    }
    void pop()
    {
        if (!list.isEmpty())
            list.popFront();
        else
            cout << "Queue underflow";
    }
    int front()
    {
        if (!list.isEmpty())
            return list.front();
        else
            cout << "Queue is empty";
        return -1;
    }
    bool isEmpty()
    {
        return list.isEmpty();
    }
    int size()
    {
        return list.size();
    }
};
int main()
{
    iQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    cout << q.size() << endl;

    q.pop();

    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    cout << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << q.front() << endl;
    cout << q.isEmpty() << endl;
    cout << q.size();
}