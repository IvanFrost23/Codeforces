#include <iostream>
#include <map>

using namespace std;

map <string, int> ans;

int main()
{
    int num = 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            if (i == j) continue;
            string jj = "";
            jj+= i;
            jj += j;
            ans[jj] = num++;
        }
    }

    int t;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> s;
        cout << ans[s] << endl;
    }
    return 0;
}
