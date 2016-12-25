#include<iostream>
#include<stack>

using namespace std;

int main() {
	int num,count=0;
	cin>>num;
	for(int i=1;i<=num;++i) {
		int tmp=i;
		while(i>0) {
			if(tmp%10==1) {
				++count;
				continue;
			}
			tmp/=10;
		}
	}
	cout<<count<<endl;
}