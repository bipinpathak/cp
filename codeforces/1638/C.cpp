#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    stack<int> available;
    for(int i=n-1; i>=0; i--) {
        if(available.empty() || a[i]<available.top()) {
            available.push(a[i]);
        } else {
            int curr=available.top();
            while(!available.empty() && a[i]>available.top()) {
                available.pop();
            }
            available.push(curr);
        }
    }
    cout<<available.size()<<endl;
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

