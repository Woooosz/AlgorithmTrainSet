#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    int height;
    node(int _data):data(_data), left(0), right(0), height(1){}
};
inline int max(int a, int b){ return a > b ? a : b;}
int getHeight(node *root) {
    if(!root) return 0;
    else return root->height;
}
void updateHeight(node *&root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
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
        root = new node(x);
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
int f = 0;
bool bfs(node *root) {
    queue<node *> q;
    q.push(root);
    node *ptr;
    while(!q.empty()) {
        ptr = q.front();
        q.pop();
        if(!f) {
            printf("%d", ptr->data);
            f = 1;
        } else {
            printf(" %d", ptr->data);
        }
        if(ptr->left) q.push(ptr->left);
        if(ptr->right) q.push(ptr->right);
    }
    return true;
}
bool isCompleteTree(node *root) {
    queue<node *> q;
    node *p = root;
    int tag = 0;
    if(p == 0) return true;
    q.push(root);
    while(!q.empty()) {
        p = q.front(); q.pop();
        if(p->left && !tag) q.push(p->left);
        else if(p->left) return false;
        else tag = 1;
        if(p->right && !tag) q.push(p->right);
        else if(p->right) return false;
        else tag = 1;
    }
    return true;
}
int main() {
    node *root = 0;
    int n, t;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        insert(root, t);
    }
    bfs(root);
    if(isCompleteTree(root))
        printf("\nYES\n");
    else
        printf("\nNO\n");
}