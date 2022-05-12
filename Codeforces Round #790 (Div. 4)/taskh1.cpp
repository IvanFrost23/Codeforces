#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> a;
map <int, int> b;
map <int, int> pref;

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        b.clear();

        cin >> n;
        a.clear();
        pref.clear();
        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);
            b[x]++;
        }
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[k] <= a[j])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
