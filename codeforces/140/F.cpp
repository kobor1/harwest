// Krzysztof Boryczka
#pragma GCC optimize("O3")
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

const int N=2e5+5;

int n;
ii pt[N];
vii ans;

void solve(){
	srand(123);
	int k;
	cin>>n>>k;
	if(n<=k){
		cout<<-1<<ent;
		return;
	}
	FOR(i, 1, n) cin>>pt[i].st>>pt[i].nd;
	sort(pt+1, pt+n+1);
    FOR(a, 1, min(k+1, n)){
        FORD(b, n, max(n-k, 0)){
    		ii mid={pt[a].st+pt[b].st, pt[a].nd+pt[b].nd};
    		int zeps=0, last=n;
    		FOR(i, 1, n){
    			if(zeps>k) break;
    			ii drugi={mid.st-pt[i].st, mid.nd-pt[i].nd};
                while(last>0 && pt[last]>drugi) last--;
                if(last<1 || pt[last]!=drugi) zeps++;
    		}
    		if(zeps<=k) ans.pb(mid);
        }
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout<<fixed<<setprecision(1);
	cout<<SIZE(ans)<<ent;
	for(auto &x: ans) cout<<x.st*0.5<<sp<<x.nd*0.5<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt){
	// 	cout<<"Case #"<<te<<": ";
	// 	solve();
	// }
	solve();
	return 0;
}
