#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<int> ansRow(n), ansCol(m);
    int curr=1e9;
    for(int r=0; r<=a[0][0]; r++) {
        vector<int> row(n), col(m);
        row[0]=r;
        bool possible=true;
        for(int j=0; j<m && possible; j++) {
            col[j]=a[0][j]-row[0];
            possible=col[j]>=0;
        }
        for(int i=1; i<n && possible; i++) {
            row[i]=a[i][0]-col[0];
            possible=row[i]>=0;
        }
        for(int i=0; i<n && possible; i++) {
            for(int j=0; j<m && possible; j++) {
                possible=(a[i][j]==(row[i]+col[j]));
            }
        }
        if(possible) {
             int count=0;
             for(auto k : row) {
                count+=k;
             }
             for(auto k : col) {
                count+=k;
             }
             if(count<curr) {
                ansRow=row;
                ansCol=col;
                curr=count;
             }      
        }
    }
    if(curr!=1e9) {
        cout<<curr<<endl;
        for(int k=0; k<n; k++) {
            while(ansRow[k]--) {
                cout<<"row "<<k+1<<endl;
             }
        }
        for(int k=0; k<m; k++) {
            while(ansCol[k]--) {
                cout<<"col "<<k+1<<endl;
            }
        }
      return;
    }
    cout<<-1<<endl;
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

