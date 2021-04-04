#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int w, l;
    cin>>w>>l;
    vector<int> a(w), have(w);
    for(int i=0; i<w-1; i++) {
        cin>>a[i];
        if(i<l) {
            have[i]=a[i];
        }
    }
    a[w-1]=1e9;
    int left=0;
    for(int i=l; i<w; i++)  {
        while(left<i && a[i]>have[i]) {
            if(i-left<=l) {
                int transfer=min(have[left], a[i]-have[i]);
                have[left]-=transfer;
                have[i]+=transfer;
            }
            if(have[left]==0 || i-left>l) {
                left++;
            }
        }
    }
    cout<<have[w-1]<<endl;
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

