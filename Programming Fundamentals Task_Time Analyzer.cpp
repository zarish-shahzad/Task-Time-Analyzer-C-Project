#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Task {
    string name;
    int h, m, s;
    bool completed;
};

Task tasks[10];
int taskCount = 0;

void waitReturn() {
    char q;
    cout << "\nPress q to return to main menu: ";
    do { cin >> q; } while(q != 'q');
    }

void showTime() {
    time_t now = time(0);
    cout << "\nCurrent Time: " << ctime(&now);
    waitReturn();
    }

void addTask() {
    if(taskCount >= 10) {
        cout << "Task list full.\n";
        waitReturn();
        return;
    }

    cin.ignore();
    cout << "Enter task name: ";
    getline(cin, tasks[taskCount].name);

    cout << "Enter time (h m s): ";
    cin >> tasks[taskCount].h >> tasks[taskCount].m >> tasks[taskCount].s;

    tasks[taskCount].completed = false;
    taskCount++;

    cout << "Task added successfully.\n";
    waitReturn();
}

void viewTasks() {
    if(taskCount == 0) {
        cout << "No tasks available.\n";
    } else {
        for(int i = 0; i < taskCount; i++) {
            cout << i+1 << ". " << tasks[i].name << " (" << tasks[i].h << ":" << tasks[i].m << ":" << tasks[i].s << ") " << (tasks[i].completed ? "[Done]" : "[Pending]") << endl;
        }
    }
    waitReturn();
}

void alarm() {
    cout << "\n*** TIME UP! ***\n";
    for(int i = 0; i < 3; i++) {
        Beep(3000, 300);
        Sleep(200);
    }
}

void startTask() {
    if(taskCount == 0) {
        cout << "No tasks available.\n";
        waitReturn();
        return;
    }

    cout << "\nAvailable Tasks:\n";
    for(int i = 0; i < taskCount; i++) {
        cout << i+1 << ". " << tasks[i].name
             << " (" << tasks[i].h << ":" << tasks[i].m << ":" << tasks[i].s << ") "
             << (tasks[i].completed ? "[Done]" : "[Pending]") << endl;
    }

    cout << "\nSelect task number: ";
    int n;
    cin >> n;
    n--;

    int total = tasks[n].h * 3600 + tasks[n].m * 60 + tasks[n].s;

    cout << "Starting task: " << tasks[n].name << endl;

    while(total > 0) {
        int h = total / 3600;
        int m = (total % 3600) / 60;
        int s = total % 60;

        cout << "\rRemaining: " << h << ":" << m << ":" << s << "   ";
        Sleep(1000);
        total--;
    }

    tasks[n].completed = true;
    alarm();
    waitReturn();
}

void stopwatch() {
    int sec = 0;
    char ch;
    bool running = false;

    cout << "\nStopwatch Controls:\n";
    cout << "s = start | r = resume | p = pause | x = restart | q = quit\n";

    while(true) {
        cout << "\nEnter command: ";
        cin >> ch;

        if(ch == 's' || ch == 'r') {
            running = true;
            while(running) {
                cout << "\rTime: " << sec << " sec   ";
                Sleep(1000);
                sec++;

                if(_kbhit()) {
                    char c = _getch();
                    if(c == 'p') running = false;
                    else if(c == 'x') { sec = 0; running = false; }
                    else if(c == 'q') { running = false; goto exit_stopwatch; }
                }
            }
        }
        else if(ch == 'x') {
            sec = 0;
            cout << "Reset to 0";
        }
        else if(ch == 'p') {
            running = false;
        }
        else if(ch == 'q') {
            break;
        }
    }

exit_stopwatch:
    waitReturn();
}

int main() {
    string user;
    cout << "Enter your name: ";
    getline(cin, user);

    int choice;
    do {
        cout << "\n=========================\n";
        cout << "Welcome " << user << " to Time Task Analyzer\n";
        cout << "=========================\n";
        cout << "1. Show current time\n";
        cout << "2. Add task\n";
        cout << "3. View tasks\n";
        cout << "4. Start task\n";
        cout << "5. Stopwatch\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: showTime(); 
			break;
            case 2: addTask(); 
			break;
            case 3: viewTasks(); 
			break;
            case 4: startTask(); 
			break;
            case 5: stopwatch(); 
			break;
            case 6: cout << "Thank you for using TimeTask Analyzer!\n"; 
			break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 6);

    return 0;
}

