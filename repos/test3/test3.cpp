#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, m;
    char inp;
    cin >> n;
    cin >> m;
    char** arr = new char* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> inp;
            arr[i][j] = inp;
        }
    }
    int k;
    cin >> k;
    char** check = new char* [k];
    for (int i = 0; i < k; i++)
    {
        check[i] = new char[m];
    }
    fflush(stdin);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            inp = getchar();
            if (inp == 10)
            {
                break;
            }
            if (inp == 32)
            {
                j--;
                continue;
            }
            check[i][j] = inp;
        }
    }
    cout << check[1][5];
    return 0;
}