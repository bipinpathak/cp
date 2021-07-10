#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int go(vector<int> &a, int target) {
    int low=0, high=(int)a.size()-1;
    while(low<high) {
        int mid=(high+low+1)/2;
        if(a[mid]>target) {
            high=mid-1;
        } else {
            low=mid;
        }
    }
    return low;
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> row(n, {-1}), col(m, {-1});
    ll total=(ll)n*m-k-1;
    while(k--) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for(auto &i : row) {
        i.push_back(m);
        sort(i.begin(), i.end());
    }
    for(auto &i : col) {
        i.push_back(n);
        sort(i.begin(), i.end());
    }
    int up=-1, down=n, right=m, left=-1, dir=0, x=0, y=0;
    while(up<down && left<right) {
        int x1=x, y1=y;
        if(dir==0) {
            int index=upper_bound(row[x].begin(), row[x].end(), y)-row[x].begin();
            y1=min(right, row[x][index])-1;
            right=y1;
            up=x1;
        } else if(dir==1) {
            int index=upper_bound(col[y].begin(), col[y].end(), x)-col[y].begin();
            x1=min(down, col[y][index])-1;
            right=y1;
            down=x1;
        } else if(dir==2) {
            int index=go(row[x], y);
            y1=max(left, row[x][index])+1;
            left=y1;
            down=x1;
        } else {
            int index=go(col[y], x);
            x1=max(up, col[y][index])+1;
            up=x1;
            left=y1;
        }
        total-=(ll)(abs(x-x1)+1)*(abs(y-y1)+1);
        total++;
        x=x1, y=y1;
        dir=(dir+1)%4;
    }
    string ans="Yes";
    if(total) {
        ans="No";
    }
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

