#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> v[i] >> w[i];
        
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i - v[j] >= 0)
                f[i] = max(f[i], f[i - v[j]] + w[j]);
        }
    
    cout << f[m] << endl;
}
