#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(vector<int> &a) {
    if((int)a.size()==1) {
        return true;
    }
    int high=0, count=0;
    for(auto i : a) {
        if(i>high) {
            high=i;
            count=0;
        }
        count+=i==high;
    }
    return count!=(int)a.size();
}

void go(int left, vector<int> &a) {
    int high=0;
    for(auto &i : a) {
        high=max(high, i);
    }
    int n=(int)a.size(), boss;
    for(int i=0; i<n; i++) {
        if(a[i]==high && ((i+1<n && a[i+1]<high) || (i-1>=0 && a[i-1]<high))) {
            boss=i;
            break;
        }
    }
    int i=boss-1, j=boss+1;
    while(i>=0 || j<n) {
        if(i>=0 && a[i]<a[boss]) {
            a[boss]+=a[i];
            cout<<left+i+2<<" L"<<endl;
            i--;
        } else {
            a[boss]+=a[j];
            cout<<left+i+2<<" R"<<endl;
            j++;
        }
    }
    return;
}   

void solve() {
    int n, k;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    cin>>k;
    vector<int> b(k);
    for(auto &i : b) {
        cin>>i;
    }
    string ans="YES";
    vector<vector<int>> store;
    while(!b.empty()) {
        store.push_back({});
        while(!a.empty() && b.back()) {
            b.back()-=a.back();
            store.back().push_back(a.back());
            a.pop_back();
        }
        if(b.back() || !possible(store.back())) {
            ans="NO";
            break;
        }
        b.pop_back();
    }
    if(!a.empty()) {
        ans="NO";
    }
    cout<<ans<<endl;
    if(ans=="NO") {
        return;
    }
    reverse(store.begin(), store.end());
    int left=0;
    for(auto &i : store) {
        reverse(i.begin(), i.end());
        go(left, i);
        left++;
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

