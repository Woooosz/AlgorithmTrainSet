#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pre[105], weight(105), tmppath, tmp;
vector<vector<int>> ans;
vector<bool> isNonleaf(105);
int s;
bool cmp(vector<int>a, vector<int> b){
    for (int i = 0; i < a.size() && i < b.size(); i++){
        if (a[i] == b[i])continue;
        else return a[i] > b[i];
    }
    if (a.size() > b.size()) return true;
    else return false;
}
void dfs(int v) {
    if(v == 0) {
        tmppath.push_back(v);
        int thisans = 0;
        for(int i = 0; i < tmppath.size(); ++i) {
            thisans += weight[tmppath[i]];
        }
        if(thisans == s)  {
            tmp.clear();
            for(int i = tmppath.size() - 1; i >= 0; --i) {
                tmp.push_back(weight[tmppath[i]]);
            }
            ans.push_back(tmp);
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(v);
    for(int i = 0; i < pre[v].size(); ++i) {
        dfs(pre[v][i]);
    }
    tmppath.pop_back();
}
int main() {
    int n, m;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; ++i)
        scanf("%d", &weight[i]);
    isNonleaf[0] = true;
    for(int i = 0; i < m; ++i) {
        int thisroot, k, p;
        scanf("%d %d", &thisroot, &k);
        isNonleaf[thisroot] = true;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &p);
            pre[p].push_back(thisroot);
        }
    }
    for(int i = 1; i < n; ++i) {
        if(!isNonleaf[i])
            dfs(i);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int j = 0; j < ans.size(); ++j) {
        printf("%d", ans[j][0]);
        for(int i = 1; i < ans[j].size(); ++i) {
            printf(" %d", ans[j][i]);
        }
        printf("\n");
    }
}