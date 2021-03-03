#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int go(vector<int> &boxes, vector<int> &special) {
    int ans=0;
    int n=boxes.size(), m=special.size();
    vector<int> right(m+1);
    int i=n-1, j=m-1, curr=0;
    while(j>=0) {
        while(i>=0 && boxes[i]>special[j]) {
            i--;
        }
        if(i>=0 && boxes[i]==special[j]) {
            curr++;
            i--;
        }
        right[j]=curr;
        j--;
    }
    i=0;
    int left=0;
    for(j=0; j<m; j++) {
        while(i<n && boxes[i]<=special[j]) {
            i++;
        }
        while(left<m && special[j]-special[left]>i-1) {
            left++;
        }
        ans=max(ans, j-left+1+right[j+1]);
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> a1, a2, b1, b2;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        if(x>0) {
            a1.push_back(x);
        } else {
            a2.push_back(-x);
        }
    }
    for(int i=0; i<m; i++) {
        int x;
        cin>>x;
        if(x>0) {
            b1.push_back(x);
        } else {
            b2.push_back(-x);
        }
    }
    reverse(a2.begin(), a2.end());
    reverse(b2.begin(), b2.end());
    cout<<go(a1, b1)+go(a2, b2)<<endl;
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

