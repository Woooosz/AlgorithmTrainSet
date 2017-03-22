/*
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:

For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
inline int min(int a,int b) {return a<b?a:b;}
int main() {
    //freopen("/Users/shizhewu/a.in","r",stdin);
    char s1[65],s2[65],s3[65],s4[65];
    scanf("%s %s %s %s",s1,s2,s3,s4);
    vector<string> week={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int count=0;
    for(int i=0;i<65;++i) {
        if(count==0 && s1[i]==s2[i] && s1[i]>='A' && s1[i]<='G') {
            ++count;
            printf("%s ",week[s1[i]-'A'].c_str());
            continue;
        }
        if(s1[i]==s2[i] && s1[i]>='A' && s1[i]<='N' && count==1) {
            printf("%02d:",s1[i]-'A'+10);
            break;
        } else if(s1[i]==s2[i] && s1[i]>='0' && s1[i]<='9' && count==1) {
            printf("%02d:",s1[i]-'0');
            break;
        }
    }
    for(int i=0;i<65;++i) {
        if(s3[i]==s4[i] && ((s3[i]>='a' && s3[i]<='z') || ((s3[i]>='A' && s3[i]<='Z')))) {
            printf("%02d\n",i);
            return 0;
        }
    }
}
