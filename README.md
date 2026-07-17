# TimeTask Analyzer ⏱️

TimeTask Analyzer is a simple C++ console application designed to help users organize their work by creating timed tasks, tracking countdowns, using a built-in stopwatch, and receiving notifications when a task is completed.

## Features

- Display the current system time
- Add tasks with a custom duration (hours, minutes, and seconds)
- View all saved tasks with their completion status
- Start a countdown timer for any task
- Automatic task completion marking
- Audible alarm using Windows Beep() when time is up
- Built-in stopwatch with:
  - Start
  - Pause
  - Resume
  - Restart
  - Quit
- Simple menu-driven interface

## Technologies Used

- C++
- Windows API (`windows.h`)
- Standard C++ Libraries
- Console-based User Interface

## Project Structure

- Current Time Display
- Task Management
- Countdown Timer
- Stopwatch
- Alarm Notification

## How to Run

1. Open the project in Visual Studio Code or any C++ IDE.
2. Compile the source file using a C++ compiler.

Example using g++:

```bash
g++ TimeTaskAnalyzer.cpp -o TimeTaskAnalyzer
```

3. Run the executable:

```bash
TimeTaskAnalyzer.exe
```

## Menu

```
1. Show Current Time
2. Add Task
3. View Tasks
4. Start Task
5. Stopwatch
6. Exit
```

## Sample Workflow

1. Enter your name.
2. Add one or more tasks with a desired duration.
3. View the task list.
4. Start a task to begin its countdown.
5. When the timer reaches zero, an alarm sounds and the task is marked as completed.
6. Use the stopwatch independently whenever needed.

## Limitations

- Task data is stored only during program execution (no file saving).
- Designed for Windows because it uses `windows.h`, `Sleep()`, and `Beep()`.

## Future Improvements

- File handling to save tasks permanently
- Task editing and deletion
- Task priorities and categories
- Date-based scheduling
- Multiple simultaneous timers
- GUI version using Qt or Tkinter
- Progress statistics and reports

## Author

Developed by **Zarish Shahzad** as a C++ console application for learning data structures, timers, and Windows API programming.
