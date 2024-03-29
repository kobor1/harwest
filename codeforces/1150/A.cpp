//Krzysztof Boryczka
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, st, kup, sprzed, a, ans;
	cin>>n>>m>>st;
	kup=inf; sprzed=ans=0;
	FOR(i, 1, n){
		cin>>a;
		kup=min(kup, a);
	}
	FOR(i, 1, m){
		cin>>a;
		sprzed=max(sprzed, a);
	}
	if(kup<=sprzed) cout<<(sprzed)*(st/kup)+st%kup<<ent;
	else cout<<st<<ent;
	return 0;
}
