#include <iostream>

using namespace std;

int main()
{
    int t, n;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> s;
        bool f = true;
        int cnt_b = 0;
        int cnt_r = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'W') {
                if (cnt_b == 0 && cnt_r == 0) continue;
                if (cnt_b != 0 && cnt_r != 0)
                {
                    cnt_b = 0;
                    cnt_r = 0;
                    continue;
                }
                f = false;
                break;
            }
            if (s[j] == 'B')
            {
                cnt_b++;
            }
            if (s[j] == 'R')
            {
                cnt_r++;
            }
        }

        if (cnt_b == 0 && cnt_r != 0) f = false;
        if (cnt_b != 0 && cnt_r == 0) f = false;
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
