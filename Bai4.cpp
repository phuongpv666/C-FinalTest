#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int find_min_steps(int n, int k, int m, int s, int f) {
    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int current_floor = q.front();
        q.pop();

        if (current_floor == f) {
            return dist[f];
        }

        vector<int> adjacent_floors;
        if (current_floor + k <= n) {
            adjacent_floors.push_back(current_floor + k);
        }
        if (current_floor - m >= 1) {
            adjacent_floors.push_back(current_floor - m);
        }

        for (int neighbor_floor : adjacent_floors) {
            if (dist[current_floor] + 1 < dist[neighbor_floor]) {
                dist[neighbor_floor] = dist[current_floor] + 1;
                q.push(neighbor_floor);
            }
        }
    }

    return -1;
}

int main() {
    int n, k, m, s, f;

    cout << "Nhap so tang cua toa nha (n): ";
    cin >> n;

    cout << "Nhap so tang len (k) va so tang xuong (m): ";
    cin >> k >> m;

    cout << "Nhap vi tri tang xuat phat (s) va vi tri tang dich (f): ";
    cin >> s >> f;

    int min_steps = find_min_steps(n, k, m, s, f);

    cout << "So buoc it nhat di chuyen thang may: " << min_steps << endl;

    return 0;
}

