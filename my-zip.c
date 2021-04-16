#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create_Tempfile(char *file_name, FILE *fp_tempFile);
void compress_File(FILE *file);

int main(int argc, char *argv[]){

    if(argc == 1){
        fprintf(stdout, "wzip: file1 [file2 ...]\n");   //The error message differs between assigment and tests
        exit(1);
    }

    if(argc < 3){
        FILE *fp;
        if ((fp = fopen(argv[1], "r")) == NULL) {
            fprintf(stdout,"wzip: cannot open file\n"); //The error message differs between assigment and tests
            exit(1);
        }
        compress_File(fp);
    }else{
        //How to use temporary file in c: https://www.geeksforgeeks.org/tmpfile-function-c/
        FILE *fp_tempFile = tmpfile(); 

        //Reading all the given files to a temporary file
        for(int i = 1; i < argc;i++){
            create_Tempfile(argv[i], fp_tempFile);
        }

        //How to use temporary file in c: https://www.geeksforgeeks.org/tmpfile-function-c/
        rewind(fp_tempFile);

        //Reads and zips the temporary file
        compress_File(fp_tempFile);
    }

    return(0);
}


void create_Tempfile(char *file_name, FILE *fp_tempFile){
    char *line = NULL;
    ssize_t line_size;
    size_t buffer_size = 0;
    FILE *file;

    if ((file = fopen(file_name, "r")) == NULL) {
        fprintf(stdout,"wzip: cannot open file\n"); //The error message differs between assigment and tests
        exit(1);
    }

    while((line_size = getline(&line, &buffer_size, file)) != -1){ 
        fprintf(fp_tempFile, "%s", line);
        //create_Zip(line, line_size);
    }

    free(line);
    fclose(file);
}


void compress_File(FILE *file){
    char c; 
    char pre_char;
    int counter = 0;

    if(feof(file)){
        fprintf(stdout,"wzip: the file is empty\n"); //The error message differs between assigment and tests
        exit(1);
    }

    //Reads the file character by character using fgetc. Source: https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
    c = fgetc(file);
    pre_char = c;

    while(1){ 
        if(feof(file)){
            fwrite(&counter, 4, 1,stdout);
            fprintf(stdout,"%c", pre_char);
            break;
        }
        if(pre_char == c){
            counter++;
        }else{
            fwrite(&counter, 4, 1,stdout);
            fflush(stdout);
            fprintf(stdout,"%c", pre_char);
            fflush(stdout);
            pre_char = c;
            counter = 1;
        }

        c = fgetc(file);
    }

    fclose(file);
}

/*******************EOF*******************/