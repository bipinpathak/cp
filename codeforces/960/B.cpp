#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, j;
    long long ans=0, temp, k;
    cin>>n>>k>>temp;
    k+=temp;
    vector<long long> a(n);
    for(auto &i : a) cin>>i;
    for(i=0; i<n; i++) {
        cin>>temp;
        a[i]=abs(a[i]-temp);
    }
    a.push_back(0);
    sort(a.begin(), a.end(), greater<int>());
    for(i=0; i<n; i++) {
        if(a[i]==a[i+1]) continue;
        if((a[i]-a[i+1])*(i+1)<=k) {
            k-=(a[i]-a[i+1])*(i+1);
            for(j=0; j<=i; j++) a[j]=a[i+1];
        } else {
            temp=k/(i+1);
            for(j=0; j<=i; j++) a[j]-=temp;
            k-=temp*(i+1);
            for(j=0; j<k; j++) a[i-j]--;
            k=0;
            break;
        }
    }
    for(auto i : a) ans+=i*i;
    if(k%2) ans++;
    cout<<ans<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

