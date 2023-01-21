//
// Created by AghoyPandaaa on 1/19/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TDY_TDBASE_H
#define TDY_TDBASE_H

#endif //TDY_TDBASE_H
typedef struct taskData task;
//Linked-List Node
struct taskData{
    char title[51];
    char description[101];
    char deadLine[11];
    int taskNumber;
    task *next;
};


task *head = NULL;

void fixTasksNum(task *head){
    int i =1;
    task *tempHead = head;
    while(tempHead != NULL){
        tempHead->taskNumber = i;
        i++;
        tempHead = tempHead->next;
    }
}

task *newTask (){
 task *newTaskNode = (task *)malloc(sizeof(task));
 printf("Enter a title for task (max 50 characters) : \n");
 gets(newTaskNode->title);
 printf("Enter a description for the task (max 100 characters) : \n");
 gets(newTaskNode->description);
 printf("Enter a deadline date in YYYY/MM/DD form : \n");
 gets(newTaskNode->deadLine);
 newTaskNode->taskNumber = 0;
 newTaskNode->next = NULL;

 return newTaskNode;

}

task *addTaskToList(task *head, task *newTaskNode){
    task *tempHead = head;
    if(tempHead == NULL)
        return newTaskNode;
    while(tempHead->next != NULL)
        tempHead = tempHead->next;

     tempHead->next = newTaskNode;
    return head;
}

void displayTaskList(task *head){
    task *tempHead = head;
    if(tempHead == NULL)
        printf("There are no added task yet. Please add some and try again.  \n\n\n");
    else{
        printf("All Tasks List : \n\n");
        while(tempHead != NULL){
            printf("%d) %s  |  info : %s  | Dead Line : %s  . \n",tempHead->taskNumber,tempHead->title , tempHead->description, tempHead->deadLine  );
            tempHead = tempHead->next;
        }
    }

}