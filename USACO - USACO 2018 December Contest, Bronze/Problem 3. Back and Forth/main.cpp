// Author : 3
// Date : 11/17/21
// Problem Name : Problem 3. Back and Forth
// Content : USACO - USACO 2018 December Contest, Bronze
// Memory Limit : 256
// timeLimit : 4000
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define trav(a, x) for (auto &a : x)
#define mn(n) *min_element(n.begin(), n.end())
#define mx(n) *max_element(n.begin(), n.end())
#define unq(x) x.erase(unique(x.begin(), x.end()), x.end())
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mt make_tuple
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define rev(i, n) for (ll i = n - 1; i <= 0; --i)
#define loop(i, a, b) for (ll i = a; i < b; ++i)
#define nl '\n'
#define MOD 1e9 + 7
#define INF 1e9

template <class A> void read(vector<A> &v);
template <class A, size_t S> void read(array<A, S> &a);
template <class T> void read(T &x) { cin >> x; }
void read(double &d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double &d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T> void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A> void read(vector<A> &x) { trav(a, x) read(a); }
template <class A, size_t S> void read(array<A, S> &x) { trav(a, x) read(a); }

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifdef DEBUG
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

vl ntv(ll X) {
  vl final;
  while (X) {
    final.pb(X % 10);
    X /= 10;
  }
  reverse(all(final));
  return final;
}

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

void setIO(string file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
#ifdef LOCAL
  freopen((file + ".err").c_str(), "w", stderr);
#endif
}

/*
Solution
Simulate all transfers recursively ( Complexity 10*11^4 )
We can exchange the buckets at barn 1 ( v1/x.second ) and barn 2 ( v2/y.second )
through each iteration of the simulation For example on monday, barn 1 and barn
2 both have 10 bucket. On tuesday, we remove a bucket from barn 1 and add that
bucket to barn 2. Now we pass the newly updated buckets, the vector of 11
elements to barn 1 and the vector of 9 elements to barn 2. We remove the amount
of milk in the choosen bucket from the total amount of milk in barn 1 and add
the amount of milk in the choosen bucket to the total amount of milk in barn 2.
We do this recursion for all buckets in barn 1.
We also keep track of the milk at each barn ( x.first, y.first ) .
When the day reachs friday ( day == 4 ) then can add the milk at barn 1 to the
set of answers The number of elements in the set of elements is how many
readings we can get
*/

set<int> ans;

void dfs(int day, pair<int, vi> x, pair<int, vi> y) {
  if (day == 4) {
    ans.insert(x.f);
    return;
  } else {
    forn(i, sz(x.s)) {
      int bucket = x.s[i];
      vi t1 = x.s;
      t1.erase(t1.begin() + i);
      vi t2 = y.s;
      t2.pb(bucket);
      dfs(day + 1, {y.f + bucket, t2}, {x.f - bucket, t1});
    }
  }
}

void solve() {
  vi v1, v2;
  int t;
  forn(i, 10) {
    read(t);
    v1.pb(t);
  }
  forn(i, 10) {
    read(t);
    v2.pb(t);
  }
  dfs(0, {1000, v1}, {1000, v2});
  cout << ans.size();
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("backforth");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
