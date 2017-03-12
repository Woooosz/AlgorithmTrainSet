/*
1001. A+B Format (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991

*/
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,ans,f=0;
    scanf("%ld %ld",&a,&b);
    ans = a + b;
    string s;
    if(ans < 0)  {
        ans = ans * -1;
        f=1;
    }
    int m,n=0;
    if(ans==0) {
        cout<<0<<endl;
        return 0;
    }
    while(ans > 0) {
        m = ans % 10;
        s.insert(s.begin(),m + '0');
        ans/=10;
        n++;
        if(!(n % 3) && ans) s.insert(s.begin(),',');
    }
    if(f) s.insert(s.begin(),'-');
    cout<<s<<endl;
}