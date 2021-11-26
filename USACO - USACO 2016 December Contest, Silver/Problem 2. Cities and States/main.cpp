// Author : 3
// Date : 11/22/21
// Problem Name : Problem 2. Cities and States
// Content : USACO - USACO 2016 December Contest, Silver
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

// Iterate over every pair of state codes {s1,s2};
// If the first two letter of any city from s1 matches s2
// And if the first two letters from any city city from s2 matches s1
// then we increment the answer
// Iterate ovre all of these matching cities

void solve() {
  int n;
  cin >> n;
  unordered_map<string, unordered_map<string, int>> m;
  string s1, s2;
  for (int i = 0; i < n; ++i) {
    cin >> s1;
    cin >> s2;
    // dbg(s1);
    // dbg(s2);
    m[s2][s1.substr(0, 2)]++;
    // dbg(m[s2][s1.substr(0, 2)]);
    // if (!m.count(s2)) { // Empty
    //   m[s2][s1.substr(0, 2)] = 0;
    //   dbg(m[s2][s1.substr(0, 2)]);
    // } else { // Exists
    //   m[s2][s1.substr(0, 2)]++;
    //   dbg(m[s2][s1.substr(0, 2)]);
    // }
  }
  int ans = 0;
  for (auto i = m.begin(); i != m.end(); ++i) {
    for (auto j = next(i, 1); j != m.end(); ++j) {
      if (i->second[j->first] > 0 && j->second[i->first] > 0) {
        // dbg(i->second[j->first]);
        // dbg(j->second[i->first]);
        ans += i->second[j->first] * j->second[i->first];
      }
    }
  }
  cout << ans;
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("citystate");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
