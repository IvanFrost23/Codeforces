#include <iostream>

using namespace std;

int main()
{
    int t, n, r, b;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> r >> b;

        string ans = "";

        for (int j = 1; j <= n; j++)
        {
            int need = r / j;

            if (r % j != 0)
            {
                need++;
            }

            need--;

            if (b < need)
            {
                continue;
            }

            while (r != 0)
            {
                int ind = 0;
                while (ind < j && r > 0)
                {
                    ind++;
                    r--;
                    ans += "R";
                }

                if (b > 0)
                {
                    ans += "B";
                    b--;
                }
            }

            if (b != 0)
            {
                string ans2 = "";
                for (int j = 0; j < ans.length(); j++)
                {
                    if (b <= 0)
                    {
                        ans2 += ans[j];
                        continue;
                    }
                    if (ans[j] == 'B')
                    {
                        ans2 += ans[j];
                    }
                    else
                    {
                        if ((j == 0) || ans2[ans2.size() - 1] == 'R' && ans[j] == 'R')
                        {
                            ans2 += "B";
                            b--;
                        }
                        ans2 += ans[j];
                    }
                }
                ans = ans2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
