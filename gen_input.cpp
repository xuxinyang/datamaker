#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;

int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);    // register the random generator function
    // 取得第一个参数，即生成的测试用例的起始数字
    int start = atoi(argv[1]);
    // 取得第二个参数，即生成的测试用例的结束数字
    int end = atoi(argv[2]);
    // 取得第三个参数，即生成的测试用例的数据范围
    int range = atoi(argv[3]);
    for (int i = start; i <= end; i++) // generate (end-start+1) test cases
    {
        startTest(i);
        int n = rnd.next(1, range);
        printf("%d\n", n);
        for (int i = 1; i <= n; i++)
        {
            int x = rnd.next(1, 100);
            printf("%d ", x);
        }
    }
    return 0;
}