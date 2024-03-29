// Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'

const int N=1010;

int a[N], b[N];

void solve(){
	int n, m;
	cin>>n>>m;
	FOR(i, 1, n) cin>>a[i];
	FOR(i, 1, m) cin>>b[i];
	FOR(i, 1, n){
		FOR(j, 1, m) if(a[i]==b[j]){
			cout<<"YES\n";
			cout<<1<<sp<<a[i]<<ent;
			return;
		}
	}
	cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt){
		// cout<<"Case #"<<te<<": ";
		solve();
	}
	// solve();
	return 0;
}
