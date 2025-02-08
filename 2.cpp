#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter" << " " << n << " " << "numbers : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    cout << "Now reversed array is :";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    int largest = arr[0], secondLargest = -1;
    int smallest = arr[0], secondSmallest = -1;

    for (int i = 1; i < n; i++)
    {
        
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }

       
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] != smallest)
        {
            secondSmallest = arr[i];
        }
    }

    cout << "Second Smallest Element: " << secondSmallest << endl;
    cout << "Second Largest Element: " << secondLargest << endl;

    return 0;
}
