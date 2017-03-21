/*
1066. Root of AVL Tree (25)

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
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/
#include <iostream>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
	int height;
	node(int _data):data(_data), left(0), right(0), height(1){}
};
inline max(int a, int b){ return a > b ? a : b;}
int getHeight(node *root) {
	if(!root) return 0;
	else return root->height;
}
int updateHeight(node &*root) {
	root->height = max(root->left, root->right) + 1;
}
int balbanceFactor(node *root) {
	return getHeight(root->left) - getHeight(root->right);
}
void L(node *&root) {
	node *tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void R(node *&root) {
	node *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void insert(node *&root, int x) {
	if(!root) {
		node = new node(x);
		return;
	}
	if(x < root->data) {
		insert(root->left, x);
		updateHeight(root);
		if(balbanceFactor(root) == 2) {
			if(balbanceFactor(root->left) == 1) {
				R(root);
			} else if(balbanceFactor(root->left) == -1) {
				L(root->left);
				R(root);
			}
		}
	} else {
		insert(root->right, x);
		updateHeight(root);
		if(balbanceFactor(root) == -2) {
			if(balbanceFactor(root->right) == -1)  {
				L(root);
			} else if(balbanceFactor(root->right) == 1) {
				R(root->right);
				L(root);
			}
		}
	}
}
int main() {
	int n, t;
	node *tree = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t);
		insert(root, t);
	}
	printf("%d\n", root->data);
}