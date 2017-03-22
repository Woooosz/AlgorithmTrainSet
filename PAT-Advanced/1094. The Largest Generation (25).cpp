/*
1094. The Largest Generation (25)

时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
无权重的单源最短路径算法（BFS基础上改编）
*/
#include<iostream>
#include<map>
#include<queue>
#define MAX 200
using namespace std;
vector<int> arr[MAX];
int dist[MAX];
int visit[MAX];

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    int N,M;
    cin>>N>>M;
    map<int,int> dict;
    for(int i=1;i<=N;++i) {
        dist[i]=-1;
        visit[i]=-1;
    }
    for(int i=0;i<M;++i) {
        int thisroot,child_num,child;
        cin>>thisroot>>child_num;
        for(int j=0;j<child_num;++j) {
            cin>>child;
            arr[thisroot].push_back(child);
            arr[child].push_back(thisroot);
        }
    }
    queue<int> Q;
    Q.push(1);
    dist[1]=1;
    while(!Q.empty()) {
        int tmp=Q.front();
        Q.pop();
        visit[tmp]=1;
        for(int i=0;i<arr[tmp].size();++i) {
            if(visit[arr[tmp][i]]<0) {
                dict[dist[tmp]+1]++;
                dist[arr[tmp][i]]=dist[tmp]+1;
                Q.push(arr[tmp][i]);
            }
        }
    }
    map<int,int>::iterator pi;
    int max=1,index=1;
    for(pi=dict.begin();pi!=dict.end();++pi) {
        if(pi->second > max) {
            index=pi->first;
            max=pi->second;
        }
    }
    cout<<max<<" "<<index<<endl;
}