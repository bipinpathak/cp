#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n;
        n=s.length();
        if(s.at(n-1)=='o') {
        	cout<<"FILIPINO"<<endl;
		}
		else if(s.at(n-1)=='a'){
			cout<<"KOREAN"<<endl;
		}
		else {
			cout<<"JAPANESE"<<endl;
		}
    }
}