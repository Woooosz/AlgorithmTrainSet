/*
1036. Boys vs Girls (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference gradeF-gradeM. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA
之前只通过了两个测试点，不过把sex[2]换成char类型就一下子ac了= =
！(compare(tmp.sex,"M"))
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct node {
	char name[10];
	char sex[2];
	char id[20];
	int grade;
}
int compare(const node &a,const node &b) {
	return a.grade >b.grade
}
int main() {
	int num;
	cin>>num;
	vector<node> male,female;
	node tmp;
	while(num--) {
		scanf("%s %s %s %d",&tmp.name,&tmp.sex,&tmp.id,&tmp.grade);
		if(!strcmp(sex,"M")) // Male
			male.push_back(tmp);
		else 
			female.push_back(tmp);
	}
	sort(male.begin(),male.end(),compare);
	sort(female.begin(),female.end(),compare);
	//Find the lowest grade of all the male students
	//Find the highest grade of all female students
	int grade=female[0].grade-male[male.size()-1].grade;
	printf("%s %s\n",female[0].name,female[0].id);
	printf("%s %s\n",male[male.size()-1].name,male[male.size()-1].id);
	printf("%d\n",grade);
}