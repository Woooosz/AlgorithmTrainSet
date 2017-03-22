/*
1006. Sign In and Sign Out (25)

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
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133
时间的处理可以将时间转化为文字，不过直接用字符串比较更方便一些，代码也更加简便。
注意strcmp(a,b)>0
*/
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    char firstTime[20]="23:59:59";
    char lastTime[20]="00:00:00";
    int num;
    scanf("%d",&num);
    char in[20],out[20],no[20];
    char laster[20],firster[20];
    while(num--) {
        scanf("%s%s%s",no,in,out);
        if(strcmp(firstTime,in)>0) {
            strcpy(firstTime,in);
            strcpy(firster,no);
        }
        if(strcmp(lastTime,out)<0) {
            strcpy(laster,no);
            strcpy(lastTime,out);
        }
    }
    printf("%s %s",firster,laster);
}