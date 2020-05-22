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
/*Lenguaje Imperativo*/
/*--------------------------------------------------------------------------------------------------------------------*/

#define MAXCHAR 10000
typedef enum { RESIDENCIALES, FULLMOVIL, MOVISTAR, CLARO, KOLBI } Type; /*['(506)2...','(506)5...','(506)6...','(506)7...','(506)8...']*/

/*--------------------------------------------------------------------------------------------------------------------*/
/*Structs*/
struct node {
    Type type;
    char num[11];
    struct node *next;
};
struct node *head = NULL;

/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to insert node  */
void insertNode(char *number, int size, Type type) {
    //create a node
    struct node *node = (struct node*) malloc(sizeof(1));
    node->type = type;
    /*Make an international number*/
    if(size == 8){
        node->num[0] = '5';
        node->num[1] = '0';
        node->num[2] = '6';
        for (int i = 0; i < size; ++i) {
            node->num[i + 3] = number[i];
        }
    }else{
        for (int i = 0; i < size; ++i) {
            node->num[i] = number[i];
        }
    }
    //point it to old first node
    node->next = head;
    //point first to new first node
    head = node;
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*Methods to display the list phone numbers*/
void printList(Type type, char str[]) {
    struct node *ptr = head;
    printf("\n******************************************");
    printf("\nNumeros de %s", str);
    //start from the beginning
    while(ptr != NULL) {
        if(ptr->type == type){
            printf("\n=>%s", ptr->num);
        }
        ptr = ptr->next;
    }
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*Method to check if exist a pattern in string*/
int match(const char *string, const char *pattern){
    regex_t regex;
    if (regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB) != 0){
        return 0;
    }
    int status = regexec(&regex, string, 0, NULL, 0);
    regfree(&regex);
    if (status != 0) {
        return 0;
    }
    return 1;
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*Method to get phone numbers in string*/
void getNumber(char string[MAXCHAR]){
    char array[11];
    int cont =0;
    /*For in every char*/
    for (int i = 0; i < strlen(string); ++i) {
        if (isdigit(string[i]) == 1){
            array[cont] = (char) string[i];
            cont++;
        }
    }
    /*if are less of 8 numbers in string, int's phone number*/
    if(cont < 8 ){
        return ;
    }
    /*check the type*/
    const char* tel = "506[0-9]{8}";
    /*if the number had 506?*/
    if(match(array, tel) == 1){
        const char* house = "5062[0-9]{7}";
        const char* fullmovil = "5065[0-9]{7}";
        const char* movistar = "5066[0-9]{7}";
        const char* claro = "5067[0-9]{7}";
        const char* kolbi = "5068[0-9]{7}";

        if(match(array, house) == 1){
            printf("\nCASA ENCONTRADA.........................");
            insertNode(array, 11, RESIDENCIALES);
        }
        else if(match(array, movistar) == 1){
            insertNode(array, 11, MOVISTAR);
        }
        else if(match(array, kolbi) == 1){
            insertNode(array, 11, KOLBI);
        }
        else if(match(array, claro) == 1){
            insertNode(array, 11, CLARO);
        }
        else if(match(array, fullmovil) == 1){
            insertNode(array, 11, FULLMOVIL);
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
        if(match(array, house) == 1){
            insertNode(array, 8, RESIDENCIALES);
        }
        else if(match(array, movistar) == 1){
            insertNode(array, 8, MOVISTAR);
        }
        else if(match(array, kolbi) == 1){
            insertNode(array, 8, KOLBI);
        }
        else if(match(array, claro) == 1){
            insertNode(array, 8, CLARO);
        }
        else if(match(array, fullmovil) == 1){
            insertNode(array, 8, FULLMOVIL);
        }
        else{
            printf("\t\t\n=>Telefono No Identificado");
        }
    }
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*show structs info*/
void showInfo(){
    /*----------------------------------------------------------------------------------------------------------------*/
    printf("\n******************************************");
    printf("\n******MOSTRANDO DATOS DE LA LISTA*********");
    char residenciales[] = "Residenciales";
    char  fullmovil[] = "Fullmovil";
    char  movistar[] = "Movistar";
    char  claro[] = "Claro";
    char  kolbi[] = "Kolbi";

    printList(RESIDENCIALES, residenciales);
    printList(FULLMOVIL, fullmovil);
    printList(MOVISTAR,movistar);
    printList(CLARO, claro);
    printList(KOLBI, kolbi);
    printf("\n******************************************");
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Load archive*/
void loadArchive(int opcion){
    char path[MAXCHAR];
    char cwd[PATH_MAX];
    char archiveName[15];
    if(opcion == 1){
        strcpy(archiveName, "/archivo.txt");
    }else{
        strcpy(archiveName, "/archivo2.txt");
    }
    /*----------------------------------------------------------------------------------------------------------------*/
    /*Check if is possible to get the proyect path*/
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcpy(path, cwd);
        strcat(path, archiveName);
        printf("\n->La ubicacion del archivo de texto es: %s\n", path);
    } else {
        perror("\n->Error al ubicar del archivo");
        return ;
    }
    /*----------------------------------------------------------------------------------------------------------------*/
    /*Try to open the file*/
    FILE *fp;
    char str[MAXCHAR];
    char* filename = path;
    /*open in read mode*/
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("\n\n->No se pudo abrir el archivo %s",filename);
        return ;
    }
    head = NULL;
    /*----------------------------------------------------------------------------------------------------------------*/
    /*loop to read line by line in File*/
    while (fgets(str, MAXCHAR, fp) != NULL){
        getNumber(str);
    }
    fclose(fp);
    showInfo();
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*Application*/
int main() {
    /*----------------------------------------------------------------------------------------------------------------*/
    /*Menu*/
    int  opcion;
    do{
        printf("\n\n*********************************************************************************");
        printf( "\n   1. Clasificar numeros del archivo 1");
        printf( "\n   2. Clasificar numeros del archivo 2");
        printf( "\n   3. Salir." );
        printf( "\n\n   Introduzca opci%cn (1-3): ", 162 );
        scanf( "%d", &opcion );
        printf("\n*********************************************************************************");
        switch ( opcion ){
            case 1:
                loadArchive(opcion);
                break;
            case 2:
                loadArchive(opcion);
                break;
        }
    } while ( opcion != 3 );
    printf("\nGracias por utilizar el programa!");
    /*----------------------------------------------------------------------------------------------------------------*/
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
