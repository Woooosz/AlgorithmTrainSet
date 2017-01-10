//    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int find_min_window(vector<int> &window) {
    int index=-1;
    int min=0x7ffff;
    for(int i=0;i<window.size();++i) {
        if(window[i]<min) {
            min=window[i];
            index=i;
        }
    }
    return index;
}
int find_min_size(vector<queue<int>> q) {
    int index=-1;
    int min=0x7ffff;
    for(int i=0;i<q.size();++i) {
        if(q[i].size()<min) {
            min=q[i].size();
            index=i;
        }
    }
    return index;
}
int main() {
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    int n,m,k,qnum;
    scanf("%d %d %d %d",&n,&m,&k,&qnum);
    vector<int> prog(k+1),quer(qnum+1),ans(k+1);
    for(int i=1;i<=k;++i)
        scanf("%d",&prog[i]);
    for(int i=1;i<=qnum;++i)
        scanf("%d",&quer[i]);
    vector<int> window(m);
    vector<queue<int>> q(m);
    for(int i=1;i<=n*m;++i) {
        int a=find_min_size(q);
        q[a].push(i);
    }
    int index=n*m+1;
    for(int i=index;i<=k;) {
        for(int j=0;j<q.size();++j) {
            if(!q[j].empty()) {
                int cnum=q[j].front();
                q[j].pop();
                window[j]+=prog[cnum];
                ans[cnum]=window[j];
                int a=find_min_window(window);
                q[a].push(i++);
            }
        }

    }
    for(int i=0;i<q.size();++i) {
        while(!q[i].empty()) {
            int cnum=q[i].front();
            q[i].pop();
            window[i]+=prog[cnum];
            ans[cnum]=window[i];
        }
    }
    for(int i=1;i<=qnum;++i) {
        int hour=8;
        int min=ans[quer[i]];
        hour+=(min/60);
        min%=60;
        if(hour==17 && min>0)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n",hour,min);
    }
}
