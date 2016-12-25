/*
1116. Come on! Let's C (20)

时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the idea of the contest is for fun, the award rules are funny as the following:

0. The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
1. Those who ranked as a prime number will receive the best award -- the Minions (小黄人)!
2. Everyone else will receive chocolates.

Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10000), the total number of contestants. Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer K followed by K query ID's.

Output Specification:

For each query, print in a line "ID: award" where the award is "Mystery Award", or "Minion", or "Chocolate". If the ID is not in the ranklist, print "Are you kidding?" instead. If the ID has been checked before, print "ID: Checked".

Sample Input:
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
Sample Output:
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
*/
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#define MAX 10001
using namespace std;
int main() {
    int na,tmp;
    map<int,int> rank;
    cin>>na;
    for(int i=1;i<=na;++i) {
        cin>>tmp;
        rank[tmp]=i;
    }
    int nb;
    int prime[MAX];
    for(int i=0;i<MAX;i++)
        prime[i]=1;
    for(int i=3;i<MAX;i++)
        prime[i]=i%2?1:0;
    for(int i=3;i<=sqrt(MAX);++i) {
        if(prime[i]) {
            for(int j=i*2;j<MAX;j+=i) {
                prime[j]=0;
            }
        }
    }
    prime[2]=1;
    cin>>nb;
    map<int,int>::iterator pi;

    while(nb--) {
        cin>>tmp;
        printf("%04d: ",tmp);
        pi=rank.find(tmp);
        if(pi==rank.end()) {
            printf("Are you kidding?\n");
            continue;
        }
        if(rank[tmp]==1) {
            printf("Mystery Award\n");
            rank[tmp]=-1;
        } else if(rank[tmp]==-1) {
            printf("Checked\n");
        } else if(prime[rank[tmp]]==1) {
            printf("Minion\n");
            rank[tmp]=-1;
        } else if(prime[rank[tmp]==0]){
            printf("Chocolate\n");
            rank[tmp]=-1;
        }
    }
}