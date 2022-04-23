#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> a;

int main()
{
    int t, n, k;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        map <int, int> b;

        cin >> n >> k;

        a.clear();

        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);

            for (int j = 0; j <= 30; j++)
            {
                b[j] += 1 - x % 2;
                x /= 2;
            }
        }
        long long ans = 0;
        for (int j = 30; j >= 0; j--)
        {
            if (b[j] <= k)
            {
                k -= b[j];
                ans += (1 << j);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
