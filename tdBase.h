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
//Linked-List Node Structure
struct taskData{
    char title[51];
    char description[101];
    char deadLine[11];
    int taskNumber;
    task *next;
};


task *head = NULL;
//Function to fix task numbers
void fixTasksNum(task *head){
    int i =1;
    task *tempHead = head;
    while(tempHead != NULL){
        tempHead->taskNumber = i;
        i++;
        tempHead = tempHead->next;
    }
}
//Create a new node for linked list
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
//Append the new node to end of tasks list
task *addTaskToEndOfList(task *head, task *newTaskNode){
    task *tempHead = head;
    if(tempHead == NULL)
        return newTaskNode;
    while(tempHead->next != NULL)
        tempHead = tempHead->next;

     tempHead->next = newTaskNode;
    return head;
}

//Add a task to first of the list
task *insertTaskToFirst(task *head ,task *newTaskNode){
    newTaskNode->next = head;
    head = newTaskNode;
}

//Add a task to n position of list
task *insertToNPosition(int n, task *newTaskNode, task *head){
    int currentPosition = 1;
    task *tempHead = head;
    while(currentPosition + 1 < n){
        currentPosition++;
        tempHead = tempHead->next;
    }
    newTaskNode->next = tempHead->next;
    tempHead->next = newTaskNode;
}


/*//print all tasks list
void displayTaskList(task *head){
    task *tempHead = head;
    if(tempHead == NULL)
        printf("There are no added tasks yet. Please add some and try again.  \n\n\n");
    else{
        printf("All Tasks List : \n\n");
        while(tempHead != NULL){
            printf("%d) %s  |  info : %s  | Dead Line : %s  . \n",tempHead->taskNumber,tempHead->title , tempHead->description, tempHead->deadLine  );
            tempHead = tempHead->next;
        }
    }

}*/

void displayTaskTitles(task *head){
    task *tempHead = head;
    if(tempHead == NULL)
        printf("There are no added tasks yet. Please add some and try again.  \n\n\n");
    else{
        printf("All Tasks Titles : \n\n");
        while(tempHead != NULL){
            printf("%d) %s   \n",tempHead->taskNumber,tempHead->title);
            tempHead = tempHead->next;
        }
    }

}
task *searchTaskByNumber(task *head){
//    printf("Enter a number to show its data : ");
    int givenTaskNumber;
    scanf("%d",&givenTaskNumber);
    task *tempHead = head;
    if(tempHead == NULL)
        printf("No tasks added.");
    else
        while(tempHead != NULL) {
            if (tempHead->taskNumber == givenTaskNumber) {
                printf("\n\n\%d) %s  |  info : %s  | Dead Line : %s  . \n",tempHead->taskNumber,tempHead->title , tempHead->description, tempHead->deadLine  );
                return tempHead;
            }
            tempHead = tempHead->next;
        }
        return NULL;
}
//Delete first node of the linked list
task *deleteFirstTask(task *head){
    task *prev_head = head;
    head = head->next;
    free(prev_head);
}

//Delete last node of the linked list
task *deleteLastTask(task *head){
    task *traversPointer = head;
    while(traversPointer->next->next != NULL)
        traversPointer = traversPointer->next;
    free(traversPointer->next->next);
    traversPointer->next = NULL;
}

//Delete n position task from the linked list

task *deleteNPositionTask(task *head,int position){
    task *traversPointer = head;
    int currentPos = 1;

    while(currentPos + 1 < position){
        position++;
        traversPointer = traversPointer->next;
    }
    task *deletedTask = traversPointer->next;
    traversPointer->next = traversPointer->next->next;
    free(deletedTask);
}


void *editTaskData(){



}