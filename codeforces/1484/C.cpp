#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> day(m), person(n);
    vector<int> left(n, (m+1)/2), ans(m, -1), open(m, 0);
    set<vector<int>> active;
    for(int i=0; i<m; i++) {
        int k;
        cin>>k;
        while(k--) {
            int x;
            cin>>x;
            x--;
            day[i].push_back(x);
            person[x].push_back(i);
            open[i]++;
        }
    }
    for(int i=0; i<n; i++) {
        left[i]=min(left[i], (int) person[i].size());
        active.insert({left[i], i});
    }
    while(!active.empty()) {
        vector<int> curr=*(active.begin());
        active.erase(curr);
        set<vector<int>> chosen;
        for(auto v : person[curr[1]]) {
            if(ans[v]!=-1) {
                continue;
            }   
            chosen.insert({open[v], v});
        }
        while(!chosen.empty() && left[curr[1]]) {
            auto temp=*(chosen.begin());
            chosen.erase(temp);
            int chosenDay=temp[1];
            ans[chosenDay]=curr[1];
            left[curr[1]]--;
        }
        for(auto v : person[curr[1]]) {
            if(open[v]) {
                open[v]--;
            }
        }
    }
   for(auto i : ans) {
        if(i==-1) {
            cout<<"NO"<<endl;
            return;
        }   
   }
   cout<<"YES"<<endl;
   for(auto i : ans) {
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

