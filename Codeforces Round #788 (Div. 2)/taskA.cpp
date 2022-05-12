#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        a.clear();

        cin >> n;

        int mi = 0;

        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x < 0)
            {
                mi++;
            }
            a.push_back(x);
        }
        for (int j = 0; j < n; j++)
        {
            if (j < mi)
            {
                a[j] = -abs(a[j]);
            }
            else
            {
                a[j] = abs(a[j]);
            }
        }
        bool f = true;
        for (int j = 1; j < n; j++)
        {
            if (a[j] < a[j - 1])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
