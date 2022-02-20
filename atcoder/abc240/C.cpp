#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<int> possible(x+1);
    possible[0]=1;
    for(auto &i : a) {
        for(int j=x; j>=0; j--) {
            if(!possible[j]) {
                continue;
            }
            if(j+i[0]<=x) {
                possible[j+i[0]]=1;
            }
            if(j+i[1]<=x) {
                possible[j+i[1]]=1;
            }
            possible[j]=0;
        }
    }
    string ans=possible[x]?"Yes":"No";
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

