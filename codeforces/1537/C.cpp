#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> h(n);
    for(auto &i : h) {
        cin>>i;
    }
    sort(h.begin(), h.end());
    if(n==2) {
        for(auto i : h) {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    int lowest=h.back()-h.front(), last=n-1;
    for(int i=1; i<n; i++) {
        if(h[i]-h[i-1]<lowest) {
            last=i;
            lowest=h[i]-h[i-1];
        }
    }
    vector<int> ans;
    ans.push_back(h[last-1]);
    for(int i=last+1; i<n; i++) {
        ans.push_back(h[i]);
    }
    for(int i=0; i<last-1; i++) {
        ans.push_back(h[i]);
    }
    ans.push_back(h[last]);
    for(auto i : ans) {
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

