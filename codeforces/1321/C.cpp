#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool possible(string &s) {
    int n=(int)s.size(), index=-1;
    for(int i=0; i<n; i++) {
        if(i+1<n && s[i+1]==s[i]+1) {
            if(index==-1 || s[i]>s[index]) {
                index=i;
            }
        }
        if(i-1>=0 && s[i-1]==s[i]+1) {
            if(index==-1 || s[i]>s[index]) {
                index=i;
            }
        }
    }
    if(index!=-1) {
        if(index+1<n && s[index+1]==s[index]+1) {
            index++;
        } else {
            index--;
        }
        s.erase(s.begin()+index);
        return true;
    }
    return false;
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    while(possible(s)) {
        ans++;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

