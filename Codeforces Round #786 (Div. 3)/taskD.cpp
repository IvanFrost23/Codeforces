#include <iostream>
#include <vector>

using namespace std;

vector <int> a;
vector <int> ans;

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        a.clear();

        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);
        }
        ans.clear();
        if (n % 2 == 0)
        {
            for (int j = 0; j < n; j += 2)
            {
                ans.push_back(min(a[j], a[j + 1]));
                ans.push_back(max(a[j], a[j + 1]));
            }
        }
        else
        {
            ans.push_back(a[0]);
            for (int j = 1; j < n; j += 2)
            {
                ans.push_back(min(a[j], a[j + 1]));
                ans.push_back(max(a[j], a[j + 1]));
            }
        }
        bool f = true;
        for (int j = 1; j < n; j++)
        {
            if (ans[j] < ans[j - 1])
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
