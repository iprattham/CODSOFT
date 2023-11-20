#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    Task newTask(description);
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            } else {
                cout << "[Pending] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markAsCompleted(vector<Task>& tasks, int taskNumber) {
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed: " << tasks[taskNumber - 1].description << endl;
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int taskNumber) {
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "todo-list Manager by: Pratham Aggarwal\n" << endl;

    do {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cin.ignore();  // Clear the newline character from the previous input
                    string description;
                    cout << "Enter the task description: ";
                    getline(cin, description);
                    addTask(tasks, description);
                }
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                int taskNumber;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskNumber;
                markAsCompleted(tasks, taskNumber);
                break;
            case 4:
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                removeTask(tasks, taskNumber);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
