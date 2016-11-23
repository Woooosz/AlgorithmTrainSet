#include<stdio.h>
#include<map>

using namespace std;

int main() {
    int n,tmp;
    map<int,int> age;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&tmp);
        age[tmp]++;
    }
    map<int,int>::iterator pi;
    for(pi=age.begin();pi!=age.end();++pi) {
        printf("%d:%d\n",pi->first,pi->second);
    }
}