#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool possible(vector<int> curr, vector<vector<int>> &a, int &c) {
    set<int> colors;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            colors.insert(a[curr[0]+i][curr[1]+j]);
        }
    }
    colors.erase(0);
    if(colors.size()==1) {
        c=*colors.begin();
        return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m)), done;
    done=a;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<int>> available;
    for(int i=0; i+1<n; i++) {
        for(int j=0; j+1<m; j++) {
            int c=0;
            if(possible({i, j}, a, c)) {
                available.push_back({i, j, c-1});
                done[i][j]=1;
            }
        }
    }
    vector<vector<int>> ans;
    while(!available.empty()) {
        auto curr=available.back();
        ans.push_back(curr);
        available.pop_back();
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                a[curr[0]+i][curr[1]+j]=0;
            }   
        }
        for(int i=-1; i<2; i++) {
            for(int j=-1; j<2; j++) {
                int x=curr[0]+i, y=curr[1]+j;
                if(min(x, y)<0 || x+1>=n || y+1>=m || done[x][y]) {
                    continue;
                }
                int c=0;
                if(possible({x, y}, a, c)) {
                    available.push_back({x, y, c-1});
                    done[x][y]=1;
                }
            }
        }
    }
    for(auto &i : a) {
        for(auto &j: i) {
            if(j) {
                cout<< -1<<'\n';
                return;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto &i : ans) {
        for(auto &j : i) {
            cout<<j+1<<" ";
        }
        cout<<'\n';
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

