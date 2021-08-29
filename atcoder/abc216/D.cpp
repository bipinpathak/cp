#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> group(m);
    for(auto &i : group) {
        int k;
        cin>>k;
        while(k--) {
            int a;
            cin>>a;
            a--;
            i.push_back(a);
        }
        reverse(i.begin(), i.end());
    }
    vector<vector<int>> exposed(n);
    vector<int> two;
    for(int i=0; i<m; i++) {
        exposed[group[i].back()].push_back(i);
        if((int)exposed[group[i].back()].size()==2) {
            two.push_back(group[i].back());
        }
    }
    vector<int> done(n);
    while(!two.empty()) {
        auto curr = two.back();
        two.pop_back();
        done[curr]=1;
        for(int i=0; i<2; i++) {
            int g=exposed[curr][i];
            group[g].pop_back();
            if(!group[g].empty()) {
                exposed[group[g].back()].push_back(g);
                if((int)exposed[group[g].back()].size()==2) {
                    two.push_back(group[g].back());
                }
            }
        }
    }
    string ans="Yes";
    for(auto i : done) {
        if(!i) {
            ans="No";
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

