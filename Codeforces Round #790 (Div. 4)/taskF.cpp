#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> a;
map <int, int> cnt;
vector <pair <int, int>> help;

int main()
{
    int t, n, k;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        a.clear();
        cnt.clear();

        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);
            cnt[x]++;
        }

        int now = 0;
        int prev = -2e9;
        int ma = 0;
        int ans_l = -1;

        for (auto j : cnt)
        {
            if (prev == -2e9)
            {
                if (j.second >= k)
                {
                    now++;
                    prev = j.first;
                }
                else
                {
                    now = 0;
                    prev = -2e9;
                }
            }
            else
            {
                if (j.first == prev + 1 && j.second >= k)
                {
                    now++;
                    prev++;
                }
                else
                {
                    if (now > ma)
                    {
                        ans_l = prev;
                        ma = max(ma, now);
                    }

                    if (j.second >= k)
                    {
                        now = 1;
                        prev = j.first;
                    }
                    else
                    {
                        now = 0;
                        prev = -2e9;
                    }
                }
            }

        }
        if (now > ma)
        {
            ans_l = prev;
            ma = max(ma, now);
        }
        if (ma == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans_l - ma + 1 << ' ' << ans_l  << endl;
        }
    }
    return 0;
}
