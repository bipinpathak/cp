#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }   
    vector<int> incoming(n, -1);
    int count=0;
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++) {
        if(incoming[a[i]]==-1) {
            incoming[a[i]]=i;
            count++;
            ans[i]=a[i];
        }
    }
    int done=0;
    for(int i=0; i<n; i++) {
        if(ans[i]!=-1) {
            continue;
        }
        while(incoming[done]!=-1) {
            done++;
        }
        ans[i]=done;
        done++;
    }
    for(int i=0; i<n; i++) {
        if(ans[i]==i) {
            int other=incoming[a[i]];
            swap(ans[i], ans[other]);
        }
    }
    cout<<count<<endl;
    for(auto i : ans) {
        cout<<i+1<<" ";
    }
    cout<<endl;
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
