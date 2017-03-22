#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    int left;
    int right;
};
vector<node> a;
vector<int> x;
int str2int(char *s) {
    int ans=0;
    while(*s!='\0') ans=ans*10+*(s++)-'0';
    return ans;
}
void inorder(int n) {
    if(a[a[n].left].left!=-1 || a[a[n].left].right!=-1)
        inorder(a[n].left);
    x.push_back(n);
    if(a[a[n].right].left!=-1 || a[a[n].right].left!=-1)
        inorder(a[n].right);
    
}
bool cmp(int a,int b) {
    return a<b;
}
int main() {
    freopen("/Users/shizhewu/a.in","r",stdin);
    int n,f=0;
    scanf("%d",&n);
    a.resize(n);
    vector<int> visit(n,0);
    char c[3],d[3];
    for(int i=0;i<n;++i) {
        scanf("%s %s",c,d);
        if(c[0]=='-') {
            a[i].left=-1;
            if(d[0]!='-')f=1;
        }
        else {
            int nc=str2int(c);
            visit[nc]=1;
            a[i].left=nc;
        }
        if(d[0]=='-') a[i].right=-1;
        else {
            int nd=str2int(d);
            visit[nd]=1;
            a[i].right=nd;
        }
    }
    int root = 0;
    for(int i=0;i<n;++i) {
        if(visit[i]==0) {
            root=i;
            break;
        }
    }
    if(f) printf("NO %d",root);
    inorder(root);
    vector<int> y=x;
    sort(y.begin(),y.end(),cmp);
    if(y==x) printf("YES %d",root);
}