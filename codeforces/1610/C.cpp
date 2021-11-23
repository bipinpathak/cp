#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool possible(int k, vector<int> &a, vector<int> &b) {
    int count=0;
    for(int i=0; i<(int)a.size(); i++) {
        if(b[i]>=count && a[i]>=k-count-1) {
            count++;
        }
    }
    return count>=k;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) {
        cin>>a[i]>>b[i];
    }
    int low=0, high=n;
    while(low<high) {
        int mid=(low+high+1)/2;
        if(possible(mid, a, b)) {
            low=mid;
        } else {
            high=mid-1;
        }   
    }
    cout<<low<<endl;
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

