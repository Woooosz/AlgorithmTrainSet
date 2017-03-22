/*
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.


Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15
*/
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
vector<int> in,post;
int n;
struct node {
    int data;
    node *left;
    node *right;
    node(int v_data):data(v_data),left(0),right(0){ }
};
node *create(int inL,int inR,int postL,int postR) {
    if(inL > inR) return 0;
    node *root = new node(post[postR]);
    int i;
    for(i=inL;i<=inR;++i)
        if(in[i] == post[postR]) break;
    int leftnum = i - inL;
    root->left = create(inL,i - 1,postL,postL + leftnum - 1);
    root->right = create(i + 1,inR,postL + leftnum,postR - 1);
    return root;
}
int main () {
    scanf("%d",&n);
    in.resize(n);
    post.resize(n);
    for(int i=0;i<n;++i)
        scanf("%d",&in[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&post[i]);
    node *root = create(0,n-1,0,n-1);
    stack<node *> s1,s2;
    s1.push(root);
    int f=0;
    while(!s1.empty() || !s2.empty()) {
        node *p;
        while(!s1.empty()) {
            p = s1.top();
            s1.pop();
            if(!f) {
                printf("%d",p->data);
                f=1;
            } else {
                printf(" %d",p->data);
            }
            if(p->right) s2.push(p->right);
            if(p->left) s2.push(p->left);
        }
        while(!s2.empty()) {
            p = s2.top();
            s2.pop();
            printf(" %d",p->data);
            if(p->left) s1.push(p->left);
            if(p->right) s1.push(p->right);
        }
    }
}
