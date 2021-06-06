#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void next(string &s) {
    if(s.empty()) {
        s="a";
    } else {
        int i=(int)s.length()-1;
        while(i>=0 && s[i]=='z') {
            s[i]='a';
            i--;
        }
        if(i==-1) {
            s.push_back('a');
        } else {
            s[i]++;
        }
    }
    return;
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    set<string> sub;
    for(int i=0; i<n; i++) {
        string curr="";
        for(int j=i; j<n; j++) {
            curr.push_back(s[j]);
            sub.insert(curr);
        }
    }
    string curr="a";
    while(sub.find(curr)!=sub.end()) {
        next(curr);
    }
    cout<<curr<<endl;
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

