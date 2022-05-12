#include <iostream>
#include <vector>

using namespace std;

vector <string> a;

int main()
{
    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        a.clear();

        cin >> n >> m;

        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            a.push_back(s);
        }
        int ans = 2e9;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j == k) continue;
                int now = 0;
                for (int r = 0; r < m; r++)
                {
                    now += abs(a[j][r] - a[k][r]);
                }
                ans = min(ans, now);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
