#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> calc(vector<int> &total, vector<int> &use) {
    vector<vector<int>> ans(2, total);
    ans[0][1]=use[0]-1;
    ans[1][0]=use[1]+1;
    return ans;
}

int fetch(vector<int> &total, vector<vector<int>> &moves, vector<vector<int>> &grundy) {
    if(total[0]>total[1]) {
        return 0;
    }
    if(grundy[total[0]][total[1]]==-1) {
        grundy[total[0]][total[1]]=0;
        set<int> have;
        for(auto &i : moves) {
            if(total[0]<=i[0] && i[1]<=total[1]) {
                auto next=calc(total, i);
                int curr=0;
                curr^=fetch(next[0], moves, grundy);
                curr^=fetch(next[1], moves, grundy);
                have.insert(curr);
            }
        }
        while(have.count(grundy[total[0]][total[1]])) {
            grundy[total[0]][total[1]]++;
        }
    }
    return grundy[total[0]][total[1]];
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
            j--;
        }
        i[1]--;
    }
    vector<vector<int>> grundy(100, vector<int> (100, -1));
    vector<int> total={0, 99};
    string ans="Bob";
    if(fetch(total, a, grundy)) {
        ans="Alice";
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

