#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    map<int, int> f;
    while(n--) {
        int x;
        cin>>x;
        f[x]++;
    }
    vector<int> a;
    for(auto &i : f) {
        a.push_back(i.second);
    }
    sort(a.begin(), a.end());
    n=(int)a.size();
    int sum=0;
    for(int i=0; i<n-1; i++) {
        sum+=a[i];
    }
    int ans=0;
    if(sum>=a.back()) {
        sum+=a.back();
        if(sum%2) {
            ans++;
        }
    } else {
        ans=a.back()-sum;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

