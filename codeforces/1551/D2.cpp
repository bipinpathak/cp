#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<char>> grid(n, vector<char> (m, 'a'));
    for(int i=0; i+1<n; i+=2) {
        int start=!((i/2)%2);
        while(start<m) {
            grid[i][start]=grid[i+1][start]='b';
            start+=2;
        }
    }
    string ans="NO";
    int total=(n*m)/2;
    if(n%2 || m%2) {
        if(n%2) {
            total-=m/2;
            k-=m/2;
            char curr='c', prev='d';
            for(int j=0; j+1<m; j+=2) {
                grid[n-1][j]=grid[n-1][j+1]=curr;
                swap(curr, prev);
            }
            n--;
        } else {
            total-=n/2;
            m--;
        }
    }
    if(k%2==0 && k<=total && k>=0) {
        ans="YES";
        k=max(k, 0);
        for(int i=0; i+1<n && k; i+=2) {
            char curr='e', prev='f';
            for(int j=0; j+1<m && k; j+=2) {
                grid[i][j]=grid[i][j+1]=curr;
                grid[i+1][j]=grid[i+1][j+1]=prev;
                swap(curr, prev);
                k-=2;
            }
        }
    }
    cout<<ans<<endl;
    if(ans=="YES") {
        for(auto i : grid) {
            for(auto j : i) {
                cout<<j;
            }
            cout<<endl;
        }
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

