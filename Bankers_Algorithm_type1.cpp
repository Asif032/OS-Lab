#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int n, r;
  cin >> n >> r;
  vector<int> total(r), available(r);
  for (int i = 0; i < r; i++) {
    cin >> total[i];
    available[i] = total[i];
  }
  vector<vector<int>> allocated(n, vector<int> (r));
  vector<vector<int>> max_need(n, vector<int> (r));
  vector<vector<int>> curr_need(n, vector<int> (r));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++) {
      cin >> max_need[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++) {
      cin >> allocated[i][j];
      available[j] -= allocated[i][j];
      curr_need[i][j] = max_need[i][j] - allocated[i][j];
    }
  }
  int completed = 0;
  vector<int> exc_sequence;
  vector<bool> used(n);
  cout << "Process\tCurrent Needs\tAvailable\n\n";
  while (completed < n) {
    int id = -1;
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      bool ok = true;
      for (int j = 0; j < r; j++) {
        if (curr_need[i][j] > available[j]) {
          ok = false;
        }
      }
      if (ok) {
        id = i;
        break;
      }
    }
    if (id == -1) break;
    completed++;
    used[id] = true;
    exc_sequence.push_back(id + 1);
    cout << " P["<<id + 1<<"]\t  ";
    for (int i = 0; i < r; i++) {
      cout << curr_need[id][i] << " ";
    }
    cout << "\t ";
    for (int i = 0; i < r; i++) {
      cout << available[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < r; i++) {
      available[i] += allocated[id][i];
    }
  }
  if (completed < n) {
    cout << "System is in unsafe state\n";
  } else {
    for (int p : exc_sequence) {
      cout << p << ' ';
    }
    cout << '\n';
  }
  return 0;
}