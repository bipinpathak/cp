#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int calc(vector<int> &a) {
    int ans=0, n=(int)a.size(), offer=0;
    for(int i=0; i<2*n; i++) {
        int curr=i%n;
        if(a[curr]==0) {
            offer=0;
        } else {
            offer++;
        }
        ans=max(ans, offer);
    }
    if(ans>n) {
        ans=-1;
    }   
    return ans;
}

void solve() {
    int n, d;
    cin>>n>>d;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<vector<int>> elements;
    vector<int> done(n);
    for(int i=0; i<n; i++) {
        int curr=i;
        vector<int> build;
        while(!done[curr]) {
            build.push_back(a[curr]);
            done[curr]=1;
            curr=(curr+d)%n;
        }
        if(!build.empty()) {
            elements.push_back(build);
        }
    }
    int ans=0;
    for(auto &i : elements) {
        int curr=calc(i);
        if(curr==-1) {
            ans=-1;
            break;
        }
        ans=max(ans, curr);
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

