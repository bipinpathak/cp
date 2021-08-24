#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int r, int c, vector<string> &a) {
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1;j++) {
            if(i==0 && j==0) {
                continue;
            }
            if(a[r+i][c+j]=='.') {
                return false;
            }
        }   
    }
    return true;
}   

void fill(int r, int c, vector<string> &a, vector<string> &build) {
    if(!check(r, c, a)) {
        return;
    }
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1;j++) {
            if(i==0 && j==0) {
                continue;
            }
            build[r+i][c+j]='#';
        }   
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<string> build(n, string (m, '.'));
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            fill(i, j, a, build); 
        }
    }
    string ans="YES";
    for(int i=0; i<n && ans=="YES"; i++) {
        for(int j=0; j<m && ans=="YES"; j++) {
            if(a[i][j]!=build[i][j]) {
                ans="NO";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

