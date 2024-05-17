#include <iostream>
#include <cstdio>
#include <cstring>

void append_text_to_end(char** text, char* append_text){

}

void start_new_line(){

}
void save_info(){
//    FILE* file;
//    file = fopen("myfile.txt", "w");
//    if (file != NULL)
//    {
//        fputs("Hello, files world!", file);
//        fclose(file);
//    }
//    return 0;
/*
 * fprintf(file_object,) // запише набір байт в файл
 * fscanf() // читаємо файл
 * load from the file - все видалити в char**, зробити load з чистого листа
 * */
}
void print_text(){

}
void insert_text_by_line(){

}
void search_text(){

}
void clear_console(){

}
int main() {
    int user_command;
    const size_t buffer_size = 256;
    int row_number = 2;
    char** text = (char**)malloc(row_number * sizeof(char*));
    for (int i = 0; i < row_number; i++)
        text[i] = (char*)malloc(buffer_size * sizeof(char));

    printf("Help information:\n'This program implements Simple Text Editor: the basics of procedural and structural programming'\n");
    printf("Enter a command: ");
    scanf("%d", &user_command);
    printf("Selected command is: %d\n", user_command);
    printf("The command is not implemented");

    for (int i = 0; i < row_number; i++)
        free(text[i]);
    free(text);
    return 0;
}
