#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int calc(int i, int j, vector<vector<char>> &a) {
    int ans=0, m=(int)a.front().size();
    while(i-ans>=0 && j-ans>=0 && j+ans<m) {
        if(a[i-ans][j-ans]!='*' || a[i-ans][j+ans]!='*') {
            break;
        }
        ans++;
    }
    ans--;
    return ans;
}

void fill(int i, int j, int d, vector<vector<char>> &a) {
    while(d>=0) {
        a[i-d][j-d]='*';
        a[i-d][j+d]='*';
        d--;
    }
    return;
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<char>> a(n, vector<char> (m));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<char>> b(n, vector<char> (m, '.'));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j]=='.') {
                continue;
            }   
            int d=calc(i, j, a);
            if(d>=k) {
                fill(i, j, d, b);
            }
        }   
    }
    string ans=(a==b)?"YES":"NO";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

