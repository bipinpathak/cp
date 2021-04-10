#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char> (n));
    for(auto &i : grid) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    pair<int, int> one, two;
    one={-1, -1};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j]=='*') {
                if(one.first==-1) {
                    one={i, j};
                } else {
                    two={i, j};
                }
            }
        }
    }
    if(one.first==two.first) {
        one.first=two.first=(one.first+1)%n;
    } else if(one.second==two.second) {
        one.second=two.second=(one.second+1)%n;
    } else {
        swap(one.second, two.second);
    }
    grid[one.first][one.second]=grid[two.first][two.second]='*';
    for(auto &i : grid) {
        for(auto &j : i) {
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
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

