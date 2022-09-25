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

class iStack
{
    Node *head;
    int current_size;

public:
    iStack()
    {
        head = NULL;
        current_size = 0;
    }
    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        current_size++;
    }
    void pop()
    {
        if (head != NULL && head->next != NULL)
        {
            head = head->next;
            current_size--;
        }
        else
            cout << "stack underflow";
    }
    int top()
    {
        if (current_size > 0)
            return head->val;
        else
            cout << "no element present";
        return -1;
    }
    int size()
    {
        return current_size;
    }
    void display()
    {
        Node *start = head;
        while (start != NULL)
        {
            cout << start->val << " ";
            start = start->next;
        }
        cout << endl;
    }
};

int main()
{

    iStack st;
    st.push(10);
    st.display();
    st.push(23);
    st.display();
    st.push(54);
    st.display();
    cout << st.size() << endl;
    st.pop();
    cout << st.top();
    st.display();
    st.pop();
    st.pop();
};