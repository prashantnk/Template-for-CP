#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007LL
#define all(x) x.begin() , x.end()
#define ld long double
#define inf 1e15
void solve();
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1; //cin >> t;
	while (t--)
		solve();
	return 0;
}
void solve()
{
	ll n; cin >> n;
	ll arr[n];
	for (auto &x : arr)
	{
		cin >> x;
		if (x == 0) x = 2;
		else x = (x % 2);
	}
	ll dp[n][2][(n / 2) + 1];
	for (int i = 0; i < n; i++) for (int j = 0; j <= n / 2; j++) dp[i][0][j] = dp[i][1][j] = inf;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (arr[i] == 0) dp[i][0][1] = 0;
			else if (arr[i] == 1) dp[i][1][0] = 0;
			else dp[i][0][1] = dp[i][1][0] = 0;
			continue;
		}
		for (int j = 0; j <= n / 2 and j <= (i + 1); j++)
		{
			if (arr[i] == 2)
			{
				if (j > 0) dp[i][0][j] = min(dp[i - 1][0][j - 1] , dp[i - 1][1][j - 1] + 1);
				dp[i][1][j] = min(dp[i - 1][1][j] , dp[i - 1][0][j] + 1);
			}
			else
			{
				if (arr[i] == 0 and j > 0) dp[i][0][j] = min(dp[i - 1][0][j - 1] , dp[i - 1][1][j - 1] + 1) ;
				else if (arr[i] == 1) dp[i][1][j] = min(dp[i - 1][1][j] , dp[i - 1][0][j] + 1);
			}
		}
	}
	if (n > 1) cout << min(dp[n - 1][0][n / 2] , dp[n - 1][1][n / 2]);
	else cout << 0;

	cout << "\n";
	return ;
}