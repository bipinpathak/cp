#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    int all=(1<<9);
    vector<int> happy(all);
    while(n--) {
        int s, i=0;
        cin>>s;
        while(s--) {
            int b;
            cin>>b;
            b--;
            i+=(1<<b);
        }
        happy[i]++;
    }
    for(int i=all-1; i; i--) {
        if(!happy[i]) {
            continue;
        }
        for(int j=i+1; j<all; j++) {
            if((i&j)==i) {
                happy[j]+=happy[i];
            }
        }
    }
    vector<int> singlePrice(all, 1e9+1), singleIndex(all, -1), doublePrice(all, 2e9+1);
    vector<vector<int>> doubleIndex(all);
    for(int i=0; i<m; i++) {
        int c, f, val=0;
        cin>>c>>f;
        while(f--) {
            int b;
            cin>>b;
            b--;
            val+=(1<<b);
        }   
        for(int j=0; j<all; j++) {
            if(singleIndex[j]==-1) {
                continue;
            }
            int join=(val|j);
            if(doublePrice[join]>singlePrice[j]+c) {
                doublePrice[join]=singlePrice[j]+c;
                doubleIndex[join]={singleIndex[j], i};
            }
        }
        if(singlePrice[val]>c) {
            singlePrice[val]=c;
            singleIndex[val]=i;
        }
    }
    int maxHappy=0, first=0, second=1, cost=2e9+1;
    for(int i=0; i<all; i++) {
        if(doubleIndex[i].empty()) {
            continue;
        }
        if(happy[i]>maxHappy || (happy[i]==maxHappy && doublePrice[i]<cost)) {
            maxHappy=happy[i];
            cost=doublePrice[i];
            first=doubleIndex[i][0];
            second=doubleIndex[i][1];
        }
    }
    cout<<first+1<<" "<<second+1<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

