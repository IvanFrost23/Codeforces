#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

int main()
{
    int t, n, k;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k >> s;

        a.clear();

        a.resize(n, 0);

        int sum = 0;

        for (int j = 0; j < n; j++)
        {
            if (sum == k)
            {
                break;
            }
            if (k % 2 == 0 && s[j] == '1')
            {
                continue;
            }
            if (k % 2 == 1 && s[j] == '0')
            {
                continue;
            }
            sum++;
            a[j] = 1;
        }
        a[n - 1] += k - sum;

        for (int j = 0; j < n; j++)
        {
            if ((k - a[j]) % 2 == 0 && s[j] == '0')
            {
                cout << '0';
            }
            if ((k - a[j]) % 2 == 0 && s[j] == '1')
            {
                cout << '1';
            }
            if ((k - a[j]) % 2 == 1 && s[j] == '0')
            {
                cout << '1';
            }
            if ((k - a[j]) % 2 == 1 && s[j] == '1')
            {
                cout << '0';
            }
        }
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
