/*
1052. Linked List Sorting (25)

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
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
不要忽视对输入个数为0的处理，输出0 -1
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct node {
    int prev;
    int data;
    int next;
};
int compare(const node &a,const node &b) {
    return a.data<b.data;
}
int main() {
    int num,start,t1,t2,t3;
    scanf("%d %d",&num,&start);
    map<int,node> in;
    vector<node> deal;
    for(int i=0;i<num;++i) {
        scanf("%d %d %d",&t1,&t2,&t3);
        in[t1].prev=t1;
        in[t1].data=t2;
        in[t1].next=t3;
    }
    int pi=start;
    while(pi!=-1) {
        deal.push_back(in[pi]);
        pi=in[pi].next;
    }
    sort(deal.begin(),deal.end(),compare);
    if(deal.size()==0)  {
        printf("0 -1\n"); //不要忽视对输入参数为0，head为-1时的处理
        return 0;
    } else {
        printf("%d %05d\n",deal.size(),deal[0].prev);
    }
    for(int i=0;i<deal.size()-1;++i) {
        deal[i].next=deal[i+1].prev;
    }
    deal[deal.size()-1].next=-1;
    int i;

    for(i=0;i<deal.size()-1;++i) {
        printf("%05d %d %05d\n",deal[i].prev,deal[i].data,deal[i].next);
    }
    printf("%05d %d %d\n",deal[i].prev,deal[i].data,deal[i].next);
}