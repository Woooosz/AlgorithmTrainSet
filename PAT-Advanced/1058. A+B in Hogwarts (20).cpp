/*
1058. A+B in Hogwarts (20)

时间限制
50 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28
*/
#include<iostream>

using namespace std;

int main() {
    long long a1,a2,a3,b1,b2,b3,ans1=0,ans2=0,ans3=0,tmp=0;
    scanf("%lld%*c%lld%*c%lld %lld%*c%lld%*c%lld",&a1,&a2,&a3,&b1,&b2,&b3);
    tmp=(a3+b3)/29;
    ans3=(a3+b3)%29;
    ans2+=(a2+b2+tmp)%17;
    tmp=(a2+b2+tmp)/17;
    ans1=a1+b1+tmp;
    printf("%lld.%lld.%lld\n",ans1,ans2,ans3);
}