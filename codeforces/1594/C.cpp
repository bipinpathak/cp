#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void mark(vector<int> &a, int n) {
    for(int i=1; i*i<=n; i++) {
        if(n%i==0) {
            a[i]=a[n/i]=0;
        }
    }
    return;
}

void solve() {
    int n;
    char c;
    string s;
    cin>>n>>c>>s;
    vector<int> useful(n+1, 1), bad;
    for(int i=0; i<n; i++) {
        if(s[i]==c) {
            continue;
        }
        bad.push_back(i+1);
        mark(useful, i+1);
    }   
    vector<int> operations;
    if(bad.empty()) {
        cout<<0<<endl;
        return;
    }
    for(int i=1; i<=n; i++) {
        if(useful[i]) {
            operations.push_back(i);
            bad.clear();
            break;
        }
    }
    if(!bad.empty()) {
        if(bad.back()==n) {
            operations.push_back(n-1);
            bad.pop_back();
            while(!bad.empty() && bad.back()%operations.back()) {
                bad.pop_back();
            }
        }
        if(!bad.empty()) {
            operations.push_back(n);
        }
    }
    cout<<operations.size()<<endl;
    for(auto i : operations) {
        cout<<i<<" ";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

