// Author : 3
// Date : 10/12/21
// Problem Name : Problem 1. Team Tic Tac Toe
// Content : USACO - USACO 2018 US Open Contest, Bronze
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
typedef pair<char,char> pc;

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

struct custom_comparator {
    bool operator()(const std::pair<int, int>& a,
                    const std::pair<int, int>& b) const
    {
        return less_comparator(std::minmax(a.first, a.second),
                               std::minmax(b.first, b.second));
    }

    std::less<std::pair<int, int>> less_comparator;
};

void solve(){
	char arr[3][3];
	forn(i,3){
		forn(j,3){
			cin >> arr[i][j];
		}
	}
	set<char> d1;
	set<char> d2;
	set<char> ans1;
	for ( int i = 0 ; i < 3 ; i++ ) {
		set<char> s1;
		set<char> s2;
		for ( int j = 0 ; j < 3 ; j++ ) {
			if ( i == j ) d1.insert(arr[i][j]);
			if ( i + j == 2 ) d2.insert(arr[i][j]);
			s1.insert(arr[i][j]);
			s2.insert(arr[j][i]);
		}
		if ( s1.size() == 1 ) {
			ans1.insert( *s1.begin() );
		}
		if ( s2.size() == 1 ) {
			ans1.insert( *s2.begin() );
		}
	}
	if ( d1.size() == 1 ) ans1.insert(*d1.begin());
	if ( d2.size() == 1 ) ans1.insert(*d2.begin());
	cout << ans1.size() << nl;

	set<pc> ans2;
	for ( int i = 0 ; i < 3 ; i++ ) {
		set<char> s1;
		set<char> s2;
		for ( int j = 0 ; j < 3 ; j++ ) {
			s1.insert(arr[i][j]);
			s2.insert(arr[j][i]);
		}
		if ( s1.size() == 2 ) {
			dbg(i);
			dbg(s1);
			dbg(*s1.begin());
			dbg(*next(s1.begin(),1));
			ans2.insert({*s1.begin(),*next(s1.begin(),1)});
			// ans2.insert(s1);
			dbg(ans2);
		}
		if ( s2.size() == 2 ) {
			dbg(i);
			dbg(*s2.begin());
			dbg(*next(s2.begin(),1));
			ans2.insert({*s2.begin(),*next(s2.begin(),1)});
			dbg(ans2);
		}
	}
	if ( d1.size() == 2 ) {
		dbg(d1);
		dbg(*d1.begin());
		dbg(*next(d1.begin(),1));
		ans2.insert({*d1.begin(),*next(d1.begin(),1)});
	}
	if ( d2.size() == 2 ) {
		dbg(d2);
		dbg(*d2.begin());
		dbg(*next(d2.begin(),1));
		ans2.insert({*d2.begin(),*next(d2.begin(),1)});
	}
	cout << ans2.size() << nl;
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("tttt");
	int T = 1;
	while ( T-->0 ) solve();
	return 0;
}
