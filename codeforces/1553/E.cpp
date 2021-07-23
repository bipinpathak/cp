#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calc(vector<int> &a, int shift) {
    int n=(int)a.size(), ans=0;    
    vector<int> done(n, 0);
    for(int i=0; i<n; i++) {
        int curr=a[i], count=0;
        while(!done[curr]) {
            done[curr]=1;
            count++;
            curr=a[(curr+shift)%n];
        }
        ans+=max(0, count-1);
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    vector<int> same(n);
    for(int i=0; i<n; i++) {
        int x=i-a[i];
        if(x<0) {
            x+=n;
        }
        same[x]++;
    }
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(same[i]+2*m>=n && calc(a, i)<=m) {
            ans.push_back(i);
        }
    }
    cout<<ans.size();
    for(auto i : ans) {
        cout<<" "<<i;
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

