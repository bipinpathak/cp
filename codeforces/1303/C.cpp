#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int index=25, n=(int)s.size();
    vector<int> ans(52, -1);
    ans[index]=s[0]-'a';
    set<int> seen;
    seen.insert(ans[index]);
    for(int i=1; i<n; i++) {
        int curr=s[i]-'a';
        if(index+1<52 && curr==ans[index+1]) {
            index++;
        } else if(index-1>=0 && curr==ans[index-1]) {
            index--;
        } else if(index+1<52 && ans[index+1]==-1 && !seen.count(curr)) {
            ans[index+1]=curr;
            index++;
        } else if(index-1>=0 && ans[index-1]==-1 && !seen.count(curr)) {
            ans[index-1]=curr;
            index--;
        } else {
            cout<<"NO"<<endl;
            return;
        }
        seen.insert(curr);
    }
    cout<<"YES"<<endl;
    s="";
    for(auto i : ans) {
        if(i>=0) {
            char curr='a';
            curr+=i;
            s.push_back(curr);
        }   
    }
    for(int i=0; i<26; i++) {
        if(!seen.count(i)) {
            char curr='a';
            curr+=i;
            s.push_back(curr);
        }
    }
    cout<<s<<endl;
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

