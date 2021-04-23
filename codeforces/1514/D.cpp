#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n=3e5;
vector<int> a(n+1), seg(2*n+1);
vector<vector<int>> f(n+1);

int calc(int val, int l, int r) {
    int ans=upper_bound(f[val].begin(), f[val].end(), r)-lower_bound(f[val].begin(), f[val].end(), l);
    return ans;
}

void build(int l, int r, int index) {
    if(l==r) {
        seg[index]=a[l];
    } else {
        int mid=l+(r-l)/2; 
        build(l, mid, index+1);
        build(mid+1, r, index+2*(mid-l+1));
        int x=seg[index+1], y=seg[index+2*(mid-l+1)];
        if(x!=y) {
            int fx=calc(x, l, r), fy=calc(y, l, r);
            if(fy>fx) {
                x=y;
            }
        }
        seg[index]=x;
    }
    return;
}

int query(int l, int r, int index, int start, int end) {
    if(l>end || r<start) {
        return 0;
    }
    if(start<=l && r<=end) {
        return calc(seg[index], start, end);
    }
    int mid=l+(r-l)/2;
    return max(query(l, mid, index+1, start, end), query(mid+1, r, index+2*(mid-l+1), start, end));
}

void handle(int l, int r) {
    int fx=query(1, n, 1, l, r),ans=1, total=r-l+1;
    ans=max(ans, 2*fx-total); 
    cout<<ans<<endl;
    return;
}

void solve() {
    int q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        f[a[i]].push_back(i);
    }
    build(1, n, 1);
    while(q--) {
        int l, r;
        cin>>l>>r;
        handle(l, r);
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

