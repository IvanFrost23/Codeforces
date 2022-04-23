#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, x;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        vector <int> a;

        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);
        }
        bool f = true;
        for (int j = 0; j < n; j += 2)
        {
            if (a[j] % 2 != a[0] % 2)
            {
                f = false;
                break;
            }
        }
        for (int j = 1; j < n; j += 2)
        {
            if (a[j] % 2 != a[1] % 2)
            {
                f = false;
                break;
            }
        }
        if (f)
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
