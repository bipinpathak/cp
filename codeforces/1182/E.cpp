#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> fac;
ll p=1e9+7;
ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}
ll modInv(ll a) {
	return power(a, p-2);
}

vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    int n1=(int)a.size(), n2=(int)a.front().size(), n3=(int)b.front().size(); 
    vector<vector<ll>> ans(n1, vector<ll> (n3));
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n3; j++) {
            for(int k=0; k<n2; k++) {
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%(p-1);
            }   
        }
    }
    return ans;
}

ll go(vector<vector<ll>> a, vector<vector<ll>> x, ll n) {
    vector<vector<ll>> curr=x;
    n--;
    while(n) {
        if(n&1) {
            curr=mul(curr, x);
        }
        x=mul(x, x);
        n=n>>1;
    }
    a=mul(a, curr);
    return a[0][2];
}

void solve() {
    ll n, a1, a2, a3, c;
    cin>>n>>a1>>a2>>a3>>c;
    ll A1, A2, A3, C;
    vector<vector<ll>> a={{1, 0, 0}};
    vector<vector<ll>> x={{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
    ll ans=modInv(power(c, n));
    n-=3;
    A1=go(a, x, n);
    a[0][0]=0;
    a[0][1]=1;
    A2=go(a, x, n);
    a[0][1]=0;
    a[0][2]=1;
    A3=go(a, x, n);
    a[0][0]=1;
    a[0][1]=2;
    a[0][2]=3;
    C=go(a, x, n);
    ans=(ans*power(a1, A1))%p;
    ans=(ans*power(a2, A2))%p;
    ans=(ans*power(a3, A3))%p;
    ans=(ans*power(c, C))%p;
    cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

