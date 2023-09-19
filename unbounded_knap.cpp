#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int val[N], weight[N];
int dp[1005][1005];

int unBounded_knap(int n, int s)
{
    if (n <= 0 || s <= 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (weight[n - 1] <= s)
    {
        int op1 = val[n - 1] + unBounded_knap(n, s - weight[n - 1]);
        int op2 = unBounded_knap(n - 1, s);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = unBounded_knap(n - 1, s);
    }
}

int main()
{
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << unBounded_knap(n, w);

    return 0;
}