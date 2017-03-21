#include <iostream>
#include <vector>
using namespace std;
vector<int> post,in,level(1e4, -1);
void create(int root, int left, int right, int index) {
    if(left > right) return;
    int i = left;
    for(i = left; i <= right; ++i)
        if(in[i] == post[root]) break;
    level[index] = post[root];
    create(root - right + i - 1, left, i - 1, index * 2 + 1);
    create(root - 1, i + 1, right, index * 2 + 2);
}
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d",&n);
    post.resize(n); in.resize(n);
    for(int i =0 ;i < n; ++i)
        scanf("%d", &post[i]);
    for(int i =0 ;i < n; ++i)
        scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    printf("%d", level[0]);
    int cnt = 1;
    for(int i = 1; i < level.size(); ++i) {
        if(level[i] == -1)
            continue;
        printf(" %d", level[i]);
        ++cnt;
        if(cnt == n + 1) break;
    }
    printf("\n");
}