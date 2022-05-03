#include <iostream>

using namespace std;

int main()
{
    int t;
    string s, q;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> s >> q;
        bool f = false;
        for (int j = 0; j < q.length(); j++)
        {
            if (q[j] == 'a')
            {
                f = true;
                break;
            }
        }
        if (f)
        {
            if (q == "a")
            {
                cout << 1 << endl;
                continue;
            }
            cout << -1 << endl;
            continue;
        }
        long long ans = 1;
        for (int i = 0; i < s.length(); i++)
        {
            ans *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
