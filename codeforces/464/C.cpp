#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
void solve() {
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> q(n);
    for(auto &i : q) {
        cin>>i;
    }
    vector<vector<ll>> val(10, vector<ll> (2));
    for(int i=0; i<10; i++) {
        val[i][0]=i;
        val[i][1]=1;
    }
    while(!q.empty()) {
        string t=q.back();
        q.pop_back();
        n=(int)t.length();
        vector<ll> curr(2, 0);
        ll right=1;
        for(int i=n-1; i>2; i--) {
            int k=t[i]-'0';
            curr[0]=(curr[0]+(val[k][0]*right)%p)%p;
            right=(right*power(10, val[k][1]))%p;
            curr[1]=(curr[1]+val[k][1])%(p-1);
        }
        int k=t[0]-'0';
        val[k]=curr;
    }
    n=(int) s.length();
    ll ans=0, right=1;
    for(int i=n-1; i>=0; i--) {
        int k=s[i]-'0';
        ans=(ans+(val[k][0]*right)%p)%p;
        right=(right*power(10, val[k][1]))%p;
    }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
