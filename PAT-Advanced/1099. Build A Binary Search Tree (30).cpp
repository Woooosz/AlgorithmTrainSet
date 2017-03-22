/*
1099. Build A Binary Search Tree (30)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.


Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
二叉搜索树中序遍历结果是一组数字的升序
对集合进行升序排序
对树的中序遍历算法进行改进，递归将每个数填进去
调用层序遍历输出
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
struct node {
    int data=0;
    int left;
    int right;
};
bool compare(int a,int b) {
    return a<b;
}
int flag=0;
void inorder(vector<node> &in,vector<int> &data,int index) {
    if(in[index].left!=-1)
        inorder(in,data,in[index].left);
    in[index].data=data[flag++];
    if(in[index].right!=-1)
        inorder(in,data,in[index].right);
}
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    int num,left,right;
    scanf("%d\n",&num);
    vector<node> in(num);
    vector<int> data(num);
    for(int i=0;i<num;++i) {
        scanf("%d %d\n",&left,&right);
        in[i].left=left;
        in[i].right=right;
    }
    for(int i=0;i<num;++i) {
        cin>>left;
        data[i]=left;
    }
    sort(data.begin(),data.end(),compare);
    inorder(in,data,0);
    queue<int> que;
    que.push(0);
    int tflag=0;
    while(!que.empty()) {
        int tmp=que.front();
        que.pop();
        if(in[tmp].left!=-1)
            que.push(in[tmp].left);
        if(in[tmp].right!=-1)
            que.push(in[tmp].right);
        if(!tflag) {
            printf("%d",in[tmp].data);
            tflag=1;
        }else
            printf(" %d",in[tmp].data);
    }
}
