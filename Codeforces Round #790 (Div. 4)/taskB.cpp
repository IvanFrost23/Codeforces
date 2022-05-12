#include <iostream>
#include <vector>

using namespace std;

vector <long long> a;

int main()
{
    long long t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        a.clear();
        long long mi = 2e9;
        for (int j = 0; j < n; j++)
        {
            long long x;
            cin >> x;
            a.push_back(x);
            mi = min(mi, x);
        }
        long long ans = 0;
        for (int j = 0; j < n; j++)
            ans += a[j] - mi;
        cout << ans << endl;
    }
    return 0;
}
