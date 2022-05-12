#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;
vector <long long> pref;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, q;

    cin >> t;

    for (int tt = 0; tt < t; tt++)
    {
        cin >> n >> q;
        a.clear();
        pref.clear();
        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int j = n - 1; j >= 0; j--)
        {
            if (j == n - 1)
            {
                pref.push_back(a[j]);
            }
            else
            {
                pref.push_back(pref[pref.size() - 1] + a[j]);
            }
        }
        for (int j = 0; j < q; j++)
        {
            long long zn;
            cin >> zn;
            int left = -1;
            int right = pref.size();

            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (pref[middle] < zn)
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }

            if (right != pref.size() && pref[right] >= zn)
            {
                cout << right + 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
