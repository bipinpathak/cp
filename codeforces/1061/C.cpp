#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int mod=1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), count(n+1);
    count[0]=1;
    for(auto &i : a) {
        cin>>i;
        vector<int> left, right;
        for(int j=1; j*j<=i; j++) {
            if(i%j==0) {
                left.push_back(j);
                if(i/j>j) {
                    right.push_back(i/j);
                }
            }
        }
        for(auto &j : right) {
            if(j>n) {
                continue;
            }
            count[j]+=count[j-1];
            if(count[j]>=mod) {
                count[j]-=mod;
            }
        }
        reverse(left.begin(), left.end());
        for(auto &j : left) {
            if(j>n) {
                continue;
            }
            count[j]+=count[j-1];
            if(count[j]>=mod) {
                count[j]-=mod;
            }
        }
    }
    ll ans=0;
    for(auto &i : count) {
        ans+=i;
        if(ans>=mod) {
            ans-=mod;
        }
    }
    ans--;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

