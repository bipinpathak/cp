#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool connected(int i, int j, int r, vector<vector<int>> &a) {
    int n=(int)a.size();
    if(i+1<n && a[i+1][j]==r) {
        return true;
    }
    if(j+1<n && a[i][j+1]==r) {
        return true;
    }
    if(i && a[i-1][j]==r) {
        return true;
    }
    if(j && a[i][j-1]==r) {
        return true;
    }
    return false;
}   

void solve() {
    int n;
    cin>>n;
    vector<int> count(n);
    for(auto &i : count) {
        cin>>i;
    }
    vector<vector<int>> a(n, vector<int> (n));
    vector<int> available(n);
    for(int i=0; i<n; i++) {
        a[i][i]=count[i];
        available[i]=i+1;
    }
    for(int k=0; k<n; k++) {
        int r=count[k];
        count[k]--;
        vector<int> low(n, n), high(n, -1);
        low[k]=high[k]=k;
        while(count[k]--) {
            bool done=false;
            for(int j=0; j<n && !done; j++) {
                if(low[j]<=high[j]) {
                    if(low[j]-1>=j && a[low[j]-1][j]==0) {
                        low[j]--;
                        a[low[j]][j]=r;
                        done=true;
                        break;
                    }
                    if(high[j]+1<n && a[high[j]+1][j]==0) {
                        high[j]++;
                        a[high[j]][j]=r;
                        done=true;
                        break;
                    }
                } else if(j+1<n && high[j+1]>=low[j+1]) {
                    while(available[j]<n && a[available[j]][j]!=0) {
                        available[j]++;
                    }
                    if(available[j]<=high[j+1]) {
                        int chose=max(available[j], low[j+1]);
                        a[chose][j]=r;
                        low[j]=high[j]=chose;
                        done=true;
                        break;
                    }
                }
            }
            if(!done) {
                cout<<-1<<endl;
                return;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout<<a[i][j]<<" ";
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

