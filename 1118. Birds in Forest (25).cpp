/*
1118. Birds in Forest (25)

时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<= 104) which is the number of pictures. Then N lines follow, each describes a picture in the format:
K B1 B2 ... BK
where K is the number of birds in this picture, and Bi's are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than 104.

After the pictures there is a positive number Q (<= 104) which is the number of queries. Then Q lines follow, each contains the indices of two birds.

Output Specification:

For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line "Yes" if the two birds belong to the same tree, or "No" if not.

Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
Sample Output:
2 10
Yes
No
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAX 10001
vector<int> x(MAX);
int find(int index) {
	return x[index]<0?x[index]:(x[index]=find(x[index]));
}
void unions(int a,int b) {
	int roota=find(a);
	int rootb=find(b);
	if(roota!=rootb) {
		x[roota]=rootb;
	}
}
int main() {
	int num;
	cin>>num;
	int numa,tmp;
	map<int,int> dict;
	for(int i=0;i<num;++i) 
		x[i]=-1;
	for(int i=0;i<num;++i) {
		cin>>numa;
		for(int j=0;j<numa;++j) {
			cin>>tmp;
			if(dict.find(tmp)!=dict.end())
				unions(dict[tmp],i);
			dict[tmp]=i;
		}
	}
	int count=0;
	for(int i=0;i<num;++i) {
		if(x[i]<0)  count++;
	}
}