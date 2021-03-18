#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(vector<int> &a, vector<int> &good) {
    int mex=1, high=0, n=(int)a.size();
    set<int> have;
    vector<int> count(n);
    for(int i=0; i<n; i++) {
        if(count[a[i]]) {
            break;
        }
        count[a[i]]++;
        have.insert(a[i]);
        high=max(high, a[i]);
        while(!have.empty() && *have.begin()==mex) {
            mex++;
            have.erase(have.begin());
        }
        if(mex==high+1) {
            good[i]=1;
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> front(n), back(n);
    go(a, front);
    reverse(a.begin(), a.end());
    go(a, back);
    reverse(back.begin(), back.end());
    vector<int> ans;
    for(int i=0; i<n-1; i++) {
        if(front[i] && back[i+1]) {
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i<<" "<<n-i<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

