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
int fixTasksNum(task *head){
    int i =1;
    task *traversPointer = head;
    while(traversPointer != NULL){
        traversPointer->taskNumber = i;
        i++;
        traversPointer = traversPointer->next;
    }
    return i;
}
//Create a new node for linked list
task *newTask (){
 task *newTaskNode = (task *)malloc(sizeof(task));
 printf("Enter a title for task (max 50 characters) : \n");
char title[51];
int i;
for(i = 0 ; (title[i]= getchar()) != '\n' ; i++){}
title[i] = '\0';
strcpy(newTaskNode->title , title);
 printf("Enter a description for the task (max 100 characters) : \n");
    char description[101];
    int j;
    for(j = 0 ; (description[j]= getchar()) != '\n' ; j++){}
    description[j] = '\0';
    strcpy(newTaskNode->description , description);
 printf("Enter a deadline date in YYYY/MM/DD form : \n");
    char deadLine[11];
    int k;
    for(k = 0 ; (title[k]= getchar()) != '\n' ; i++){}
    deadLine[k] = '\0';
    strcpy(newTaskNode->deadLine , deadLine);
 newTaskNode->taskNumber = 0;
 newTaskNode->next = NULL;

 return newTaskNode;

}
//Append the new node to end of tasks list
task *addTaskToEndOfList(task *head, task *newTaskNode){
    task *traversPointer = head;
    if(traversPointer == NULL)
        return newTaskNode;
    while(traversPointer->next != NULL)
        traversPointer = traversPointer->next;

    traversPointer->next = newTaskNode;
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
    task *temptraversPointeread = head;
    while(currentPosition + 1 < n){
        currentPosition++;
        temptraversPointeread = temptraversPointeread->next;
    }
    newTaskNode->next = temptraversPointeread->next;
    temptraversPointeread->next = newTaskNode;
}


//print all tasks list
void displayFullTaskList(task *head){
    task *traversPointer = head;
    if(traversPointer == NULL)
        printf("There are no added tasks yet. Please add some and try again.  \n\n\n");
    else{
        printf("All Tasks List : \n\n");
        while(traversPointer != NULL){
            printf("%d) %s  |  info : %s  | Dead Line : %s  . \n", traversPointer->taskNumber, traversPointer->title , traversPointer->description, traversPointer->deadLine  );
            traversPointer = traversPointer->next;
        }
    }

}

void displayTaskTitles(task *head){
    task *traversPointer = head;
    if(traversPointer == NULL)
        printf("There are no added tasks yet. Please add some and try again.  \n\n\n");
    else{
        printf("All Tasks Titles : \n\n");
        while(traversPointer != NULL){
            printf("%d) %s   \n", traversPointer->taskNumber, traversPointer->title);
            traversPointer = traversPointer->next;
        }
    }

}
task *searchTaskByNumber(task *head , int desiredTaskNumber){


    task *traversPointer = head;
    if(traversPointer == NULL)
        printf("No tasks added.");
    else
        while(traversPointer != NULL) {
            if (traversPointer->taskNumber == desiredTaskNumber) {
                printf("\n\n\%d) %s  |  info : %s  | Dead Line : %s  . \n", traversPointer->taskNumber, traversPointer->title , traversPointer->description, traversPointer->deadLine  );
                return traversPointer;
            }
            traversPointer = traversPointer->next;
        }
        return NULL;
}




//Delete Node
void deleteTask(task** head, int selectedTaskNumber){
    task *traversPointer = *head , *prev;

    if(traversPointer != NULL && traversPointer->taskNumber == selectedTaskNumber){
        *head = traversPointer->next;
        free(traversPointer);
        return;
    }

    while (traversPointer != NULL && traversPointer->taskNumber != selectedTaskNumber){
        prev = traversPointer;
        traversPointer = traversPointer->next;
    }

    if(traversPointer == NULL)
        return;


    prev->next = traversPointer->next;
    free(traversPointer);
}
//Edit a task
void editTaskData(task *selectedTask){
    char newTitle[51];
    char newDescription[101];
    char newDeadLine[11];
    printf("\n\n\n To edit tasks title, enter 1 \n To edit tasks description, enter 2\n To edit tasks deadline, enter 3: \n\n");
    int editMode; scanf("%d",&editMode);
    if(editMode == 1){
        fgets(newTitle,50,stdin);
        strcpy(selectedTask->title , newTitle);
    }
    else if(editMode == 2){
        fgets(newDescription, 100, stdin);
        strcpy(selectedTask->description, newDescription);
    }
    else if(editMode == 3){
        fgets(newDeadLine, 10,stdin);
        strcpy(selectedTask->deadLine , newDeadLine);
    }
    else
    {
        printf("The selected number wasn't in the options list.");
    }



}

task *getLastNode(task *head){
    task *traversPointer = head;
    while((traversPointer != NULL)&&(traversPointer->next != NULL))
        traversPointer = traversPointer->next;
    return traversPointer;
}

