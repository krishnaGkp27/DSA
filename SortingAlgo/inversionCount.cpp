#include <iostream>
using namespace std;
typedef long long ll;

int temp[2000000];

ll merge(int arr[], int low, int mid, int high)
{
    int size = high - low + 1;
    // int temp[size];
    int l = low;
    int r = mid + 1;
    int tempIdx = 0;
    ll inversionCount = 0;
    while (l <= mid && r <= high)
    {
        if (arr[l] <= arr[r])
            temp[tempIdx++] = arr[l++];
        else
        {
            inversionCount += (mid - l + 1);
            temp[tempIdx++] = arr[r++];
        }
    }
    while (l <= mid)
        temp[tempIdx++] = arr[l++];
    while (r <= high)
        temp[tempIdx++] = arr[r++];

    for (int i = 0; i < size; i++)
        arr[i + low] = temp[i];

    return inversionCount;
}
ll mergeSort(int arr[], int low, int high)
{
    ll sum = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        sum += mergeSort(arr, low, mid);
        sum += mergeSort(arr, mid + 1, high);
        sum += merge(arr, low, mid, high);
    }
    return sum;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << mergeSort(arr, 0, n - 1) << '\n';
    }
}