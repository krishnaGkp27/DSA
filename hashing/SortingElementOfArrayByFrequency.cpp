#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

#define endl '\n'
using namespace std;

int main()
{
    // code
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<int, set<int>> mp;
        unordered_map<int, int> ump;

        while (n--)
        {
            int val;
            cin >> val;
            ump[val]++;
        }

        for (pair<int, int> x : ump)
            mp[x.second].insert(x.first);

        for (auto itr = mp.rbegin(); itr != mp.rend(); itr++)
        {
            int frequency = itr->first;
            set<int> values = itr->second;

            for (int element : values)
                for (int i = 0; i < frequency; i++)
                    cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}