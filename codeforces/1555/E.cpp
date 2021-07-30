#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> seg, lazy;

void push(int l, int r, int index) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1]+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)]+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, int start, int end, int val) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]+=val;
            lazy[index]+=val;
        } else {
            push(l, r, index);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, start, end, val);
            update(mid+1, r, index+2*(mid-l+1), start, end, val);
            seg[index]=min(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
int query(int l, int r, int index, int start, int end) {
    int ans=1;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index); 
            int mid=l+(r-l)/2;
            ans=min(query(l, mid, index+1, start, end), query(mid+1, r, index+2*(mid-l+1), start, end));
        }
    }
    return ans;
}
int go(vector<vector<int>> &a, int &m) {
    int n=(int)a.size();
    int left=0, right=0;
    int ans=1e9;
    while(left<n) {
        while(right<n && query(1, m, 1, 1, m)==0) {
            update(1, m, 1, a[right][1], a[right][2], 1);
            right++;
        }
        if(query(1, m, 1, 1, m)) {
            ans=min(ans, a[right-1][0]-a[left][0]);
        }
        update(1, m, 1, a[left][1], a[left][2], -1);
        left++;
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (3));
    int start=m;
    for(auto &i : a) {
        cin>>i[1]>>i[2]>>i[0];
        i[1]*=2;
        i[2]*=2;
        start=min(start, i[1]);
    }
    sort(a.begin(), a.end());
    for(auto &i : a) {
        i[1]-=start-1;
        i[2]-=start-1;
        m=max(m, i[2]);
    }
    seg.resize(2*m+1), lazy.resize(2*m+1);
    cout<<go(a, m)<<endl;
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

