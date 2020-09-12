#include <bits/stdc++.h>
using namespace std;
bool custom(long long a, long long b) {
    return a>b;
}
void solve() {
    int n, i, j, zero=0;
    cin>>n;
    vector<long long> positive, negative;
    for(i=0; i<n; i++) {
        cin>>j;
        if(j>0) positive.push_back(j);
        else if(j<0) negative.push_back(j);
        else zero++;
    }
    sort(positive.begin(), positive.end(), custom);
    sort(negative.begin(), negative.end());
    long long ans=-243*1e15, temp;
    if(zero) ans=0;
    for(j=0; j<=5; j++) {
        if((int) negative.size()>=j && (int) positive.size()>=5-j) {
            temp=1;
            if(j%2==0) for(i=0; i<j; i++) temp*=negative[i];
            else for(i=(int)negative.size()-1; i>=(int)negative.size()-j; i--) temp*=negative[i];
            for(i=0; i<5-j; i++) temp*=positive[i];
            ans=max(ans, temp);
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

