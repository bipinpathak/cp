#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(vector<ll> &a, ll &sum) {
    ll ans=0, cf=0, index=-1, n=a.size();
    while(2*cf<sum) {
        index++;
        cf+=a[index];
    }
    for(int i=0; i<n; i++) {
        ans+=abs(index-i)*a[i];
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(auto &i : a) {
        cin>>i;
        sum+=i;
    }
    if(sum==1) {
        cout<<-1<<endl;
        return;
    }
    vector<ll> primes;
    for(ll i=2; i*i<=sum; i++) {
        if(sum%i==0) {
            primes.push_back(i);
            while(sum%i==0) {
                sum/=i;
            }
        }
    }
    if(sum>1) {
        primes.push_back(sum);
    }
    ll ans=1e18;
    for(auto p :primes) {
        sum=0;
        ll offer=0;
        vector<ll> count, temp=a;
        for(int i=0; i<n; i++) {
            a[i]%=p;
            if(a[i]==0 && sum==0) {
                continue;
            }
            sum+=a[i];
            count.push_back(a[i]);
            if(sum>=p) {
                ll rem=sum%p;
                count.back()-=rem;
                sum-=rem;
                offer+=calc(count, sum);
                sum=0;
                count.clear();
                if(rem) {
                    sum=rem;
                    count.push_back(rem);
                }
            }   
        }
        ans=min(ans, offer);
        a=temp;
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
    while(t--) {
        solve();
    }
    return 0;
}

