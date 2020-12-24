#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define clr(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
const int N = 1e5 + 1;
const int INF = 1e9 + 7;
const int inf = 1e18;

vector <pair<int, int>> adj[100];
vector <vector<int>> d(50, vector <int> (50, INF));
vector <vector<int>> p(50, vector <int> (50, INF));
int n;

void fw()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] < INF && d[k][j] < INF)
				{
					if (d[i][k] + d[k][j] < d[i][j]) {d[i][j] = d[i][k] + d[k][j];  p[i][j] = k;}
				}
			}
		}
	}
}

int32_t main()
{
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		d[b][a] = w;
		d[a][b] = w;
	}
	for (int i = 1; i <= n; i++) {d[i][i] = 0;}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{p[i][j] = j;}
	}
	fw();
	vector <int> res;
	int i = 1 , j = n;
	while (i != j)
	{
		res.pb(i);
		i = p[i][j];
	}
	res.pb(j); /*reverse(all(res));*/
	for (auto x : res) {cout << x << " ";}
}
/* 4 4
   1 2 2
   1 3 3
   2 3 4
   2 4 5 */