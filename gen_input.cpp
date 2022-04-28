#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;

int main(int argc, char **argv)
{
    registerGen(argc, argv, 1); // register the random generator function
    for (int i = 1; i <= 10; i++) // generate 10 test cases
    {
        startTest(i);
        // 创造一个含元音字母的随机字符串，长度在1-3*10^5之间
        string s;
        int len = rnd.next(1, 10);
        cout << rnd.next("[0-9][1-9]{1,%d}", len) << endl;
    }
    return 0;
}