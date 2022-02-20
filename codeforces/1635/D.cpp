#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=1e9+7;

int calc(int n) {
    int ans=0;
    while(n) {
        ans++;
        n>>=1;
    }
    return ans;
}

void solve() {
    int n, p;
    cin>>n>>p;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    set<int> seen;
    for(auto &i : a) {
        bool found=false;
        int temp=i;
        while(temp) {
            if(seen.count(temp)) {
                found=true;
                break;
            }
            if((temp&1)) {
                temp>>=1;
            } else {
                if(temp%4) {
                    break;
                }
                temp>>=2;
            }
        }
        if(!found) {
            seen.insert(i);
        }
    }   
    vector<ll> count(p+1), total(p+1);
    count[0]=total[0]=1;
    for(int i=1; i<=p; i++) {
        count[i]=count[i-1]; 
        if(i-2>=0) {
            count[i]=(count[i]+count[i-2])%mod;
        }
        total[i]=(total[i-1]+count[i])%mod;
    }
    ll ans=0;
    for(auto &i : seen) {
        int left=p-calc(i);
        if(left>=0) {
            ans=(ans+total[left])%mod;
        }
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

