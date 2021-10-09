#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> moves(2*n, vector<char> (m));
    for(auto &i : moves) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<int>> scores(2*n, vector<int> (2));
    for(int i=0; i<2*n; i++) {
        scores[i]={0, -i};
    }
    for(int round=0; round<m; round++) {
        for(int i=0; i<2*n; i+=2) {
            char left=moves[-scores[i][1]][round], right=moves[-scores[i+1][1]][round]; 
            if(left==right) {
                continue;
            }
            if(left=='G') {
                if(right=='P') {
                    scores[i+1][0]++;
                } else {
                    scores[i][0]++;
                }
            } else if(left=='P') {
                if(right=='G') {
                    scores[i][0]++;
                } else {
                    scores[i+1][0]++;
                }
            } else if(right=='G') {
                scores[i+1][0]++;
            } else {
                scores[i][0]++;
            }
        }
        sort(scores.rbegin(),scores.rend());
    }
    for(auto i : scores) {
        cout<<1-i[1]<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

