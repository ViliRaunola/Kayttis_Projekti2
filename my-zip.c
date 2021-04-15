#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  _POSIX_C_SOURCE 200809L



void create_Zip(char *line, ssize_t line_size);
void read_File(char *file_name);

int main(int argc, char *argv[]){

    if(argc == 1){
        fprintf(stdout, "wzip: file1 [file2 ...]\n");   //The error message differs between assigment and tests
        exit(1);
    }

    for(int i = 1; i < argc;i++){
        read_File(argv[i]);
    }

    return(0);
}



void read_File(char *file_name){
    char *line = NULL;
    ssize_t line_size;
    size_t buffer_size = 0;
    FILE *file;

    if ((file = fopen(file_name, "r")) == NULL) {
        fprintf(stdout,"wzip: cannot open file\n"); //The error message differs between assigment and tests
        exit(1);
    }

    while((line_size = getline(&line, &buffer_size, file)) != -1){ 
        create_Zip(line, line_size);
    }

    free(line);
    fclose(file);
}

void create_Zip(char *line, ssize_t line_size){

    int counter = 0;
    char previous_character = line[0];
    

    for(int j=0;j<=line_size;j++) {
        if(previous_character == '\n') {
            counter = 1;
            fwrite(&counter, sizeof(int), 1,stdout);
            fflush(stdout);
            printf("\n");
            fflush(stdout);
            break;
        }
        if(previous_character == line[j]){
            counter++;
        }else{
            
            fwrite(&counter, sizeof(int), 1,stdout);
            fflush(stdout);
            printf("%c", previous_character);
            fflush(stdout);
            
            counter = 1;
            previous_character = line[j];
            
        }
    }
}




/*******************EOF*******************/














