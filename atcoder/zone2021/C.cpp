#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(int target, vector<vector<int>> &a) {
    set<int> seen;
    for(auto i : a) {
        int curr=0;
        for(int j=0; j<5; j++) {
            if(i[j]>=target) {
                curr+=(1<<j);
            }
        }
        seen.insert(curr);
    }
    for(auto i : seen) {
        for(auto j : seen) {
            for(auto k : seen) {
                if((i|j|k)==(1<<5)-1) {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (5));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int low=1, high=1e9;
    while(low<high) {
        int mid=(low+high+1)/2;
        if(possible(mid, a)) {
            low=mid;
        } else {
            high=mid-1;
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

