#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll A, S;
    cin>>A>>S;
    vector<int> a, s, b;
    while(A) {
        a.push_back(A%10);
        A/=10;
    }
    reverse(a.begin(), a.end());
    while(S) {
        s.push_back(S%10);
        S/=10;
    }
    reverse(s.begin(), s.end());
    while(!a.empty() || !s.empty()) {
        if(s.empty()) {
            cout<<-1<<endl;
            return;
        }
        int ai=0, si=s.back(), bi;
        s.pop_back();
        if(!a.empty()) {
            ai=a.back();
            a.pop_back();
        }
        if(si<ai) {
            if(s.empty()) {
                cout<<-1<<endl;
                return;
            }
            si+=s.back()*10;
            s.pop_back();
        }
        bi=si-ai;
        if(bi<0 || bi>9) {
            cout<<-1<<endl;
            return;
        }
        b.push_back(bi);
    }
    reverse(b.begin(), b.end());
    ll B=0;
    for(auto i : b) {
        B=B*10 + i;
    }
    cout<<B<<endl;
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

