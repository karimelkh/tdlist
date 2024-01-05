#include <iostream>
#include <list>
#include <string>

using namespace std;

#define PENDING_STATE "To-Do"
#define ACTIVE_STATE "In Progress"
#define FINISHED_STATE "Completed"
#define ABANDONED_STATE "Canceled"
#define STALLED_STATE "Blocked"

struct task {
  string title, desc, state, due_date;
  int id;
  task(const string& task_title, const string& task_desc, const string& task_state, const string& task_due_date, int task_id)
  : title(task_title), desc(task_desc), state(task_state), due_date(task_due_date), id(task_id) {}
};

class TodoList {
private:

  list<task*> tasks_list;
  int cur_id = 0;
  int tasks_count = 0;

public:

  int get_tasks_count() {return tasks_count;}

  task* find_task(int task_id) {
    if(tasks_list.empty()) return nullptr;
    for(const auto& task : tasks_list) {
      if(task->id == task_id) return task;
    }
    return nullptr;
  }

  void add_task(string task_title) {
    task* t = new task(task_title, "none", PENDING_STATE, "today", cur_id++);
    tasks_list.push_back(t);
    tasks_count++ ;
  }
  
  void del_task(int task_id) {
    if(tasks_list.empty()) {
      cout << "You have nothing to delete." << endl;
      return;
    }
    task* t = find_task(task_id);
    if(t == nullptr) {
      cout << "Task not found." << endl;
      return;
    }
    tasks_list.remove(t);
    delete t;
    tasks_count-- ;
  }

  void display_tasks() {
    if(tasks_list.empty()) {
      cout << "Congrats! You've done all your tasks for now." << endl;
      return;
    }
    cout << "All Tasks:" << endl;
    for (const auto* t : tasks_list) {
      cout << "ID: " << t->id << ", Title: " << t->title << ", State: " << t->state << endl;
    }
  }
};

void display_menu() {
  cout << "1. add\n" << "2. rm\n" << "3. display\n" << "4. stats\n" << "0. exit" << endl;
  cout << "enter your choice: ";
}

void add(TodoList& todo_list) {
  string title;
  cout << "Title: ";
  cin >> title;
  todo_list.add_task(title);
}

void del(TodoList& todo_list) {
  int id;
  cout << "ID: ";
  cin >> id;
  todo_list.del_task(id);
}

void stats(TodoList& todo_list) {
  cout << "N.O. tasks: " << todo_list.get_tasks_count() << endl;
}

int main() {
  int choice;
  TodoList todo_list;

  do {

    display_menu();
    cin >> choice;

    switch(choice) {
      case 1: add(todo_list); break;
      case 2: del(todo_list); break;
      case 3: todo_list.display_tasks(); break;
      case 4: stats(todo_list);
      case 0: break;
      default: cout << "Invalid choice." << endl;
    }

    cout << endl;

  } while(choice != 0);

  cout << "bye!" << endl;

  return 0;
}

