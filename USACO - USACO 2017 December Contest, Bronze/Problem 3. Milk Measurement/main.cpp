// Author : 3
// Date : 11/25/21
// Problem Name : Problem 3. Milk Measurement
// Content : USACO - USACO 2017 December Contest, Bronze
// Memory Limit : 256
// timeLimit : 4000
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pi> vpi;

#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define trav(a, x) for (auto &a : x)
#define nl '\n'
#define MOD 1e9 + 7
#define INF 1e9

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
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;

void setIO(string file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
  freopen((file + ".err").c_str(), "w", stderr);
}

void solve() {
  int ans = 0;
  unordered_map<string, int> m;
  m["Bessie"] = 7;
  m["Elsie"] = 7;
  m["Mildred"] = 7;
  vs wcow = {"Bessie", "Elsie", "Mildred"};
  vs ccow;
  int tmp;
  int n;
  cin >> n;
  vector<tuple<int, string, int>> v(n);
  trav(e, v) {
    cin >> get<0>(e);
    cin >> get<1>(e);
    cin >> get<2>(e);
  }
  sort(all(v));
  for (int i = 0; i < n; ++i) {
    m[get<1>(v[i])] += get<2>(v[i]);
    tmp = max({m["Bessie"], m["Elsie"], m["Mildred"]});
    ccow.clear();
    trav(e, m) {
      if (e.second == tmp) {
        ccow.push_back(e.first);
      }
    }
    sort(all(wcow));
    sort(all(ccow));
    if (wcow != ccow) {
      ans++;
    }
    wcow = ccow;
  }
  cout << ans;
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("measurement");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
