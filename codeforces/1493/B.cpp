#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<int> bad={3, 4, 6, 7, 9};
int h, m;
vector<vector<int>> mirror={{0, 0}, {1, 1}, {2, 5}, {5, 2}, {8, 8}};

bool good(int x, int y) {
    int a=x, b=y, c=x, d=y;
    while(x) {
        if(bad.find(x%10)!=bad.end()) {
            return false;
        }       
        x/=10;
    }       
    while(y) {
        if(bad.find(y%10)!=bad.end()) {
            return false;
        }       
        y/=10;
    }       
    while(a) {
        int curr=a%10;
        a/=10;
        for(auto i : mirror) {
            if(i[0]==curr) {
                x=x*10+i[1];
                break;
            }   
        }
    }
    while(b) {
        int curr=b%10;
        b/=10;
        for(auto i : mirror) {
            if(i[0]==curr) {
                y=y*10+i[1];
                break;
            }   
        }
    }
    if(c<10) {
        x*=10;
    }
    if(d<10) {
        y*=10;
    }
    swap(x, y);
    return (x<h && y<m);
}   

void solve() {
    cin>>h>>m;
    string s;
    cin>>s;
    int ch, cm;
    ch=(s[0]-'0')*10+s[1]-'0';
    cm=(s[3]-'0')*10+s[4]-'0';
    while(!good(ch, cm)) {
        cm++;
        if(cm==m) {
            cm=0;
            ch=(ch+1)%h;
        }
    }
    string ans="", zero="0";
    if(ch<10) {
        ans+=zero;
    }
    ans+=to_string(ch)+":";
    if(cm<10) {
        ans+=zero;
    }   
    ans+=to_string(cm);
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

