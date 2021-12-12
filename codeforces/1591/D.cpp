#include "bits/stdc++.h"
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
    auto b=a;
    sort(b.begin(), b.end());
    vector<int> index(n);
    for(int i=1; i<n; i++) {
        if(b[i]==b[i-1]) {
            cout<<"YES"<<endl;
            return;
        }
        index[a[i]]=i;
    }
    for(int i=n-1; i>=2; i--) {
        if(index[b[i]]==i) {
            continue;
        }
        int x=index[b[i]], y=x==0;
        swap(a[x], a[i]);
        swap(a[y], a[x]);
        index[a[y]]=y;
        index[a[x]]=x;
        index[a[i]]=i;
    }
    string ans="YES";
    if(n>1 && a[0]>a[1]) {
        ans="NO";
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

