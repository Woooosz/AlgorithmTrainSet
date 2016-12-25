#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#define MAX 10001
using namespace std;
vector<int> map[MAX];
int visit[MAX];
int deep[MAX];
int vt;
int _max;
inline int max(int a,int b) {
    return a>b?a:b;
}
void dfs1(int index) {
    visit[index]=1;
    for(int i=0;i<map[index].size();++i) {
        if(!visit[map[index][i]])
            dfs1(map[index][i]);
    }
}
int dfs2(int index) {
    int deep=0;
    visit[index]=1;
    for(int i=0;i<map[index].size();++i) {
        if(!visit[map[index][i]]) {
            int tmp=dfs2(map[index][i]);
            deep=max(deep,tmp);
        }
    }
    return deep+1;
}
int main() {
    cin>>vt;
    int va,vb;
    for(int i=0;i<vt-1;++i) {
        cin>>va>>vb;
        map[va].push_back(vb);
        map[vb].push_back(va);
    }
    memset(visit,0,sizeof(visit));
    int count=0;
    for(int i=1;i<=vt;++i) {
        if(!visit[i]) {
            count++;
            dfs1(i);
        }
    }
    if(count!=1) {
        cout<<"Error: "<<count<<" components"<<endl;
        return 0;
    }
    
    memset(deep,0,sizeof(deep));
    for(int i=1;i<=vt;++i) {
        memset(visit,0,sizeof(visit));
        deep[i]=dfs2(i);
    }
    for(int i=1;i<=vt;++i) _max=max(_max,deep[i]);
    for(int i=1;i<=vt;++i) {
        if(deep[i]==_max) {
            cout<<i<<endl;
        }
    }
}