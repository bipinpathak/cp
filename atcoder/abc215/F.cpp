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

bool possible(int target, vector<vector<int>> &a, vector<int> &seg) {
    int n=(int)a.size();
    int l=0, r=0;
    while(l<n) {
        while(r<n && a[r][0]-a[l][0]<target) {
            r++;
        }
        if(r==n) {
            break;
        }
        if(query(1, n, 1, seg, r+1, n)-a[l][1]>=target) {
            return true;
        }
            l++;
    }
    return false;
}

int go(vector<vector<int>> &a) {
    int lowX=1e9, lowY=1e9;
    for(auto &i : a) {
        lowX=min(lowX, i[0]);
        lowY=min(lowY, i[1]);
    }
    for(auto &i : a) {
        i[0]-=lowX;
        i[1]-=lowY;
    }
    sort(a.begin(), a.end());
    int n=(int)a.size();
    vector<int> seg(2*n+1);
    for(int i=0; i<n; i++) {
        update(1, n, 1, seg, i+1, i+1, a[i][1]);
    }
    int low=0, high=a[n-1][0]-a[0][0];
    while(low<high) {
        int mid=(low+high+1)/2;
        if(possible(mid, a, seg)) {
            low=mid;
        } else {
            high=mid-1;
        }
    }
    return low;
}

void solve() {
    int n;
    cin>>n; 
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int ans=go(a);
    for(auto &i : a) {
        swap(i[0], i[1]);
        i[0]*=-1;
    }
    ans=max(ans, go(a));
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

