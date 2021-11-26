// Author : 3
// Date : 11/11/21
// Problem Name : Problem 3. Guess the Animal
// Content : USACO - USACO 2019 January Contest, Bronze
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
#define sz(x) ((int)x.size())
#define trav(a,x) for (auto& a : x)
#define mn(n) *min_element(n.begin(),n.end())
#define mx(n) *max_element(n.begin(),n.end())
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mt make_tuple
#define forn(i,n) for(ll i=0;i<n;++i)
#define rev(i,n) for(ll i=n-1;i<=0;--i)
#define loop(i,a,b) for(ll i=a;i<b;++i)
#define nl '\n'
#define MOD 1e9+7
#define INF 1e9

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vector<A>& x) {
	trav(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	trav(a, x)
		read(a);
}

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
	// The largest number of common characteristics between two animals + 1 is the answer
	int n; read(n);
	vector<vs> v;
	forn(i,n){
		string _;read(_);
		int k; read(k);
		vs tmp(k);
		trav(e,tmp) read(e);
		v.pb(tmp);
	}
	dbg(v);
	// Check number of dupes
	int ans = 0;
	for ( int i = 0 ; i < n ; ++i ) {
		for ( int j = i + 1 ; j < n ; ++j ) {
			set<string> s;
			s.insert(all(v[i]));
			s.insert(all(v[j]));
			ans = max(ans,(sz(v[i])+sz(v[j])-sz(s)) + 1);
		}
	}
	cout << ans;
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("guess");
	int T = 1;
	while ( T-->0 ) solve();
	return 0;
}
