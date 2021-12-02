// Author : 3
// Date : 11/30/21
// Problem Name : Problem 1. Sleepy Cow Herding
// Content : USACO - USACO 2019 February Contest, Bronze
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

// For cows that are already consecutive to each other, they will have a move of
// 0 for both For minimum, if there are any patterns where only one move is
// needed, then the minimum will be 1, otherwise, the minimum is 2.
//
// The maximum is the largest gap between a,b or b,c.
void solve() {
  vi v(3);
  trav(e, v) { cin >> e; }
  sort(all(v));
  if (v[2] - v[1] == 1 && v[1] - v[0] == 1) {
    cout << 0 << nl;
    cout << 0 << nl;
  } else {
    int mn = INF;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i != j) {
          mn = min(mn, abs(v[i] - v[j]));
        }
      }
    }
    if (mn == 2) {
      cout << 1 << nl;
    } else {
      cout << 2 << nl;
    }
    cout << max((v[2] - v[1]), (v[1] - v[0])) - 1 << nl;
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("herding");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
