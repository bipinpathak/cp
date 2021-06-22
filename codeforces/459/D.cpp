#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(int index, vector<int> &a, int val) {
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
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> prefix(n), suffix(n);
    map<int, int> f;
    vector<int> points;
    for(int i=0; i<n; i++) {
        f[a[i]]++;
        prefix[i]=f[a[i]];
        points.push_back(prefix[i]);
    }
    f.clear();
    for(int i=n-1; i>=0; i--) {
        f[a[i]]++;
        suffix[i]=f[a[i]];
        points.push_back(suffix[i]);
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    int m=(int)points.size();
    map<int, int> id;
    for(int i=0; i<m; i++) {
        id[points[i]]=i+1;
    }   
    vector<int> bit(m+1);
    ll ans=0;
    for(int i=n-1; i>=0; i--) {
        ans+=get(id[prefix[i]]-1, bit);
        add(id[suffix[i]], bit, 1);
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

