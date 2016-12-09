#include<stdio.h>
#include<vector>

using namespace std;

struct node
{
	int exp;
	double conf;
};
int main() {
	int A,B;
	scanf("%d",&A);
	vector<node> a(A);
	for(int i=0;i<A;++i) 
		scanf("%d %f",&a[i].exp,&a[i].conf);
	scanf("%d",&B);
	vector<node> b(B);
	for(int i=0;i<B;++i) 
		scanf("%d %lf",&b[i].exp,&b[i].conf);
	vector<node> ans;
	int ans[20]={0};
	for(int i=0;i<A;++i) {
		for(int j=0;j<B;++j) {
			ans[a[i].exp+b[j].exp]=a[i].conf*b[i].conf;
		}
	}
	int count=0;
	for(int i=0;i<20;++i)
		if(ans[i]) count++;
	printf("%d",count);
	for(int i=20;i>=0;--i)
		printf(" %d %.1f",&i)
}