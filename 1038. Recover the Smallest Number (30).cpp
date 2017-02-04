/*
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:

Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the smallest number in one line. Do not output leading zeros.

Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const string a,const string b) {
    return a+b<b+a;
}
int main() {
    int n;
    scanf("%d",&n);
    vector<string> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a.begin(),a.end(),cmp);
    string ss;
    for(int i=0;i<n;++i) {
        ss+=a[i];
    }
    while(ss[0]=='0')
        ss=ss.substr(1,-1);
    if(ss.empty()) ss="0";
    cout<<ss<<endl;

}