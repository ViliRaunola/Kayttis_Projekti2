#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Source: https://stackoverflow.com/questions/59014090/warning-implicit-declaration-of-function-getline */
/* error with getline() solved with '#define  _POSIX_C_SOURCE 200809L' */
#define  _POSIX_C_SOURCE 200809L

void read_File(char *searchTerm, char *file_name);
void readStdin(char *searchTerm);

int main(int argc, char *argv[]){
    if(argc <= 1){
        fprintf(stdout,"wgrep: searchterm [file ...]\n");    //The error message differs between assigment and tests
        exit(1);
    } else if (argc == 2) {
        readStdin(argv[1]);
        exit(0);
    }
    for(int i = 2; i < argc;i++) {
        read_File(argv[1], argv[i]);
    }
    return(0);
}


void read_File(char *searchTerm, char *file_name){
    char *line = NULL;
    size_t buffer_size = 0;
    FILE *file;

    if ((file = fopen(file_name, "r")) == NULL) {
        fprintf(stdout,"wgrep: cannot open file\n"); //The error message differs between assigment and tests
        exit(1);
    }

    while(getline(&line, &buffer_size, file) != -1){ 
        /*source: https://www.delftstack.com/howto/c/string-contains-in-c/ */
        if (strstr(line, searchTerm)) {
            fprintf(stdout, "%s", line);
        }
    }
    free(line);
    fclose(file);
}


void readStdin(char *searchTerm) {
    char *line = NULL;
    size_t buffer_size = 0;

    while(getline(&line, &buffer_size, stdin) != -1){ 
        /*source: https://www.delftstack.com/howto/c/string-contains-in-c/ */
        if (strstr(line, searchTerm)) {
            fprintf(stdout, "%s", line);
        }
    }
    free(line);
}