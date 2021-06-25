#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, t;
    cin>>n>>t;
    vector<vector<int>> a(n, vector<int> (3));
    for(int i=0; i<n; i++) {
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i;
    }
    sort(a.begin(), a.end());
    set<vector<int>> ans;
    int totalUsed=0;
    for(int i=n-1; i>=0 && (int)ans.size()<=a[i][0]; i--) {
        ans.insert({a[i][1], a[i][2]}); 
        totalUsed+=a[i][1];
        while(totalUsed>t || (int)ans.size()>a[i][0]) {
            totalUsed-=ans.rbegin()->at(0);
            ans.erase(*ans.rbegin());
        }
    }
    cout<<ans.size()<<endl;
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i[1]+1<<" ";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

