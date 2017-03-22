#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> cnt;
inline int max(int a,int b){return a>b?a:b;}
struct node {
    int data;
    int level;
    node *left,*right;
    node(int x):data(x),level(0),left(0),right(0){}
};
void insert(node *&t,int x) {
    if(!t) {
        t=new node(x);
        return;
    }
    if(x > t->data) insert(t->right,x);
    else insert(t->left,x);
}
int bfs(node *t) {
    queue<node *> q;
    q.push(t);
    int maxcnt=0;
    while(!q.empty()) {
        node *p=q.front();
        q.pop();
        cnt[0]=1;
        if(p->left) {
            cnt[p->level+1]++;
            maxcnt=max(p->level+1,maxcnt);
            p->left->level=p->level+1;
            q.push(p->left);
        }
        if(p->right) {
            cnt[p->level+1]++;
            maxcnt=max(p->level+1,maxcnt);
            p->right->level=p->level+1;
            q.push(p->right);
        }
    }
    return maxcnt;
}
int main() {
    int n,p;
    node *tree=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&p);
        insert(tree, p);
    }
    cnt.resize(n);
    int maxcnt=bfs(tree);
    printf("%d + %d = %d\n",cnt[maxcnt],cnt[maxcnt-1],cnt[maxcnt]+cnt[maxcnt-1]);
}