#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    cin.ignore();
    int k, n, m;
    cin>>k>>n>>m;
    vector<int> a(n), b(m);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> ans;
    while(!a.empty() || !b.empty()) {
        if(b.empty() ||  (!a.empty() && a.back()<=b.back())) {
            ans.push_back(a.back());
            a.pop_back();
        } else {
            ans.push_back(b.back());
            b.pop_back();
        }
        if(ans.back()>k) {
            ans={-1};
            break;
        }
        k+=!ans.back();
    }
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

