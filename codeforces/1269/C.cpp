#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k, i;
    string x;
    cin>>n>>k>>x;
    vector<int> a(n);
    for(i=0; i<n; i++) {
        a[i]=x[i]-'0';
    }
    vector<int> digits(k, -1);
    for(i=0; i<n; i++) {
        if(digits[i%k]==-1) digits[i%k]=a[i];
        else if(digits[i%k]!=a[i]) break;
    }
    if(i<n && digits[i%k]<a[i]) {
        reverse(digits.begin(), digits.end());
        int carry=1;
        for(i=0; i<k; i++) {
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
            if(carry==0) break;
        }
        reverse(digits.begin(), digits.end());
    }
    cout<<n<<endl;
    for(i=0; i<n; i++) cout<<digits[i%k];
    cout<<endl;
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

