#include <iostream>

using namespace std;

int matrix[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m;

    cin >> t;

    for (int tt = 0; tt < t; tt++)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        long long ma = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = i;
                int y = j;
                long long sum = 0;
                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    sum += matrix[x][y];
                    x--;
                    y--;
                }
                x = i;
                y = j;
                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    sum += matrix[x][y];
                    x++;
                    y--;
                }
                x = i;
                y = j;
                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    sum += matrix[x][y];
                    x--;
                    y++;
                }
                x = i;
                y = j;
                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    sum += matrix[x][y];
                    x++;
                    y++;
                }
                ma = max(ma, sum - 3 * matrix[i][j]);
            }
        }
        cout << ma << endl;
    }
    return 0;
}
