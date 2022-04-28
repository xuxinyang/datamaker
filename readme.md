## 本文我们介绍如何使用testlib造数据
---
### 一、 安装testlib
> 在github中下载 <kbd>testlib.h</kbd>
> [点击链接下载](https://github.com/xuxinyang/testlib)
下载好后将该文件拷贝到当前目录或者mingw或者其它编译器的<kbd>include</kbd>目录下。

####  参考目录：
> C:\MinGW\include
> 上面是自己的mingw的安装路径，根据自己的情况修改

### 二、 找到一个题目
> 我们以 <kbd>[括号匹配](http://oj.hetao101.com/d/training/p/1415)</kbd>这个题目为例

### 三、 造输入数据
> 这里我们只需要造左括号和右括号即可，参考代码如下：
```C++
// gen_input.cpp
#include <bits/stdc++.h>
#include <testlib.h>
using namespace std;
stack<char> st;
void genData(string s)
{
    cout << s;
}

int main(int argc, char **argv)
{
    registerGen(argc, argv, 1); // register the random generator function
    string s;
    for (int i = 1; i <= 10; i++) // generate 10 test cases
    {
        startTest(i);
        // generate the input just have left and right bracket, the length is random from 1 to 1000
        int length = rnd.next(1, 1000);
        s = rnd.next("[()]{1, %d}", length);
        genData(s);
    }
    return 0;
}
```
**造其它数据找到相应的模板，修改对应的代码即可**

### 四、 造输出数据
> 这里我们只需要在我们的标程代码中添加几行代码即可，参考代码如下：
```C++
// stand_code.cpp
#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
// 注意这里我们要使用带参数的模板函数
int main(int argc, char const *argv[])
{
    // 添加代码开始
    string filename = argv[1];
    string outfilename = argv[2];
    freopen(filename.c_str(), "r", stdin);
    freopen(outfilename.c_str(), "w", stdout);
    // 添加代码结束
    cin >> s;
    int n = s.size();
    // 求删除多少个括号才能构成合法的括号
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}
```
### 五、 执行bat文件生成输入输出数据
> 这里为了方便大家操作已经将bat文件和编译器环境结合在一起，可以直接执行即可

![文件目录](https://s3.bmp.ovh/imgs/2022/04/25/7ba7b4ade55eb2f5.png)

> 运行脚本后的输出结果：

![输出结果](https://s3.bmp.ovh/imgs/2022/04/25/a624dd3535801e7a.png)

> 这样就可以看到我们的输入和输出数据了。

### 五、 上传数据

> 我们分别将input中的 <kbd>\*.in</kbd> 和output中 <kbd> \*.out</kbd>文件上传到OJ上即可
1. 输入文件：

![](https://s3.bmp.ovh/imgs/2022/04/25/e29412e989098dd6.png)
2. 输出文件：

![](https://s3.bmp.ovh/imgs/2022/04/25/770e01422ba3aab7.png)
3. 操作指引

![](https://s3.bmp.ovh/imgs/2022/04/25/e09bdf64ed8419be.png)

**<font face="宋体" color=red size=5>注意事项</font>**

> 保证生成输入数据的文件名为 gen_input.cpp
> 保证生成输出数据的文件名为 stand_code.cpp