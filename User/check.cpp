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
const int N = 1e6 + 1;
const int INF = 1e9 + 7;
const int inf = 1e18;

vector <int> adj[N];
int vis[N];
int A[N];
int ct[N];
vector <int> ans;

void dfs(int node , int par)
{
    vis[node] = 1;
    ct[node] = 0;
    for (auto it : adj[node])
    {
        if ( !vis[it] && it != par) {
            if (A[it]) ct[node]++;
            dfs(it, node);
        }
    }
    if (ct[node] == adj[node].size() - 1 && A[node]) {ans.pb(node);}
}

int32_t main()
{
    string s;
    cin >> s;



    for (int i = 0; i + 1 < s.size(); i++)
    {

        if (s[i] != s[i + 1]) continue;

        else
        {
            //cout<<"work"<<endl;
            if (i + 2 < s.size())
            {
                if (s[i + 1] + 1 != s[i + 2])
                {
                    s[i + 1] = s[i + 1] + 1;
                    if (s[i + 1] > 'z') s[i + 1] = 'a' + s[i + 1] - 'z' - 1;
                }
                else
                {
                    s[i + 1] = s[i + 1] + 2;
                    if (s[i + 1] > 'z') s[i + 1] = 'a' + s[i + 1] - 'z' - 1;

                }
            }
            else
            {
                if (s[i] == 'z') s[i + 1] = 'a';
                else s[i + 1] = s[i + 1] + 1;
            }
        }

    }


    cout << s << endl;




}

