#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(int l, int r, int index, vector<ll> &seg, int start, int end, ll val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]=val;
        } else {
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val);
            seg[index]=__gcd(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll query(int l, int r, int index, vector<ll> &seg, int start, int end) {
    ll ans=0;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=__gcd(query(l, mid, index+1, seg, start, end), query(mid+1, r, index+2*(mid-l+1), seg, start, end));
        }
    }
    return ans;
}


void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> b;
    for(int i=1; i<n; i++) {
        b.push_back(abs(a[i]-a[i-1]));
    }
    n--;
    vector<ll> seg(2*n+1);
    for(int i=0; i<n; i++) {
        update(1, n, 1, seg, i+1, i+1, b[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        int curr=i+1;
        int low=curr, high=n;
        while(low<high) {
            int mid=(high+low+1)/2;
            ll g=query(1, n, 1, seg, curr, mid);
            if(g>1) {
                low=mid;
            } else {
                high=mid-1;
            }
        }
        if(curr<=low && query(1, n, 1, seg, curr, low)>1) {
            ans=max(ans, low-curr+1);
        }
    }
    ans++;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

