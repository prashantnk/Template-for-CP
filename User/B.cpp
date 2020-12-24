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
	ll n , u; cin >> n >> u;
	ll arr[n]; for (auto &x : arr) cin >> x;
	ld res = -1;
	for (int i = 0; i < n - 2; i++)
	{
		ll index = upper_bound(arr , arr + n , arr[i] + u) - arr - 1 ;
		if (index - i + 1 <= 2) continue;
		ld tp = (arr[index] - arr[i + 1]) * 1.0 / (arr[index] - arr[i]);
		res = max(res , tp);
	}
	if (res < 0) cout << -1;
	else {
		cout << fixed << setprecision(12);
		cout << res;
	}
	cout << "\n";
	return ;
}