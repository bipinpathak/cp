#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    n*=2;
    vector<vector<int>> a(n, vector<int> (2));
    for(int i=0; i<n; i++) {
        cin>>a[i][0];
        a[i][1]=i;
    }
    sort(a.begin(), a.end());
    for(int i=0; 2*i<n; i++) {
        a[a[i][1]][0]*=-1; 
    }
    string ans(n, '(');
    int pos=0, neg=0;
    for(int i=0; i<n; i++) {
        if(a[i][0]<0) {
            if(pos) {
                ans[i]=')';
                pos--;
            } else {
                neg++;
            }
        } else {
            if(neg) {
                ans[i]=')';
                neg--;
            } else {
                pos++;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

