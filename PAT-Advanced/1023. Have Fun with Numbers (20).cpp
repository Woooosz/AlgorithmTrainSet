/*
1023. Have Fun with Numbers (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
vector<int> check(10)={0};
int main() {
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i) 
		++check[s[i]-'0'];
	string ss;
	int carry=0,count=0;
	for(int i=s.size()-1;i>=0;--i) {
		int tmp=carry+(s[i]-'0');
		ss.insert(ss.begin(),tmp%10+'0');
		carry=tmp/10;
	}
	if(carry!=0) ss.insert(ss.begin(),carry);
	for(int i=0;i<ss.size();++i)
		--check[ss[i]-'0'];
	for(int i=0;i<ss.size();++i) 
		if(check[i]!=0) count++;
	if(count)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	cout<<ss<<endl;

}