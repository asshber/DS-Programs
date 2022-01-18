#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    for (int gap = size / 2; gap >= 1; gap = gap / 2)
    {
        for (int j = gap; j < size; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (arr[i + gap] < arr[i])
                {
                    int temp = arr[i + gap];
                    arr[i + gap] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
