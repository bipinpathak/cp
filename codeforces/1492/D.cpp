#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string add(string &a, string &b, bool &possible) {
    int n=(int) a.size(), carry=0;
    string ans="";
    for(int i=0; i<n; i++) {
        int sum=carry+a[i]+b[i]-2*'0';
        carry=sum/2;
        sum%=2;
        if(sum) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }
    if(carry) {
        possible=false;
    }
    return ans;
}

void solve() {
    int a, b, k;
    cin>>a>>b>>k;
    string y(a+b, '1'), t(k, '1'), x(a+b, '0');
    bool possible=true;
    if(k==a+b) {
        possible=false; 
    }
    if(possible) {
        if(a) {
            y[k]='0';
        }
        int count=1;
        for(int i=1; count<a; i++) {
            if(y[i]=='1') {
                y[i]='0';
                count++;
            }
        }
        string temp(a+b-k, '0');
        t+=temp;
        x=add(y, t, possible);
        if(x.back()=='0' || y.back()=='0') {
            possible=false;
        }
    }
    if(!possible) {
        cout<<"No"<<endl;
        return;
    }
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    cout<<"Yes"<<endl<<x<<endl<<y<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}
