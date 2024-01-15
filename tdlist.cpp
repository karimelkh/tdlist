#include "tdlist.h"

using namespace std;

int main() {
  int choice;
  tdlist todo_list;

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

  } while(choice != 0);

  cout << "bye!" << endl;

  return 0;
}
