#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s,c;
        cin>>s>>c;
        int i=0,swap=0,j,index;
        char temp;
        if(s<c) {
        	cout<<s<<endl;
		}
		else {
			for(i=0;i<min(s.length(),c.length()) && !swap;i++) {
        		if(s.at(i)>=c.at(i)) {
        			index=i;
					for(j=i+1;j<s.length();j++) {
        				if(s.at(j)<=s.at(index)) {
        					index=j;
						}
					}
					if(s.at(index)<s.at(i)){
						temp=s.at(i);
						s.at(i)=s.at(index);
						s.at(index)=temp;
						swap++;
					}
				}
			}
			if(s<c) {
				cout<<s<<endl;
			}
			else {
				cout<<"---"<<endl;
			}	
		}
	}
}