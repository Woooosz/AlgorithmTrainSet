#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
struct node{
    int exp;
    int a;
};
int main() {
    //freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    vector<node> x,y;
    node tmp;
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;++i) {
        scanf("%d %d",&tmp.a,&tmp.exp);
        x.push_back(tmp);
    }
    scanf("%d",&num);
    for(int i=0;i<num;++i) {
        scanf("%d %d",&tmp.a,&tmp.exp);
        y.push_back(tmp);
    }
    map<int,int> result;
    map<int,int> add_result;
    for(int i=0;i<x.size();++i) {
        for(int j=0;j<y.size();++j) {
            result[x[i].exp+y[j].exp]+=x[i].a*y[j].a;
        }
    }
    for(int i=0;i<x.size();++i)
        add_result[x[i].exp]+=x[i].a;
    for(int i=0;i<y.size();++i)
        add_result[y[i].exp]+=y[i].a;
    
    map<int,int>::reverse_iterator it;
    int flag=0;
    int flagx=0;
    for(it=result.rbegin();it!=result.rend();++it) {
        if(it->second==0 && it->first!=0) {
            continue;
        } else if(it->second==0 && it->first ==0) {
            continue;
        } else {
            flagx=1;
            if(flag) {
                printf(" %d %d",it->second,it->first);
            } else {
                printf("%d %d",it->second,it->first);
                flag=1;
            }
        }
    }
    if(flagx==0) {
        printf("0 0");
    }
    printf("\n");
    flag=0;
    flagx=0;
    for(it=add_result.rbegin();it!=add_result.rend();++it) {
        if(it->second==0 && it->first!=0) {
            continue;
        } else if(it->second==0 && it->first ==0) {
            continue;
        } else {
            flagx=1;
            if(flag) {
                printf(" %d %d",it->second,it->first);
            } else {
                printf("%d %d",it->second,it->first);
                flag=1;
            }
        }
    }
    if(flagx==0) {
        printf("0 0");
    }
}