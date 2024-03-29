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
	cin.tie(0);
	int n, a, b;
	cin>>n;
	a=b=sqrt(n);
	while(true){
		if(a*b>=n){
			break;
		}
		a++;
		if(a*b>=n){
			break;
		}
		b++;
	}
	cout<<a+b<<ent;
	return 0;
}
