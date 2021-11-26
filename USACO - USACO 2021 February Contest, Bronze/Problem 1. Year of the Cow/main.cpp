// Author : 3
// Date : 11/21/21
// Problem Name : Problem 1. Year of the Cow
// Content : USACO - USACO 2021 February Contest, Bronze
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

void setIO(string file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
  freopen((file + ".err").c_str(), "w", stderr);
}

void solve() {
  int n;
  cin >> n;
  vs v = {"Ox",   "Tiger",  "Rabbit",  "Dragon", "Snake", "Horse",
          "Goat", "Monkey", "Rooster", "Dog",    "Pig",   "Rat"};
  unordered_map<string, string> m;
  unordered_map<string, int> ans;
  ans["Bessie"] = 0;
  m["Bessie"] = "Ox";
  string c1, c2, animal, year, tmp;
  for (int i = 0; i < n; ++i) {
    cin >> c1;
    cin >> tmp;
    cin >> tmp;
    cin >> year;
    cin >> animal;
    cin >> tmp;
    cin >> tmp;
    cin >> c2;
    m[c1] = animal;
    int pos = find(all(v), m[c2]) - v.begin();
    if (year == "previous") {
      for (int j = 12 + pos - 1; j >= 0; --j) {
        if (v[j % 12] == animal) {
          ans[c1] = ans[c2] - (12 + pos - j);
          break;
        }
      }
    } else {
      for (int j = pos + 1; j < 24; ++j) {
        if (v[j % 12] == animal) {
          ans[c1] = ans[c2] + (j - pos);
          break;
        }
      }
    }
    if (c1 == "Elsie") {
      cout << abs(ans[c1]);
      break;
    }
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
