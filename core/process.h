#pragma once

#define DEF_ARGC 5
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

/*
argv	0	1	2		3		4		5
	tdlist	add	<>		<>		<>		<>
        tdlist	rm	<task id>
        tdlist	edit	<task id>	<edit option>	<new value>
*/

namespace Process {
	/* print all args */
	void print_args(int argc, char* argv[]) {
		int i = 1;
		while(i < argc)
			std::cout << "[" << i << "]: " << argv[i++] << std::endl;
	}

    /**
   * @brief remove a task from the todo list
   * @param tid a task id
   * @param list tdlist object, passed by reference
   * @see del_task()
   * @return 0 if successed else 1
   */
  int rm(const int tid, tdlist& list) {
    list.display_tasks();
    return list.del_task(tid);
  }

  /**
   * @brief edit the task elements
   * @param 
   * @param 
   * @see 
   * @return 
   */
  int edit(const int tid, const char opt, char* new_value , tdlist& list) {
    if(opt == 'f' && !is_valid_date(new_value)) {
      log_msg("Invalid date");
      return FAI_RES;
    }
    list.edit_task(tid, new_value, opt);
    list.display_tasks();
    return SUC_RES;
  }

/**
  * @brief process the giving arguments and decide what task to perform
  * @param argc number of giving arguments
  * @param argv array of giving arguments
  * @param list tdlist object, passed by reference
  * @see add()
  * @see rm()
  * @see edit()
  * @see display()
  */
void all_args(int argc, char* argv[], tdlist& list) {
  int tid;
  std::string opt = argv[1];
  // print_args(argc, argv);
  if(opt == "add") {
    // log_msg("add mode");
    list.add_task(argv[2], argv[3], argv[4], argv[5]);
  } else if(opt == "rm") {
    // log_msg("rm mode");
    tid = (int) argv[2][0];
    rm(tid, list);
  } else if(opt == "edit") {
    // log_msg("edit mode");
    tid = (int) argv[2][0];
    edit(tid, argv[3][0], argv[4], list);
  } else if(opt != "display") {
    std:: cout << argv[1] << ": nothing appropriate." << std::endl;
  }
  list.display_tasks();
}
}

