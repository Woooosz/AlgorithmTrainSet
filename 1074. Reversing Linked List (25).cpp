/*
1074. Reversing Linked List (25)

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
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
注意一下那个reverse的for循环就好
对于这类链表题在预处理都是开一个INT_MAX的数组，保存结构体。
之后开一个空间为链表元素个数的数组，对初始化的大数组进行链表遍历插入到prog数组，进行再次处理。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv=10e5+3;
class node {
public:
    int curr;
    int next;
    int data;
};
int main() {
    //freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    int head,n,k;
    scanf("%d %d %d",&head,&n,&k);
    vector<node> in(maxv);
    for(int i=0;i<n;++i) {
        int tmp;
        scanf("%d",&tmp);
        scanf("%d %d",&in[tmp].data,&in[tmp].next);
        in[tmp].curr=tmp;
    }
    vector<node> prog;
    int pi=head;
    while(pi!=-1) {
        prog.push_back(in[pi]);
        pi=in[pi].next;
    }
    for(int i=0;i+k<=prog.size();i+=k) {
        reverse(prog.begin()+i,prog.begin()+k+i);
    }
    for(int i=0;i<prog.size()-1;++i) {
        prog[i].next=prog[i+1].curr;
    }
    prog[prog.size()-1].next=-1;
    int i;
    for(i=0;i<prog.size()-1;++i) {
        printf("%05d %d %05d\n",prog[i].curr,prog[i].data,prog[i].next);
    }
     printf("%05d %d %d\n",prog[i].curr,prog[i].data,prog[i].next);
    
}
