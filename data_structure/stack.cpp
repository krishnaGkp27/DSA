#include <iostream>
using namespace std;
class iStack
{

private:
    int pointer;

public:
    int ar[2];

    iStack()
    {
        pointer = -1;
    }

    void push(int val)
    {
        if (pointer + 1 > 1)
            cout << "Stack overflow" << endl;
        else
        {
            pointer++;
            ar[pointer] = val;
        }
    }

    void pop()
    {
        if (pointer < 0)
            cout << "Stack underflow";
        else
            pointer--;
    }

    int top()
    {
        if (pointer != -1)
            return ar[pointer];
        else
            cout << "No element present";
        return -1;
    }

    bool empty()
    {
        if (pointer == -1)
            return true;
        else
            return false;
    }

    int size()
    {
        return pointer + 1;
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

    cout << st.top() << endl;
    cout << st.empty() << endl;
    cout << st.size();
}