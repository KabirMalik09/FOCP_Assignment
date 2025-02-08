#include <iostream>
using namespace std;

int main()
{
    int a, n, number = 1;

    cout << "Enter the number: ";
    cin >> a;

    if (a <= 1)
    {
        number = 0;
    }
    else
    {
        for (n = 2; n <= a / 2; n++)
        {
            if (a % n == 0)
            {
                number = 0;
                break;
            }
        }
    }

    if (number == 1)
    {
        cout << "Prime no.";
        while (a > 2)
        {
            a++;
            for (n = 2; n < a; n++)
            {
                if (a % n == 0)
                {
                    break;
                }
            }
            if (n == a)
            {
                cout << "Next Prime no. is " << a;
                break;
            }
        }
    }
    else
    {
        cout << "Composite no." << endl
             << "The Factors are:" << endl;
        for (n = 2; n < a; n++)
        {
            if (a % n == 0)
            {
                cout << n << " ";
            }
        }
    }
    return 0;
}
