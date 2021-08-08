#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, w, n;
    cin>>h>>w>>n;
    vector<vector<int>> a(n, vector<int> (2));
    map<int, int> row, col;
    for(auto &i : a) {
        cin>>i[0]>>i[1];
        i[0]--, i[1]--;
        row[i[0]]++;
        col[i[1]]++;
    }
    map<int, int> newRow, newCol;
    int curr=0;
    for(auto i : row) {
        newRow[i.first]=curr;
        curr++;
    }   
    curr=0;
    for(auto i : col) {
        newCol[i.first]=curr;
        curr++;
    }
    for(auto i : a) {
        cout<<newRow[i[0]]+1<<" "<<newCol[i[1]]+1<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

