#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <regex.h>

/*--------------------------------------------------------------------------------------------------------------------*/
#define MAXCHAR 10000


/*--------------------------------------------------------------------------------------------------------------------*/
int match(const char *string, const char *pattern)
{
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
int getNumber(char string[MAXCHAR]){

    char arr[strlen(string)];
    int cont =0;

    /*For in every char*/
    for (int i = 0; i < strlen(string); ++i) {
        if (isdigit(string[i]) == 1){
            arr[cont] = (char) string[i];
            cont++;
        }
    }
    /*if isn't numbers in string*/
    if(cont == 0){
        return 1;
    }
    printf("\n------------------------------------------------------------");
    printf("\nPhone Number:");
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
        const char* movistar = "5066[0-9]{7}";
        const char* kolbi = "5068[0-9]{7}";
        const char* claro = "5067[0-9]{7}";
        if(match(arr, house) == 1){
            printf("\t\t\n=>Telefono Fijo Encontrado");
        }
        else if(match(arr, movistar) == 1){
            printf("\t\t\n=>Telefono Movistar Encontrado");
        }
        else if(match(arr, kolbi) == 1){
            printf("\t\t\n=>Telefono Kolbi Encontrado");
        }
        else if(match(arr, claro) == 1){
            printf("\t\t\n=>Telefono Claro Encontrado");
        }else{
            printf("\t\t\n=>Telefono Claro Encontrado");
        }

    }else{
        printf("\t\t\n=>Telefono Sin 506");
        const char* house = "2[0-9]{7}";
        const char* movistar = "6[0-9]{7}";
        const char* kolbi = "8[0-9]{7}";
        const char* claro = "7[0-9]{7}";
        if(match(arr, house) == 1){
            printf("\t\t\n=>Telefono Fijo Encontrado");
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

    }

    return 1;
}
/*--------------------------------------------------------------------------------------------------------------------*/
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

    return 0;
}


