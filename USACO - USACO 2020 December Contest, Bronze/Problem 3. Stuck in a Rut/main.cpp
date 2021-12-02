// Author : 3
// Date : 11/25/21
// Problem Name : Problem 3. Stuck in a Rut
// Content : USACO - USACO 2020 December Contest, Bronze
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
#define f first
#define s second
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
  for (auto const &i : x)
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

bool cmp(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
  return (get<1>(a) < get<1>(b));
}

void solve() {
  int n;
  cin >> n;
  char dir;
  int x, y;
  vector<tuple<int, int, int>> north;
  vector<tuple<int, int, int>> east;
  for (int i = 0; i < n; ++i) {
    cin >> dir;
    cin >> x;
    cin >> y;
    if (dir == 'E') {
      east.push_back({x, y, i});
    } else {
      north.push_back({x, y, i});
    }
  }
  sort(all(north));
  sort(all(east), cmp);
  // Since we sorted the north cows by x coordinate and the east cows by the y coordinates, we can ensure that the distance from start to stopping for each cow will be the minimum
  trav(e, north) { dbg(get<0>(e), get<1>(e), get<2>(e)); }
  trav(e, east) { dbg(get<0>(e), get<1>(e), get<2>(e)); }
  vector<int> ans(n, 0);
  trav(ncow, north) {
    trav(ecow, east) {
      int nx = get<0>(ncow);
      int ny = get<1>(ncow);
      int ex = get<0>(ecow);
      int ey = get<1>(ecow);
      int dx = abs(nx - ex);
      int dy = abs(ny - ey);
      if (nx > ex && ey > ny) {
        // we only need to check the east cow because we break when the north
        // cow stops so every iteration, it is guraranteed that the north cow on
        // the current iteration has not been stopped yet.
        if (dy < dx && ans[get<2>(ecow)] == 0) {
          ans[get<2>(ecow)] = dx;
        } else if (dx < dy && ans[get<2>(ecow)] == 0) {
          ans[get<2>(ncow)] = dy;
          break;
        }
      }
    }
  }
  trav(e, ans) {
    if (e == 0) {
      cout << "Infinity";
    } else {
      cout << e;
    }
    cout << nl;
  }
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  setIO("test");
  int T = 1;
  while (T-- > 0)
    solve();
  return 0;
}
