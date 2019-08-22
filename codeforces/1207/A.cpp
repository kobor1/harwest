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

void solve(){
	int b, p, f, h, c, ans, pom;
	cin>>b>>p>>f>>h>>c;
	if(c>=h){
		pom=min(b/2, f);
		ans=pom*c;
		b-=pom*2;
		f-=pom;
	}
	else{
		pom=min(b/2, p);
		ans=pom*h;
		b-=pom*2;
		p-=pom;
	}
	ans+=min(b/2, p)*h+min(b/2, f)*c;
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}
