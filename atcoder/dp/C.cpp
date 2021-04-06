#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> happiness(n, vector<int> (3)), tasks;
    tasks=happiness;
    for(auto &i : tasks) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    happiness[0]=tasks[0];
    for(int i=1; i<n; i++) {
        happiness[i][0]=tasks[i][0]+max(happiness[i-1][1], happiness[i-1][2]);
        happiness[i][1]=tasks[i][1]+max(happiness[i-1][0], happiness[i-1][2]);
        happiness[i][2]=tasks[i][2]+max(happiness[i-1][1], happiness[i-1][0]);
    }
    int ans=0;
    for(auto i : happiness[n-1]) {
        ans=max(ans, i);
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

