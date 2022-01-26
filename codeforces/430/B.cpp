#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k, x;
    cin>>n>>k>>x;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int ans=0;
    for(int i=0; i<n-1; i++) {
        if(!(a[i]==x && a[i+1]==x)) {
            continue;
        }
        int offer=2, left=i-1, right=i+2;
        while(left>=0 && right<n) {
            int color=a[left], count=0;
            while(left>=0 && a[left]==color) {
                count++;
                left--;
            }
            while(right<n && a[right]==color) {
                count++;
                right++;
            }
            if(count<3) {
                break;
            }
            offer+=count;
        }
        ans=max(ans, offer);
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

