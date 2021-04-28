#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(int l, int r, int index, vector<ll> &seg, int start, int end, ll val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]=max(val, seg[index]);
        } else {
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val);
            seg[index]=max(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll query(int l, int r, int index, vector<ll> &seg, int start, int end) {
    ll ans=0;
    if(!(end<l || start>r || start>end)) {
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
    int n;
    cin>>n;
    vector<vector<int>> flowers(n, vector<int> (2));
    vector<int> heights(n);
    for(int i=0; i<n; i++) {
        cin>>flowers[i][0];
        heights[i]=flowers[i][0];
    }
    for(int i=0; i<n; i++) {
        cin>>flowers[i][1];
    }
    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());
    int m=(int)heights.size();
    vector<ll> seg(2*m+1);
    map<int, int> index;
    for(int i=0; i<m; i++) {
        index[heights[i]]=i+1;
    }
    ll ans=0;
    for(int i=0; i<n; i++) {
        int curr=index[flowers[i][0]]; 
        ll prev=query(1, m, 1, seg, 1, curr-1), offer=prev+flowers[i][1];
        ans=max(ans, offer);
        update(1, m, 1, seg, curr, curr, offer);
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

