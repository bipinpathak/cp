#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i :a) {
        cin>>i;
    }
    if(n==1) {
        cout<<0<<endl;
        return;
    }
    int diff=-1;
    for(int i=1; i<n; i++) {
        if(a[i]>a[i-1]) {
            diff=a[i]-a[i-1];
            break;
        }
    }
    if(diff!=-1) {
        int m=0;
        for(int i=1; i<n; i++) {
            if(a[i]<a[i-1]) {
                m=a[i-1]+diff-a[i];
                break;
            }
        }
        if(m) {
            for(int i=0; i<n; i++) {
                if( (i && a[i]!=(a[i-1]+diff)%m) || a[i]>=m) {
                    cout<<-1<<endl;
                    return;
                }
            }
            cout<<m<<" "<<diff<<endl;
            return;
        } else {
            diff=a[1]-a[0];
            for(int i=1; i<n; i++) {
                if(a[i]-a[i-1]!=diff) {
                    cout<<-1<<endl;
                    return;
                }
            }
            cout<<0<<endl;
            return;
        }
    } else {
        int same=0;
        for(int i=1; i<n; i++) {
            same+=a[i]==a[i-1];
        }
        if(same) {
            if(same==n-1) {
                cout<<0<<endl;
                return;
            } else {
                cout<<-1<<endl;
                return;
            }
        }
        diff=a[0]-a[1];
        for(int i=1; i+1<n; i++) {
            if(a[i]-a[i+1]!=diff) {
                cout<<-1<<endl;
                return;
            }
        }
        cout<<0<<endl;
        return;
    }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

