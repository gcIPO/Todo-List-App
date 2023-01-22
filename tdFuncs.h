//
// Created by AghoyPandaaa on 1/19/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "tdBase.h"
#ifndef TDY_TDFUNCS_H
#define TDY_TDFUNCS_H

#endif //TDY_TDFUNCS_H


task *addNewTask(){
    head = addTaskToEndOfList(head, newTask());
    return head;
}


void removeTask(){
    displayTaskTitles(head);
    printf("Which one should be deleted? : ");
    int selectedTaskToDelete; scanf("%d",&selectedTaskToDelete);
    deleteTask(&head, selectedTaskToDelete);
    fixTasksNum(head);

}


task *searchTasks(int taskNum){
    displayTaskTitles(head);
    return searchTaskByNumber(head, taskNum);
}


void editTask(){
    displayTaskTitles(head);
    printf("Which one needs to be edited? : ");
    int selectedTaskNumber; scanf("%d", &selectedTaskNumber);
    task *selectedTask = (searchTaskByNumber(head, selectedTaskNumber));
    editTaskData(selectedTask);
    displayFullTaskList(head);
}

void prioritizeTask(){
    displayTaskTitles(head);
    printf("Enter the task you want to change its position : ");
    int selectedTask; scanf("%d",&selectedTask);


}

