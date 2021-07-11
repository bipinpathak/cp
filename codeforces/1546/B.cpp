#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> a(n), b(n-1);
    vector<vector<int>> count(m, vector<int> (26));
    for(auto &i : a) {
        cin>>i;
        for(int j=0; j<m; j++) {
            count[j][i[j]-'a']++;
        }
    }
    for(auto i : b) {
        cin>>i;
        for(int j=0; j<m; j++) {
            count[j][i[j]-'a']--;
        }
    }
    string ans="";
    for(auto i : count) {
        for(int j=0; j<26; j++) {
            if(i[j]) {
                ans.push_back('a'+j);
                break;
            }
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

