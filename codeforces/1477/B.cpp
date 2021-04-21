#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void push(int l, int r, int index, vector<int> &seg, vector<int> &lazy) {
    if(lazy[index]==-1) {
        return;
    }
    int mid=l+(r-l)/2;
    seg[index+1]=min(lazy[index], mid-l+1);
    seg[index+2*(mid-l+1)]=min(lazy[index], r-mid);
    lazy[index+1]=lazy[index];
    lazy[index+2*(mid-l+1)]=lazy[index];
    lazy[index]=-1;
    return;
}

void update(int l, int r, int index, vector<int> &seg, int start, int end, int val, vector<int> &lazy) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            val=min(val, r-l+1);
            seg[index]=val;
            lazy[index]=val;
        } else {
            push(l, r, index, seg, lazy);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy);
            seg[index]=seg[index+1]+seg[index+2*(mid-l+1)];
        }
    }
    return;
}
 
int query(int l, int r, int index, vector<int> &seg, int start, int end, vector<int> &lazy) {
    int ans=0;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy); 
            int mid=l+(r-l)/2;
            ans=query(l, mid, index+1, seg, start, end, lazy)+query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy);
        }
    }
    return ans;
}
 
void solve() {
    int n, qn;
    string s, f;
    cin>>n>>qn>>s>>f;
    vector<pair<int, int>> queries(qn);
    for(auto &[l, r] : queries) {
        cin>>l>>r;
    }   
    vector<int> seg(2*n+1), lazy(2*n+1, -1);
    for(int i=0; i<n; i++) {
        int val=f[i]=='1';
        update(1, n, 1, seg, i+1, i+1, val, lazy);
    }
    string ans="YES";
    reverse(queries.begin(), queries.end());
    for(auto &[l, r] : queries) {
        int total=r-l+1, one=query(1, n, 1, seg, l, r, lazy), zero=total-one;
        if(one==zero) {
            ans="NO";
            break;
        }
        int val=0;
        if(one>zero) {
            val=n;
        }
        update(1, n, 1, seg, l, r, val, lazy);
    }
    if(ans=="YES") {
        for(int i=0; i<n; i++) {
            if(query(1, n, 1, seg, i+1, i+1, lazy)!=(s[i]-'0')) {
                ans="NO";
                break;
            }
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
    auto start=clock();
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

