#include <bits/stdc++.h>
using namespace std;
struct ST_DATA
{
    int start;  // from start to end
    int end;    // from start to end
    int range;  // data range
};
ST_DATA st_data[10];
int main()
{
    cout << "-------------------------------TEST CASE GENERATOR-------------------------------" << endl;
    cout << " # Example: 1 10 (create 1 group and 10 test cases.)" << endl;
    cout << " # Example: 1 10 100 (start=1, end=10, range<=100)" << endl;
    cout << "Please input how many test cases do you want to create and sum cases: ";
    int n, sum;
    cin >> n >> sum;
    for (int i = 1; i <= n; i++)
    {
        cout << "Please input the start, end and range of the group " << i << " test case: ";
        cin >> st_data[i].start >> st_data[i].end >> st_data[i].range;
    }
    // write the test cases to the config file
    ofstream fout("data.config");
    fout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        fout << st_data[i].start << " " << st_data[i].end << " " << st_data[i].range << endl;
    }
    fout.close();
    // judge the test cases
    ifstream fin("data.config");
    int n_tmp;
    fin >> n_tmp;
    if (n_tmp != n)
    {
        cout << "Failed to generate the test cases!" << endl;
        return 0;
    }
    cout << "Test cases created successfully!" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    return 0;
}