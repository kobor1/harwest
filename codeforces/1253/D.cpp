//Krzysztof Boryczka
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
//END OF TEMPLATE

const int N=2e5+5;

int n, m, ans;
vi G[N];
int p[N], sklad[N], done[N], maks[N];

int Find(int v){
	return p[v]==v ? v : p[v]=Find(p[v]);
}

void Union(int v, int u){
	v=Find(v);
	u=Find(u);
	p[u]=v;
	maks[v]=max(maks[v], maks[u]);
}

void solve(){
	int a, b;
	cin>>n>>m;
	FOR(i, 1, n) maks[i]=p[i]=sklad[i]=i;
	FOR(i, 1, m){
		cin>>a>>b;
		Union(a, b);
	}
	FOR(i, 1, n){
		int ojc=Find(i);
		if(done[ojc]) continue;
		done[ojc]=1;
		FOR(j, i+1, maks[ojc]){
			if(Find(j)!=ojc){
				Union(ojc, j);
				ans++;
			}
		}
		i=maks[ojc];
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}
