#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool peak(int index, vector<int> &a) {
    int n=(int)a.size();
    if(index-1>=0 && index+1<n) {
        return (a[index]>a[index-1] && a[index]>a[index+1]);   
    }
    return false;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int m=0;
    for(int i=1; i+1<n; i++) {
        if(peak(i-1, a) && peak(i+1, a)) {
            m++;
            a[i]=max(a[i-1],a[i+1]);
        }
    }
    for(int i=0; i<n; i++) {
        if(peak(i, a)) {
            m++;
            a[i]=max(a[i-1],a[i+1]);
        }
    }
    cout<<m<<endl;
    for(auto &i : a) {
        cout<<i<<" ";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

