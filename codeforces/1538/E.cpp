#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct info{
    ll inside;
    string start, end;
};

ll count(string s) {
    ll ans=0, n=(ll)s.length();
    for(ll i=0; i<n; i++) {
        for(ll j=0; j<4; j++) {
            if(!((s[i+j]=='h' && j%2==0) || (s[i+j]=='a' && j%2==1))) {
                break;
            }
            ans+=j==3;
        }
    }
    return ans;
}

info build(string &s) {
    info add;
    add.inside=count(s);
    ll n=(ll)s.length();
    for(ll i=0; i<min((ll)3, n); i++) {
        add.start.push_back(s[i]);
        add.end.push_back(s[n-1-i]);
    }
    return add;
}

void solve() {
    ll n;
    cin>>n;
    map<string, info> dict;
    string assign=":=";
    ll ans=0;
    while(n--) {
        string x, op;
        cin>>x>>op;
        if(op==assign) {
            string s;
            cin>>s;
            dict[x]=build(s);
        } else {
            string a, sign, b;
            cin>>a>>sign>>b;
            info add;
            add.start=dict[a].start;
            if((ll)add.start.length()<3) {
                ll m=(ll)dict[b].start.length(), i=0;
                while(add.start.length()<3 && i<m) {
                    add.start.push_back(dict[b].start[i]);
                    i++;
                }
            }
            add.end=dict[b].end;
            if((ll)add.end.length()<3) {
                ll m=(ll)dict[a].end.length(), i=0;
                while(add.end.length()<3 && i<m) {
                    add.end.push_back(dict[a].end[i]);
                    i++;
                }
            }
            string temp=dict[a].end;
            reverse(temp.begin(), temp.end());
            string mid=temp+dict[b].start;
            add.inside=dict[a].inside+dict[b].inside+count(mid);
            dict[x]=add;
        }
        ans=dict[x].inside;
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

