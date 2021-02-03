#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, int> f;
    for(auto &i : a) {
        cin>>i;
        f[i]++;
    }
    vector<int> temp;
    vector<vector<int>> store;
    for(auto i : f) {
            temp.push_back(i.second);
            store.push_back({i.second, i.first});
    }
    sort(temp.begin(), temp.end());
    sort(store.rbegin(), store.rend());
    int total=(int)temp.size(), ans=0, col=0, row=0, start=1;
    vector<int> sum(total+1);
    for(int i=1; i<=total; i++) {
        sum[i]=sum[i-1]+temp[i-1];
    }
    while(start*start<n) {
        start++;
    }
    for(int i=start; i; i--) {
        int small=lower_bound(temp.begin(), temp.end(), i)-temp.begin();
        int offer=sum[small]+(total-small)*i;
        offer-=offer%i;
        col=offer/i;
        if(col>=i && offer>ans) {
            ans=offer;
            row=i;
        }
    }           
    col=ans/row;
    vector<vector<int>> grid(row, vector<int> (col));
    vector<int> elements;
    for(auto key : store) {
        key[0]=min(key[0], row);
        while((int)elements.size()<ans && key[0]) {
            key[0]--;
            elements.push_back(key[1]);
        }
        if((int)elements.size()==ans) {
            break;
        }
    }
    for(int i=0; i<ans; i++) {
        grid[i%row][(i/row+i%row)%col]=elements[i];
    }
    //comment
    cout<<ans<<endl<<row<<" "<<col<<endl;
    for(auto &i : grid) {
        for(auto &j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}


