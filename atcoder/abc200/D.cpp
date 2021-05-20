#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(vector<int> a) {
    cout<<a.size();
    for(auto i : a) {
        cout<<" "<<i+1;
    }
    cout<<endl;
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i%=200;
    }
    vector<vector<int>> seen(200);
    for(int mask=1; mask<=201; mask++) {
        vector<int> path;
        int curr=0, temp=mask;
        for(int i=0; i<n && temp; i++) {
            if(temp&(1<<i)) {
                path.push_back(i);
                curr=(curr+a[i])%200;
                temp-=(1<<i);
            }
        }
        if(!seen[curr].empty() && seen[curr]!=path) {
            cout<<"Yes"<<endl;
            go(path);
            go(seen[curr]);
            return;
        }
        seen[curr]=path;
    }
    cout<<"No"<<endl;
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

