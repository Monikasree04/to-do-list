#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;
    std::vector<bool> completed;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        completed.push_back(false); 
        std::cout << "Task added: " << task << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks found." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i] << " (" << (completed[i] ? "Completed" : "Pending") << ")" << std::endl;
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            completed[index - 1] = true;
            std::cout << "Task marked as completed: " << tasks[index - 1] << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            completed.erase(completed.begin() + index - 1); 
            std::cout << "Task removed." << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::cout<<"TO-DO LIST"<<"\n";

    do {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore(); 
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                todoList.markTaskCompleted(index);
                break;
            }
            case 4: {
                size_t index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }

    } while (choice != 0);

    return 0;
}