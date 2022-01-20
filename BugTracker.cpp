//Bug Tracking System in C++

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cstdio>
//#include <conio.h>

using namespace std; 
//Filing The Bug 

void fileBug(int id){
    printf("****************** \n");
    printf("BUG IS BEING FILED \n");
    printf("****************** \n");

    //Current Time Using time library
    char name[20], bugType[50];
    char bugDescription[1000];
    char bugPriority[30];
    int bugStatus;

    time_t currentTime;
    time(&currentTime);
    FILE* ptr;

    //UserName
    printf("Enter File Name: \n");
    scanf("%s", name);
    char ids[10];
    //itoa(id, ids, 10);
    strcat(name, ids);
    char ex[] = ".txt";
    strcat(name, ex);

    //fileName of Bug
    printf("FileName: %s \n", name);
    ptr = fopen(name, "w");

    //if file cant be created
    if(ptr == NULL){
        printf("Cannot Create The File!! \n");
    }
    fprintf(ptr,"Date and Time: %s", ctime(&currentTime));

    //Adds ID to text file
    fprintf(ptr, "Bug ID:  %d\n", id);
    //Adds new Line in Text File
    fprintf(ptr, "\n");

    //Bug ID
    printf("Bug ID: %d\n", id);
    fprintf(ptr, "Bug Filed by %s\n", name);
    fprintf(ptr, "\n");

    printf("Enter Bug Type:\n");
    scanf("%[^\n]", bugType);

    //BugType
    fprintf(ptr, "Type of Bug: %s", bugType);
    fprintf(ptr, "\n");

    //bugPriority
    printf("Enter Bug Priority:\n");
    scanf(" %[^\n]s", bugPriority);
    fprintf(ptr, "Bug Priority: %s\n",bugPriority);
    fprintf(ptr, "\n");

    //bugDescription
    printf("Enter Bug Description:\n");
    scanf(" %[^\n]s", bugDescription);

    fprintf(ptr, "Bug Description: %s\n", bugDescription);
    fprintf(ptr, "\n");

    printf("Status of Bug:\n");
    printf("1.Not Assigned Yet\n");
    printf("2.Being Fixed\n");
    printf("3.Fixed\n");
    printf("4.Delivered\n ENTER YOUR CHOICE:");

    int k;
    scanf("%d", &k);

    // Bug Creation : Date and Time
    fprintf(ptr, "Date and Time: %s", ctime(&currentTime));
    fprintf(ptr, "Bug Status: ");

    //Switching Bug Status
    switch (k) {
        case 1:
            fprintf(ptr,"Not Assigned Yet\n");
            break;
        case 2:
            fprintf(ptr,"Being Fixed\n");
            break;
        case 3:
            fprintf(ptr,"Fixed\n");
            break;
        case 4:
            fprintf(ptr,"Delivered\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
    fclose(ptr);
}

//Function To change status of bug
void changeStatus(){
    printf("*************");
    printf("Change Status");
    printf("*************\n");

    //TimeStamp
    time_t currentTime;
    time(&currentTime);

    FILE* file;
    char name[50];

    //Name for Bug File
    printf("Enter File Name: \n");
    scanf("%s", name);
    char ex[] = ".txt";
    strcat(name, ex);

    //Opening File in Edit mode (APPEND)
    file = fopen(name, "a");

    printf("\n1.Not Assigned Yet\n");
    printf("2.Being Fixed\n3.Fixed\n");
    printf("4.Delivered\nEnter Your Choice:");

    //Change Status
    int j;
    scanf("%d", &j);

    fprintf(file, "\n");
    fprintf(file, "Date and Time: %s", ctime(&currentTime));
    fprintf(file, "Bug Status:");

    // Changing the status on the
    // basis of the user input
    switch (j) {
        case 1:
            fprintf(file,"Not Assigned Yet\n");
            break;
        case 2:
            fprintf(file,"Being Fixed\n");
            break;
        case 3:
            fprintf(file,"Fixed\n");
            break;
        case 4:
            fprintf(file,"Delivered\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
    fclose(file);
}

void report(){
    printf("**********");
    printf("Report");
    printf("**********\n");

    FILE* fp;
    char name[50];

    //Asking the Filename to report
    printf("Enter File Name: \n");
    scanf("%s", name);
    char ex[] = ".txt";
    strcat(name, ex);

    //Opening the file in read mode
    fp = fopen(name, "r");

    char ch;
    ch = getc(fp);

    //Character Of The File
    while (ch != EOF){
        printf("%c", ch);
        ch = getc(fp);
    }
    fclose(fp);
    getchar();
}

//Driver Code
int main(){
    printf("***************");
    printf("BUG TRACKING SYSTEM");
    printf("***************\n");

    int number, i = 1;

    //Initialize ID to 0
    int id = 0;

    //while loop to run
    while(i != 0){
        printf("\n1.File A New Bug\n");
        printf("2.Change Status Of The Bug\n");
        printf("3.Get Bug Report\n4.Exit");
        printf("\n\n Enter Your Choice:");

        scanf("%d", &number);

        //Switch Cases
        switch(number){
            case 1:
                id++;

                //Creating A New Bug
                fileBug(id);
                break;

            case 2:
                //Change Status Of Bug
                changeStatus();
                break;

            case 3:
                //Report the Bug
                report();
                break;

            case 4:
                i = 0;
                break;

            default:
                printf("\n invalid entry");
                break;
        }
    }
}


