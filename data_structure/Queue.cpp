#include <iostream>
using namespace std;

class iQueue
{
private:
    int q[5];
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
    void insert(int val)
    {
        if (front_pointer + 1 >= 5)
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
        for (int i = back_pointer; i <= front_pointer && i > -1 && i < 5; i++)
            cout << "\"" << q[i] << "\""
                 << " ";
        cout << " ]" << endl;
    }
};

int main()
{
    iQueue q;

    q.insert(10);
    q.insert(34);
    q.insert(65);
    q.insert(134);
    q.insert(16);
    q.insert(16);

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
