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

void prioritizeTasks(){
    int numberOfTasks = fixTasksNum(head);
    displayTaskTitles(head);
    printf("Enter the number of task you want to change its position : ");
    int selectedTaskNumber; scanf("%d", &selectedTaskNumber);
    task *selectedTask = searchTaskByNumber(head, selectedTaskNumber);
    printf("\n\nEnter new postition of the task : ");
    int newPos; scanf("%d", &newPos);
    if(newPos > numberOfTasks)
        printf("There are only %d tasks, try again...\n\n\n",numberOfTasks);
    if(newPos == selectedTask->taskNumber)
        return;
    task *traversPointer = head;
    task *posPointer = head;
    int posHolder = newPos;
    if(newPos > selectedTask->taskNumber)
        newPos++;

    if(selectedTask->taskNumber == 1)
        head = traversPointer->next;
    else{
        while(traversPointer->next->taskNumber != selectedTask->taskNumber)
            traversPointer = traversPointer->next;
        traversPointer->next = traversPointer->next->next;
    }
    if(posHolder == 1){
        selectedTask->next = head;
        head = selectedTask;
    }
    else if(posHolder == getLastNode(head)->taskNumber){
        getLastNode(head)->next = selectedTask;
        selectedTask->next = NULL;

    }
    else{
        while(posPointer->next->taskNumber != newPos)
            posPointer = posPointer->next;
        selectedTask->next = posPointer->next;
    }
    fixTasksNum(head);
}

/*    printf("pick the node you want to priorities : \n");
    struct to_do * choosed = search();
    printf("Enter the position that you want to replace to : \n");
    int position = getnumber();
    if (position-1 >= getTheLastNode()->key)
    {
        printf("WTF , just choose a position in the range :/   between 1 and %d , it's not that hard dude :( " , getTheLastNode()->key); 
    }//////////////////////////
    if (position == choosed->key)
    {
        return;
    }
    struct to_do * traversing_pointer = head;
    struct to_do * position_pointer = head;
    int positionHolder = position;
    if ( position > choosed->key)
    {
        position++;
    }

    if (choosed->key == 1)
    {
        head = traversing_pointer->link;
    }
    else
    {
        while (traversing_pointer->link->key != choosed->key)
        {
            traversing_pointer = traversing_pointer->link;
        }
        traversing_pointer->link = traversing_pointer->link->link;
    }
    if (positionHolder == 1)
    {
        choosed->link = head;
        head = choosed;
    }
    else if (positionHolder == getTheLastNode()->key)
    {
        getTheLastNode()->link = choosed;
        choosed->link = NULL;
    }
    else
    {
        while (position_pointer->link->key != position)
        {
            position_pointer = position_pointer->link;
        }
        choosed->link = position_pointer->link;
        position_pointer->link = choosed;
    }
    fixingKeys();*/

