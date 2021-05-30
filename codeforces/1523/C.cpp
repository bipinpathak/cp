#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<vector<int>> ans(n, vector<int> (n));
    int index=0;
    ans[0][0]=1;
    for(int i=1; i<n; i++) {
        if(a[i]==1) {
            index++;
        } else if(a[i]!=a[i-1]+1) {
            while(ans[i-1][index]!=a[i]-1) {
                index--;
            }
        }   
        ans[i][index]=a[i];
        for(int j=index-1; j>=0 && i; j--) {
            ans[i][j]=ans[i-1][j];
        }
    }
    for(int i=0; i<n; i++) {
        cout<<ans[i][0];
        for(int j=1; j<n && i; j++) {
            if(ans[i][j]==0) {
                break;
            }
            cout<<"."<<ans[i][j];
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

