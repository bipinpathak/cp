#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> ans;
    int left=0, right=n-1;
    while(left<right) {
        if(s[left]=='0') {
            left++;
        } else if(s[right]=='1') {
            right--;
        } else {
            ans.push_back(left);
            ans.push_back(right);
            left++;
            right--;
        }
    }
    if(ans.empty()) {
        cout<<0<<endl;
        return;
    }
    cout<<1<<endl<<ans.size();
    sort(ans.begin(), ans.end());
    for(auto i : ans) {
        cout<<" "<<i+1;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

