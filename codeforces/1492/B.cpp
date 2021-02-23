#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> p(n), used(n), ans;
    vector<vector<int>> order;
    for(int i=0; i<n; i++) {
        cin>>p[i];
        order.push_back({p[i], i});
    }
    sort(order.rbegin(), order.rend());
    for(int i=0; i<n; i++) {
        int index=order[i][1]; 
        while(index<n && !used[index]) {
            ans.push_back(p[index]);
            used[index]=1;
            index++;
        }
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
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

