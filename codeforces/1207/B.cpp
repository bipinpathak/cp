#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m)), b;
    b=a;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<int>> moves;
    for(int i=0; i+1<n; i++) {
        for(int j=0; j+1<m; j++) {
            int count=0;
            for(int k=0; k<2; k++) {
                for(int l=0; l<2; l++) {
                    count+=a[i+k][j+l];
                }
            }
            if(count!=4) {
                continue;
            }
            moves.push_back({i, j});
            for(int k=0; k<2; k++) {
                for(int l=0; l<2; l++) {
                    b[i+k][j+l]=1;
                }
            }
        }
    }
    if(a!=b) {
        cout<< -1<<endl;
        return;
    }
    cout<<moves.size()<<endl;
    for(auto &i : moves) {
        for(auto &j : i) {
            cout<<j+1<<" ";
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

