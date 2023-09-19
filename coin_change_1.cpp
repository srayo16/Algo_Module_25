#include <bits/stdc++.h>
using namespace std;

// unbounded-sub_set... {1,2,3,5} ekhane 5 koybar jog kore ana jabe? {2,3}, {5}, {1,1,1,1,1} etc. total 6 bar korar way ase.

int main()
{
    int n;
    cin >> n;

    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int s;
    cin >> s;

    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - w[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // dp[n][s] ? cout << "YES" << endl : cout << "NO" << endl;
    cout << dp[n][s] << endl;
    return 0;
}