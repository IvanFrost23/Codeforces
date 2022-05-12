#include <iostream>
#include <vector>
#include <set>

using namespace std;

set <char> let;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, k;
    char l;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        let.clear();
        cin >> n >> s >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> l;
            let.insert(l);
        }
        int old_j = -1;

        int ans = -2e9;
        for (int j = 0; j < n; j++)
        {
            if (let.count(s[j]) != 0)
            {
                if (old_j == -1) {
                    old_j = j;
                    ans = max(ans, j);
                }
                else
                {
                    ans = max(ans, j - old_j);
                    old_j = j;
                }
            }
        }


        if (ans == -2e9)
        {
            if (old_j == -1)
            {
                ans = 0;
            }
            else
            {
                ans = old_j;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
