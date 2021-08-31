#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void minUpdate(int l, int r, int index, vector<ll> &seg, int start, int end, ll val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]=val;
        } else {
            int mid=l+(r-l)/2;
            minUpdate(l, mid, index+1, seg, start, end, val);
            minUpdate(mid+1, r, index+2*(mid-l+1), seg, start, end, val);
            seg[index]=min(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll minQuery(int l, int r, int index, vector<ll> &seg, int start, int end) {
    ll ans=1e18;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=min(minQuery(l, mid, index+1, seg, start, end), minQuery(mid+1, r, index+2*(mid-l+1), seg, start, end));
        }
    }
    return ans;
}

void maxUpdate(int l, int r, int index, vector<ll> &seg, int start, int end, ll val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]=val;
        } else {
            int mid=l+(r-l)/2;
            maxUpdate(l, mid, index+1, seg, start, end, val);
            maxUpdate(mid+1, r, index+2*(mid-l+1), seg, start, end, val);
            seg[index]=max(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll maxQuery(int l, int r, int index, vector<ll> &seg, int start, int end) {
    ll ans=-1e18;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=max(maxQuery(l, mid, index+1, seg, start, end), maxQuery(mid+1, r, index+2*(mid-l+1), seg, start, end));
        }
    }
    return ans;
}
void solve() {
    int n, q;
    cin>>n>>q;
    vector<ll> p(n);
    for(auto &i : p) {
        cin>>i;
    }
    vector<ll> minSeg(2*n+1), maxSeg(2*n+1);
    for(int i=0; i<n; i++) {
        ll b;
        cin>>b;
        p[i]=b-p[i];
        p[i]+=i?p[i-1]:0;
        minUpdate(1, n, 1, minSeg, i+1, i+1, p[i]);
        maxUpdate(1, n, 1, maxSeg, i+1, i+1, p[i]);
    }
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        ll total=p[r]-(l?p[l-1]:0);
        ll ans=-1;
        if(total==0) {  
            ll left=l?p[l-1]:0;
            l++, r++;
            ll low=minQuery(1, n, 1, minSeg, l, r), high=maxQuery(1, n, 1, maxSeg, l, r);
            low-=left, high-=left;
            if(low>=0) {
                ans=high;
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

