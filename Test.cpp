#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
};

struct CompareBurstTime {
    bool operator()(Process const& p1, Process const& p2) {
        return p1.burst_time > p2.burst_time;
    }
};

void calculateWaitingTime(Process proc[], int n, int wt[]) {
    int remaining_time[n];
    for(int i=0; i<n; i++) {
        remaining_time[i] = proc[i].burst_time;
    }

    priority_queue<Process, vector<Process>, CompareBurstTime> pq;
    int current_time = 0;
    int completed = 0;
    bool flag = false;

    while(completed != n) {
        for(int i=0; i<n; i++) {
            if(proc[i].arrival_time <= current_time && remaining_time[i] > 0) {
                pq.push(proc[i]);
                flag = true;
            }
        }

        if(!flag) {
            current_time++;
            continue;
        }

        Process curr_proc = pq.top();
        pq.pop();
        int index = curr_proc.pid;
        wt[index] += current_time - proc[index].arrival_time;
        remaining_time[index]--;

        if(remaining_time[index] == 0) {
            completed++;
            flag = false;
            int finish_time = current_time + 1;
            int turnaround_time = finish_time - proc[index].arrival_time;
            cout << "Process " << proc[index].pid << "\t\t"
                 << proc[index].burst_time << "\t\t"
                 << proc[index].arrival_time << "\t\t"
                 << finish_time << "\t\t\t"
                 << turnaround_time << "\t\t\t"
                 << wt[index] << "\n";
        }
        current_time++;
    }
}

void calculateTurnaroundTime(Process proc[], int n, int wt[], int tat[]) {
    for(int i=0; i<n; i++) {
        tat[i] = proc[i].burst_time + wt[i];
    }
}

void calculateAvgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    calculateWaitingTime(proc, n, wt);
    calculateTurnaroundTime(proc, n, wt, tat);

    cout << "\nProcesses  Burst time  Arrival time  Finish time  Turnaround time  Waiting time\n";
    for(int i=0; i<n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turnaround time = " << (float)total_tat / (float)n;
}

int main() {
    freopen("inputat.txt", "r", stdin);
    int n;
    // cout << "Enter the number of processes: ";
    cin >> n;
    Process proc[n];
    for(int i=0; i<n; i++) {
        // cout << "Enter the burst time and arrival time of process " << i << ": ";
        cin >> proc[i].arrival_time >> proc[i].burst_time;
        proc[i].pid = i;
    }

    sort(proc, proc+n, [](Process a, Process b) {
      return a.arrival_time < b.arrival_time;
    });

    calculateAvgTime(proc, n);

    return 0;
}
