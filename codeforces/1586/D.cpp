#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int ask(vector<int> &a) {
    cout<<"?";
    for(auto i : a) {
        cout<<" "<<i;
    }
    cout<<endl;
    int res;
    cin>>res;
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<int> ans(n), a(n, 1);
    int res=n;
    for(int i=0; i<n && res; i++) {
        a.back()++;
        if(a.back()>n) {
            break;
        }
        res=ask(a);
    }
    ans[n-1]=n+2-a[n-1];
    a[n-1]=1;
    for(int target=ans[n-1]+1; target<=n; target++) {
        a[n-1]++;
        ans[ask(a)-1]=target;
    }
    a[n-1]=1;
    for(int target=ans[n-1]-1; target; target--) {
        for(int i=0; i<n-1; i++) {
            a[i]++;
        }
        ans[ask(a)-1]=target;
    }
    cout<<"!";
    for(auto i : ans) {
        cout<<" "<<i;
    }
    cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
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

