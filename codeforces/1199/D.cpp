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
    int q;
    cin>>q;
    vector<vector<int>> b(q);
    for(auto &i : b) {
        int key;
        cin>>key;
        if(key==1) {
            int p, x;
            cin>>p>>x;
            p--;
            i={p, x};
        } else {
            int x;
            cin>>x;
            i={x};
        }
    }
    vector<int> last(n, -1), highest(q);
    int curr=0;
    for(int i=q-1; i>=0; i--) {
        if((int)b[i].size()==1) {
            curr=max(curr, b[i][0]);
        } else {
            last[b[i][0]]=max(last[b[i][0]], i);
        }
        highest[i]=curr;
    }
    for(int i=0; i<n; i++) {
        if(last[i]>=0) {
            a[i]=b[last[i]][1];
        }
        last[i]=max(last[i], 0);
        a[i]=max(a[i], highest[last[i]]);
        cout<<a[i]<<" ";
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

