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

int main()
{
    iStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    cout << st.empty() << endl;
    cout << st.size() << endl;

    st.pop();

    cout << st.top() << endl;
    cout << st.empty() << endl;
    cout << st.size() << endl;

    st.pop();
    st.pop();
    st.pop();

    cout << st.top() << endl;
    cout << st.empty() << endl;
    cout << st.size();
}