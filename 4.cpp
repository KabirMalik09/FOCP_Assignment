#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];  

    int l = 0, r = m - 1, t = 0, b = n - 1;
    int num = 1; 

    while (l <= r && t <= b) {
        
        for (int i = l; i <= r; i++) {
            arr[t][i] = num++;
        }
        t++;

        
        for (int i = t; i <= b; i++) {
            arr[i][r] = num++;
        }
        r--;

        
        if (t <= b) {
            for (int i = r; i >= l; i--) {
                arr[b][i] = num++;
            }
            b--;
        }

        
        if (l <= r) {
            for (int i = b; i >= t; i--) {
                arr[i][l] = num++;
            }
            l++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
