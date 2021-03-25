#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void mini(vector<int> a) {
    int n=(int)a.size();
    set<int> left;
    for(int i=0; i<n; i++) {
        left.insert(i+1);
    }
    for(int i=0; i<n; i++) {
        if(a[i]!=-1) {
            left.erase(a[i]);
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i]==-1) {
            a[i]=*left.begin();
            left.erase(a[i]);
        }
    }
    for(auto i : a) {
        cout<<i<<" ";
    }
    cout<<endl;

    return;
}

void maxi(vector<int> a) {
    int n=(int)a.size();
    stack<int> left;
    int curr=0, last=-1;
    for(int i=0; i<n; i++) {
        if(a[i]!=-1) {
            while(last<i && last>=0) {
                a[last]=left.top();
                left.pop();
                last++;
            }
            last=-1;
            while(curr<a[i]) {
                left.push(curr);
                curr++;
            }
            curr++;
        } else if(last==-1) {
            last=i;
        }
    }
    while(curr<n+1) {
        left.push(curr);
        curr++;
    }
    while(last<n && last>=0) {
        a[last]=left.top();
        left.pop();
        last++;
    }
    for(auto i : a) {
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> q(n);
    for(auto &i : q) {
        cin>>i;
    }
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++) {
        if(i==0 || q[i]!=q[i-1]) {
            ans[i]=q[i];
        }
    }
    mini(ans);
    maxi(ans);
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

