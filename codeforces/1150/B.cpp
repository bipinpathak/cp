#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool possible=true;

bool go(int i, int j, int n, vector<string> &board) {
    if(!(i+2<n && j+1<n && j-1>=0)) {
        return false;
    }
    if(board[i+1][j]=='#' || board[i+2][j]=='#' || board[i+1][j+1]=='#' || board[i+1][j-1]=='#') {
        return false;
    }
    board[i+1][j]=board[i+2][j]=board[i+1][j+1]=board[i+1][j-1]='#';
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<string> board(n);
    for(auto &i : board) {
        cin>>i;
    }
    for(int i=0; i<n && possible; i++) {
        for(int j=0; j<n && possible; j++) {
            if(board[i][j]=='#') {
                continue;
            }
            possible=go(i, j, n, board);
        }
    }
    if(possible) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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

