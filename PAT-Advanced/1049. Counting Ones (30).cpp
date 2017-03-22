/*
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/
#include<iostream>
using namespace std;
int main() {
    int n,left=0,right=0,a=1,now=1;
    scanf("%d",&n);
    int ones=0;
    while(n/a) {
        left=n/(a*10);
        now=n/a % 10;
        right=n % a;
        if(now==0) ones+=left*a;
        else if(now==1) ones+=left*a+right+1;
        else ones+=(1+left)*a;
        a*=10;
    }
    printf("%d",ones);
}