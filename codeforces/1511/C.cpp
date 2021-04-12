#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    vector<int> index(50, n);
    for(int i=0; i<n; i++) {
        index[a[i]]=min(index[a[i]], i);
    }
    while(q--) {
        int t;
        cin>>t;
        t--;
        cout<<index[t]+1<<" ";
        for(auto &i : index) {
            if(i<index[t]) {
                i++;
            }
        }
        index[t]=0;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

