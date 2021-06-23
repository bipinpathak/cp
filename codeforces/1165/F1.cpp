#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(vector<int> need, vector<vector<int>> &discount, int days) {
    int n=(int)discount.size(), total=days, left=0;
    for(int i=n-1; i>=0; i--) {
        if(discount[i][0]>days) {
            continue;
        }
        int extra=max(0, total-discount[i][0]);
        left+=extra;
        total-=extra;
        int use=min(need[discount[i][1]], total);
        need[discount[i][1]]-=use;
        total-=use;
    }
    left+=total;
    for(auto i : need) {
        left-=2*i; 
    }
    return left>=0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> need(n);
    vector<vector<int>> discount(m, vector<int> (2));
    int all=0;
    for(auto &i : need) {
        cin>>i;
        all+=i;
    }
    for(auto &i : discount) {
        for(auto &j : i) {
            cin>>j;
        }
        i[1]--;
    }
    sort(discount.begin(), discount.end());
    int low=1, high=2*all;
    while(low<high) {
        int mid=low+(high-low)/2;
        if(possible(need, discount, mid)) {
            high=mid;
        } else {
            low=mid+1;
        }
    }
    cout<<low<<endl;
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

