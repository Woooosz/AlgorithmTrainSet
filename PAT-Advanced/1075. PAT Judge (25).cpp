/*
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=104), the total number of users, K (<=5), the total number of problems, and M (<=105), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
需要考虑一种情况：即当某位选手提交某题多次都是编译未通过以及最后一次编译通过但是得分为0的情况
这个解决掉，测试点3和测试点5都会通过
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class per{
public:
    int id;
    vector<int> score;
    int total=0;
    int solve=0;
    int use=0;
    int flag=0;
};
bool comapare(const per &a,const per &b){
    bool ans=false;
    if(a.total>b.total) ans=a.total>b.total;
    else if(a.total==b.total && a.solve>b.solve) ans=true;
    else if(a.total==b.total && a.solve==b.solve && a.id<b.id) ans=true;
    else ans=(a.use>b.use);
    return ans;
}
int main() {
    //freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    vector<int> fullmark(k+1);
    for(int i=1;i<=k;++i)
        scanf("%d",&fullmark[i]);
    vector<per> in(10010);
    for(int i=0;i<m;++i) {
        int uid,pid,score;
        scanf("%d %d %d",&uid,&pid,&score);
        
        per &tmp=in[uid];
        tmp.id=uid;
        if(tmp.score.empty()) {
            tmp.score.resize(k+1);
            fill(tmp.score.begin(),tmp.score.end(),-1);
            tmp.use=1;
        }
        if(score==fullmark[pid] && score>tmp.score[pid]) tmp.solve++;
        if(score>=0)
            tmp.flag=1;
        if(tmp.score[pid]==-1) {
            if(score==-1) score=0;
            tmp.total+=score;
            tmp.score[pid]=score;
        } else {
            if(tmp.score[pid]<score) {
                tmp.total=tmp.total-tmp.score[pid]+score;
                tmp.score[pid]=score;
            }
        }

    }
    sort(in.begin(),in.end(),comapare);
    int cur=-1,index=-1;
    for(int i=0;i<n;++i) {
        if(!in[i].flag) break;
        if(cur!=in[i].total) {
            index=i;
            cur=in[i].total;
        }
        printf("%d %05d %d",index+1,in[i].id,in[i].total);
        for(int j=1;j<=k;++j) {
            if(in[i].score[j]>=0)
                printf(" %d",in[i].score[j]);
            else
                printf(" -");
        }
        printf("\n");
    }
}