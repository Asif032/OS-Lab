#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> bt(n), p(n), wt(n), tat(n);
  for (int i = 0; i < n; i++) {
    cin >> bt[i];
    p[i] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (bt[j] > bt[j + 1]) {
        int temp = bt[j];
        bt[j] = bt[j + 1];
        bt[j + 1] = temp;

        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << ' ' << bt[i] << '\n';
  }
  int timer = 0;
  for (int i = 0; i < n; i++) {
    timer += bt[i];
    tat[i] = timer;
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