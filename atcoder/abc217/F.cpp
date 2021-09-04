#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=998244353;

vector<ll> fac, invFac;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%mod;
		}
		x=x>>1;
		a=(a*a)%mod;
	}
	return ans;
}

ll modInv(ll a) {
	return power(a, mod-2);
}

ll ncr(ll n, ll r) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=(((fac[n]*invFac[r])%mod)*invFac[n-r])%mod;
	}
	return ans;
}

void pre(int n) {
	ll x=1;
	fac.push_back(x);
    invFac.push_back(modInv(fac.back()));
	for(ll i=1; i<=n; i++) {
		x=(x*i)%mod;
		fac.push_back(x);
        invFac.push_back(modInv(fac.back()));
	}
	return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    n*=2;
    vector<vector<int>> options(n);
    while(m--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        if((l&1)==(r&1)) {
            continue;
        }
        options[l].push_back(r);
    }
    for(auto &i : options) {
        sort(i.begin(), i.end()); 
    }
    vector<vector<ll>> dp(n, vector<ll> (n));
    for(int d=1; d<n; d+=2) {
        for(int left=0; left+d<n; left++) {
            int right=left+d;
            for(auto mid : options[left]) {
                if(mid>right) {
                    break;
                }
                ll leftHalf, rightHalf;
                if(left+1>mid-1) {
                    leftHalf=1;
                } else {
                    leftHalf=dp[left+1][mid-1];
                }
                if(mid+1>right) {
                    rightHalf=1;
                } else {
                    rightHalf=dp[mid+1][right];
                }
                ll add=(leftHalf*rightHalf)%mod;
                ll leftMoves=(mid-left+1)/2, rightMoves=(right-(mid+1)+1)/2;
                add=(add*ncr(leftMoves+rightMoves, leftMoves))%mod;
                dp[left][right]=dp[left][right]+add;
                if(dp[left][right]>=mod) {
                    dp[left][right]-=mod;
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    //cin>>t;
    pre(200);
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

