#include<bits/stdc++.h>
using namespace std;

struct Compare {
  bool operator() (pair<int, int> below, pair<int, int> above) {
    return below > above;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> bt(n), p(n), wt(n), tat(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
  for (int i = 0; i < n; i++) {
    cin >> bt[i];
    p[i] = i + 1;
    q.push({bt[i], i});
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << ' ' << bt[i] << '\n';
  }
  int timer = 0;
  while (!q.empty()) {
    int BT = q.top().first;
    int P = q.top().second;
    q.pop();
    timer++;
    BT--;
    if (BT == 0) {
      tat[P] = timer;
    } else {
      q.push({BT, P});
    }
  }
  for (int i = 0; i < n; i++) {
    wt[i] = tat[i] - bt[i];
  }
  double wtavg = 0, tatavg = 0;
  for (int i = 0; i < n; i++) {
    wtavg += wt[i];
    tatavg += tat[i];
  }
  wtavg /= n;
  tatavg /= n;
  cout << "\nProcess\t    Burst Time\t  Waiting Time\t  Turnaround Time\n";
  for(int i = 0;i < n; i++) {
    cout << "\nP["<<p[i] <<"]" << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" <<tat[i];
  }
  cout << "\n\nAverage Waiting Time: " << wtavg;
  cout << "\nAverage Turnaround Time: " << tatavg;
  return 0;
}