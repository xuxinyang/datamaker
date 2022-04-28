#include <bits/stdc++.h>
using namespace std;

// 注意这里使用带参数的main函数，参数为输入文件名和输出文件名
 bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
string s;
int main(int argc, char const *argv[])
{
    // 添加代码开始
    string filename = argv[1];
    string outfilename = argv[2];
    freopen(filename.c_str(), "r", stdin);
    freopen(outfilename.c_str(), "w", stdout);
    // 添加代码结束
    cin >> s;
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !isVowel(s[i])) {
            i++;
        }
        while (i < j && !isVowel(s[j])) {
            j--;
        }
        swap(s[i], s[j]);
        i++;
        j--;
    }
    cout << s << endl;
    return 0;
}
