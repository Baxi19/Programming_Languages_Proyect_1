#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------------------------------------------------*/
#define MAXCHAR 10000
void displayString(char str[]);
/*--------------------------------------------------------------------------------------------------------------------*/
/*Companies Structs*/
struct nodeHouse {
    char num[11];
    struct nodeHouse *next;
};
struct nodeHouse *head_h = NULL;
struct nodeHouse *current_h = NULL;

struct nodeFullmovil {
    char num[11];
    struct nodeFullmovil *next;
};
struct nodeFullmovil *head_f = NULL;
struct nodeFullmovil *current_f = NULL;

struct nodeMovistar {
    char num[11];
    struct nodeMovistar *next;
};
struct nodeMovistar *head_m = NULL;
struct nodeMovistar *current_m = NULL;

struct nodeClaro {
    char num[11];
    struct nodeClaro *next;
};
struct nodeClaro *head_c = NULL;
struct nodeClaro *current_c = NULL;

struct nodeKolbi {
    char num[11];
    struct nodeKolbi *next;
};
struct nodeKolbi *head_k = NULL;
struct nodeKolbi *current_k = NULL;


/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert link at the first location in House */
void insertFirstHouse(char number[] , int size) {
    //create a link
    struct nodeHouse *link = (struct nodeHouse*) malloc(sizeof(1));

    if(size == 8){
        link->num[0] = '5';
        link->num[1] = '0';
        link->num[2] = '6';
        for (int i = 0; i < size; ++i) {
            link->num[i+3] = number[i];
        }
    }else{
        for (int i = 0; i < size; ++i) {
            link->num[i] = number[i];
        }
    }
    //for (int i = 0; i < size; ++i) {
      //  link->num[i] = number[i];
    //}
    //link->num == &number;

    //point it to old first node
    link->next = head_h;

    //point first to new first node
    head_h = link;
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the list*/
void printListHouse() {
    struct nodeHouse *ptr = head_h;
    printf("\n******************************************");
    printf("\nNumeros Fijos:");
    //start from the beginning
    while(ptr != NULL) {
        printf("\n%s", ptr->num);
        ptr = ptr->next;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Method to check if exist a pattern in string*/
int match(const char *string, const char *pattern){
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0){
        return 0;
    }
    int status = regexec(&re, string, 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return 0;
    }
    return 1;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Method to get phone numbers in string*/
int getNumber(char string[MAXCHAR]){

    char arr[11];
    int cont =0;

    /*For in every char*/
    for (int i = 0; i < strlen(string); ++i) {
        if (isdigit(string[i]) == 1){
            arr[cont] = (char) string[i];
            cont++;
        }
    }

    /*if are less of 8 numbers in string, int's phone number*/
    if(cont < 8 ){
        return 1;
    }

    printf("\n------------------------------------------------------------");
    printf("\nNumero De Telefono:");

    /*Loop to print phone numbers the information*/
    for (int j = 0; j < cont; ++j) {
        printf("[%c]", arr[j]);
    }

    /*check the type*/
    const char* tel = "506[0-9]{8}";

    /*if the number had 506?*/
    if(match(arr, tel) == 1){
        printf("\t\t\n=>Telefono Con 506");

        const char* house = "5062[0-9]{7}";
        const char* fullmovil = "5065[0-9]{7}";
        const char* movistar = "5066[0-9]{7}";
        const char* claro = "5067[0-9]{7}";
        const char* kolbi = "5068[0-9]{7}";

        if(match(arr, house) == 1){
            printf("\t\t\n=>Telefono Fijo Encontrado");
            insertFirstHouse(arr, 11);
        }
        else if(match(arr, movistar) == 1){
            printf("\t\t\n=>Telefono Movistar Encontrado");
        }
        else if(match(arr, kolbi) == 1){
            printf("\t\t\n=>Telefono Kolbi Encontrado");
        }
        else if(match(arr, claro) == 1){
            printf("\t\t\n=>Telefono Claro Encontrado");
        }
        else if(match(arr, fullmovil) == 1){
            printf("\t\t\n=>Telefono Fullmovil Encontrado");
        }
        else{
            printf("\t\t\n=>Telefono No Identificado");
        }

    }else{
        printf("\t\t\n=>Telefono Sin 506");

        const char* house = "2[0-9]{7}";
        const char* fullmovil = "5[0-9]{7}";
        const char* movistar = "6[0-9]{7}";
        const char* claro = "7[0-9]{7}";
        const char* kolbi = "8[0-9]{7}";

        if(match(arr, house) == 1){
            printf("\t\t\n=>Telefono Fijo Encontrado");
            insertFirstHouse(arr, 8);
        }
        else if(match(arr, movistar) == 1){
            printf("\t\t\n=>Telefono Movistar Encontrado");
        }
        else if(match(arr, kolbi) == 1){
            printf("\t\t\n=>Telefono Kolbi Encontrado");
        }
        else if(match(arr, claro) == 1){
            printf("\t\t\n=>Telefono Claro Encontrado");
        }
        else if(match(arr, fullmovil) == 1){
            printf("\t\t\n=>Telefono Fullmovil Encontrado");
        }
        else{
            printf("\t\t\n=>Telefono No Identificado");
        }

    }

    return 1;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Application*/
int main() {
    /*----------------------------------------------------------------------------------------------------------------*/
    /*VARS*/
    char path[MAXCHAR];
    char cwd[PATH_MAX];

    /*----------------------------------------------------------------------------------------------------------------*/
    /*Check if is possible to get the proyect path*/
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcpy(path, cwd);
        strcat(path, "\\archivo.txt");
        printf("La ubicacion del archivo es: %s\n", path);
    } else {
        perror("Error al ubicar del archivo");
        return 1;
    }
    /*----------------------------------------------------------------------------------------------------------------*/
    /*Try to open the file*/
    FILE *fp;
    char str[MAXCHAR];
    char* filename = path;
    /*open in read mode*/
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("No se pudo abrir el archivo %s",filename);
        return 1;
    }
    /*----------------------------------------------------------------------------------------------------------------*/
    /*loop to read line by line in File*/
    while (fgets(str, MAXCHAR, fp) != NULL){
        int number = getNumber(str);
    }
    fclose(fp);
    /*----------------------------------------------------------------------------------------------------------------*/
    printListHouse();
    return 0;
    /*----------------------------------------------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------------------------------------------------*/
void displayString(char str[]){


}
