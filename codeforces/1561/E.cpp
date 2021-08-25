#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void rev(int len, vector<int> &a, vector<int> &ans) {
    if(len>1) {
        reverse(a.begin(), a.begin()+len);
        ans.push_back(len);
    }
    return;
}

void move(int val, vector<int> &a, vector<int> &ans) {
    for(int i=0; ; i++) {
        if(a[i]==val) {
            rev(i+1, a, ans);
            break;
        }
    }
    return;
}

void go(int n, vector<int> &a, vector<int> &ans) {
    if(n==1) {
        return;
    } 
    move(n, a, ans);
    for(int i=0; ; i++) {
        if(a[i]==n-1) {
            rev(i, a, ans);
            break;
        }
    }
    rev(n, a, ans);
    move(n, a, ans);
    rev(n, a, ans);
    go(n-2, a, ans);
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(int i=0; i<n; i++) {
        if((a[i]&1)==(i&1)) {
            cout<<-1<<endl;
            return;
        }
    }
    vector<int> ans;
    go(n, a, ans);
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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

