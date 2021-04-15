#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int m, n;
    cin>>m>>n;
    vector<set<int>> day(m);
    for(auto &i : day) {
        int t;
        cin>>t;
        while(t--) {
            int x;
            cin>>x;
            i.insert(x);
        }
    }
    string ans="possible";
    for(int i=0; i<m; i++) {
        int count=0;
        for(int j=i+1; j<m; j++) {
            for(auto k : day[i]) {
                if(day[j].find(k)!=day[j].end()) {
                    count++;
                    break;
                }
            }
        }
        if(count!=m-1-i) {
            ans="impossible";
            break;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

