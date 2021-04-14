#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  _POSIX_C_SOURCE 200809L


void create_Zip(char *line);
void read_File(char *file_name);

int main(int argc, char *argv[]){

    if(argc == 1){
        fprintf(stdout, "my-zip: file1 [file2 ...]\n");
        exit(1);
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
        perror("my-zip: cannot open file");
        fprintf(stderr,"\n");
        exit(1);
    }

    while(getline(&line, &buffer_size, file) != -1){ 
        create_Zip(line);
    }

    free(line);
    fclose(file);
}

void create_Zip(char *line){

    int i = 0;
    int counter = 0;
    char *temp;
    strcpy(temp, line[i]);

    while(line[i] != "\n"){
        
        if(strcmp(line[i], temp)){
            counter++;
        }else{
            fwrite(&counter, 4, 1,stdout);
            fprintf(stdout, "%s", line[i]);
        }

    }


}




/*******************EOF*******************/














