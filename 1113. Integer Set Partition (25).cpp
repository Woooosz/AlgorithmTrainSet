#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(const int a,const int b) {
    return a<b;
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end(),compare);
    if(n%2) {
        cout<<1<<" "; //余1
    } else {
        cout<<0<<" ";
    }
    int suma=0,sumb=0,i;
    for(i=0;i<n/2;++i)
        suma+=a[i];
    for(i=n/2;i<a.size();++i)
        sumb+=a[i];
    cout<<sumb-suma<<endl;
    
}