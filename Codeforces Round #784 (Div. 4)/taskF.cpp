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

        for (int j = 0; j < n; j++)
        {
            int x;

            cin >> x;

            a.push_back(x);
        }

        int ind1 = 0;
        int ind2 = a.size() - 1;
        long long sum1 = 0;
        long long sum2 = 0;
        long long ans = 0;

        while (ind1 <= ind2)
        {
            //cout << "informatiion: ind1 = " << ind1 << " ind2 = " << ind2 << " sum1 = " << sum1 << " sum2 = " << sum2 << endl;
            if (sum1 == sum2)
            {
                //cout << "indexis : " << ind1 << ' ' << ind2 << endl;
                ans = ind1 + a.size() - ind2 - 1;
                sum1 += a[ind1++];
                continue;
            }
            if (sum1 < sum2)
            {
                sum1 += a[ind1++];
                continue;
            }
            else
            {
                sum2 += a[ind2--];
            }
        }

        if (sum1 == sum2)
        {
            //cout << "indexis : " << ind1 << ' ' << ind2 << endl;
            ans = ind1 + a.size() - ind2 - 1;
            //sum1 += a[ind1++];
            //continue;
        }

        cout << ans << endl;
    }
    return 0;
}
