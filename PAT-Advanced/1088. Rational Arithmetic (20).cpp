/*
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

*/
#include<iostream>
#include<cstdlib>
using namespace std;
long long int a1,b1,a2,b2,gcdv,x1=0,x2=1;
long long gcd(long long a,long long b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
void simplify(long long &a,long long &b) {
    long long gcdv=gcd(a,b);
    a/=gcdv;
    b/=gcdv;
    if(b<0 && a>0) {
        b*=-1;
        a*=-1;
    }
    if(b==0) {
        printf("Inf");
        return;
    }
    long long integer=a/b;
    long long aa=a-integer*b;
    if(integer!=0) {
        if(integer>0)
            printf("%lld",integer);
        else if(integer<0 && b==1)
            printf("(%lld)",integer);
        else
            printf("(%lld",integer);
        if(aa!=0) printf(" ");
        else return;
    }
    if(aa==0) printf("0");
    else if(aa>0) printf("%lld/%lld",aa,b);
    else if(aa<0 && integer!=0) printf("%lld/%lld)",abs(aa),b);
    else printf("(%lld/%lld)",aa,b);
}
void print(char s) {
    simplify(a1,a2);
    printf(" %c ",s);
    simplify(b1,b2);
    printf(" = ");
    simplify(x1,x2);
    printf("\n");
}
int main() {
    scanf("%lld/%lld %lld/%lld",&a1,&a2,&b1,&b2);
    x1=a1*b2+a2*b1;
    x2=a2*b2;
    print('+');
    x1=a1*b2-a2*b1;
    x2=a2*b2;
    print('-');
    x1=a1*b1;
    x2=a2*b2;
    print('*');
    x1=a1*b2;
    x2=a2*b1;
    print('/');
    
}