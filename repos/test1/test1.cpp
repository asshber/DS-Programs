
#include <iostream>
#include<vector>
using namespace std;
class Result
{
public:
    int i;
    int j;
    int min = -98989898;
    Result() {}
    Result(int x, int y, int z) :i(x), j(y), min(z) {}
};
Result max(int* arr, int i, int n)
{

    if (i == n - 1)
        return Result(i, n - 1, arr[i]);

    Result next = max(arr, i + 1, n);
    Result s_max;
    s_max.i = i;
    int sum = 0;
    for (int j = i; j < n; j++)
    {
        sum += arr[j];
        if (sum > s_max.min)
        {
            s_max.j = j;
            s_max.min = sum;
        }
    }
    if (next.min > s_max.min)
    {
        return next;
    }

    return s_max;
}
int main()
{
    int n;
    cin >> n;
    if (!(n > 0))
    {
        exit(1);
    }
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Result ans = max(arr, 0, n);

    for (int i = ans.i; i <= ans.j; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << ans.min;
}

