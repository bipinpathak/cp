#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    set<int> x;
    for(auto &i : a) {
        cin>>i;
        x.insert(i);
    }       
    sort(a.begin(), a.end());
    int mex=0, high=a.back();
    for(auto i : a) {
        if(i==mex) {
            mex++;
        }
    }
    int add=(mex+high+1)/2;
    if(mex==high+1 || k==0) {
        cout<<x.size()+k<<endl;
    } else {
        x.insert(add);
        cout<<x.size()<<endl;
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
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

