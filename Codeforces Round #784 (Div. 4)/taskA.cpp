#include <iostream>

using namespace std;

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        if (n <= 1399)
        {
            cout << "Division 4" << endl;
            continue;
        }
        if (n <= 1599)
        {
            cout << "Division 3" << endl;
            continue;
        }
        if (n <= 1899)
        {
            cout << "Division 2" << endl;
            continue;
        }
        cout << "Division 1" << endl;
    }
    return 0;
}
