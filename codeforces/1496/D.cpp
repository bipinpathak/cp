#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> left(n), right(n);
    for(int i=1; i<n; i++) {
        left[i]=0;
        if(a[i]>a[i-1]) {
            left[i]=1+left[i-1];
        }   
    }
    for(int i=n-2; i>=0; i--) {
        right[i]=0;
        if(a[i]>a[i+1]) {
            right[i]=1+right[i+1];
        }
    }
    int ans=0, highest=0, count=0;
    for(int i=0; i<n; i++) {
        if(left[i]>highest) {
            highest=left[i];
            count=0;
        }
        if(right[i]>highest) {
            highest=right[i];
            count=0;
        }
        count+=left[i]==highest;
        count+=right[i]==highest;
    }
    for(int i=0; i<n; i++) {
        if(right[i]==0 || left[i]==0) {
            continue;
        }
        int curr=0;
        curr+=right[i]==highest;
        curr+=left[i]==highest;
        if(right[i]==left[i] && left[i]%2==0 && curr==count) {
            ans++;
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
    while(t--) {
        solve();
    }
    return 0;
}

