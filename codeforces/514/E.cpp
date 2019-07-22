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

const int mod=1e9+7;
const int N=101;

struct mat{
	int m[N+1][N+1];
	mat(){
		memset(m, 0, sizeof(m));
	}
	mat operator *(mat b){
		mat c=mat();
		FOR(i, 1, N) FOR(k, 1, N) FOR(j, 1, N) c.m[i][j]=(c.m[i][j]+(ll)m[i][k]*b.m[k][j])%mod;
		return c;
	}
};

mat base, ret;

void pov(int exp){
	FOR(i, 1, N) ret.m[i][i]=1;
	while(exp){
		if(exp&1) ret=ret*base;
		base=base*base;
		exp>>=1;
	}
}

void solve(){
	int n, k, a;
	cin>>n>>k;
	FOR(i, 1, n){
		cin>>a;
		base.m[1][a]++;
	}
	FOR(i, 2, N-1) base.m[i][i-1]++;
	base.m[N][1]=base.m[N][N]=1;
	pov(k+1);
	cout<<ret.m[N][1]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
