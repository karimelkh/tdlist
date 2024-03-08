#include "core/tdlist.h"

int main(const int argc, const char* argv[]) {
	if(argc == 1) { /* enter tdlist interface */ }
	else if(argc > 5) { /* display HELP snd EXIT */ }
	else { /* process arguments */ }
	return 0;
}

/*
int main(int argc, char* argv[]) {
	if(argc == 1) {
		std::string cmd;
		do {
			std::cout << "tdlist> ";
			std::getline(std::cin, cmd);
			if(cmd == "clear") system("clear");
			else if(cmd == "exit" || cmd == "quit") {
				std::cout << "bye!" << std::endl;
				break;
			}
			else std::cout << cmd << std::endl;
		} while (true);
	} else {}
}
*/

/*
int main(int argc, char* argv[]) {

  if(argc == 1) help();

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
*/
