#include <bits/stdc++.h>
using namespace std;
int fetch(vector<long long>&axis, int i) {
    int ans=0;
    while(i) {
        ans+=axis[i];
        i-=i&(-i);
    }
    return ans;
}
void add(vector<long long>& axis, int i) {
    int n=axis.size();
    while(i<n) {
        axis[i]+=1;
        i+=i&(-i);
    }
}
void solve() {
    int n, i;
    long long t, ans=0;
    cin>>n>>t;
    vector<long long> prefix(n);
    for(i=0; i<n; i++) {
        cin>>prefix[i];
        if(i) prefix[i]+=prefix[i-1];
        if(prefix[i]<t) ans+=1;
    }
    vector<long long> axis;
    axis=prefix;
    for(i=0; i<n; i++) {
        axis.push_back(prefix[i]-t);
    }
    unordered_map<long long, int> valToIndex;
    sort(axis.begin(), axis.end());
    for(i=0; i<(int)axis.size(); i++) {
        valToIndex[axis[i]]=i+1;
        axis[i]=0;
    }
    axis.push_back(0);
    for(i=0; i<n; i++) {
        ans+=fetch(axis,2*n)-fetch(axis, valToIndex[prefix[i]-t]);
        add(axis, valToIndex[prefix[i]]);
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
//    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

