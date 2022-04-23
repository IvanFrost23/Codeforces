#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    int n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        map <char, int> a;
        map <char, int> aa;
        map <string, int> b;
        vector <string> c;

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            a[s[0]]++;
            aa[s[1]]++;
            c.push_back(s);
            b[s]++;
        }

        long long ans = 0;

        for (int j = 0; j < n; j++)
        {
            a[c[j][0]]--;
            aa[c[j][1]]--;
            b[c[j]]--;
            ans += a[c[j][0]] + aa[c[j][1]];
            ans -= 2 * b[c[j]];
        }

        cout << ans << endl;
    }
    return 0;
}
