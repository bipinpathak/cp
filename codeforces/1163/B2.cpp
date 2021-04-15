#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, high=0;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        high=max(high, i);
        i--;
    }
    set<int> seen;
    vector<int> countFrequency(n+1), colorCount(high);
    int ans=0;
    for(int i=0; i<n; i++) {
        countFrequency[colorCount[a[i]]]--;
        colorCount[a[i]]++;
        countFrequency[colorCount[a[i]]]++;
        seen.insert(a[i]);
        int temp=(int)seen.size();
        if(i%temp==0 && countFrequency[i/temp]==temp-1) {
            ans=i+1;
        } else if(temp>1 && i%(temp-1)==0 && countFrequency[i/(temp-1)]==temp-1) {
            ans=i+1;
        } else if(temp==i+1) {
            ans=i+1;
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

