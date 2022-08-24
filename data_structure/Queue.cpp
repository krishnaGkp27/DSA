#include <iostream>
using namespace std;

class iQueue
{
    const static int capacity = 5;
    int q[capacity];
    int back_pointer;
    int front_pointer;

public:
    iQueue()
    {
        back_pointer = -1;
        front_pointer = -1;
    }
    int front()
    {
        print();
        if (front_pointer == -1 || front_pointer > back_pointer)
        {
            cout << "No element present inside queue";
            return -1;
        }
        return q[front_pointer];
    }
    void pop()
    {
        print();
        if (front_pointer == -1 || front_pointer > back_pointer)
            cout << "Queue underflow";
        else
            front_pointer++;
    }
    void push(int val)
    {
        if (back_pointer + 1 >= capacity)
            cout << "Queue overflow";

        else if (back_pointer == -1)
        {

            front_pointer++;
            back_pointer++;
            q[back_pointer] = val;
        }
        else
        {
            back_pointer++;
            q[back_pointer] = val;
        }
        print();
    }
    void print()
    {
        cout << endl
             << "[ ";
        for (int i = front_pointer; i <= back_pointer && i > -1 && i < capacity; i++)
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
