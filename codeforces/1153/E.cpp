#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(int x1, int y1, int x2, int y2) {
    int res;
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    cin>>res;
    return res%2;
}

void solve() {
    int n;
    cin>>n;
    vector<int> row, col;
    for(int i=1; i<=n; i++) {
        if(ask(i, 1, i, n)) {
            row.push_back(i);
        }
        if(ask(1, i, n, i)) {
            col.push_back(i);
        }
    } 
    if(row.empty()) {
        int low=1, high=n, mid;
        while(low<high) {
            mid=low+(high-low)/2;
            if(ask(1, col.back(), mid, col.back())) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        row.push_back(low);
        row.push_back(low);
    } 
    if(col.empty()) {
        int low=1, high=n, mid;
        while(low<high) {
            mid=low+(high-low)/2;
            if(ask(row.back(), 1, row.back(), mid)) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        col.push_back(low);
        col.push_back(low);
    }
    if(!ask(1, 1, row[0], col[0])) {
        reverse(col.begin(), col.end());
    }
    cout<<"! "<<row[0]<<" "<<col[0]<<" "<<row[1]<<" "<<col[1]<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}
