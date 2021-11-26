// Author : 3
// Date : 11/22/21
// Problem Name : Problem 1. Don't Be Last!
// Content : USACO - USACO 2017 January Contest, Bronze
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
#define unq(x) x.erase(unique(x.begin(), x.end()), x.end())
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
  int n;
  cin >> n;
  unordered_map<string, int> m;
  string name;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> name;
    if (m.count(name) == 0) {
      cin >> m[name];
    } else {
      cin >> t;
      m[name] += t;
    }
  }
  int mn = INF;
  map<int, string> ans;
  set<int> check;
  for (auto e : m) {
    ans[e.second] = e.first;
    mn = min(mn, e.second);
    check.insert(e.second);
  }
  if (check.size() == 1 && n != 1) {
    cout << "Tie\n";
    return;
  }
  if (m.size() == 7) {
    cout << ans.upper_bound(mn)->second;
  } else {
    cout << ans.lower_bound(mn)->second;
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("notlast");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
