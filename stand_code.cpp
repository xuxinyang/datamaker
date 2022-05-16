#include <bits/stdc++.h>
using namespace std;
int n, a[10005], sum;
int main(int argc, char *argv[])
{
	string filename = argv[1];
	string outfilename = argv[2];
	freopen(filename.c_str(), "r", stdin);
	freopen(outfilename.c_str(), "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum;
    return 0;
}
