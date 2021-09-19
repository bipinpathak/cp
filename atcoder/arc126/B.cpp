#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void update(int l, int r, int index, vector<int> &seg, int start, int end, int val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]=max(seg[index], val);
        } else {
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val);
            seg[index]=max(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
int query(int l, int r, int index, vector<int> &seg, int start, int end) {
    int ans=0;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            int mid=l+(r-l)/2;
            ans=max(query(l, mid, index+1, seg, start, end), query(mid+1, r, index+2*(mid-l+1), seg, start, end));
        }
    }
    return ans;
}
void solve() {
    int n, m;
    cin>>n>>m;
    map<int, vector<int>> a;
    while(m--) {
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
    }   
    vector<int> seg(2*n+1);
    int ans=0;
    for(auto &[x, y] : a) {
        sort(y.rbegin(), y.rend());
        for(auto i : y) {
            int offer=1+query(1, n, 1, seg, 1, i-1);
            ans=max(ans, offer);
            update(1, n, 1, seg, i, i, offer);
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

