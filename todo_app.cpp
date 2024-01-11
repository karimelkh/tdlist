#include <iostream>
#include <list>
#include <string>
#include <limits>

using namespace std;

#define PENDING_STATE "To-Do"
#define ACTIVE_STATE "In Progress"
#define FINISHED_STATE "Completed"
#define ABANDONED_STATE "Canceled"
#define STALLED_STATE "Blocked"

#define TBL_SEPERATOR "+----+---------------+-------------------------+------------+-------------+"
#define TBL_HEADER    "| ID |     Title     |       Description       |  Due date  |    State    |"
//                    "+----+---------------+-------------------------+------------+-------------+"

#define DESC_CHAR_LMT 20 // 25
#define TITLE_CHAR_LMT 10 // 15

void print_max(string str, int max) {
  if(str.length() <= max) {
    cout << str;
    for(int i=0; i<max-str.length()+3; i++) cout << " ";
  }
  else cout << str.substr(0, max) << "...";
}

void clear_buffer() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

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

public:

  int get_tasks_count() {return tasks_list.size();}

  task* find_task(int task_id) {
    if(tasks_list.empty()) return nullptr;
    for(const auto& task : tasks_list) {
      if(task->id == task_id) return task;
    }
    return nullptr;
  }

  void add_task(string title, string desc = "none", string state = PENDING_STATE, string ddate = "today") {
    task* t = new task(title, desc, state, ddate, cur_id++);
    tasks_list.push_back(t);
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
  }

  void display_tasks() {
    if(tasks_list.empty()) {
      cout << "Congrats! You've done all your tasks for now." << endl;
      return;
    }
    cout << TBL_SEPERATOR << endl;
    cout << TBL_HEADER << endl;
    cout << TBL_SEPERATOR << endl;
    for (const auto* t : tasks_list) {
      if(t->id < 10) cout << "| 0" << t->id << " | ";
      else cout << "| " << t->id << " | ";
      print_max(t->title, TITLE_CHAR_LMT);
      cout << " | ";
      print_max(t->desc, DESC_CHAR_LMT);
      cout << " | ";
      print_max(t->due_date, 7);
      cout << " | ";
      print_max(t->state, 8);
      cout << " |" << endl;
      cout << TBL_SEPERATOR << endl;
    }
  }

  /*
   * t => title
   * d => description
   * s => state
   * f => due date (final date)
   */
  void edit_task(int task_id, string new_value, const char opt = 't') {
    task* t = find_task(task_id);
    if(t == nullptr) return;
    switch(opt) {
      case 't': t->title = new_value; break;
      case 'd': t->desc = new_value; break;
      case 's': t->state = new_value; break;
      case 'f': t->due_date = new_value; break;
      default: cout << "Invalid choice." << endl; return;
    }
    cout << "task " << task_id << " edited successfully.";
  }
};

void display_menu() {
  cout << "1. add\n" << "2. rm\n" << "3. display\n" << "4. stats\n"<< "5. edit\n" << "0. exit" << endl;
  cout << "enter your choice: ";
}

void add(TodoList& todo_list) {
  string title;
  cout << "Title: ";
  getline(cin, title);
  todo_list.add_task(title);
}

void del(TodoList& todo_list) {
  int id;
  cout << "ID: ";
  cin >> id;
  clear_buffer();
  todo_list.del_task(id);
}

void stats(TodoList& todo_list) {
  cout << "N.O. tasks: " << todo_list.get_tasks_count() << endl;
}

void edit(TodoList& todo_list) {
  int id;
  string new_value;
  cout << "ID: ";
  cin >> id;
  clear_buffer();
  cout << "what are you want to edit? (t)itle, (d)escription, (s)tate, (f) due date or (c)ancel?\n>";
  char opt;
  cin >> opt;
  clear_buffer();
  if(opt == 'c') return;
  if(opt == 's') {
    cout << "1. " << PENDING_STATE << endl;
    cout << "2. " << ACTIVE_STATE << endl;
    cout << "3. " << FINISHED_STATE << endl;
    cout << "4. " << ABANDONED_STATE << endl;
    cout << "5. " << STALLED_STATE << endl;
    cout << "6. other" << endl;
    cout << "> ";
    char c;
    cin >> c;
    clear_buffer();
    switch(c) {
      case '1': new_value = PENDING_STATE; break;
      case '2': new_value = ACTIVE_STATE; break;
      case '3': new_value = FINISHED_STATE; break;
      case '4': new_value = ABANDONED_STATE; break;
      case '5': new_value = STALLED_STATE; break;
      case '6': new_value = c; break;
      default: cout << "Invalid choice"; break;
    }
  } else {
    cout << "the new value: ";
   getline(cin, new_value);
  }
  todo_list.edit_task(id, new_value, opt);
}

int main() {
  int choice;
  TodoList todo_list;

  do {

    display_menu();
    cin >> choice;
    clear_buffer();    

    switch(choice) {
      case 1: add(todo_list); break;
      case 2: del(todo_list); break;
      case 3: todo_list.display_tasks(); break;
      case 4: stats(todo_list);
      case 5: edit(todo_list);
      case 0: break;
      default: cout << "Invalid choice." << endl;
    }

    cout << endl;

  } while(choice != 0);

  cout << "bye!" << endl;

  return 0;
}

