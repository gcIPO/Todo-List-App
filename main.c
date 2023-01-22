#include <stdio.h>
#include <stdlib.h>
#include "tdFuncs.h"


int main() {
    head = addNewTask();
    system("cls");
    head = addNewTask();
    head = addNewTask();
 //   head = addTaskToList(head ,newTask());
 //   head = addTaskToList(head ,newTask());
    fixTasksNum(head);
    system("cls");
    displayTaskTitles(head);
    system("pause");
    searchTasks(2);
    system("pause");
    fixTasksNum(head);
    prioritizeTasks();
    displayTaskTitles(head);



}
