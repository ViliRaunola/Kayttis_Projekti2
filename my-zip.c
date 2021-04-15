#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  _POSIX_C_SOURCE 200809L

struct mystruct_st
{
    int var1;
    char var2;
};


void create_Zip(char *line, ssize_t line_size);
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
    ssize_t line_size;
    size_t buffer_size = 0;
    FILE *file;

    if ((file = fopen(file_name, "r")) == NULL) {
        perror("my-zip: cannot open file");
        fprintf(stderr,"\n");
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
    int number_one = 1;
    char temp = line[0];
    //struct mystruct_st mystruct;
    

    for(int j=0;j<=line_size;j++) {
        if(temp == '\n') {
            fwrite(&number_one, sizeof(int), 1,stdout);
            fflush(stdout);
            printf("\n");
            fflush(stdout);
            break;
        }
        if(temp == line[j]){
            counter++;
        }else{
            
            fwrite(&counter, sizeof(int), 1,stdout);
            fflush(stdout);
            printf("%c", temp);
            fflush(stdout);
            
           /*
            mystruct.var1 = counter;
            mystruct.var2 = temp;
            fwrite(&mystruct, sizeof(struct mystruct_st), 1, stdout);
            */
            counter = 1;
            temp = line[j];
            
        }
    }
}




/*******************EOF*******************/














