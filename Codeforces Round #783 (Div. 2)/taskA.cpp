#include <iostream>

using namespace std;

int main()
{
    long long t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;

        if (n == 1 && m == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 1 && m == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if (m == 1 && n == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 1 || m == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n > m)
            swap(n, m);
        long long ans = n - 1 + n - 1 + 2 * (m - n);
        if ((m - n) % 2 == 1)
        {
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
