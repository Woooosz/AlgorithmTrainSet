#include<iostream>
#include<sstream>
using namespace std;
void print(string s) {
    cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
}
int main() {
    string s;
    int n,cnt=0,flag=0;
    double ans=.0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        cin>>s;
        flag=0;
        if(s.find('.')!=-1 && s.length()-s.find('.')>3) {
            print(s);
            continue;
        }
        for(int i=0;i<s.length();++i) {
            if(!((s[i]>='0' && s[i]<='9') || s[i]=='.' || s[i]=='-')) {
                print(s);
                flag=1;
                break;
            }
        }
        if(flag) continue;
        stringstream ss;
        ss<<s;
        double t;
        ss>>t;
        ss.clear();
        if(t < -1000 || t>1000) {
            print(s);
            continue;
        } else {
            ++cnt;
            ans+=t;
        }
    }
    if(cnt==0) cout<<"The average of 0 numbers is Undefined"<<endl;
    else if(cnt==1) printf("The average of 1 number is %.2lf",ans);
    else printf("The average of %d numbers is %.2lf\n",cnt,ans/cnt);
}