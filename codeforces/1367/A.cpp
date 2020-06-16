#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string b,a;
        cin>>b;
        a+=b[0];
        int i=1;
        while(i<b.length()) {
            a+=b[i];
            i+=2;
        }
        cout<<a<<endl;
    }
	return 0;
}
