#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin>>n>>m;
    vector<int> count(60);
    ll total=0;
    while(m--) {
        int a;
        cin>>a;
        total+=a;
        int index=-1;
        while(a) {
            index++;
            a>>=1;
        }
        count[index]++;
    }
    if(total<n) {
        cout<<-1<<endl;
        return;
    }
    vector<int> target(60);
    for(int i=0; i<60; i++) {
        if(n&((ll)1<<i)) {
            target[i]++;
        }
    }
    int ans=0;
    for(int i=0; i<60; i++) {
        while(target[i] && count[i]) {
            target[i]--;
            count[i]--;
        }
        while(target[i]) {
            int high=i;
            while(count[high]==0) {
                high++;
            }
            while(high>i) {
                count[high]--;
                count[high-1]+=2;
                ans++;
                high--;
            }
            target[i]--;
            count[i]--;
        }
        while(i+1<60 && count[i]>1) {
            count[i]-=2;
            count[i+1]++;
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

