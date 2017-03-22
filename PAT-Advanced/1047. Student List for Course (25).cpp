//    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
    
using namespace std;    
int compare(const char *name1, const char *name2){return strcmp(name1,name2)<0;}
    
int main(){
    //freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    int N,K,C,num;
    cin >> N >> K;
    vector<vector<char*> > course(K+1);
    for(int i = 0; i < N; i++){
       char* name = new char[4];
       scanf("%s%d",name,&C);
          for(int j = 0; j < C; j++){
            scanf("%d",&num);
            course[num].push_back(name);
            }
        }
    for(int j = 1; j <= K; j++){
        sort(course[j].begin(),course[j].end(),compare);
        printf("%d %d\n",j,course[j].size());
        for(int k = 0; k < course[j].size(); k++){
            printf("%s\n",course[j][k]);
        }
    }
    return 0;
}