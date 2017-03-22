#include <iostream>
uisng namespace std;
int *pre, *in, n,f = 0;
void post(int root, int left, int right) {
	if(left > right) return;
	int i;
	for(i = left;i <= right; ++i)
		if(pre[root] == in[i]) break;
	post(root + 1, start, i - 1);
	post(i - start + 1 + root, i + 1, end);
	if(!f) {
		printf(" %d",pre[root]);
		f = 1;
	} else {
		printf(" %d", pre[root]);
	}
}
int main() {
	scanf("%d", &n);
	pre = new int [n];
	in = new int [n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i) 
		scanf("%d", &in[i]);
	post(0,0,n-1);
	delete [] pre,in;
}