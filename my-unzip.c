#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  _POSIX_C_SOURCE 200809L

struct compressed_char_struct
{
    int var1;
    char var2;
};



void create_Zip(char *line, ssize_t line_size);
void read_File(char *file_name);

int main(int argc, char *argv[]){

    if(argc == 1){
        fprintf(stdout, "my-unzip: file1 [file2 ...]\n");
        exit(1);
    }

    for(int i = 1; i < argc;i++){
        read_File(argv[i]);
    }

    return(0);
}



void read_File(char *file_name){
    char *line = NULL;
    //ssize_t line_size = 0;
    //size_t buffer_size = 0;
    FILE *file;
    struct compressed_char_struct compressed_char;

    //unsigned char buffer[1];



    if ((file = fopen(file_name, "rb")) == NULL) {
        perror("my-zip: cannot open file");
        fprintf(stderr,"\n");
        exit(1);
    }

    //How to read file to struct https://overiq.com/c-programming-101/fread-function-in-c/
    while (fread(&compressed_char, 5, 1, file) == 1){
        printf("%d", compressed_char.var1);
        printf("%c", compressed_char.var2);
    }

        

/*
    while((line_size = getline(&line, &buffer_size, file)) != -1){ 
        unZip(line, line_size);
    }
*/
    free(line);
    fclose(file);
}

/*
void unZip(char *line){


}
*/


/*******************EOF*******************/


