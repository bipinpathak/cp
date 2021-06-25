#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> open(n, vector<int> (2)), segments(n, vector<int> (2));
    for(int i=0; i<n; i++) {
        cin>>segments[i][0]>>segments[i][1];
        open[i][0]=segments[i][0];
        open[i][1]=i;
    }
    sort(open.begin(), open.end());
    map<int, vector<int>> close;
    set<int> ans;
    int active=0;
    for(auto i : open) {
        int id=i[1], curr=i[0];
        close[segments[id][1]].push_back(id);
        active++;
        while(!close.empty() && close.begin()->first<curr) {
            active-=(int)close.begin()->second.size();
            close.erase(close.begin());
        }
        while(active>k) {
            int last=close.rbegin()->first, extra=close[last].back();
            ans.insert(extra);
            close[last].pop_back();
            if(close[last].empty()) {
                close.erase(last);
            }
            active--;
        }
    }
    cout<<ans.size()<<endl;
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

