#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int get(int index, vector<int> &a) {
    int ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
    }
    return ans;
}

void add(int index, vector<int> &a, int val) {
    int n=(int)a.size();
    while(index<n) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (3));
    vector<int> points;
    for(int i=0; i<n; i++) {
        for(int j=0; j<2; j++){
            cin>>a[i][j];
        }
        points.push_back(a[i][1]);
        a[i][1]*=-1;
        a[i][2]=i;
    }
    sort(points.begin(), points.end());
    map<int, int> id;
    for(int i=0; i<n; i++) {
        id[points[i]]=i+1;
    }
    vector<int> bit(n+1);
    sort(a.rbegin(), a.rend());
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        a[i][1]*=-1;
        int right=id[a[i][1]];
        ans[a[i][2]]=get(right, bit);
        add(right, bit, 1);
    }
    for(auto i : ans) {
        cout<<i<<endl;
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

