#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

struct node {
    int parent;
    int left;
    int right;
    node():parent(-1),left(-1),right(-1){}
};
vector<node> a;
int n,f=0;;
int findRoot() {
    int b=-1;
    for(int i=0;i<n;++i) {
        if(a[i].parent == -1) {
            b=i;
            break;
        }
    }
    return b;
}
void level(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int p=q.front();
        q.pop();
        if(!f) {
            printf("%d",p);
            f=1;
        } else {
            printf(" %d",p);
        }
        if(a[p].left!=-1) q.push(a[p].left);
        if(a[p].right!=-1) q.push(a[p].right);
    }
}
void inOrder(int root) {
    if(root == -1) return;
    inOrder(a[root].left);
    if(!f) {
        printf("%d",root);
        f=1;
    } else {
        printf(" %d",root);
    }
    inOrder(a[root].right);
}
int main() {
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;++i) {
        char b[3],c[3];
        scanf("%s %s",b,c);
        if(b[0]!='-') {
            int nb=atoi(b);
            a[i].right = nb;
            a[nb].parent=i;
            
        }
        if(c[0]!='-') {
            int nc=atoi(c);
            a[i].left = atoi(c);
            a[nc].parent=1;
        }
    }
    int root=findRoot();
    level(root);
    f=0;
    printf("\n");
    inOrder(root);
    printf("\n");
}