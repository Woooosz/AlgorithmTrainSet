#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> a,b;
int n,p=0;
int cmp(const int a,const int b) {
    return a<b;
}
void inorder(int i) {
    if(i > n) return;
    int left=2 * i + 1;
    int right=2 * i + 2;
    if(left < n) inorder(left);
    b[i]=a[p++];
    if(right < n) inorder(right);
    
}

int main() {
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end(),cmp);
    inorder(0);
    printf("%d",b[0]);
    for(int i=1;i<n;++i)
        printf(" %d",b[i]);
}