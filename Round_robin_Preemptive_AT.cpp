#include<bits/stdc++.h>
using namespace std;

struct Process {
  int id;
  int at;
  int bt;
};

bool cmp(Process p1, Process p2) {
  return p1.at < p2.at;
}

int main() {
  freopen("inputat.txt", "r", stdin);
  int n;
  cin >> n;
  vector<Process> p(n);
  vector<int>  wt(n), tat(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].at >> p[i].bt;
    p[i].id = i;
  }
  int time_quantum;
  cin >> time_quantum;
  sort(p.begin(), p.end(), cmp);
  queue<Process> q;
  int timer = 0;
  int completed = 0;
  int ptr = 0;
  double tatavg = 0.0;
  double wtavg = 0.0;
  while (completed < n) {
    if (ptr < n && p[ptr].at <= timer) {
      q.push(p[ptr++]);
    }
    if (q.empty()) {
      timer++;
      continue;
    }
    Process t = q.front();
    q.pop();
    int id = t.id;
    if (t.bt <= time_quantum) {
      timer += t.bt;
      while (ptr < n && p[ptr].at <= timer) {
        q.push(p[ptr++]);
      }
      completed++;
      tat[id] = timer - t.at;
      wt[id] = tat[id] - t.bt;
      tatavg += tat[id];
      wtavg += wt[id];
    } else {
      timer += time_quantum;
      while (ptr < n && p[ptr].at <= timer) {
        q.push(p[ptr++]);
      }
      t.bt -= time_quantum;
      q.push(t);
    }
  }
  tatavg /= n;
  wtavg /= n;
  cout << "\nProcess\t   Arrival Time\t   Burst Time\t  Waiting Time\t  Turnaround Time\n";
  for (int i = 0; i < n; i++) {
    cout << "\n" << i + 1 << "\t\t" << p[i].at << "\t\t" << p[i].bt << "\t\t" << wt[i] << "\t\t" <<tat[i];
  }
  cout << "\n\nAverage Waiting Time: " << wtavg;
  cout << "\nAverage Turnaround Time: " << tatavg;
  return 0;
}