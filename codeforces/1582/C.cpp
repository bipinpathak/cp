#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool check(vector<int> &a) {
    int n=(int)a.size();
    for(int i=0; i<n-1-i; i++) {
        if(a[i]!=a[n-1-i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        char c;
        cin>>c;
        i=c-'a';
    }
    int ans=n+1;
    if(check(a)) {
        ans=0;
    } else for(int i=0; i<26; i++) {
        vector<int> temp;
        for(auto j : a) {
            if(j!=i) {
                temp.push_back(j);
            }
        }
        if(!check(temp)) {
            continue;
        }
        int offer=0, left=0, right=n-1;
        while(left<right) {
            if(a[left]!=a[right]) {
                if(a[left]==i) {
                    right++;
                } else {
                    left--;
                }
                offer++;
            }
            left++;
            right--;
        }
        ans=min(ans, offer);
    }
    if(ans==n+1) {
        ans=-1;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

