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

int n, ans;
int t[N];
bool vis[N]={1};

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	sort(t+1, t+n+1);
	FOR(i, 1, n){
		if(!vis[t[i]-1]){
			vis[t[i]-1]=1; ans++; continue;
		}
		if(!vis[t[i]]){
			vis[t[i]]=1; ans++; continue;
		}
		if(!vis[t[i]+1]){
			vis[t[i]+1]=1; ans++; continue;
		}
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
