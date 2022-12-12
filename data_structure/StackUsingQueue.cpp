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
class iStack
{
public:
    iQueue q;
    void push(int val)
    {
        q.push(val);
    }
    void pop()
    {
        remove_last();
    }
    int top()
    {
        if (q.isEmpty())
        {
            cout << "Stack is empty";
            return -1;
        }
        int last_value = remove_last();
        q.push(last_value);
        return last_value;
    }
    bool empty()
    {
        return q.size();
    }
    int size()
    {
        return q.size();
    }
    int remove_last()
    {
        int last_element = -1;
        // if (q.size() == 1)
        // {
        //     last_element = q.front();
        //     q.pop();
        //     return last_element;
        // }

        iQueue q2;
        while (q.size() > 1)
        {
            q2.push(q.front());
            q.pop();
        }
        if (!q.isEmpty())
        {
            last_element = q.front();
            q.pop();
            cout << "isNotEmpty" << endl;
        }
        // while (!q2.isEmpty())
        // {
        //     q.push(q2.front());
        //     q2.pop();
        // }
        q = q2;
        return last_element;
    }
};
int main()
{
    iStack st;
    st.push(10);
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.push(20);
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.push(30);
    cout << st.top() << endl;
    cout << st.size() << endl;

    // cout << st.top() << endl;
    // cout << st.size() << endl;
    // cout << st.empty() << endl;
    // cout << st.size() << endl;

    // st.pop();

    // cout << st.top() << endl;
    // cout << st.empty() << endl;
    // cout << st.size() << endl;

    // st.pop();
    // st.pop();
    // st.pop();

    // cout << st.top() << endl;
    // cout << st.empty() << endl;
    // cout << st.size();
}