/*
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
typedef map<int,int>::iterator itor;
using namespace std;
const int maxv=10000;
int main() {
    bool prime[maxv];
    fill(prime,prime+maxv,true);
    for(int i=0;i<maxv;++i) {
        if(i%2==0) prime[i]=false;
    }
    for(int i=3;i<=sqrt(maxv);++i) {
        if(prime[i]) {
            for(int j=i*2;j<maxv;j+=i)
                prime[j]=false;
        }
    }
    prime[2]=true;
    unsigned long long x;
    cin>>x;
    printf("%lld=",x);
    if(x==1) {
        printf("1");
        return 0;
    }
    map<int,int> dict;
    int i=1;
    while(x>1) {
        for(i=i+1;i<maxv;++i)
            if(prime[i]) break;
        while(x%i==0) {
            x/=i;
            dict[i]++;
        }
    }
    int flag=0;
    for(itor pi=dict.begin();pi!=dict.end();++pi) {
        if(!flag) flag=1;
        else printf("*");
        if(pi->second==1)
            printf("%d",pi->first);
        else
            printf("%d^%d",pi->first,pi->second);
    }
}