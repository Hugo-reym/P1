/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Hugo Rey Montoliu LOGIN 1: hugo.reym
 * AUTHOR 2: Daniel Garcia Alaimo LOGIN 2: d.alaimo
 * GROUP: 6.1
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void addNewConsole(tList *list,tItemL d,char *param1,char *param2,char *param3,char *param4) {
    tPosL pos;
    char y[9];
    printf(": console %s seller %s brand %s price %s\n",  param1, param2, param3, param4);

    strcpy(d.consoleId,param1);
    strcpy(d.seller,param2);
    d.consoleBrand=(unsigned)*param3;
    d.consolePrice=atof(param4);
    d.bidCounter=0;
    if((char)d.consoleBrand == 'n') {
        strcpy(y, "nintendo");
    }else {
        strcpy(y, "sega");
    }
    if(findItem(d.consoleId,*list)==LNULL) {
        if(insertItem(d,LNULL,list)) {
            printf(" *New: console %s seller %s brand %s price %.2f\n", d.consoleId,d.seller,y,d.consolePrice);
        } else {
            printf(" +Error: new not possible\n");
        }
    } else{printf(" +Error: new not possible\n");}

}
void stats(tList list){
    tPosL pos;
    char y[9];
    int number_sega,number_nintendo;
    number_sega=number_nintendo=0;
    float sum_prices_sega,sum_prices_nintendo,average_prices_sega,average_prices_nintendo;
    sum_prices_sega=sum_prices_nintendo=average_prices_nintendo=average_prices_sega=0.0;
    if(!isEmptyList(list)) {

        for(pos=first(list);pos!=next(last(list),list);pos = next(pos,list)) {
            tItemL tmp;
            tmp=getItem(pos,list);
            if((char)tmp.consoleBrand == 'n') {
                strcpy(y, "nintendo");
                number_nintendo++;
                sum_prices_nintendo+=pos->data.consolePrice;
                average_prices_nintendo=((float)sum_prices_nintendo/(float)number_nintendo);
            }else {
                strcpy(y, "sega");
                number_sega++;
                sum_prices_sega+=pos->data.consolePrice;
                average_prices_sega=((float)sum_prices_sega/(float)number_sega);
            }

            printf("Console %s seller %s brand %s price %.2f bids %d \n",pos->data.consoleId,pos->data.seller,y,pos->data.consolePrice,pos->data.bidCounter);
        }
        printf("Brand    Consoles    Price    Average\nNintendo        %d    %.2f    %.2f\n",number_nintendo,sum_prices_nintendo,average_prices_nintendo);
        printf("Sega            %d   %.2f   %.2f\n", number_sega, sum_prices_sega, average_prices_sega);
    } else{printf(" +Error: stats not possible\n");}
}
void deleteconsole(tList *list,tConsoleId id) {
    tItemL temp;
    char y[9];
    temp=getItem(findItem(id,*list),*list);
   if(!isEmptyList(*list)) {
       if(findItem(id,*list)==LNULL) {
           printf("+Error: delete not possible");
       } else {
           tItemL d=getItem(findItem(id,*list),*list);
           deleteAtPosition(findItem(id,*list),list);
           if((char)temp.consoleBrand == 'n') {
               strcpy(y, "nintendo");
           }else {
               strcpy(y, "sega");
           }
           printf("Delete: console %s seller %s brand %s price %f bids %d",temp.consoleId,temp.seller,y,temp.consolePrice,temp.bidCounter);
       }
   } else {
       printf("+Error: delete not possible");
   }
}
void bid(tList *list,tConsoleId console,tUserId seller,tConsolePrice price) {
    tItemL temp;
    char y[9];
    temp=getItem(findItem(console,*list),*list);
    if(findItem(console,*list)==LNULL || price<=temp.consolePrice || (strcmp(seller,temp.seller)==0)) {
        printf("+Error: bid not possible");
    }else {
        if((char)temp.consoleBrand == 'n') {
            strcpy(y, "nintendo");
        }else {
            strcpy(y, "sega");
        }
        temp.bidCounter++;
        temp.consolePrice=price;
        printf("*Bid: console %s seller %s brand %s price %f bids %d",temp.consoleId,temp.seller,y,temp.consolePrice,temp.bidCounter);
    }
}
void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *list) {
    tItemL d;
    char y[9];
    tPosL pos;
    printf("********************\n %s %c", commandNumber, command);
    switch (command) {
        case 'N':
            addNewConsole(list,d,param1,param2,param3,param4);
        break;
        case 'D':
            deleteconsole(list,param1);
            break;
        case 'B':
            bid(list,param1,param2,*param4);
            break;
        case 'S':printf("\n");
        stats(*list);
            break;
        default:
            break;
    }
}

void readTasks(char *filename, tList l) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4,&l);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    tList l;
    createEmptyList(&l);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name,l);

    return 0;
}





