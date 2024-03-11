#pragma once

#define DEF_ARGC 4
#define SKP_CHR '-'
#define DEF_DESC "none"
#define DEF_DDATE "tomorrow"

/*
	* tdlist "title" "description" "deadline" "state"
	* tdlist "title" - "deadline" -
	
	if you don't want to specify an argument write -
	example:
		if don't want to provide the description for now,
		the apropriate commande will be then:
			```
			tdlist "title" - "deadline" "state"
			```

	NOTE: `title` is always required
*/

namespace Process {
	/* print all args */
	void print_args(int argc, char* argv[]) {
		int i = 1;
		while(i < argc)
			std::cout << "[" << i << "]: " << argv[i++] << std::endl;
	}

	/* process all the args (just add tasks for now) */
	void all_args(int argc, char* argv[], tdlist& list) {
		list.add_task(argv[1], argv[2], argv[3], argv[4]);
    list.display_tasks();
	}
}

