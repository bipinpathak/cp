#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), next(n), ans;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        next[i]=i+1;
    }
    next[n-1]=0;
    deque<int> order;
    for(int i=0; i<n; i++) {
        if(__gcd(a[i], a[next[i]])==1) {
            order.push_back(i);
        }
    }
    while(!order.empty()) {
        int i=order.front();
        order.pop_front();
        if(a[i]==0) {
            continue;
        }
        ans.push_back(next[i]);
        a[next[i]]=0;
        next[i]=next[next[i]];
        if(__gcd(a[i], a[next[i]])==1) {
            order.push_back(i);
        }
    }
    cout<<ans.size();
    for(auto i :ans) {
        cout<<" "<<i+1;
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
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

