#include <stdio.h>
#include <stdlib.h>
#include "tdFuncs.h"





int main() {
    head = addTaskToList(head ,newTask());
    head = addTaskToList(head , newTask());
    head = addTaskToList(head , newTask());
    fixTasksNum(head);
    displayTaskList(head);
}
