#include <stdio.h>
#include <stdlib.h>
#include "tdFuncs.h"





int main() {
    head = addTaskToEndOfList(head ,newTask());
 //   head = addTaskToList(head ,newTask());
 //   head = addTaskToList(head ,newTask());
    fixTasksNum(head);
    displayTaskTitles(head);
    searchTaskByNumber(head);

}
