#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void go(int u, vector<vector<int>> &sus, vector<vector<int>> &ok, vector<int> &real, vector<vector<int>> &meok, vector<vector<int>> &mesus, set<int> &visited, int &offer) {
    visited.insert(u);
    for(auto v : sus[u]) {
        if(!visited.count(v)) {
            real[v]=!real[u];
            go(v, sus, ok, real, meok, mesus, visited, offer);
        } else if(real[u]==real[v]) {
            offer=-1;
        }
        if(offer==-1) {
            return;
        }
    }   
    for(auto v : ok[u]) {
        if(!visited.count(v)) {
            real[v]=real[u];
            go(v, sus, ok, real,meok, mesus, visited, offer);
        } else if(real[u]!=real[v]) {
            offer=-1;
        }
        if(offer==-1) {
            return;
        }
    }
    for(auto v : mesus[u]) {
        if(!visited.count(v)) {
            real[v]=!real[u];
            go(v, sus, ok, real, meok, mesus, visited, offer);
        } else if(real[u]==real[v]) {
            offer=-1;
        }
        if(offer==-1) {
            return;
        }
    }   
    for(auto v : meok[u]) {
        if(!visited.count(v)) {
            real[v]=real[u];
            go(v, sus, ok, real,meok, mesus, visited, offer);
        } else if(real[u]!=real[v]) {
            offer=-1;
        }
        if(offer==-1) {
            return;
        }
    }
    offer+=!real[u];
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;  
    vector<int> real(n, -1);
    vector<vector<int>> sus(n), ok(n), mesus(n), meok(n);
    while(m--) {
        int i, j;
        string s;
        cin>>i>>j>>s;
        i--, j--;
        if(s[0]=='i') {
            sus[i].push_back(j);
            mesus[j].push_back(i);
        } else {
            ok[i].push_back(j);
            meok[j].push_back(i);
        }
    }
    set<int> visited;
    int ans=0;
    for(int i=0; i<n && ans!=-1; i++) {
        if(real[i]!=-1) {
            continue;
        }
        int offer1=0, offer2=0;
        real[i]=1;
        visited.clear();
        go(i, sus, ok, real, meok, mesus, visited, offer1);
        real[i]=0;
        visited.clear();
        go(i, sus, ok, real, meok, mesus, visited, offer2);
        offer1=max(offer1, offer2);
        if(offer1==-1) {
            ans=-1;
        } else {
            ans+=offer1; 
        }
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

