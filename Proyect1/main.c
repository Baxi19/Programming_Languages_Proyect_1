/*--------------------------------------------------------------------------------------------------------------------*/
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>
/*--------------------------------------------------------------------------------------------------------------------*/
/*Randald Villegas Brenes*/
/*Proyecto #1 de lenguajes de programacion*/
/*Lenguaje imperativo*/
/*--------------------------------------------------------------------------------------------------------------------*/
#define MAXCHAR 10000

/*--------------------------------------------------------------------------------------------------------------------*/
/*Companies Structs*/
struct nodeHouse {
    char num[11];
    struct nodeHouse *next;
};
struct nodeHouse *head_h = NULL;

struct nodeFullmovil {
    char num[11];
    struct nodeFullmovil *next;
};
struct nodeFullmovil *head_f = NULL;

struct nodeMovistar {
    char num[11];
    struct nodeMovistar *next;
};
struct nodeMovistar *head_m = NULL;

struct nodeClaro {
    char num[11];
    struct nodeClaro *next;
};
struct nodeClaro *head_c = NULL;

struct nodeKolbi {
    char num[11];
    struct nodeKolbi *next;
};
struct nodeKolbi *head_k = NULL;


/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert link at the first location in House */
void insertFirstHouse(char number[] , int size) {
    //create a link
    struct nodeHouse *link = (struct nodeHouse*) malloc(sizeof(1));

    /*Make an international number*/
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

    //point it to old first node
    link->next = head_h;
    //point first to new first node
    head_h = link;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert link at the first location in Fullmovil */
void insertFirstFullmovil(char number[] , int size) {
    //create a link
    struct nodeFullmovil *link = (struct nodeFullmovil*) malloc(sizeof(1));

    /*Make an international number*/
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

    //point it to old first node
    link->next = head_f;
    //point first to new first node
    head_f = link;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert link at the first location in Movistar */
void insertFirstMovistar(char number[] , int size) {
    //create a link
    struct nodeMovistar *link = (struct nodeMovistar*) malloc(sizeof(1));

    /*Make an international number*/
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

    //point it to old first node
    link->next = head_m;
    //point first to new first node
    head_m = link;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert link at the first location in Claro */
void insertFirstClaro(char number[] , int size) {
    //create a link
    struct nodeClaro *link = (struct nodeClaro*) malloc(sizeof(1));

    /*Make an international number*/
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

    //point it to old first node
    link->next = head_c;
    //point first to new first node
    head_c = link;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert link at the first location in Kolbi */
void insertFirstKolbi(char number[] , int size) {
    //create a link
    struct nodeKolbi *link = (struct nodeKolbi*) malloc(sizeof(1));

    /*Make an international number*/
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

    //point it to old first node
    link->next = head_k;
    //point first to new first node
    head_k = link;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the houses list phone numbers*/
void printListHouse() {
    struct nodeHouse *ptr = head_h;
    printf("\n******************************************");
    printf("\nNumeros Fijos (Recidenciales):");
    //start from the beginning
    while(ptr != NULL) {
        printf("\n=>%s", ptr->num);
        ptr = ptr->next;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the fullmovil list phone numbers*/
void printListFullMovil() {
    struct nodeFullmovil *ptr = head_f;
    printf("\n******************************************");
    printf("\nNumeros Fullmovil:");
    //start from the beginning
    while(ptr != NULL) {
        printf("\n=>%s", ptr->num);
        ptr = ptr->next;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the movistar list phone numbers*/
void printListMovistar() {
    struct nodeMovistar *ptr = head_m;
    printf("\n******************************************");
    printf("\nNumeros Movistar:");
    //start from the beginning
    while(ptr != NULL) {
        printf("\n=>%s", ptr->num);
        ptr = ptr->next;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the claro list phone numbers*/
void printListClaro() {
    struct nodeClaro *ptr = head_c;
    printf("\n******************************************");
    printf("\nNumeros Claro:");
    //start from the beginning
    while(ptr != NULL) {
        printf("\n=>%s", ptr->num);
        ptr = ptr->next;
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the kolbi list phone numbers*/
void printListKolbi() {
    struct nodeKolbi *ptr = head_k;
    printf("\n******************************************");
    printf("\nNumeros Kolbi:");
    //start from the beginning
    while(ptr != NULL) {
        printf("\n=>%s", ptr->num);
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

    /*check the type*/
    const char* tel = "506[0-9]{8}";

    /*if the number had 506?*/
    if(match(arr, tel) == 1){
        const char* house = "5062[0-9]{7}";
        const char* fullmovil = "5065[0-9]{7}";
        const char* movistar = "5066[0-9]{7}";
        const char* claro = "5067[0-9]{7}";
        const char* kolbi = "5068[0-9]{7}";

        if(match(arr, house) == 1){
            //printf("\t\t\n=>Telefono Fijo Encontrado");
            insertFirstHouse(arr, 11);
        }
        else if(match(arr, movistar) == 1){
            //printf("\t\t\n=>Telefono Movistar Encontrado");
            insertFirstMovistar(arr, 11);
        }
        else if(match(arr, kolbi) == 1){
            //printf("\t\t\n=>Telefono Kolbi Encontrado");
            insertFirstKolbi(arr, 11);
        }
        else if(match(arr, claro) == 1){
            //printf("\t\t\n=>Telefono Claro Encontrado");
            insertFirstClaro(arr, 11);
        }
        else if(match(arr, fullmovil) == 1){
            //printf("\t\t\n=>Telefono Fullmovil Encontrado");
            insertFirstFullmovil(arr, 11);
        }
        else{
            printf("\t\t\n=>Telefono No Identificado");
        }

    }else{
        const char* house = "2[0-9]{7}";
        const char* fullmovil = "5[0-9]{7}";
        const char* movistar = "6[0-9]{7}";
        const char* claro = "7[0-9]{7}";
        const char* kolbi = "8[0-9]{7}";

        if(match(arr, house) == 1){
            insertFirstHouse(arr, 8);
        }
        else if(match(arr, movistar) == 1){
            insertFirstMovistar(arr, 8);
        }
        else if(match(arr, kolbi) == 1){
            insertFirstKolbi(arr, 8);
        }
        else if(match(arr, claro) == 1){
            insertFirstClaro(arr, 8);
        }
        else if(match(arr, fullmovil) == 1){
            insertFirstFullmovil(arr, 8);
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
        printf("\n\nLa ubicacion del archivo de texto es: %s\n", path);
    } else {
        perror("\n\nError al ubicar del archivo");
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
        printf("\n\nNo se pudo abrir el archivo %s",filename);
        return 1;
    }
    /*----------------------------------------------------------------------------------------------------------------*/
    /*loop to read line by line in File*/
    while (fgets(str, MAXCHAR, fp) != NULL){
        int number = getNumber(str);
    }
    fclose(fp);
    /*----------------------------------------------------------------------------------------------------------------*/
    printf("\n******************************************");
    printf("\n******MOSTRANDO DATOS DE LAS LISTAS*******");
    printListHouse();
    printListFullMovil();
    printListMovistar();
    printListClaro();
    printListKolbi();
    printf("\n******************************************");
    return 0;
    /*----------------------------------------------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------------------------------------------------*/
