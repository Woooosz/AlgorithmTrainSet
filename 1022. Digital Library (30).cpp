#include<iostream>
#include<vector>
#define MAX 10000
using namespace std;
struct book{
	char id[8];
	char title[81];
	char author[81];
	char keywords[81*6];
	char publisher[81];
	char publishedyear;
};
book in[MAX];
int main() {
	int num;
	scanf("%d",&num);
	char id[8];
	char title[81];
	char author[81];
	char keywords[6][81];
	char publisher[81];
	int publishedyear;
	for(int i=0;i<num;++i) {
		scanf("%s",in[i].id);
		scanf("%s",in[i].title);
		scanf("%s",in[i].author);
		scanf("%s",in[i].keywords);
		scanf("%s",in[i].publisher);
		scanf("%d",in[i].publishedyear);

	}
	int num2;
	scanf("%d",num2);
	for(int i=0;i<num2;++i) {
		char s[100];
		scanf("%s",query);
		char *pi;
		while(*pi!='\0') {
			
		}
	}
}