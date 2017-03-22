#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node {
    int parent;
    int left;
    int right;
    node():parent(-1),left(-1),right(-1){}
};
vector<node> a;
int n,last;
int char2int(char *s) {
    int ans=0;
    while(*s!='\0')
        ans=ans * 10 + *s++ - '0';
    return ans;
}
int findRoot() {
    int i=-1;
    for(i=0;i < n && a[i].parent!=-1;++i);
    return i;
}
bool levelOrder(int root) {
    queue<int> q;
    q.push(root);
    int cnt=0;
    while(q.front()!=-1) {
        int tmp=q.front();
        q.pop();
        q.push(a[tmp].left);
        q.push(a[tmp].right);
        last=tmp;
        ++cnt;
    }
    if(cnt==n) return true;
    else return false;
}
int main() {
    scanf("%d\n",&n);
    a.resize(n);
    char c[3],d[3];
    for(int i=0;i<n;++i) {
        scanf("%s %s",c,d);
        if(c[0]!='-') {
            int e=char2int(c);
            a[i].left=e;
            a[e].parent=i;
        }
        if(d[0]!='-') {
            int f=char2int(d);
            a[i].right=f;
            a[f].parent=i;
        }
    }
    int root=findRoot();
    if(levelOrder(root)) printf("YES %d",last);
    else printf("NO %d",root);
}