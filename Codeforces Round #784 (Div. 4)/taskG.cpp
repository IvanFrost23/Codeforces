#include <iostream>

using namespace std;

int main()
{
    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;

        char matrix[55][55];

        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                cin >> matrix[j][k];
            }
        }

        for (int j = 0; j < 2 * n; j++)
        {
            for (int x = n; x >= 1; x--)
            {
                for (int y = 1; y <= m; y++)
                {
                    if (matrix[x][y] == '*')
                    {
                        if (x + 1 <= n && matrix[x + 1][y] == '.')
                        {
                            matrix[x + 1][y] = '*';
                            matrix[x][y] = '.';
                        }
                    }
                }
            }
        }
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= m; y++)
            {
                cout << matrix[x][y];
            }
            cout << endl;
        }
    }
    return 0;
}
