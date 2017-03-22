/*
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
需要考虑数字为1.23E+2 1.234E+1时候小数点移位这种情况
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int string2int(const string &a) {
    int ans=0;
    for(int i=1;i<a.length();++i) {
        ans=ans*10+a[i]-'0';
    }
    return ans;
}
int main() {
    string s,ans;
    cin>>s;
    int pi=s.find('E');
    for(int i=1;i<pi;++i) {
        if(i==2) continue;
        ans.insert(ans.end(),s[i]);
    }
    int x=string2int(&s[pi+1]);
    if(s[pi+1]== '-') { //小数字
        if(x==0) ans.insert(ans.begin()+1,'.');
        for(int i=0;i<x;++i) {
            if(i==x-1) ans.insert(ans.begin(),'.');
            ans.insert(ans.begin(),'0');
        }
    } else { //大数字
        if(x>ans.length()-1) {
            for(int i=0;i<x-1;++i)
                ans.insert(ans.end(),'0');
        } else if(x<ans.length()-1){
            ans.insert(ans.begin()+x+1,'.');
        } else { }

    }
    if(s[0]=='-') ans.insert(ans.begin(),'-');
    cout<<ans<<endl;
}