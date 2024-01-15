#ifndef TDLIST_H

#include "common.h"

struct task {
  std::string title, desc, state, due_date;
  int id;
  task(const std::string& task_title, const std::string& task_desc, const std::string& task_state, const std::string& task_due_date, int task_id)
  : title(task_title), desc(task_desc), state(task_state), due_date(task_due_date), id(task_id) {}
};

class tdlist {
private:

  std::list<task*> tasks_list;
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

  void add_task(std::string title, std::string desc = "none", std::string state = PENDING_STATE, std::string ddate = "today") {
    task* t = new task(title, desc, state, ddate, cur_id++);
    tasks_list.push_back(t);
  }
  
  void del_task(int task_id) {
    if(tasks_list.empty()) {
      std::cout << "You have nothing to delete." << std::endl;
      return;
    }
    task* t = find_task(task_id);
    if(t == nullptr) {
      std::cout << "Task not found." << std::endl;
      return;
    }
    tasks_list.remove(t);
    delete t;
  }

  void display_tasks() {
    if(tasks_list.empty()) {
      std::cout << "Congrats! You've done all your tasks for now." << std::endl;
      return;
    }
    std::cout << TBL_SEPERATOR << std::endl << TBL_HEADER << std::endl << TBL_SEPERATOR << std::endl;
    for (const auto* t : tasks_list) {
      if(t->id < 10) std::cout << "| 0" << t->id << " | ";
      else std::cout << "| " << t->id << " | ";
      print_max(t->title, TITLE_CHAR_LMT);
      std::cout << " | ";
      print_max(t->desc, DESC_CHAR_LMT);
      std::cout << " | ";
      print_max(t->due_date, 9); // 7
      std::cout << " | ";
      print_max(t->state, 8);
      std::cout << " |" << std::endl;
      std::cout << TBL_SEPERATOR << std::endl;
    }
  }

  /*
   * t => title
   * d => description
   * s => state
   * f => due date (final date)
   */
  void edit_task(int task_id, std::string new_value, const char opt = 't') {
    task* t = find_task(task_id);
    if(t == nullptr) return;
    switch(opt) {
      case 't': t->title = new_value; break;
      case 'd': t->desc = new_value; break;
      case 's': t->state = new_value; break;
      case 'f': t->due_date = new_value; break;
      default: std::cout << "Invalid choice." << std::endl; return;
    }
    std::cout << "task " << task_id << " edited successfully." << std::endl;
  }
};

bool is_valid_date(string& date) {
  if(date.size() != DATE_LEN || date[2] != '-' || date[5] != '-') return false;
  vector<string> vdate;
  std::string token;
  istringstream iss(date);
  while(getline(iss, token, '-')) { vdate.push_back(token); }
  if(vdate.size() != 3) return false;
  std::string& d = vdate.at(0);
  std::string& m = vdate.at(1);
  std::string& y = vdate.at(2);
  int int_d = stoi(d), int_m = stoi(m), int_y = stoi(y);
  if(d.size() != DAY_LEN || m.size() != MO_LEN || y.size() != YR_LEN) return false;
  if (!isdigit(d[0]) || !isdigit(m[0]) || !isdigit(y[0])) return false;
  if(int_d < BEG_DAY || int_d > END_DAY || int_m < BEG_MO || int_m > END_MO) return false;
  if(int_y < 0) return false;
  return true;
}

void display_menu() {
  std::cout << "1. add\n" << "2. rm\n" << "3. display\n" << "4. stats\n"<< "5. edit\n" << "0. exit" << endl;
  std::cout << "enter your choice: ";
}

void add(tdlist& todo_list) {
  std::string title;
  std::cout << "Title: ";
  getline(cin, title);
  todo_list.add_task(title);
}

void del(tdlist& todo_list) {
  int id;
  std::cout << "ID: ";
  cin >> id;
  clear_buffer();
  todo_list.del_task(id);
}

void stats(tdlist& todo_list) {
  std::cout << "N.O. tasks: " << todo_list.get_tasks_count() << endl;
}

void edit(tdlist& todo_list) {
  int id;
  std::string new_value;
  std::cout << "ID: ";
  cin >> id;
  clear_buffer();
  std::cout << "what are you want to edit? (t)itle, (d)escription, (s)tate, (f) due date or (c)ancel?\n> ";
  char opt;
  cin >> opt;
  clear_buffer();
  if(opt == 'c') { std::cout << "edit canceled" << endl; return; }
  if(opt == 's') {
    std::cout << "1. " << PENDING_STATE << endl;
    std::cout << "2. " << ACTIVE_STATE << endl;
    std::cout << "3. " << FINISHED_STATE << endl;
    std::cout << "4. " << ABANDONED_STATE << endl;
    std::cout << "5. " << STALLED_STATE << endl;
    std::cout << "6. other" << endl;
    std::cout << "> ";
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
      default: std::cout << "Invalid choice"; break;
    }
  } else if(opt == 'f') {
    do {
      std::cout << "new due date (dd-mm-yyyy)\n> ";
      cin >> new_value;
      clear_buffer();
      if(is_valid_date(new_value)) break;
      std::cout << "Invalid date." << endl;
    } while(1);
  } else {
    std::cout << "the new value: ";
   getline(cin, new_value);
   clear_buffer();
  }
  todo_list.edit_task(id, new_value, opt);
}

#endif