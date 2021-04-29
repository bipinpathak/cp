#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(vector<ll> &ans, vector<ll> &curr) {
    sort(curr.rbegin(), curr.rend());
    int n=(int)curr.size();
    vector<ll> prefix(n);
    for(int i=0; i<n; i++) {
        prefix[i]=curr[i];
        if(i) {
            prefix[i]+=prefix[i-1];
        }
    }
    for(int k=1; k<=n; k++) {
        int left=n%k, last=n-left;
        ans[k-1]+=prefix[last-1];
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> university(n), students(n, vector<ll> (2));
    for(auto &i : students) {
        cin>>i[0];
        i[0]--;
    }
    for(auto &i : students) {
        cin>>i[1];
    }
    for(auto i : students) {
        university[i[0]].push_back(i[1]); 
    }
    vector<ll> ans(n);
    for(auto &i : university) {
        go(ans, i);
    }
    for(auto i: ans) {
        cout<<i<<" ";
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

