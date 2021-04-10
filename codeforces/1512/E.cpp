#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r, s;
    cin>>n>>l>>r>>s;
    l--, r--;
    map<int, int> used;
    int high=n, c=s;
    vector<int> ans(n);
    for(int i=r; i>=l; i--) {
        int t=i-l;
        while(used[high]) {
            high--;
        }
        ans[i]=min(s-((t*(t+1))/2), high);
        used[ans[i]]++;
        s-=ans[i];
    }
    for(int i=0; i<n; i++) {
        if(ans[i]!=0) {
            continue;
        }
        while(used[high]) {
            high--;
        }
        ans[i]=high;
        used[ans[i]]++;
    }
    for(int i=1; i<=n; i++) {
        if(used[i]!=1) {
            ans={-1};
            break;
        }
    }
    for(int i=l; i<=r; i++) {
        c-=ans[i];
    }
    if(c!=0) {
        ans={-1};
    }
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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

