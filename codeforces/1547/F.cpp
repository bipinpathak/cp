#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(int l, int r, int index, vector<int> &seg, int start, int end, int val) {
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
 
int query(int l, int r, int index, vector<int> &seg, int start, int end) {
    int ans=0;
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
    vector<int> a(n);
    int g=0;
    for(auto &i : a) {
        cin>>i;
        g=__gcd(g, i);
    }
    for(int i=0; i<n; i++) {
        a[i]/=g;
        a.push_back(a[i]);
    }
    vector<int> seg(4*n+1);
    int ans=0;
    for(int i=0; i<2*n; i++) {
        update(1, 2*n, 1, seg, i+1, i+1, a[i]);
        int low=0, high=i;
        while(low<high) {
            int mid=(low+high+1)/2; 
            if(query(1, 2*n, 1, seg, mid+1, i+1)==1) {
                low=mid;
            } else {
                high=mid-1;
            }
        }
        ans=max(ans, i-low);
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

