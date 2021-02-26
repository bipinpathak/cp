#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, w;
    cin>>h>>w;
    vector<string> grid(h);
    for(auto &i : grid) {
        cin>>i;
    }
    vector<vector<int>> up(h, vector<int> (w)), down, left, right;
    right=left=down=up;
    int total=0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(grid[i][j]=='*') {
                total++;
                up[i][j]=1+(i?up[i-1][j]:0);
                left[i][j]=1+(j?left[i][j-1]:0);
            }
        }
    }
    for(int i=h-1; i>=0; i--) {
        for(int j=w-1; j>=0; j--) {
            if(grid[i][j]=='*') {
                down[i][j]=1+(i<h-1?down[i+1][j]:0);
                right[i][j]=1+(j<w-1?right[i][j+1]:0);
                if(up[i][j]>1 && right[i][j]>1 && left[i][j]>1 && down[i][j]>1 && up[i][j]+down[i][j]+left[i][j]+right[i][j]==total+3) {
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

