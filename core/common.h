#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef STRING
#include <string>
#endif

#ifndef LIST
#include <list>
#endif

#ifndef LIMITS
#include <limits>
#endif

#ifndef SSTREAM
#include <sstream>
#endif

#ifndef VECTOR
#include <vector>
#endif

#define DOTES_LEN 3

#define DATE_LEN 10
#define DAY_LEN 2
#define MO_LEN 2
#define YR_LEN 4

#define BEG_DAY 1
#define END_DAY 31
#define BEG_MO 1
#define END_MO 12

#define PENDING_STATE "To-Do"
#define ACTIVE_STATE "In Progress"
#define FINISHED_STATE "Completed"
#define ABANDONED_STATE "Canceled"
#define STALLED_STATE "Blocked"

#define TBL_SEPERATOR "+----+---------------+-------------------------+--------------+-------------+"
#define TBL_HEADER    "| ID |     Title     |       Description       |   Due date   |    State    |"
//                    "+----+---------------+-------------------------+--------------+-------------+"

#define DESC_CHAR_LMT 20 // 25
#define TITLE_CHAR_LMT 10 // 

// #define 

void clear_buffer() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

void print_max(std::string str, int max) {
  if(str.length() <= max) {
    std::cout << str;
    int rest_of_cell = max - str.length() + DOTES_LEN;
    for(int i=0; i<rest_of_cell; i++) std::cout << " ";
  }
  else std::cout << str.substr(0, max) << "...";
}

namespace Display {
	void help() { /* cmd desc + usage + version */ }
}
