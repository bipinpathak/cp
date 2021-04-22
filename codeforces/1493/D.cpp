#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> lp, primes;
ll mod=1e9+7;

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

void build(int high) {
    lp.resize(high+1, 0);
    lp[1]=1;
    for(int i=2; i<=high; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p>high/i || p>lp[i]) {
                break;
            }
            lp[p*i]=p;
        }
    }
    return;
}

void solve() {
    int n, q, high=2e5;
    cin>>n>>q;
    build(high);
    vector<map<int, int>> factors(n), primeFactors(high+1);
    for(auto p : primes) {
        primeFactors[p][0]=n;
    }
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        while(lp[a]>1) {
            int p=lp[a], c=0;
            while(a%p==0) {
                a/=p;
                c++;
            }
            factors[i][p]=c;
            primeFactors[p][0]--;
            primeFactors[p][c]++;
        }
    }
    ll ans=1;
    for(auto p : primes) {
        if(primeFactors[p][0]==0) {
            primeFactors[p].erase(0);
        }
        ans=(ans*power(p, primeFactors[p].begin()->first))%mod;
    }
    while(q--) {
        int i, a;
        cin>>i>>a;
        i--;
        while(lp[a]>1) {
            int p=lp[a], curr=factors[i][p], used=primeFactors[p].begin()->first;
            primeFactors[p][curr]--;
            if(primeFactors[p][curr]==0) {
                primeFactors[p].erase(curr);
            }
            while(a%p==0) {
                a/=p;
                curr++;
            }
            factors[i][p]=curr;
            primeFactors[p][curr]++;
            int updated=primeFactors[p].begin()->first;
            if(updated>used) {
                ans=(ans*power(p, updated-used))%mod;
            }
        }
        cout<<ans<<endl;
    }
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

