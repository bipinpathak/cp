#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    string s, t;
    cin>>s>>t;
    set<char> vowels={'a', 'e', 'i', 'o', 'u'};
    if(s.length()!=t.length()) {
        return false;
    }
    int n=s.length();
    for(int i=0; i<n; i++) {
        int count=0;
        if(vowels.find(s[i])==vowels.end()) {
            count++;
        }
        if(vowels.find(t[i])==vowels.end()) {
            count++;
        }
        count%=2;
        if(count) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        if(solve()) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

