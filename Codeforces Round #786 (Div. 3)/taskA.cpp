#include <iostream>

using namespace std;

int main()
{
    long long t, x, y;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        if (y % x != 0)
        {
            cout << 0 << ' ' << 0 << endl;
            continue;
        }
        long long num = y / x;
        bool f = false;
        for (long long j = 1; j <= num; j++)
        {
            long long ans = 1;
            int cnt = 0;
            while (ans < num)
            {
                if (j == 1 && cnt != 0) break;
                cnt++;
                ans *= j;
            }
            if (ans == num)
            {
                cout << max(1, cnt) << ' ' << j << endl;
                f = true;
                break;
            }
        }
        if (!f)
        {
            cout << 0 << ' ' << 0;
        }
    }
    return 0;
}
