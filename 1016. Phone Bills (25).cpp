#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct node {
    string name;
    int month;
    int day;
    int hour;
    int min;
    int status;
};
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    int cost[24];
    for(int i=0;i<24;++i)
        scanf("%d",&cost[i]);
    int N;
    scanf("%d",&N);
    map<string,double> ans;
    map<string,queue<node>> map_que;
    node tmp;
    string s;
    scanf("%d",&N);
    for(int i=0;i<N;++i) {
        cin>>tmp.name;
        scanf("%d:%d:%d:%d",&tmp.month,&tmp.day,&tmp.hour,&tmp.min);
        cin>>s;
        if(s=="on-line") {
            if( map_que[tmp.name].size()!=0 && map_que[tmp.name].front().status==1)
                map_que[tmp.name].pop();
            tmp.status=1;
        } else if(s=="off-line") {
            tmp.status=0;
        }
        map_que[tmp.name].push(tmp);
    }
    map<string,queue<node>>::iterator pi;
    queue<node> Q;
    for(pi=map_que.begin();pi!=map_que.end();++pi) {
        Q=pi->second;
        cout<<pi->first;
        printf(" %02d\n",Q.front().month);
        double total=0.0;
        double thistotal=0.0;
        int flag=0;
        node tmp0,tmp1;
        while(!Q.empty()) {
            if(!flag) {
                tmp=Q.front();
                Q.pop();
                flag++;
            } else {
                tmp1=Q.front();
                Q.pop();
                flag=0;
                if(tmp1.status==1 && tmp.status==0) swap(tmp1,tmp);
                //tmp是接通，tmp1是挂断
                printf("%02d:%02d:%02d %02d:%02d:%02d ",tmp.day,tmp.hour,tmp.min,tmp1.day,tmp1.hour,tmp1.min);
                printf("%d ",(tmp1.day-tmp.day)*24*60+(tmp1.hour-tmp.hour)*60-tmp.min+tmp1.min);
                int x=tmp1.day-tmp.day;
                for(int i=tmp.hour;i<tmp1.hour+24*x;++i)
                    thistotal+=(cost[i%24]*60);
                thistotal-=(tmp.min*cost[tmp.hour]);
                thistotal+=(tmp1.min*cost[tmp1.hour]);
                thistotal/=100;
                printf("$%.2lf\n",thistotal);
                total+=thistotal;
                thistotal=0.0;

            }
        }
        flag=0;
        printf("Total amount: $%.2lf\n",total);
    }
}