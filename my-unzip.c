#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct compressed_char_struct
{
    int binary_no;
    char character;
};


void read_Zipped_File(char *file_name);
void unZip(int amount, char character);

int main(int argc, char *argv[]){

    if(argc == 1){
        fprintf(stdout, "wunzip: file1 [file2 ...]\n"); //The error message differs between assigment and tests
        exit(1);
    }

    for(int i = 1; i < argc;i++){
        read_Zipped_File(argv[i]);
    }

    return(0);
}



void read_Zipped_File(char *file_name){
    char *line = NULL;
    FILE *file;
    struct compressed_char_struct compressed_char;

    if ((file = fopen(file_name, "rb")) == NULL) {
        fprintf(stdout, "my-zip: cannot open file\n"); //The error message differs between assigment and tests
        exit(1);
    }

    //How to read file to struct https://overiq.com/c-programming-101/fread-function-in-c/
    //The size of read bytes is 5 because char takes one byte and integer the remaining four.
    while (fread(&compressed_char, 5, 1, file) == 1)
        unZip(compressed_char.binary_no, compressed_char.character);
        
    free(line);
    fclose(file);
}

void unZip(int amount, char character){
    for(int i = 0; i < amount; i++ )
        printf("%c", character);
    

}

/*******************EOF*******************/


