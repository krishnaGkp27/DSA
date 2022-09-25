#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n >= 1)
        cout << 1;

    if (n >= 2)
        cout << 1 << " " << 2 << " " << 1;

    vector<int> arr = {1, 2, 1};

    for (int i = 3; i <= n; i++)
    {
        int terms = i + 1;
        vector<int> arr1(terms);
        for (int j = 0; j < terms; j++)
        {
            if (j == 0 || j == (terms - 1))
            {
                arr1[j] = 1;
                cout << arr1[j] << " ";
            }
            else
            {
                arr1[j] = arr[j - 1] + arr[j];
                cout << arr1[j] << " ";
            }
        }
        arr = arr1;
        cout << endl;
    }
    return 0;
}