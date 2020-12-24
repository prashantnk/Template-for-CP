#define int short int
#pragma GCC optimize("Ofast")
memset(arr , 0 , sizeof(arr));
continue ;
break ; insert ; erase ;
s.order_of_key(x); // num strictly lesser
s.find_by_order(x); // index   erase function doesn't work on ordered multiset
///////*Fenwick*//////
const long N = (1e6) + 1;
int32_t BIT[N] = {};
void update(int i , int delta)
{
    while (i < N)
    {
        BIT[i] += delta;
        i += (i & (-i));
    }
}
int sum(int i , int j = 0)
{
    int s1 = 0;
    while (i > 0)
    {
        s1 += BIT[i];
        i -= (i & (-i));
    }
    --j;
    int s2 = 0;
    while (j > 0)
    {
        s2 += BIT[j];
        j -= (j & (-j));
    }
    return s1 - s2;
}
// LOWER BOUND IN BIT with binary lifting
int find(int k)
{
    // processing each bit
    int sum = 0 , curr = 0;
    for (int i = log2(N) ; i >= 0 ; --i)
    {
        curr += (1LL << i);
        if (curr < N and BIT[curr] + sum < k) {
            sum += BIT[curr];
        }
        else curr -= (1LL << i);
    }
    return curr + 1;
}
///////*DSU*//////////
vector<int>par, sz;
int root(int a)
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
bool find(int a, int b)
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

auto divisors = [&](int x)
{
    // giving sorted list of divisors
    map<int, int> m;
    while (x != 1)
    {
        m[lp[x]]++;
        x /= lp[x];
    }
    vector<int>divs ;
    divs.push_back(1);
    for (auto p : m)
    {
        int sz = divs.size();
        for (int i = 0 ; i < (sz * p.second) ; ++i )
        {
            divs.push_back(divs[i] * p.first);
        }
    }
    sort(all(divs));
    return divs;
};


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


// lis in nlogn this produces only length of lis
int Longest_increasing_subsequence(vector<int> v) {
    int n = v.size();
    vector<int> dp(n, inf);
    for (int i = 0; i < n; i++) *lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}
int Longest_increasing_subsequence(vector<int> &v , bool ok = 0) {
    int n = v.size();
    vector<int> dp(n, inf);
    vector<int> index(n, -1);
    vector<int> par(n , -1);
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), v[i]) ;
        int ind = it - dp.begin();
        if (ind > 0) par[i] = index[ind - 1];
        *it = v[i];
        index[ind] = i;
    }
    int x =  lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
    int res = x;
    if (ok)
    {
        x--; x = index[x];
        cout << v[x] << " ";
        while (par[x] != -1) { x = par[x]; cout << v[x] << " "; }
    }
    return res;
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

// diophantine implementation
int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    int x1, y1;
    int d = extended_gcd(b , a % b , x1 , y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}
bool solution(int a, int b, int c, int &x , int &y , int g)
{
    if (c % g == 0) {
        x = x * (c / g);
        y = y * (c / g);
        if (a < 0) x = -x;
        if (b < 0) y = -y;
        return true;
    }
    else return false;
}
void diophantine() {
    /** let equation be ax+by=c;**/
    int a, b, c; cin >> a >> b >> c; ///taken input as ax+by+c=0;
    c = -c; ///converting to initial equation.
    /// let x,y be the solution of the equation;
    int x, y, g;
    g = extended_gcd(llabs(a), llabs(b), x, y);
    if (a == 0 and b == 0) {
        if (c == 0) cout << "0 0";
        else cout << "-1";
    }
    else {
        if (solution(a, b, c, x, y, g)) cout << x << " " << y;
        else cout << -1;
    }
}

int getrandom(int l)
{
    srand(time(NULL));
    int x = (abs(rand())) % l;
    return x;
}
