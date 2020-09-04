#include <bits/stdc++.h>
using namespace std;
void solve() {
    unsigned long long n, ans=1e18, s, temp, sum=0;
    cin>>n>>s;
    vector<int> a(20,0), b;
    int i, j;
    temp=n;
    for(i=0; i<20; i++) {
        a[i]=temp%10;
        sum+=a[i];
        temp/=10;
    }
    if(sum<=s) {
        ans=0;
    }
    for(i=0; i<20; i++) {
         b=a;
         for(j=0; j<i; j++) b[j]=0;
         b[j]++;
         while(b[j]==10) {
            b[j]=0;
            b[j+1]++;
            j++;
         }
         temp=0;
         sum=0;
         for(j=19; j>=0; j--) {
            temp=temp*10+b[j];
            sum+=b[j];
         }
         if(sum<=s) {
            ans=min(ans, temp-n);
         }
    }
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

