/*
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
对于字符串类型的vertex有两种处理方式
1.str2int,int2str，用map建立映射
2.直接把图的数据结构用map<string,vector<string>> 来表示
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;
map<string,vector<string>> arr;
map<string,int> weight,visit;
int n,lim,total,thismax,counts;
string head;
void bfs(string v) {
    queue<string> q;
    q.push(v);
    while(!q.empty()) {
        string tmp=q.front();
        q.pop();
        if(visit[tmp]==0) {
            visit[tmp]=1;
            ++counts;
            total+=weight[tmp];
            if(weight[tmp]>thismax) {
                head=tmp;
                thismax=weight[tmp];
            }
        }
        for(int i=0;i<arr[tmp].size();++i) {
            if(visit[arr[tmp][i]]==0)
                q.push(arr[tmp][i]);
        }
    }
}
int main() {
    //freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    int num;
    scanf("%d %d",&n,&lim);
    for(int i=0;i<n;++i) {
        string a,b;
        cin>>a>>b>>num;
        arr[b].push_back(a);
        arr[a].push_back(b);
        weight[a]+=num;
        weight[b]+=num;
        visit[a]=visit[b]=0;
    }
    map<string,int> ans;
    for(map<string,int>::iterator pi=visit.begin();pi!=visit.end();++pi) {
        if(pi->second==0) {
            //cout<<pi->first<<endl;
            total=0,head="",thismax=-1,counts=0;
            bfs(pi->first);
            if(counts>2 && total/2>lim) {
                ans[head]=counts;
            }
        }
    }
    printf("%d\n",ans.size());
    for(map<string,int>::iterator pi=ans.begin();pi!=ans.end();++pi) {
        cout<<pi->first<<" "<<pi->second<<endl;
    }
}
