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
        {
            tail->next = temp;
            tail = tail->next;
        }
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

class iStack
{
    LinkedList list;

public:
    void push(int val)
    {
        list.pushFront(val);
    }
    void pop()
    {
        if (!list.isEmpty())
            list.popFront();
        else
            cout << "Stack Empty" << endl;
    }
    int top()
    {
        if (!list.isEmpty())
            return list.front();
        else
            cout << "Stack Empty" << endl;
        return -1;
    }
    bool empty()
    {
        return list.isEmpty();
    }
    int size()
    {
        return list.size();
    }
};
class iQueue
{
public:
    iStack st;
    bool isPush;
    iQueue()
    {
        isPush = true;
    }
    void reverse()
    {
        iStack st_temp;
        while (!st.empty())
        {
            st_temp.push(st.top());
            st.pop();
        }
        st = st_temp;
    }
    void push(int val)
    {
        if (isPush)
            st.push(val);
        else
        {
            reverse();
            st.push(val);
            isPush = true;
        }
    }
    void pop()
    {
        if (!isPush)
            st.pop();
        else
        {
            reverse();
            st.pop();
            isPush = false;
        }
    }
    bool isEmpty()
    {
        return st.size() == 0;
    }
    int size()
    {
        return st.size();
    }
    int front()
    {
        if (isPush)
        {
            reverse();
            isPush = false;
        }
        return st.top();
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

    q.push(16);
    q.push(27);
    q.push(33);
    q.pop();
    q.pop();
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
