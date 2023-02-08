// SuperStrings <Project1.cpp>
// EE 312 Project 1 submission by
// Teyo Turrubiates
// ttt2443
// Slip days used: 0
// Summer 2022
// Copy-paste contents of this file at the top of every .c or .h file that you write or modify.

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/

char currString[35];
int ssloc = 0;

void IsolateWord(char targets[]){
    int w = 0;
    int x = 0;
    while(targets[x] == ' '){
        x++;
    }
    for(int i = x; targets[i] != ' '; i++){
        currString[w] = targets[i]; //program stops here
        w++;
        x = i;
    }
    x++;
    currString[w] = '\0';

}


void EraseEnters(char targets[]){
    for(int i = 0; targets[i] != '\0'; i++){
        if(targets[i] == '\n' || targets[i] == '\t'){
            targets[i] = ' ';
        }
    }
}

int numSS(char ss[]){
    if(ss[0] == '\0'){ //checking to see if there is anything in array
        return 0;
    }
    int check = 0;
    while(ss[check] == ' '){
        check++;
    }

    int wordCount = 1;

    for(int i = check; ss[i] != '\0';i++){
        if(ss[i] == ' ') {
            wordCount++;
        }
    }
    return wordCount;
}

void checkSuperArray(char string[], char superArray[]){
    int x = 0;
    int j = 0;
    int flag = 0;
    while(superArray[ssloc] != '\0'){
        for(int i = ssloc; superArray[i] != ' ' && flag != 1 && superArray[i] != '\0'; i++){
            if(superArray[i] != string[j]){
                x++;
                continue;
            }
            else {
                x++;
                j++;
                if(string[j] == '\0'){
                    flag = 1;
                    j = 0;
                }
            }
        }
        if(flag == 1){
            for(int y = ssloc;superArray[y] != ' ' && superArray[y] != '\0';y++){
                putchar(superArray[y]);
                ssloc = y;
            }
            printf("\n");
            ssloc++;
            ssloc++;
            x = ssloc;
            flag = 0;
        }
        else {
            x++;
            ssloc = x;

            j = 0;
        }
    }

}



void printSuperStrings(char targets [], char candidates []) {
    EraseEnters(targets); //erases all enters from targets
    EraseEnters(candidates); //erases all enters from candidates
    //the following runs until every word in target has been checked
    while(*targets != '\0'){
        IsolateWord(targets); //takes one word from targets
        //the following checks for superstrings of "currstring" in candidates
        checkSuperArray(currString, candidates);
        while(*targets ==' '){ //increments until next word is found
            *targets++;
        }
        while(*targets != ' ' && *targets != '\0'){
            *targets++;
        }
        if(*targets == ' '){
            *targets++;
        }
        ssloc = 0;

    }
}

