#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<set<int>> have(n);
    for(int i=0; i<n-2; i++) {
        vector<int> q(3);
        for(auto &j : q) {
            cin>>j;
            j--;
        }
        for(int j=0; j<3; j++) {
            for(int k=j+1; k<3; k++) {
                have[q[j]].insert(q[k]);
                have[q[k]].insert(q[j]);
            }
        }
    }
    int start=-1;
    for(int i=0; i<n; i++) {
        if((int)have[i].size()==2) {
            start=i;
            break;
        }
    }
    vector<int> ans;
    ans.push_back(start);
    for(auto i : have[start]) {
        ans.push_back(i);
    }
    if(have[ans[1]].size()>have[ans[2]].size()) {
        swap(ans[1], ans[2]);
    }
    set<int> used;
    used.insert({ans[0], ans[1], ans[2]});
    for(int i=3; i<n; i++) {
        for(auto j : have[ans[i-2]]) {
            if(used.find(j)==used.end()) {
                ans.push_back(j);
                break;
            }
        }
        used.insert(ans.back());
    }
    for(auto i: ans) {
        cout<<i+1<<" ";
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
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

