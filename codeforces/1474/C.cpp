#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> go(int x, map<int, int> f) {
    vector<int> ans;
    while(!f.empty()) {
        int high=f.rbegin()->first;
        if(f[x-high]-(x==2*high)) {
            ans.push_back(high);
            ans.push_back(x-high);
            f[high]--;
            f[x-high]--;
            if(f[high]==0) {
                f.erase(high);
            }
            if(f[x-high]==0) {
                f.erase(x-high);
            }
            x=high;
            continue;
        }
        break;
    }
    return ans;
}   

void solve() {
    int n;
    cin>>n;
    n*=2;
    map<int, int> f;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        f[i]++;
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    bool found=false;
    for(int i=0; i<n-1 && !found; i++) {
        ans.clear();
        ans=go(a[i]+a[n-1], f);
        if((int)ans.size()==n) {
            found=true;
        }
    }
    if(!found) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl<<ans[0]+ans[1]<<endl;
    int count=0;
    for(auto i : ans) {
        cout<<i<<" ";
        count++;
        if(count==2) {
            cout<<endl;
            count=0;
        }
    }
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

