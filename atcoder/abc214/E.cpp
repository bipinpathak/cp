#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        cin>>i[1]>>i[0];
    }
    sort(a.begin(), a.end());
    set<vector<int>> available;
    available.insert({(int)1e9, 1});
    string ans="Yes";
    for(auto i : a) {
        int start=i[1]; 
        auto it = available.lower_bound({start, 0});
        if(it==available.end()) {
            ans="No";
            break;
        }
        int l=it->back(), r=it->front();
        available.erase(it);
        int use=max(start, l);
        if(use>i[0]) {
            ans="No";
            break;
        }
        vector<int> leftPart={l, use-1}, rightPart={use+1, r};
        if(leftPart[0]<=leftPart[1]) {
            swap(leftPart[0], leftPart[1]);
            available.insert(leftPart);
        }
        if(rightPart[0]<=rightPart[1]) {
            swap(rightPart[0], rightPart[1]);
            available.insert(rightPart);
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

