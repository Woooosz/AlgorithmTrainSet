#include<iostream>
#include<vector>
using namespace std;

int main() {
    int num;
    scanf("%d",&num);
    vector<int> arr(num);
    for(int i=0;i<num;++i) {
        scanf("%d",&arr[i]);
    }
    pair<int,int> a;
    int start=0,end=0,thistotal=0,total=-1,flag=0;
    for(int i=0;i<num;++i) {
        thistotal+=arr[i];
        if(arr[i]>=0) flag=1;
        if(thistotal>=0) {
            end=i;
        }
        if(thistotal>total) {
            a.first=start;
            a.second=end;
            total=thistotal;
        }
        if(thistotal<0 && i<num-1) {
            thistotal=0;
            start=i+1;
        }
    }
    if(!flag)
        printf("0 %d %d\n",arr[0],arr[num-1]);
    else
        printf("%d %d %d\n",total,arr[a.first],arr[a.second]);
}