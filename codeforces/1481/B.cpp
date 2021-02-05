#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    bool flat=true;
    for(int i=0; i<n-1 && flat; i++) {
        if(a[i]!=a[i+1]) {
            flat=false;
        }
    }
    int last=-1;
    while(k) {
        last=-1;
        for(int i=0; i<n-1; i++) {
            if(a[i]<a[i+1]) {
                a[i]++;
                last=i+1;
                break;
            }
        }
        if(last==-1) {
            break;
        }
        k--;
    }
    cout<<last<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

