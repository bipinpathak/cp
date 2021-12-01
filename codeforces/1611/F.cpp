#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll get(int l, int r, vector<vector<ll>> &sparse) {
    int c=0;
    while(r-l+1>=(1<<(c))) {
        c++;
    }
    c--;
    r-=(1<<c)-1;
    ll ans=min(sparse[c][l], sparse[c][r]);
    return ans;
}

void solve() {
    int n;
    ll s;
    cin>>n>>s;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }   
    for(int i=1; i<n; i++) {
        a[i]+=a[i-1];
    }
    int m=18;
    vector<vector<ll>> sparse(m, vector<ll> (n, 1e18));
    sparse[0]=a;
    for(int l=1; l<m; l++) {
        sparse[l]=sparse[l-1];
        int next=(1<<(l-1));
        for(int i=0; i+next<n; i++) {
            sparse[l][i]=min(sparse[l][i], sparse[l-1][i+next]); 
        }
    }
    int low=0, high=n;
    int left=0, right=-1;
    while(low<high) {
        int mid=(low+high+1)/2;
        bool possible=false;
        for(int i=0; i+mid-1<n && !possible; i++) {
            ll curr=get(i, i+mid-1, sparse); 
            if(i) {
                curr-=a[i-1];
            }
            curr*=-1;
            if(curr<=s) {
                if(mid>right-left+1) {
                    left=i;
                    right=i+mid-1;
                }
                possible=true;
            }
        }
        if(possible) {
            low=mid;
        } else {
            high=mid-1;
        }
    }
    if(!low) {
        cout<<-1<<endl;
        return;
    }
    cout<<left+1<<" "<<right+1<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

