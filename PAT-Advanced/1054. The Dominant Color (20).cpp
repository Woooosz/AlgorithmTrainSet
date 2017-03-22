#include<iostream>
#include <map>
using namespace std;
int main() {
    int n,m,t,f=0;
    scanf("%d %d",&n,&m);
    map<int,int> p;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            scanf("%d",&t);
            if(++p[t] >= n*m/2)  {
                printf("%d",t);
                f=1;
                break;
            }
        }
        if(f) break;
    }
}