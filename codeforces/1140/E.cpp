#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=998244353;
int k;

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


ll calc(int leftval, int rightval, int d) {
    ll s=k;
    if(leftval>=0) {
        s--;
    }
    ll ans=(s*power(k-1, d-1))%mod;
    if(rightval>=0) {
        ll sub=0;
        if(leftval!=rightval) {
            sub++;
        }
        if(d%2==0) {
            sub*=-1;
        }
        ll temp=power(k-1, d-1);
        if(d%2) {
            temp--;
        } else {
            temp++;
        }
        temp=(temp*modInv(k))%mod;
        temp=(temp*s)%mod;
        sub+=temp;
        ans=(ans-sub)%mod;
    }
    return ans;
}

ll half(vector<int> &a) {
    ll ans=1;
    int n=(int)a.size(), left=0;
    while(left<n) {
        while(left<n && a[left]!=-1) {
            left++;
        }
        if(left==n) {
            break;
        }
        int right=left;
        while(right<n && a[right]==-1) {
            right++;
        }
        right--;
        int leftval=-1, rightval=-2;
        if(left-1>=0) {
            leftval=a[left-1];
        }
        if(right+1<n) {
            rightval=a[right+1];
        }
        ans=(ans*calc(leftval, rightval, right-left+1))%mod;
        left=right+1;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n>>k;
    vector<vector<int>> a(2);
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        a[i%2].push_back(x);
    }
    ll ans=1;
    ans=(half(a[0])*half(a[1]))%mod;
    for(auto i : a) {
        int last=-2;
        for(auto j : i) {
            if(j==last && last!=-1) {
                ans=0;
            }
            last=j;
        }
    }
    if(ans<0) {
        ans+=mod;
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

