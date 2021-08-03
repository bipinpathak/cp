#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int c=4, n=32, m=50;
    vector<int> count(c);
    for(auto &i : count) {
        cin>>i;
    }
    vector<vector<char>> ans(n, vector<char> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans[i][j]='A'+i/8; 
        }
    }
    for(auto &i : count) {
        i--;
    }
    for(int i=0; i<n; i+=2) {
        int curr=i/8;
        curr=(curr+1)%4;
        for(int j=0; j<m; j+=2) {
            if(count[curr]) {
                ans[i][j]='A'+curr;
                count[curr]--;
            }
        }
    }
    cout<<n<<" "<<m<<endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j;
        }       
        cout<<endl;
    }   
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

