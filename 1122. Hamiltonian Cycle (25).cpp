#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxv = 205;
const int INF = ~(1<<31);
int arr[maxv][maxv];
int main() {
    //freopen("D:\\1.txt", "r", stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < maxv; ++i) {
		for(int j = 0; j < maxv; ++j) {
			arr[i][j] = i == j ? 1 : INF;
		}
	}
	int a,b;
	for(int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		arr[b][a] = arr[a][b] = 1;
	}
	int caseNum, vecNum;
	vector<int> e, cnt(n+1);
	scanf("%d", &caseNum);
	for(int i = 0; i < caseNum; ++i) {
		scanf("%d", &vecNum);
		e.resize(vecNum);
        fill(cnt.begin(), cnt.end(), 0);
		for(int j = 0; j < vecNum; ++j) {
			scanf("%d", &e[j]);
		}
		if((vecNum < n) || (e[0] != e[vecNum - 1])) {
			printf("NO\n");
			continue;
		}
		int f = 0;
		for(int j = 0; j < vecNum - 1; ++j) {
			int cur = e[j], next = e[j + 1];
			if(arr[cur][next] != 1 || cnt[cur] != 0) {
				printf("NO\n");
				f = 1;
				break;
			} else {
                cnt[cur]++;
			}
		}
		if(!f) printf("YES\n");
	}
}