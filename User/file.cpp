#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007
#define all(x) x.begin() , x.end()
#define ld long double
const long long inf = 1e18 + 1LL;
void solve();
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
void solve()
{
	int n; cin >> n;
	cout << (ll)log2(n) + 1;
	cout << "\n";
	return ;
}
//                                                                  🙂