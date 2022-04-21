#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;

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
            long long x;
            cin >> x;

            a.push_back(x);
        }
        sort(a.begin(), a.end());

        long long sum = n + 2 * a[a.size() - 1];

        for (int j = n - 2; j >= 1; j--)
        {
            sum += a[j];
        }

        if (sum <= m)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }
    return 0;
}
