#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(int &target, vector<int> &a, int &k) {
    int n=(int)a.size(), sum=0, low=0;
    vector<int> prefix(n);
    for(int i=0; i<n; i++) {
        if(a[i]<target) {
            sum--;
        } else if(a[i]>=target) {
            sum++;
        }
        prefix[i]=sum;
        if(i>=k-1) {
            if(prefix[i]>0 || (i>k-1 && prefix[i]-prefix[low]>0)) {
                return true;
            }
            if(prefix[i-k+1]<prefix[low]) {
                low=i-k+1;
            }
        }
    }
    return false;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int low=1, high=n, mid;
    while(low<high) {
        mid=(high+low+1)/2;
        if(possible(mid, a, k)) {
            low=mid;
        } else {
            high=mid-1;
        }
    }
    cout<<low<<endl;
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

