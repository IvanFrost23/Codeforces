#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <long long> a;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        a.push_back(x);
    }

    long long ans = 2e18;

    for (int i = 0; i < n; i++)
    {
        long long sum1 = 0, sum2 = 0;
        long long old = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            long long coef = old / a[j];
            coef++;
            sum2 += coef;
            old = coef * a[j];
        }

        old = 0;
        for (int j = i + 1; j < n; j++)
        {
            long long coef = old / a[j];
            coef++;
            sum2 += coef;
            old = coef * a[j];
            //cout << "a[j] = " << a[j] << " and coeff " << coef << endl;
        }
        //cout << "zero in i:" << i << " " << sum1 << ' ' << sum2 << endl;
        ans = min(ans, sum1 + sum2);
    }
    cout << ans;
    return 0;
}
