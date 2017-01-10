/*
1055. The World's Richest (25)

时间限制
400 ms
内存限制
128000 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=105) - the total number of people, and K (<=103) - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in (0, 200]), and the net worth (integer in [-106, 106]) of a person. Finally there are K lines of queries, each contains three positive integers: M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

Output Specification:

For each query, first print in a line "Case #X:" where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format

Name Age Net_Worth
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output "None".
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
1.运用剪枝策略
2.涉及到大量字符输入，要考虑用char，scanf()，printf()
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct node{
    char name[30];
    int age;
    int mon;
};
inline int min(int a,int b) {
    return a<b?a:b;
}
int compare_mon(const node &a,const node &b) {
    return a.mon>b.mon || ((a.mon==b.mon) && (a.age<b.age)) || ((a.mon==b.mon) && (a.age==b.age) && (strcmp(a.name,b.name)<0));
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    vector<node> in;
    node x;
    int counts[201]={0}; 
    for(int i=0;i<n;++i) {
        scanf("%s %d %d",&x.name,&x.age,&x.mon);
        in.push_back(x);
    }
    sort(in.begin(),in.end(),compare_mon);
    vector<node> filter;
    for(int i=0;i<in.size();++i) {
        if(++counts[in[i].age]<101) //剪枝
            filter.push_back(in[i]);
    }
    for(int i=1;i<=m;++i) {
        printf("Case #%d:\n",i);
        int num,low,high;
        scanf("%d %d %d",&num,&low,&high);
        int index=0,flag=0;
        for(int j=0;j<filter.size();++j) {
            if(filter[j].age>=low && filter[j].age<=high && index<num) {
                printf("%s %d %d\n",filter[j].name,filter[j].age,filter[j].mon);
                ++index;
                flag=1;
            }
        }
        if(!flag) 
            printf("None\n");
    }
}