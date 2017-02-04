/*
1081. Rational Sum (20)

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
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
*/
#include<iostream>
using namespace std;
long long gcd(long long a,long long b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main() {
    long long n,a,b,suma=0,sumb=1,gcdvalue;
    scanf("%lld",&n);
    for(int i=0;i<n;++i) {
        scanf("%lld/%lld",&a,&b);
        gcdvalue=gcd(a,b);
        a/=gcdvalue;
        b/=gcdvalue;
        suma=a*sumb+b*suma;
        sumb=b*sumb;
        gcdvalue=gcd(suma,sumb);
        suma/=gcdvalue;
        sumb/=gcdvalue;
    }
    long long integer=suma/sumb;
    suma=suma-integer*sumb;
    if(integer!=0) {
        printf("%lld",integer);
        if(suma!=0) printf(" ");
        else return 0;
    }
    if(suma==0) printf("0\n");
    else printf("%lld/%lld\n",suma,sumb);
}