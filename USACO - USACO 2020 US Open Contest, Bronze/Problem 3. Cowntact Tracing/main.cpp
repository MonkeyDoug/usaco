// Author : 3
// Date : 11/12/21
// Problem Name : Problem 3. Cowntact Tracing
// Content : USACO - USACO 2020 US Open Contest, Bronze
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

vi ntv(int X) {
	vi final;
	while (X) {
		final.pb(X%10); X/=10;
	}
	reverse(all(final)); return final;
}

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

void setIO(string file) {
	freopen((file+".in").c_str(),"r",stdin);
	freopen((file+".out").c_str(),"w",stdout);
	#ifdef LOCAL
	freopen((file+".err").c_str(),"w",stderr);
	#endif
}

void solve(){
	int n,t; read(n,t);
	string s; read(s);
	vi health(n+1);
	loop(i,1,n+1){
		health[i] = s[i-1] - '0';
	}
	set<int> pz,pk;
	vector<tuple<int,int,int>> v(t);
	forn(i,t){
		int t1,t2,t3; read(t1,t2,t3);
		v[i] = mt(t1,t2,t3);
	}
	sort(all(v));
	loop(i,1,n+1){
		if ( !health[i] ) continue;
		loop(k,0,t+1){
			vector<int> check(n+1,0);
			check[i] = 1; // i is the simulated patient zero, we set him to infected first
			vi inter(n+1,0);
			trav(e,v) {
				int x = get<1>(e);
				int y = get<2>(e);
				if (check[x]) inter[x]++; // Keep track of interactions from cow x
				if (check[y]) inter[y]++; // Keep track of interactions from cow y
				if ( inter[x] <= k && check[x] ) check[y] = 1; // If cow x's interactions has not reached k and is infected, then it will infect cow y
				if ( inter[y] <= k && check[y] ) check[x] = 1; // If cow y's interactions has not reached k and is infected, then it will infect cow x
			}
			bool add = true;
			loop(ii,1,n+1){
				if ( health[ii] != check[ii] ) { // If the results of the simulation conflict with the real health of the cows, then the patient zero and k cannot be correct
					add = false; break;
				}
			}
			if ( add ) {
				pz.insert(i); pk.insert(k);
			}
		}
	}
	dbg(pz);
	dbg(pk);
	cout << sz(pz) << ' ' << mn(pk) << ' ';
	if ( mx(pk) == t ) {
		cout << "Infinity";
	} else {
		cout << mx(pk);
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	setIO("tracing");
	int T = 1;
	while ( T-->0 ) solve();
	return 0;
}
