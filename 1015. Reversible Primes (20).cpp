/*
1015. Reversible Primes (20)

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
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
题意是这么回事儿，首先x是质数，其次x转换为radix进制的数xp，将xp逆序，逆序后转换为十进制
如果十进制也为质数，则通过。题意理解有点麻烦
*/
#include<iostream>
#include<cstring>
#include<math.h>
#include<queue>
using namespace std;
int prime[100000];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    for(int i=0;i<100000;++i)
        prime[i]=1;
    for(int i=0;i<100000;i+=2)
        prime[i]=0;
    for(int i=3;i<=sqrt(100000);++i) {
        if(prime[i]==1) {
            for(int j=i*2;j<100000;j+=i)
                prime[j]=0;
        }
    }
    prime[2]=1;
    prime[1]=0;
    queue<int> que;
    int num,radix,ans=0,b;
    while(true) {
        ans=0;
        scanf("%d",&num);
        if(num<0) break;
        scanf("%d",&radix);
        b=num;
        while(num>0) {
            que.push(num%radix);
            num/=radix;
            
        }
        while(!que.empty()) {
            ans=ans*radix+que.front();
            que.pop();
        }

        if((prime[b]==1) && (prime[ans]==1)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    
    }
}
