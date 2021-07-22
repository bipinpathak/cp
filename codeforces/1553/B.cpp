#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin>>s>>t;
    int n=(int)s.length(), m=(int)t.length();
    vector<vector<int>> forward(n, vector<int> (m, 0)), backward;
    backward=forward;
    for(int i=0; i<n; i++) {
        for(int j=0; i+j<n && j<m; j++) {
            if(s[i+j]==t[j]) {
                forward[i+j][j]=1;
            } else {
                break;
            }
        }
        for(int j=0; j<m && i+j<n; j++) {
            if(s[i+j]==t[m-1-j]) {
                backward[i+j][m-1-j]=1;
            } else {
                break;
            }
        }
    }
    string ans="NO";
    for(int i=0; i<n && ans=="NO"; i++) {
        if(forward[i][m-1] || backward[i][0]) {
            ans="YES";
        }
        for(int j=0; i && j+1<m && ans=="NO"; j++) {
            if(forward[i][j] && backward[i-1][j+1]) {
                ans="YES";
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

