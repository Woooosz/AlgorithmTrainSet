/*
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible

*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int c2int(char c)
{
    if (c <= '9'&&c >= '0')
        return c - '0';
    else if (c <= 'z'&&c >= 'a')
        return c - 'a' + 10;
    else return 0;
}
unsigned long long  xTo10(string s,unsigned long long radix) {
    unsigned long long  ans=0;
    for(int i=0;i<s.length();++i) {
        if(s[i]>='0' && s[i]<='9') {
            ans=ans*radix+s[i]-'0';
        } else {
            ans=ans*radix+s[i]-'a'+10;
        }
    }
    return ans;
}
int main() {
    string s1,s2;
    int radix,tag;
    cin>>s1>>s2>>tag>>radix;
    if(tag==2) {
        swap(s1,s2);
    }
    unsigned long long x=0;
    for(int i=0;i<s2.length();++i) {
        x=max(x,(unsigned long long )c2int(s2[i]));
    }
    unsigned long long  int s1num=xTo10(s1,radix);
    unsigned long long  low=x+1,high=s1num+1;
    unsigned long long  mid=low+(high-low)/2;
    
    while(high>=low) {
        mid=(low+high)/2;
        unsigned long long s2num=xTo10(s2,mid);
        if(s2num>s1num) {
            high=mid-1;
        } else if(s2num==s1num) {
            printf("%lld",mid);
            return 0;
        } else {
            low=mid+1;
        }
    }
    printf("Impossible\n");
}