#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;
vector <pair <int, int>> b;

int main()
{
    int n, answer = 2e9;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        a.push_back(x);
        b.push_back({x, i});
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        int val_i = a[i];
        int sosed1, sosed2;
        if (i - 1 >= 0)
        {
            sosed1 = a[i - 1];
        }

        if (i + 1 < n)
        {
            sosed2 = a[i + 1];
        }

        int ans = val_i / 2 + val_i % 2;

        a[i] = 0;

        //if (a[i] == 0)
        {
            int mimi = 2e9;
            if (i - 1 >= 0)
            {
                a[i - 1] -= ans;
                mimi = min(mimi, a[i - 1]);
            }
            if (i + 1 < n)
            {
                a[i + 1] -= ans;
                mimi = min(mimi, a[i + 1]);
            }
            if (i - 1 >= 0 && a[i - 1] <= 0)
            {
                //cout << i << ' ' << ans << endl;
                answer = min(answer, ans);
                a[i] = val_i;
                if (i - 1 >= 0)
                {
                    a[i - 1] = sosed1;
                }
                if (i + 1 < n)
                {
                    a[i + 1] = sosed2;
                }
                continue;
            }
            if (i + 1 < n && a[i + 1] <= 0)
            {
                //cout << i << ' ' << ans << endl;
                answer = min(answer, ans);
                a[i] = val_i;
                if (i - 1 >= 0)
                {
                    a[i - 1] = sosed1;
                }
                if (i + 1 < n)
                {
                    a[i + 1] = sosed2;
                }
                continue;
            }
            //cout << mimi << endl;
            for (int j = 0; j < n; j++)
            {
                if (abs(b[j].second - i) >= 2)
                {
                    mimi = min(mimi, b[j].first);
                    break;
                }
            }
            //cout << i << ' ' << mimi << ' ' << mimi / 2 + mimi % 2 + ans << endl;
            answer = min(answer, mimi / 2 + mimi % 2 + ans);
            a[i] = val_i;
            if (i - 1 >= 0)
            {
                a[i - 1] = sosed1;
            }
            if (i + 1 < n)
            {
                a[i + 1] = sosed2;
            }
            continue;
        }


        a[i] = val_i;
        if (i - 1 >= 0)
        {
            a[i - 1] = sosed1;
        }
        if (i + 1 < n)
        {
            a[i + 1] = sosed2;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] % 2 == 1 && a[i + 1] % 2 == 1)
        {
            answer = min(answer, (a[i - 1] + a[i + 1]) / 2 + (a[i - 1] + a[i + 1]) % 2);
        }
    }

    for (int i = 1; i < n; i++)
    {
        int min_value = min(a[i - 1], a[i]);
        int max_value = max(a[i - 1], a[i]);
        if (max_value >= 2 * min_value)
        {
            answer = min(answer, max_value / 2 + max_value % 2);
        }
        else
        {
            int anss = (max_value + min_value) / 3;
            if ((max_value + min_value) % 3 != 0)
            {
                anss++;
            }
            answer = min(answer, anss);
            //cout << max_value << ' ' << min_value << ' ' << i << endl;
            /*int cnt = 0;
            cnt += 2 * (min_value / 3);
            max_value -= 3 * (min_value / 3);
            min_value = min_value % 3;
            if (min_value == 2)
            {
                max_value -= 1;
                cnt++;
                min_value = 0;
            } else {
                if (min_value == 1)
                {
                    max_value -= 2;
                    min_value -= 1;
                    cnt++;
                }
            }
            cnt += max(0, max_value) / 2 + max(0, max_value) % 2;
            answer = min(answer, cnt);*/
        }

    }

    cout << answer << endl;
    return 0;
}
