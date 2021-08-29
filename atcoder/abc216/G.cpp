#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(int index, int val, vector<int> &a) {
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

int range(int l, int r, vector<int> &a) {
    return get(r, a)-get(l-1, a);
}

int prev(int r, vector<int> &a) {
    int low=1, high=r;
    while(low<high) {
        int mid=(high+low+1)/2;
        int diff=high-mid+1-range(mid, high, a);
        if(diff) {
            low=mid;
        } else {
            high=mid-1;
        }
    }
    return low;
}

void go(int r, int count, vector<int> &a) {
    while(count) {
        int i=prev(r, a); 
        add(i, 1, a);
        r=i-1;
        count--;
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> rules(m, vector<int> (3));
    for(auto &i : rules) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<int>> end(n+1);
    for(int i=0; i<m; i++) {
        end[rules[i][1]].push_back(i);
    }
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        for(auto j : end[i]) {
            int left=rules[j][2];
            left-=range(rules[j][0], rules[j][1], a);
            left=max(left, 0);
            go(rules[j][1], left, a);
        }
    }
    for(int i=1; i<=n; i++) {
        int curr=range(i, i, a);
        cout<<curr<<" ";
    }
    cout<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

