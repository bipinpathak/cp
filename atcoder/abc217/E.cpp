#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int q;
    cin>>q;
    map<int, int> sorted;
    queue<int> waiting;
    while(q--) {
        int c;
        cin>>c;
        if(c==1) {
            int x;
            cin>>x;
            waiting.push(x);
        } else if(c==2) {
            if(sorted.empty()) {
                cout<<waiting.front()<<endl;
                waiting.pop();
            } else {
                cout<<sorted.begin()->first<<endl;
                sorted.begin()->second--;
                if(sorted.begin()->second==0) {
                    sorted.erase(sorted.begin());
                }   
            }
        } else {
            while(!waiting.empty()) {
                sorted[waiting.front()]++;
                waiting.pop();
            }
        }
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

