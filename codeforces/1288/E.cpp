#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(int index, vector<int> &a, int val) {
    int n=(int)a.size();
    while(index<n) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}

int get(int index, vector<int> &a) {
    int ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> minPos(n+1), maxPos(n+1), bit(m+n+1), last(n+1);
    for(int i=1; i<=n; i++) {
        minPos[i]=maxPos[i]=i;
        last[i]=n+1-i;
        update(last[i], bit, 1);
    }
    for(int i=1; i<=m; i++) {
        int a;
        cin>>a;
        minPos[a]=1;
        int offer=n-get(last[a]-1, bit);
        maxPos[a]=max(maxPos[a], offer);
        update(last[a], bit, -1);
        last[a]=n+i;
        update(last[a], bit, 1);
    }
    for(int i=1; i<=n; i++) {
        int offer=n-get(last[i]-1, bit);
        maxPos[i]=max(maxPos[i], offer);
    }
    for(int i=1; i<=n; i++) {
        cout<<minPos[i]<<" "<<maxPos[i]<<endl;
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

