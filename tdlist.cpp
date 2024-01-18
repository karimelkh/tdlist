#include "core/tdlist.h"

int main() {
  int choice;
  tdlist todo_list;

  do {

    display_menu();
    std::cin >> choice;
    clear_buffer();    

    switch(choice) {
      case 1: add(todo_list); break;
      case 2: del(todo_list); break;
      case 3: todo_list.display_tasks(); break;
      case 4: stats(todo_list); break;
      case 5: edit(todo_list); break;
      case 0: break;
      default: std::cout << "Invalid choice." << std::endl;
    }

  } while(choice != 0);

  std::cout << "bye!" << std::endl;

  return 0;
}

