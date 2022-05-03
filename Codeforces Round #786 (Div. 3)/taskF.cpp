#include <iostream>

using namespace std;

char matrix[1200][1200];
int a[1440000];
int tree[7440000];

void building(int vertex, int vl, int vr)
{
    if (vl == vr)
    {
        tree[vertex] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    building(vertex * 2, vl, vm);
    building(vertex * 2 + 1, vm + 1, vr);
    tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
}

int get_sum(int v, int vl, int vr, int l, int r)
{
    if (l <= vl && vr <= r)
    {
        return tree[v];
    }
    if (l > vr || r < vl)
    {
        return 0;
    }
    int vm = (vl + vr) / 2;
    return get_sum(2 * v, vl, vm, l, r) + get_sum(2 * v + 1, vm + 1, vr, l, r);
}

void update(int v, int vl, int vr, int pos, int val)
{
    if (vl == vr)
    {
        tree[v] = val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
    {
        update(v * 2, vl, vm, pos, val);
    }
    else
    {
        update(v * 2 + 1, vm + 1, vr, pos, val);
    }
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

int main()
{
    int n, m, q, now = 0;

    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];

            if (matrix[i][j] == '*')
            {
                now++;
            }
        }
    }
    int indexx = 0;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '*')
            {
                a[indexx++] = 1;
            }
            else
            {
                a[indexx++] = 0;
            }
        }
    }

    building(1, 0, n * m - 1);

    /*for (int i = 0; i < n * m; i++)
    {
        cout << tree[i] << ' ';
    }
    cout << endl;*/

    for (int i = 0; i < q; i++)
    {
        int x, y;

        cin >> x >> y;

        x--;
        y--;

        if (matrix[x][y] == '*')
        {
            //cout << "Zdes" << " " << y * n + x << endl;
            now--;
            a[y * n + x] = 0;
            update(1, 0, n * m - 1, y * n + x, 0);
            matrix[x][y] = '.';
        }
        else
        {
            now++;
            a[y * n + x] = 1;
            update(1, 0, n * m - 1, y * n + x, 1);
            matrix[x][y] = '*';
        }

    /*for (int ii = 0; ii < n * m; ii++)
    {
        cout << tree[ii] << ' ';
    }
    cout << endl;
*/
        int now_index = 0;
        int goodStars = 0;
        /*for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (now_index < now)
                {
                    if (matrix[k][j] == '*')
                    {
                        goodStars++;
                    }
                }
                now_index++;
            }
        }*/
        cout << now - get_sum(1, 0, n * m - 1, 0, now - 1) << endl;
    }
    return 0;
}
