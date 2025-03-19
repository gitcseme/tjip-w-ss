#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int number) {
    vector<int> pfs;
    int n = number;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            pfs.push_back(i);
            while (n % i == 0 && n > 0) {
                n /= i;
            }
        }
    }

    if (n != number && n > 1) {
        pfs.push_back(n);
    }
    return pfs;
}

int minTransformation(int s, int t) {
    vector<int> dist(t+1, INT_MAX / 2);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    
    while (!Q.empty()) {
        int u = Q.front();
        if (u == t) return dist[u];
        Q.pop();
        vector<int> pfs = getPrimeFactors(u);
        
        for (int prime : pfs) {
            int v = u + prime;
            if (dist[v] == INT_MAX/2 && v <= t) {
                Q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    
    return -1;
}

int main() {
    int s, t, T, cs = 1;
    cin >> T;
    
    while (T--) {
        cin >> s >> t;
        cout << "Case " << cs++ <<": " << minTransformation(s, t) << "\n";
    }
    
    return 0;
}
