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
    string ans="YES";
    map<int, int> hcf;
    hcf[2]=1;
    for(int i=0; i<n && ans=="YES"; i++) {
        ans="NO";
        for(auto &[p, c] : hcf) {
            int count=0;
            while(a[i]%p==0) {
                count++;
                a[i]/=p;
            }
            if(count<c) {
                ans="YES";
                break;
            }
        }
        a[i]=i+3;
        for(int j=2; j*j<=a[i]; j++) {
            int count=0;
            while(a[i]%j==0) {
                count++;
                a[i]/=j;
            }
            if(count) {
                hcf[j]=max(hcf[j], count);
            }
        }
        if(a[i]>1) {
            hcf[a[i]]=max(hcf[a[i]], 1);
        }
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

