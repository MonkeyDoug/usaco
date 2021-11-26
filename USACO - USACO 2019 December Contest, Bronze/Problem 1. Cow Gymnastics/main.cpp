#include<bits/stdc++.h>
using namespace std;

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
#ifdef LOCAL
#define DEBUG
#endif
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

bool b[20][20]; // b[A-1][B-1] = 1 if A was better than B in any session.

int main(){
	ifstream fin("gymnastics.in");
	ofstream fout("gymnastics.out");

	int k, n; fin >> k >> n;
	int a[n];
	while(k--){ // Looping through k times
		for(int i=0;i<n;i++) fin >> a[i];

		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				b[a[i]-1][a[j]-1] = true;
			}
		}
	}

	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// If either is false, we increment the count
			dbg(i);
			dbg(j);
			dbg(b[i][j]);
			dbg(b[j][i]);
			if(!b[i][j] || !b[j][i]) count++;
		}
	}
	fout << count << endl;
}
