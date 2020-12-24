#define int short int
#pragma GCC optimize("Ofast")
memset(arr , 0 , sizeof(arr));
continue ;
break ; insert ; erase ;
s.order_of_key(x); // num strictly lesser
s.find_by_order(x); // index   erase function doesn't work on ordered multiset
///////*DSU*//////////
vector<ll>par, sz;
int root(ll a)
{
    while (a != par[a])
    {
        par[a] = par[par[a]];
        a = par[a];
    }
    return a;
}
void wt_union(int a, int b)
{
    int root_a = root(a);
    int root_b = root(b);
    if (sz[root_b] > sz[root_a])
    {
        sz[root_b] += sz[root_a];
        par[root_a] = par[root_b];
    }
    else
    {
        sz[root_a] += sz[root_b];
        par[root_b] = par[root_a];
    }
}
bool find(ll a, ll b)
{
    if (root(a) == root(b)) return 1;
    else return 0;
}
if (!find(a, b)) wt_union(a, b);
///////*dfs*//////////
vector<vector<ll>>adj;
vector<bool>used;
vector<ll>comp;
void dfs(ll v)
{
    used[v] = 1;
    comp.push_back(v);
    for (auto u : adj[v])
    {
        if (!used[u]) dfs(u);
    }
}
used.assign(n , 0);
/////////////////////////////////
cout.precision(20); cout << fixed; cout << log2l(n) << "\n";//have very high precision
/*x and y direction*/
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // more precisicely it is the knight moves;
///////////////////////////////////////////////////////
ll msb(ll n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n += 1;
    return (n >> 1);
}
////////////////////
string to_binary(ll n)
{
    string res;
    if (n == 0) res += '0';
    while (n)
    {
        res += (n % 2) + '0';
        n >>= 1;
    }
    return res;
}
/////////////////////
pair<ll, ll>fib(ll n)
{
    if (n == 0) return {0, 1};
    pair<ll , ll >p = fib(n / 2);
    ll c = p.first * (2LL * p.second - p.first) ;
    ll d = p.second * p.second + p.first * p.first;
    if (n & 1) return {d, c + d};
    else return {c, d};
}
/*totient function*/
ll phi(ll n)
{
    ll res = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            res -= (res) / i ;
        }
    }
    if (n != 1)
    {
        res -= res / n;
    }
    return res;
}
/*ncr with mod*/

int invmod(int x)
{
    return modular_exp(x, mod - 2);
}

int nCr(int n, int r)
{
    return (factorial[n] * invmod((factorial[r] * factorial[n - r]) % mod)) % mod;
}
factorial.resize(n + 1);
factorial[0] = 1;
for (int i = 1; i <= n; i++)
{
    factorial[i] = (factorial[i - 1] * i) % mod;
}
//////////////////////////////////////////////////////////////////////

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

check for perfect square.
ll is_perfect_square(ll n)
{
    ll tp = floor(sqrt(n));
    if (n == (tp * tp)) return tp;
    else return -1;
}
ll biexp(ll a, ll n)
{
    if (n == 0) return 1;
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 != 0) res *= a;
        a = a * a;
        n = n / 2;
    }
    return res;
}
ll modular_exp(ll a, ll n)
{
    if (n == 0) return 1;
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 != 0) res *= a;
        a = (a * a) % mod;
        n = n / 2;
        res = res % mod;
    }
    res = (res % mod);
    return res;
}

/** sieve implementation**/

ll N = 1299827; // first 100008 primes;
vector<ll>lp(N + 1, 0);
vector<ll>pr;
for (ll i = 2; i <= N; ++i)
{
    if (lp[i] == 0)
    {
        lp[i] = i;
        pr.push_back(i);
    }
    for (ll j = 0; j < pr.size() and i * pr[j] <= N ; ++j)
    {
        lp[i * pr[j]] = pr[j];
    }
}

bool isprime(ll n)
{
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

factors in sqrt(n);
ll N = 100000;
vector<vector<ll> >factors(N + 1);
for (ll j = 1; j <= N; ++j)
{
    for (ll x = 1; x * x <= j; ++x)
    {
        if (j % x == 0)
        {
            factors[j].push_back(x);
            if (j / x != x) factors[j].push_back(j / x);
        }
    }
}


vector<pair<ll, ll> >prime_factors(ll n)
{
    vector<pair<ll, ll> >res; ll ct = 0;
    if (!(n & 1))
    {
        while (!(n & 1))
        {
            ct++; n /= 2;
        }
        res.push_back({2, ct});
    }
    ct = 0;
    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            ct++; n /= i;
        }
        if (ct > 0) res.push_back({i, ct});
        ct = 0;
    }
    if (n != 1) res.push_back({n, 1});
    return res;
}

//calculating n_C_r();
ll ncr(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; ++i)
        res = (res * (n - k + i)) / i;

    return res;
}
ll dearrangement(ll n)
{
    if (n == 0) return 1;
    if (n == 1) return 0;
    ll tp = n * dearrangement(n - 1);
    if (n & 1) tp--;
    else tp++;
    return tp;
}

int interact(int i , int j)
{
    cout << "? " << i << " " << j << endl; cout.flush();
    int ret; cin >> ret; cout.flush();
    return ret;
}
int prefixFunction(string s)
{
    ll n = s.size();
    vector<int>pi(n , 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1] ; // checking property
        while (j > 0 and s[i] != s[j]) // s[i] = s[next element after pi[i-1] length]
        {
            j = pi[j - 1]; // checking for next greatest value to satisfy
        }
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    // returning max value
    return *max_element(all(pi));
}


// lis in nlogn
int Longest_increasing_subsequence(vector<int> v) {
    int n = v.size();
    vector<int> dp(n, INF);
    for (int i = 0; i < n; i++) *lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

// finding msb
int findMsb(ll n)
{
    ll msb = 0; /*cout << msb;*/
    for (int i = 0; i < 64; i++)
    {
        if ((n >> i) & 1) msb = i;
    }
    return msb;
}