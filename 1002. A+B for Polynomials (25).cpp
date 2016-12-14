/*
1002. A+B for Polynomials (25)

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
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
如果系数为零，就不用压入结果数组中。
*/
#include<stdio.h>
#include<algorithm>

using namespace std;

struct node {
	int exp;
	double coef;
};
int main() {
	int ploA,ploB;
	scanf("%d",&ploA);
	vector<node> A(ploA);
	for(int i=0;i<ploA;++i) 
		scanf("%d %d",&A[i].exp,&A[i].coef);
	scanf("%d",&ploB);
	vector<node> B(ploB);
	for(int i=0;i<ploB;++i)
		scanf("%d %d",&B[i].exp,&A[i].coef);
	vector<node> ans;
	int i=0,j=0,k=0;
	node tmp;
	for(;i<ploA||k<ploB;) {
		if(A[i].exp>B[i].exp) {
			ans.push_back(A[i]);
			i++;
		}
		if(A[i].exp==B[i].exp) {
			tmp.exp=A[i].exp;
			tmp.coef=A[i].coef+B[i].coef;
			if(tmp.coef!=0) ans.push_back(tmp); //if coef==0 just skip
			i++,j++;
		}
		if(A[i].exp<B[i].exp) {
			ans.push_back(A[j]);
			j++;			
		}
	}
	for(;i<ploA;++i)
		ans.push_back[A[i]];
	for(;j<ploB;++j)
		ans.push_back[B[j]];
	printf("%d",ans.size()+1);
	for(int i=0;i<ans.size();++i) {
		prinf(" %d %.1f",ans[i].exp,ans[i].coef)
	}
}