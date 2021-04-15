#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> count(26);
    while(n--) {
        string s;
        cin>>s;
        count[s.front()-'a']++;
    }
    int ans=0;
    for(auto i : count) {
        int a=i/2, b=i-a;
        ans+=(a*(a-1))/2;
        ans+=(b*(b-1))/2;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

