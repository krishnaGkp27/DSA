#include <iostream>
using namespace std;

class iQueue
{
    const static int capacity = 5;
    int q[capacity];
    int front_pointer;
    int back_pointer;

public:
    iQueue()
    {
        front_pointer = -1;
        back_pointer = -1;
    }
    int front()
    {
        print();
        if (back_pointer == -1 || back_pointer > front_pointer)
        {
            cout << "No element present inside queue";
            return -1;
        }
        return q[back_pointer];
    }
    int pop()
    {
        print();
        if (back_pointer == -1 || back_pointer > front_pointer)
        {
            cout << "Queue underflow";
            return -1;
        }
        else
            return q[back_pointer++];
    }
    void push(int val)
    {
        if (front_pointer + 1 >= capacity)
            cout << "Queue overflow";

        else if (front_pointer == -1)
        {

            back_pointer++;
            front_pointer++;
            q[front_pointer] = val;
        }
        else
            q[++front_pointer] = val;

        print();
    }
    void print()
    {
        cout << endl
             << "[ ";
        for (int i = back_pointer; i <= front_pointer && i > -1 && i < capacity; i++)
            cout << "\"" << q[i] << "\""
                 << " ";
        cout << " ]" << endl;
    }
};

int main()
{
    iQueue q;

    q.push(10);
    q.push(34);
    q.push(65);
    q.push(134);
    q.push(16);
    q.push(16);

    cout << endl
         << q.front() << endl;

    q.pop();
    q.pop();
    cout << endl
         << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}
