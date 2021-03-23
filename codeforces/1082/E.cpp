#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin>>n>>c;
    c--;
    vector<int> a(n);
    vector<vector<int>> indexes(5e5);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        a[i]--;
        indexes[a[i]].push_back(i);
    }
    vector<int> left(n);
    int curr=0;
    for(int i=0; i<n; i++) {
        curr+=a[i]==c;
        left[i]=curr;
    }
    int ans=(int)indexes[c].size();
    if(ans!=n) {
        ans++;
    }
    for(auto num : indexes) {
        if(num.empty()) {
            continue;
        }
        n=(int)num.size();
        int low=0;
        for(int i=0; i<n; i++) {
            curr=i-low+1+(int)indexes[c].size();
            curr-=left[num[i]];
            if(num[low]) {
                curr+=left[num[low]-1];
            }
            ans=max(ans, curr);
            if(curr<=(int)indexes[c].size()) {
                low=i;
            }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

