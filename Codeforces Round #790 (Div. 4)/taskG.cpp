#include <iostream>
#include <vector>

using namespace std;

vector <int> a;
int dp[5000];
string s;
vector <vector <int>> graph;
int visited[5000];

void dfs(int vertex)
{
    if (s[vertex] == 'W')
    {
        dp[vertex] = 1;
    }
    else
    {
        dp[vertex] = -1;
    }
    visited[vertex] = 1;
    for (auto i : graph[vertex])
    {
        if (visited[i] == 0)
        {
            dfs(i);
            dp[vertex] += dp[i];
        }
    }
}

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        a.clear();
        graph.clear();

        cin >> n;

        for (int j = 0; j < n - 1; j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }


        cin >> s;

        graph.resize(n);

        for (int j = 0; j < n; j++)
        {
            dp[j] = 0;
            visited[j] = 0;
        }

        for (int j = 0; j < n - 1; j++)
        {
            graph[a[j] - 1].push_back(j + 1);
        }
        dfs(0);
        int ans = 0;
        for (int j = 0; j < n; j++)
            if (dp[j] == 0)
            {
                ans++;
            }
        cout << ans << endl;
    }
    return 0;
}
