#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void push(int l, int r, int index, vector<int> &seg, vector<int> &lazy) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1]+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)]+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, vector<int> &seg, int start, int end, int val, vector<int> &lazy) {
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
 
int query(int l, int r, int index, vector<int> &seg, int start, int end, vector<int> &lazy) {
    int ans=1e9;
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
    int n, k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (k+1, 1e9));
    for(int j=1; j<=k; j++) {
        vector<int> last(n+1);
        if(j==1) {
            int sum=0;
            for(int i=1; i<=n; i++) {
                if(last[a[i]]) {
                    sum+=i-last[a[i]];
                }
                dp[i][1]=sum;
                last[a[i]]=i;
            }
            continue;
        }
        vector<int> seg(2*n+1), lazy(2*n+1);
        for(int i=1; i<=n; i++) {
            if(last[a[i]]) {
                int diff=i-last[a[i]];
                update(1, n, 1, seg, 1, last[a[i]]-1, diff, lazy);
            }
            last[a[i]]=i;
            update(1, n, 1, seg, i-1, i-1, dp[i-1][j-1], lazy);
            dp[i][j]=query(1, n, 1, seg, 1, i-1, lazy);
        }
    }
    cout<<dp[n][k]<<endl;
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

