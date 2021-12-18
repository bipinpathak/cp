#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }       
    int ans=2e9;
    for(int one=0; one<=2; one++) {
        for(int two=0; two<=2; two++) {
            int offer=0;
            for(auto i : a) {
                int curr=2e9;
                for(int useOne=0; useOne<=one; useOne++) {
                    for(int useTwo=0; useTwo<=two; useTwo++) {
                        int left=i-useOne-2*useTwo;
                        if(left>=0 && left%3==0) {
                            curr=min(curr, left/3);
                        }
                    }
                }
                offer=max(offer, curr);
            }
            ans=min(ans, offer+one+two);
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

