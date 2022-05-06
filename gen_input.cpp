#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;

int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);    // register the random generator function
    for (int i = 1; i <= 100; i++) // generate 10 test cases
    {
        startTest(i);
        // 创造一个含元音字母的随机字符串，长度在1-3*10^5之间
        int n = rnd.next(1, 1000);
        printf("%d\n", n);
        for (int i = 1; i <= n; i++)
        {
            int x = rnd.next(1, 100);
            printf("%d ", x);
        }
    }
    return 0;
}