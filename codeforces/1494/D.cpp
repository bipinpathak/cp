#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, N;
    cin>>n;
    N=2*n;
    vector<vector<int>> a(N, vector<int> (N));
    vector<int> nodes(N), parent(N, -1);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>a[i][j];
            if(i==j) {
                nodes[i]=a[i][j];
            }
        }
    }
    while(1) {
        int root=5001, u=-1;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n && parent[i]==-1; j++) {
                if(parent[j]==-1 && a[i][j]<root) {
                    root=a[i][j];
                    u=i;
                }
            }
        }
        if(root==5001) {
            break;
        }
        nodes[n]=root;
        parent[u]=n;
        for(int v=0; v<n; v++) {
            if(parent[v]==-1 && a[u][v]==root) {
                parent[v]=n;
            }
        }
        for(int i=0; i<n; i++) {
            if(parent[i]==-1) {
                a[n][i]=a[i][n]=a[u][i];
            }
        }
        n++;
    }
    cout<<n<<endl;
    for(int i=0; i<n; i++) {
        cout<<nodes[i]<<" ";
    }
    cout<<endl<<n<<endl;
    for(int i=0; i<n-1; i++) {
        cout<<i+1<<" "<<parent[i]+1<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

