/*

* Project: To-Do List Application

* Description:
Create a command-line-based To-Do List application in C/C++.
Users can add tasks, mark them as completed, and view their task list.
This project will involve using data structures like linked lists or arrays,
and it will help you practice input/output, data manipulation,
and basic program organization.

* Features to Include:
1. **Adding Tasks:** Users can add tasks with a description and due date.
2. **Viewing Tasks:** Users can view their task list, including task
  descriptions and due dates.
3. **Marking Tasks as Completed:** Users can mark tasks as completed.
4. **Removing Tasks:** Users can remove tasks from the list.

* Tips:
1. Use data structures like arrays or linked lists to store the tasks.
2. Implement functions to add, view, mark, and remove tasks.
3. Create a simple text-based menu for user interaction.

* TO ADD:
  1. ARCHIVE
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class list {
  struct task {
    string title, desc, state, due_date;
    int id;
    task* next_t;
    task* prev_t;
  };

  task* head_list = nullptr;
  int tasks_count = 0;
  int current_id_count = 0;

  #define PENDING_STATE "To-Do"
  #define ACTIVE_STATE "In Progress"
  #define FINISHED_STATE "Completed"
  #define ABANDONED_STATE "Canceled"
  #define STALLED_STATE "Blocked"

public:
  bool is_empty() {
    if(tasks_count == 0) return true;
    return false;
  }
  int get_tasks_count() {
    return tasks_count;
  }
  void print_tab_header() {
    cout << " ID | Title \t Description \t State \t Due date" << endl;
  }
  void print_task(task* t) {
    cout << " " << t->id << " | " << t->title << "\t" << t->desc << "\t" << t->state << "\t" << t->due_date << endl;
  }
  // void display_list() {
  //   if(is_empty()) return;
  //   task* current_task = head_list;
  //   print_tab_header();
  //   while(current_task != nullptr) {
  //     print_task(current_task);
  //     current_task = current_task->next_t;
  //   }
  // }
  void display_list() {
    if (is_empty()) {
      cout << "No tasks to display." << endl;
      return;
    }

    const int idWidth = 4;  // Adjust as needed
    const int titleWidth = 20;  // Adjust as needed
    const int descWidth = 30;  // Adjust as needed
    const int stateWidth = 15;  // Adjust as needed
    const int dueDateWidth = 15;  // Adjust as needed

    cout << setw(idWidth) << "ID" << " | ";
    cout << setw(titleWidth) << "Title" << " | ";
    cout << setw(descWidth) << "Description" << " | ";
    cout << setw(stateWidth) << "State" << " | ";
    cout << setw(dueDateWidth) << "Due Date" << endl;
    cout << setfill('-') << setw(idWidth + 2) << "+";
    cout << setfill('-') << setw(titleWidth + 3) << "+";
    cout << setfill('-') << setw(descWidth + 3) << "+";
    cout << setfill('-') << setw(stateWidth + 3) << "+";
    cout << setfill('-') << setw(dueDateWidth) << "+";
    cout << setfill(' ') << endl;

    task* current_task = head_list;
    while (current_task != nullptr) {
      cout << setw(idWidth) << current_task->id << " | ";
      cout << setw(titleWidth) << current_task->title << " | ";
      cout << setw(descWidth) << current_task->desc << " | ";
      cout << setw(stateWidth) << current_task->state << " | ";
      cout << setw(dueDateWidth) << current_task->due_date << endl;
      current_task = current_task->next_t;
    }
  }
  task* create_task(string task_title, string desc, string due_date) {
    return new task{task_title, desc, PENDING_STATE, due_date, ++current_id_count, nullptr, nullptr};
  }
  task* find_task(int target_id) {
    if(is_empty()) return nullptr;
    task* target_task = head_list;
    int i = 1;
    while(i <= tasks_count) {
      if(target_task->id == target_id) return target_task;
      target_task = target_task->next_t;
      i++ ;
    }
    return nullptr;
  }
  void insert_task(task* new_task) {
    new_task->next_t = head_list;
    if(head_list != nullptr) head_list->prev_t = new_task;
    head_list = new_task;
    tasks_count++ ;
  }
  void delete_task(int task_id) {
    if(is_empty()) return;
    task* to_delete_task = find_task(task_id);
    if(to_delete_task == nullptr) return;
    if(to_delete_task->prev_t != nullptr) to_delete_task->prev_t->next_t = to_delete_task->next_t;
    else head_list = to_delete_task->next_t;
    if(to_delete_task->next_t != nullptr) to_delete_task->next_t->prev_t = to_delete_task->prev_t;
    delete to_delete_task;
    tasks_count-- ;
  }
  // void check_task() {}
};

void log_message(string message) {
  cout << message << endl;
}
void display_menu() {
  log_message("TODO APP");
  cout << endl;
  log_message("Options:");
  log_message("------------------");
  log_message("1. Display tasks");
  log_message("2. Add task");
  log_message("3. Check task");
  log_message("4. Remove task");
  log_message("5. Display options");
  log_message("0. Exit");
  log_message("------------------");
}
void add_task(list& l) {
  log_message("Creating new task");
  string title, desc, ddate;
  cout << "Title: ";
  getline(cin, title);
  cout << "Description: ";
  getline(cin, desc);
  cout << "Due date: ";
  getline(cin, ddate);
  l.insert_task(l.create_task(title, desc, ddate));
  log_message("1 task was added");
}
void remove_task(list& l) {
  log_message("Removing task");
  int tid;
  cout << "Task ID: ";
  cin >> tid;
  l.delete_task(tid);
  log_message("1 task was deleted");
}

int main() {
  list tlist;
  display_menu();
  int choice;
  while(1) {
    cout << "What are you want to do: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
      case 2:
        system("clear");
        add_task(tlist);
        break;
      case 1:
        system("clear");
        tlist.display_list();
        cout << "\ntasks: " << tlist.get_tasks_count() << endl;
        break;
      case 3:
        system("clear");
        cout << "check\n";
        break;
      case 4:
        system("clear");
        remove_task(tlist);
        break;
      case 5:
        system("clear");
        display_menu();
        break;
      case 0:
        exit(0);
      default:
        cout << "invalid choice";
        break;
    }
  }
  return 0;
}
