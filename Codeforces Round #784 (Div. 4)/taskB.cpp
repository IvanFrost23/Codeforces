#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        map <int, int> a;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        bool f = false;
        for (auto j : a)
        {
            if (j.second >= 3)
            {
                cout << j.first << endl;
                f = true;
                break;
            }
        }
        if (!f)
        {
            cout << -1 << endl;
            continue;
        }
    }
    return 0;
}
