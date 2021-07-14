#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void push(int l, int r, int index, vector<ll> &seg, vector<ll> &lazy) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1]+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)]+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, vector<ll> &seg, int start, int end, ll val, vector<ll> &lazy) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]+=val;
            lazy[index]+=val;
        } else {
            push(l, r, index, seg, lazy);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy);
            seg[index]=min(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll query(int l, int r, int index, vector<ll> &seg, int start, int end, vector<ll> &lazy) {
    ll ans=1e18;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy); 
            int mid=l+(r-l)/2;
            ans=min(query(l, mid, index+1, seg, start, end, lazy), query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy));
        }
    }
    return ans;
}
 
void solve() {
    int n;
    cin>>n;
    vector<int> p(n+1), index(n+1);
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) {
        cin>>p[i];
        index[p[i]]=i;
    }
    for(int i=1; i<=n; i++) {
        cin>>a[p[i]];
    }
    vector<ll> seg(2*n+1), lazy(2*n+1);
    for(int i=1; i<=n; i++) {
        update(1, n, 1, seg, i, n, a[p[i]], lazy);
    }
    ll ans=query(1, n, 1, seg, 1, n-1, lazy);
    for(int high=1; high<=n; high++) {
        int i=index[high];
        update(1, n, 1, seg, 1, i-1, a[p[i]], lazy);
        update(1, n, 1, seg, i, n, -a[p[i]], lazy);
        ans=min(ans, query(1, n, 1, seg, 1, n-1, lazy));
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

