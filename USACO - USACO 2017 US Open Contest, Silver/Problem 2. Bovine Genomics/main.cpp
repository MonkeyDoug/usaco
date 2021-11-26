// Author : 3
// Date : 11/11/21
// Problem Name : Problem 2. Bovine Genomics
// Content : USACO - USACO 2017 US Open Contest, Silver
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

// First, read in the chars as numbers. We can then use an equation to construct a unique sequence where only when the numbers are exactly the same ( the chars are the exactly the same, and in extension the genome sequence is the same ) does this equation yield the same number. We use 16,4, and 1 because 4*3 + 1*3 is 15, so there is no way two unique sequences can produce the same number. Now, all we need to do is for every position i,j,k, check if any of the numbers generated from the spotty cows sequences is equal to any of the numbers generated from the plain cow sequences.
	
void solve(){
	int n, m; read(n,m);
	int s[n][m], p[n][m];
	forn(i,n){
		forn(j,m){
			char tmp; read(tmp);
			if ( tmp == 'A') s[i][j] = 0;
			else if ( tmp == 'T') s[i][j] = 1;
			else if ( tmp == 'G') s[i][j] = 2;
			else s[i][j] = 3;
		}
	}
	forn(i,n){
		forn(j,m){
			char tmp; read(tmp);
			if ( tmp == 'A') p[i][j] = 0;
			else if ( tmp == 'T') p[i][j] = 1;
			else if ( tmp == 'G') p[i][j] = 2;
			else p[i][j] = 3;
		}
	}
	int ans = 0;
	for ( int i = 0 ; i < m ; ++i ) {
		for ( int j = i + 1 ; j < m ; ++j ){
			for ( int k = j + 1 ; k < m ; ++k ) {
				int c1[64] = {0}; // 64 is the max number from the equation + 1 ( since its 0-indexed ) 16*3 + 4*3 + 3;
				bool check = true;
				forn(ii,n){
					c1[s[ii][i]*16+s[ii][j]*4+s[ii][k]]=1;
				}
				forn(ii,n){
					if(c1[p[ii][i]*16+p[ii][j]*4+p[ii][k]]) check = false;
				}
				if ( check ) ans++;
			}
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("cownomics");
	int T = 1;
	while ( T-->0 ) solve();
	return 0;
}
