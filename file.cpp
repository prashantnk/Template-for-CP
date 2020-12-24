#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define mod 1000000007LL
#define all(x) x.begin() , x.end()
#define ld long double
const long long inf = 1e18 + 1LL;
void solve();
void ITO();
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); ITO();
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

void solve()
{
	cout << Longest_increasing_subsequence({2, 5, 3, 7, 11, 8, 10, 13, 6} , true);
	cout << "\n";
	return ;
}
void ITO()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf1.in", "w", stdout);
#endif
}
//                                                                  🙃