/*
1025. PAT Ranking (25)

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
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
PS:之前对学生编号属性使用了long int(看到最后成绩相同时按照编号大小排序)，结果造成最后一个测试点超时。
仔细想一想字符串比较也是可以的，换成string之后，成功AC
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct node{
    string No;
    int grade;
    int index=0;
    int location;
};
bool sorts(const node &v1,const node &v2) {
    return (v1.grade>v2.grade || ((v1.grade==v2.grade)&& (v1.No<v2.No)));
}
int main() {
    freopen("/Users/shizhewu/Desktop/ls/1.txt","r",stdin);
    int num,N;
    node node_a;
    cin>>num;
    vector<vector<node> >arr;
    vector<node> all;
    vector<node> tmp_node;
    for(int i=0;i<num;++i) {
        cin>>N;
        for(int j=0;j<N;++j) {
            cin>>node_a.No>>node_a.grade;
            node_a.location=i+1;
            tmp_node.push_back(node_a);
        }
        arr.push_back(tmp_node);
        tmp_node.clear();
    }
    int k=0,index;
    for(int i=0;i<num;++i) {
        sort(arr[i].begin(),arr[i].end(),sorts);
        k=arr[i][0].grade;
        index=1;
        for(int j=0;j<arr[i].size();++j) {
            if(arr[i][j].grade!=k) {
                index=j+1;
                k=arr[i][j].grade;
            }
            arr[i][j].index=index;
            all.push_back(arr[i][j]);
        }
    }
    sort(all.begin(),all.end(),sorts);
    cout<<all.size()<<endl;
    index =1;k=all[0].grade;
    for(int i=0;i<all.size();++i) {
        if(all[i].grade!=k) {
            index=i+1;
            k=all[i].grade;
        }
        cout<<all[i].No<<" "<<index<<" "<<all[i].location<<" "<<all[i].index<<endl;
    }
}