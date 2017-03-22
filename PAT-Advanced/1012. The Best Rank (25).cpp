/*
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
这道题需要注意对结构体排序的时候，对某一单科成绩，成绩相同时候的处理。
1 2 2 3 // Error:count++
1 2 2 4//  Pass:count=j
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
    char id[10];
    int gpa;
};
int compare(const node &a,const node &b) {
    return (a.gpa>b.gpa) || (a.gpa==b.gpa && strcmp(a.id,b.id)<0);
}
int main() {
    int n,ma,pa,pb,pc;
    vector<node> c,m,e,a;
    scanf("%d %d",&n,&ma);
    char name[11];
    node tmp;
    for(int i=0;i<n;++i) {
        scanf("%s",name);
        scanf("%d %d %d",&pa,&pb,&pc);
        int avg=(pa+pb+pc);
        strcpy(tmp.id,name);
        tmp.gpa=pa;
        c.push_back(tmp);
        tmp.gpa=pb;
        m.push_back(tmp);
        tmp.gpa=pc;
        e.push_back(tmp);
        tmp.gpa=avg;
        a.push_back(tmp);
    }
    sort(c.begin(),c.end(),compare);
    sort(m.begin(),m.end(),compare);
    sort(e.begin(),e.end(),compare);
    sort(a.begin(),a.end(),compare);
    for(int i=0;i<ma;++i) {
        char query[10],res;
        scanf("%s",query);
        int rank,j,count;
        for(j=0,count=0;j<a.size();++j) {
            if(j>0 && a[j-1].gpa!=a[j].gpa) count=j;
            if(strcmp(query,a[j].id)==0) break;
        }
        if(j==a.size()) {
            printf("N/A\n");
            continue;
        }
        rank=count,res='A';
        for(j=0,count=0;j<c.size();++j) {
            if(j>0 && c[j-1].gpa!=c[j].gpa) count=j;
            if(strcmp(query,c[j].id)==0) break;
        }
        if(count<rank) rank=count,res='C';
        for(j=0,count=0;j<m.size();++j) {
            if(j>0 && m[j-1].gpa!=m[j].gpa) count=j;
            if(strcmp(query,m[j].id)==0) break;
        }
        if(count<rank) rank=count,res='M';
        for(j=0,count=0;j<e.size();++j) {
            if(j>0 && e[j-1].gpa!=e[j].gpa) count=j;
            if(strcmp(query,e[j].id)==0) break;
        }
        if(count<rank) rank=count,res='E';
        printf("%d %c\n",rank+1,res);
    }
}