#include <iostream>
using namespace std;

class Heap
{
    int capacity;
    int heap_size;
    int *arr;
    static int const empty_val = -1;

    void swap(int *val1, int *val2)
    {
        int temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i)
    {
        return i * 2 + 1;
    }
    int rightChild(int i)
    {
        return i * 2 + 2;
    }

public:
    Heap(int capacity)
    {
        heap_size = 0;
        this->capacity = capacity;
        arr = new int[capacity];
    }

    void insert(int val)
    {
        if (heap_size < capacity)
            arr[heap_size++] = val;
        else
            cout << "Heap capacity is full, cannot insert new values.";

        int idx = heap_size - 1;

        while (parent(idx) >= 0 && arr[parent(idx)] > arr[idx])
        {
            swap(&arr[parent(idx)], &arr[idx]);
            idx = parent(idx);
        }
    }

    void heapify(int index)
    {
        int leftIdx = leftChild(index);
        int rightIdx = rightChild(index);

        if (leftIdx < heap_size && arr[leftIdx] < arr[index])
            swap(&arr[index], &arr[leftIdx]);

        if (rightIdx < heap_size && arr[rightIdx] < arr[index])
            swap(&arr[index], &arr[rightIdx]);

        if (leftIdx < heap_size)
            heapify(leftIdx);

        if (rightIdx < heap_size)
            heapify(rightIdx);
    }
    int top()
    {
        if (heap_size > 0)
            return arr[0];
        return empty_val;
    }
    void remove()
    {
        int val;
        if (heap_size == 0)
        {
            cout << "Heap is empty";
            return;
        }
        val = arr[0];
        heap_size--;
        arr[0] = arr[heap_size];
        arr[heap_size] = empty_val;
        heapify(0);
    }
    bool isPower2(int i)
    {
        return i == 0 || !(i & (i - 1));
    }
    void levelOrder()
    {

        for (int i = 0; i < heap_size; i++)
        {
            int n = i + 2;
            cout << arr[i] << " ";

            if (isPower2(n))
                cout << endl;
        }
    }
};
int main()
{
    Heap hp(50);
    // hp.insert(1);
    // hp.insert(4);
    // hp.insert(3);
    // hp.insert(10);
    // hp.insert(2);
    // hp.insert(12);
    // hp.remove();
    // hp.insert(5);
    // hp.insert(15);
    // hp.insert(9);
    hp.remove();
    cout << hp.top();
    hp.levelOrder();
}