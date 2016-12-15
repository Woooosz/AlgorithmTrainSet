/*
1020. Tree Traversals (25)

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
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
根据中序和后序遍历建树，递归的那部分还得琢磨琢磨。
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int num;
typedef struct node {
    int data;
    node *left=0;
    node *right=0;
}*ptrNode;
void PostMidCreateTree(ptrNode &pn,vector<int> &post,vector<int> mid,int i,int j,int len) {
    if(len<=0)
        return;
    pn=new node;
    pn->data=post[i];
    int m=j;
    while(mid[m]!=post[i])
        m++;
    PostMidCreateTree(pn->left,post,mid,i-1-(len-1-(m-j)),j,m-j);
    PostMidCreateTree(pn->right,post,mid,i-1,m+1,len-1-(m-j));
}
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    scanf("%d",&num);
    vector<int> post(num);
    vector<int> mid(num);
    for(int i=0;i<num;++i)
        scanf("%d",&post[i]);
    for(int i=0;i<num;++i)
        scanf("%d",&mid[i]);
    ptrNode tree=0;
    PostMidCreateTree(tree,post,mid,post.size()-1,0,mid.size());
    queue<ptrNode> que;
    que.push(tree);
    int flag=0;
    ptrNode tmp;
    while(!que.empty()) {
        tmp=que.front();
        if(!flag) {
            cout<<tmp->data;
            flag=1;
        }else
            cout<<" "<<tmp->data;
        if(tmp->left)
            que.push(tmp->left);
        if(tmp->right)
            que.push(tmp->right);
        que.pop();
    }
}
