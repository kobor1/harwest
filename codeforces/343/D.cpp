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

const int N=5e5+5;
const int M=1<<19;

vi G[N];
int in[N], out[N], tree[M*2+5][2], prop[M*2+5][2];
int n, tim;

void dfs(int v){
	in[v]=++tim;
	for(auto &x: G[v]){
		if(!in[x]) dfs(x);
	}
	out[v]=tim;
}

void push(int v){
	FOR(i, 0, 1){
		tree[v*2][i]=max(tree[v*2][i], prop[v][i]);
		tree[v*2+1][i]=max(tree[v*2+1][i], prop[v][i]);
		prop[v*2][i]=max(prop[v*2][i], prop[v][i]);
		prop[v*2+1][i]=max(prop[v*2+1][i], prop[v][i]);
	}
}

void add(int v, int l, int r, int ll, int rr, int val, int op){
	if(l>rr || r<ll) return;
	if(l>=ll && r<=rr){
		tree[v][op]=val;
		prop[v][op]=val;
		return;
	}
	int mid=(l+r)/2;
	push(v);
	add(v*2, l, mid, ll, rr, val, op);
	add(v*2+1, mid+1, r, ll, rr, val, op);
	FOR(i, 0, 1) tree[v][i]=max({tree[v][i], tree[v*2][i], tree[v*2+1][i]});
}

ii query(int v, int l, int r, int ll, int rr){
	if(l>rr || r<ll) return {0, 0};
	if(l>=ll && r<=rr) return {tree[v][0], tree[v][1]};
	int mid=(l+r)/2;
	push(v);
	ii ret1=query(v*2, l, mid, ll, rr);
	ii ret2=query(v*2+1, mid+1, r, ll, rr);
	FOR(i, 0, 1) tree[v][i]=max({tree[v][i], tree[v*2][i], tree[v*2+1][i]});
	return {max(ret1.st, ret2.st), max(ret1.nd, ret2.nd)};
}

void solve(){
	int a, b, q, c, v;
	ii ans1, ans2;
	cin>>n;
	FOR(i, 2, n){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1);
	cin>>q;
	FOR(i, 1, q){
		cin>>c>>v;
		if(c==1){
			add(1, 1, M-1, in[v], out[v], i, 0);
		}
		if(c==2){
			add(1, 1, M-1, in[v], in[v], i, 1);
		}
		if(c==3){
			ans1=query(1, 1, M-1, in[v], in[v]);
			ans2=query(1, 1, M-1, in[v], out[v]);
			cout<<(ans1.st>ans2.nd)<<ent;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
