#include <stdio.h>// standard input and output
#include <stdlib.h>//exit
#define BUFFER_SIZE 1000 //1000 characters

int main(int argc, char *argv[]){
    //loop through each file path and display content
    for (int i=1; i<argc; i++){ 
        FILE *filep = fopen(argv[i], "r");
        if (filep == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }
        else{ //read line by line and print
            char buffer[BUFFER_SIZE];
            fgets(buffer, BUFFER_SIZE, filep);

            while (!feof(filep)){ //print until eof, end of file, is reached \0
                printf("%s", buffer);
                fgets(buffer, BUFFER_SIZE, filep);
            }

            fclose(filep);  
        }  
    }
exit(0);
}
