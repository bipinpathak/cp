#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> original(n), want(n), painters(m);
    for(auto &i : original) {
        cin>>i;
    }
    for(auto &i : want) {
        cin>>i;
    }
    for(auto &i : painters) {
        cin>>i;
    }
    int escapeGoat=-1;
    for(int i=0; i<n; i++) {
        if(original[i]!=want[i] && want[i]==painters[m-1]) {
            escapeGoat=i;
            break;
        }
    }
    for(int i=0; i<n && escapeGoat==-1; i++) {
        if(want[i]==painters[m-1]) {
            escapeGoat=i;
            break;
        }
    }   
    if(escapeGoat==-1) {
        cout<<"NO"<<endl;
        return;
    }
    map<int, vector<int>> todo;
    for(int i=0; i<n; i++) {
        if(original[i]!=want[i]) {
            todo[want[i]].push_back(i);
        }               
    }
    vector<int> ans(m);
    for(int i=0; i<m; i++) {
        if(todo.find(painters[i])==todo.end()) {
            ans[i]=escapeGoat;
            continue;
        }
        ans[i]=todo[painters[i]].back();
        todo[painters[i]].pop_back();
        if(todo[painters[i]].empty()) {
            todo.erase(painters[i]);
        }
        original[ans[i]]=want[ans[i]];
    }       
    for(int i=0; i<n; i++) {
        if(original[i]!=want[i]) {
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
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

