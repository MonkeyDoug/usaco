// Author : 3
// Date : 10/15/21
// Problem Name : Problem 3. Mowing the Field
// Content : USACO - USACO 2016 January Contest, Bronze
// Memory Limit : 256
// timeLimit : 4000
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define all(x) x.begin(), x.end()
#define sza(x) ((int)x.size())
#define trav(a,x) for (auto& a : x)
#define mn(n) *min_element(n.begin(),n.end())
#define mx(n) *max_element(n.begin().n.end())
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define forn(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define nl '\n'
#define MOD 1e9+7
#define INF 1e9

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


bool cmp(ll a, ll b) {
	return a > b;
}

vl ntv(ll X) {
	vl final;
	while (X) {
		final.pb(X%10); X/=10;
	}
	reverse(all(final)); return final;
}

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	#ifdef LOCAL
	freopen((s+".err").c_str(),"w",stderr);
	#endif
}

void solve(){
	int n;cin>>n;
	vector<pair<char,int>> v(n);
	forn(i,n){
		cin >> v[i].first;
		cin >> v[i].second;
	}
	tuple<int,int,int> pos = {0,0,0}; // x,y,time
	int time = 0;
	vector<tuple<int,int,int>> check;
	check.pb(make_tuple(0,0,0));
	for ( int i = 0 ; i < n ; i++ ) {
		if ( v[i].first == 'N' ) {
			forn(j,v[i].second){
				// get<1>(pos)++;
				// time++;
				check.pb(make_tuple(get<0>(pos),++get<1>(pos),++time));
			}
		} else if ( v[i].first == 'E' ) {
			forn(j,v[i].second){
				// get<0>(pos)++;
				// time++;
				check.pb(make_tuple(++get<0>(pos),get<1>(pos),++time));
			}
		} else if ( v[i].first == 'S' ) {
			forn(j,v[i].second){
				// get<1>(pos)--;
				// time++;
				check.pb(make_tuple(get<0>(pos),--get<1>(pos),++time));
			}
		} else {
			forn(j,v[i].second){
				// get<0>(pos)--;
				// time++;
				check.pb(make_tuple(--get<0>(pos),get<1>(pos),++time));
			}
		}
	}
	int ans = INF;
	for ( int i = 0 ; i < check.size() ; i++ ) {
		for ( int j = 0 ; j < check.size() ; j++ ) {
			auto cur1 = check[i];
			auto cur2 = check[j];
			if ( get<2>(cur1) != get<2>(cur2) ) {
				if ( ( get<0>(cur1) == get<0>(cur2) ) && ( get<1>(cur1) == get<1>(cur2) ) ){
					ans = min(ans,abs(get<2>(cur1) - get<2>(cur2)));
				}
			}
		}
	}
	if ( ans == INF ) {
		cout << -1;
	} else {
		cout << ans;
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("mowing");
	int T = 1;
	while ( T-->0 ) solve();
	return 0;
}
