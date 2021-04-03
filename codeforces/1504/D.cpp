#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int total=n*n, balance=0;
    pair<int, int> even={0, 0}, odd={0, 1};
    while(total--) {
        int a;
        cin>>a;
        if(a==2) {
            if(balance>=0 && even.first<n) {
                a=1;
            } else if(balance<=0 && odd.first<n) {
                a=3;
            }
        }
        if(a==1 && even.first<n) {
            cout<<3<<" "<<even.first + 1<<" "<<even.second + 1<<endl;
            balance--;
            even.second+=2;
            if(even.second>=n) {
                even.first++;
                even.second=even.first%2;
            }
        } else if(a==3 && odd.first<n) {
            cout<<1<<" "<<odd.first + 1<<" "<<odd.second + 1<<endl;
            balance++;
            odd.second+=2;
            if(odd.second>=n) {
                odd.first++;
                odd.second=(odd.first+1)%2;
            }
        } else {
            if(even.first<n) {
                cout<<2<<" "<<even.first+1<<" "<<even.second+1<<endl;
                even.second+=2;
                if(even.second>=n) {
                    even.first++;
                    even.second=even.first%2;
                }
            } else {
                cout<<2<<" "<<odd.first+1<<" "<<odd.second+1<<endl;
                odd.second+=2;
                if(odd.second>=n) {
                    odd.first++;
                    odd.second=(odd.first+1)%2;
                }
            }
        }
    }
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
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

