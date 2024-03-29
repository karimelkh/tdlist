# TDLIST

command line app for managing tasks.


## SOURCE CODE TREE

```sh
tdlist
├── core
│   ├── common.h
│   ├── process.h
│   └── tdlist.h
├── LICENSE
├── Makefile
├── README.md
└── tdlist.cpp
```


## USAGE

* compiling:
```sh
make
```

* compiling and installing:
```sh
sudo make install
```

* uninstalling:
```sh
sudo make uninstall
```

* running:
```sh
tdlist
```

* cleaning:
```sh
make clean
```


## FEATURES

1. add tasks
2. delete tasks
3. display tasks
4. edit tasks
5. _**more to come**_


## TODOS

### todo:

- [ ] implement the `help` function
- [ ] add `done_task` function
- [ ] add `restore_task` function
- [ ] remove **"magic numbers"**
- [ ] enhance table formatting
- [ ] handle the storage of tasks: save the tasks in a file
- [ ] make a command-line prompt
- [ ] secure the tasks with username-password authentication
- [ ] long list of task(s)
- [ ] list by filters: state, date, ...
- [ ] add more stats
- [ ] implement the **areas** (or workspaces, groups, ...): for separating tasks.

### done:

- [X] add **Makefile**
- [X] add `help` function
- [X] re-structure the project: make .h/.hpp files
- [X] enhance `is_valide_date` function
- [X] due date handling: check date format ...
- [X] change task state (e.g., Completed, Canceled, ...)
- [X] add the **edit** option.
- [X] use stack STL instead of mine.
- [X] enhance code readability
- [X] add **stats** option.
- [X] bug: deleting a task that dosn't exist
- [X] enhance display/output formatting: display table function


## CONTANCT

If you have any questions, feedback, or suggestions, feel free to [send an email](mailto:karimelkhanoufi22+github@gmail.com).
