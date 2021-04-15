#include <stdio.h>
#include <stdlib.h>
#define  _POSIX_C_SOURCE 200809L

void read_File(char *file_name);

int main(int argc, char *argv[]){

    if(argc == 1){
        return(0);
    }

    for(int i = 1; i < argc;i++){
        read_File(argv[i]);
    }

    return(0);
}


void read_File(char *file_name){
    char *line = NULL;
    size_t buffer_size = 0;
    FILE *file;

    if ((file = fopen(file_name, "r")) == NULL) {
        fprintf(stdout ,"wcat: cannot open file\n"); //The error message differs between assigment and tests
        exit(1);
    }

    while(getline(&line, &buffer_size, file) != -1){ 
        fprintf(stdout, "%s", line);
    }

    free(line);
    fclose(file);
}
