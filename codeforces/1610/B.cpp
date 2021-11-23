#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool check(int k, vector<int> &a) {
    int left=0, right=(int)a.size()-1;
    while(left<right) {
        if(a[left]!=a[right]) {
            if(a[left]==k) {
                left++;
            } else if(a[right]==k) {
                right--;
            } else {
                return false;
            }
        } else {
            left++;
            right--;
        }
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int left=-1, right=-1;
    for(int i=0; i<n-1-i; i++) {
        if(a[i]!=a[n-1-i]) {
            left=a[i];
            right=a[n-1-i];
            break;
        }
    }
    string ans=(check(left, a)|check(right, a))?"YES":"NO";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

