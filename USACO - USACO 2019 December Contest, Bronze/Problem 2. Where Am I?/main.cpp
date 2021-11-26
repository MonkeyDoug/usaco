// Author : 3
// Date : 11/20/21
// Problem Name : Problem 2. Where Am I?
// Content : USACO - USACO 2019 December Contest, Bronze
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
#ifdef LOCAL
  freopen((file + ".err").c_str(), "w", stderr);
#endif
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int k = 1; k <= n; ++k) {
    bool check = true;
    for (int i = 0; i <= n - k; ++i) {
      string t1 = s.substr(i, k);
      for (int j = i + 1; j <= n - k; ++j) {
        string t2 = s.substr(j, k);
        if (t1 == t2) {
          check = false;
          break;
        }
      }
    }
    if (check) {
      cout << k;
      return;
    }
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("whereami");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
