/*
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
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/
#include<iostream>
#include<string>
using namespace std;
string get_reverse(string a) {
    string s;
    for(int i=0;i<a.length();++i)
        s.insert(s.begin(),a[i]);
    return s;
}
bool check_palindromic(string x) {
    bool ans=true;
    size_t len=x.length();
    for(int i=0;i<x.length();++i)
        if(x[i]!=x[len-1-i]) ans=false;
    return ans;
}
string add(string s) {
    string ans;
    string re_s=get_reverse(s);
    int len=s.length(),carry=0,num;
    for(int i=len-1;i>=0;--i) {
        num=(((s[i]-'0')+(re_s[i]-'0'))+carry)%10;
        carry=((s[i]-'0')+(re_s[i]-'0')+carry)/10;
        ans.insert(ans.begin(),num+'0');
    }
    if(carry) ans.insert(ans.begin(),carry+'0');
    return ans;
}
int main() {
    string n,s;
    long long int m,i;
    cin>>n>>m;
    if(check_palindromic(n)) {
        cout<<n<<endl<<0<<endl;
        return 0;
    }
    for(i=1;i<=m;++i) {
        n=add(n);
        if(check_palindromic(n)) break;
    }
    if(i>m) i=m;
    cout<<n<<endl<<i<<endl;
}