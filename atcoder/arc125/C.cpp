#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(k);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> ans, used(n+1);
    a.pop_back();
    int low=1;
    for(auto &i : a) {
        ans.push_back(i);
        used[i]=1;
        while(low<i && used[low]) {
            low++;
        }
        if(low<i && !used[low]) {
            ans.push_back(low);
            used[low]=1;
        }
    }
    while(n) {
        if(!used[n]) {
            ans.push_back(n);
            used[n]=1;
        }
        n--;
    }
    for(auto &i : ans) {
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

