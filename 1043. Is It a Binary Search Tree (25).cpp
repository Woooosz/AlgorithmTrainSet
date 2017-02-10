#include<iostream>
#include<vector>
using namespace std;
struct node {
    int data;
    node *left,*right;
    node(int x):data(x),left(0),right(0){}
};
void insert(node *&t,int x){
    if(!t) {
        t=new node(x);
        return;
    }
    if(x >= t->data) insert(t->right,x);
    else insert(t->left,x);
}
void insertM(node *&t,int x) {
    if(!t) {
        t=new node(x);
        return;
    }
    if(x < t->data) insertM(t->right,x);
    else insertM(t->left,x);
}
void preOrder(node *t,vector<int> &a) {
    if(!t) return;
    a.push_back(t->data);
    preOrder(t->left, a);
    preOrder(t->right, a);
}
void postOrder(node *t,vector<int> &a) {
    if(!t) return;
    postOrder(t->left,a);
    postOrder(t->right,a);
    a.push_back(t->data);
}
int main() {
    int n,data,f=0;
    vector<int> a,b,c,d,e;
    node *tree=0,*treeM=0;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>data;
        a.push_back(data);
        insert(tree,data);
        insertM(treeM,data);
    }
    preOrder(tree,b);
    preOrder(treeM,c);
    postOrder(tree,d);
    postOrder(treeM,e);
    if(a == b) {
        printf("YES\n");
        for(int i=0;i<n;++i) {
            if(!f) {
                printf("%d",d[i]);
                f=1;
            } else printf(" %d",d[i]);
        }
    } else if(a == c) {
        printf("YES\n");
        for(int i=0;i<n;++i) {
            if(!f) {
                printf("%d",e[i]);
                f=1;
            } else printf(" %d",e[i]);
        }
    } else {
        printf("NO");
    }
    printf("\n");
}