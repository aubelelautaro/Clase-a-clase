#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

void mostrarEmpleados(eEmpleado** lista, int len);
eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();
int listaParaImprimir(eEmpleado** lista, int tam, char* path);
int guardarEmpleadosCSV(eEmpleado** lista, int tam, char* path);
int guardarEmpleadosBinario(eEmpleado** lista, int tam, char* path);

int main()
{
     FILE* f;

     char buffer[4][20];
     void** lista = (void**) malloc(sizeof(void*));
     void** pAuxEmpleado;

     int cont = 0;
     int cant;

    f = fopen("./empleados.bin","rb");

    if(f == NULL){
        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    //fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
   // printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);


     while( !feof(f) ){
        eEmpleado* nuevoEmpleado = new_Empleado();
        if(nuevoEmpleado == NULL){
           exit(1);
        }

        cant = fread( nuevoEmpleado , sizeof(eEmpleado), 1, f);
     if( cant < 1){
        break;
      }

        *(lista + cont) = nuevoEmpleado;
    cont++;

    pAuxEmpleado = (void**) realloc(lista, sizeof(void*) *(cont+1));
    if(pAuxEmpleado == NULL){
        exit(1);
    }
    lista = pAuxEmpleado;
              //printf(" %5d   %10s   %20s  %8.2f\n", atoi(buffer[0]), buffer[1], buffer[2], atof(buffer[3]));
    }

    mostrarEmpleados((eEmpleado**)lista, cont);

    fclose(f);

/*
    if( listaParaImprimir(lista, cont, "ListaEmpleados.txt")){
        printf("Se ha impreso la lista\n\n");
    }
    else{
        printf("Problemas al imprimir\n\n");
    }
  */

  /*   if( guardarEmpleadosCSV(lista, cont, "empleados2")){
        printf("Se han guardado los empleados en csv\n\n");
    }
    else{
        printf("Problemas al guardar los empleados\n\n");
    }
*/

  if( guardarEmpleadosBinario(lista, cont, "empleados")){
        printf("Se han guardado los empleados en binario\n\n");
    }
    else{
        printf("Problemas al guardar los empleados\n\n");
    }






    return 0;
}


void mostrarEmpleados(eEmpleado** lista, int len){

for(int i=0; i < len; i++){
    printf(" %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
}
printf("\n\n");

}


eEmpleado* new_Empleado(){

eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

if(emp != NULL){
    emp->legajo = 0;
    strcpy(emp->nombre, "");
    strcpy(emp->apellido, "");
    emp->sueldo = 0;

}
return emp;
}

eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo){

eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

if(emp != NULL){
    emp->legajo = leg;
    strcpy(emp->nombre, nombre);
    strcpy(emp->apellido, apellido);
    emp->sueldo = sueldo;

}
return emp;
}



int listaParaImprimir(eEmpleado** lista, int tam, char* path){
    int todoOk = 1;

    FILE* f = fopen(path, "w");
    if( f == NULL){
        todoOk = 0;
        return todoOk;
    }
    fprintf(f, "Listado de Empleados\n\n");
    fprintf(f, "Legajo  Nombre  Apellido   Sueldo\n\n");

    for(int i=0; i < tam; i++){
    fprintf(f," %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
}
printf("\n\n");

fclose(f);

return todoOk;
}



int guardarEmpleadosCSV(eEmpleado** lista, int tam, char* path){
    int todoOk = 1;
    char ext[] = ".csv";
    char nombreArchivo[100];
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, ext);

    FILE* f = fopen(nombreArchivo, "w");
    if( f == NULL){
        todoOk = 0;
        return todoOk;
    }

    fprintf(f, "id,first_name,last_name,sueldo\n");

    for(int i=0; i < tam; i++){
    fprintf(f,"%d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
}

fclose(f);

return todoOk;
}

int guardarEmpleadosBinario(eEmpleado** lista, int tam, char* path){
    int todoOk = 1;
    char ext[] = ".bin";
    char nombreArchivo[100];
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, ext);

    FILE* f = fopen(nombreArchivo, "wb");
    if( f == NULL){
        todoOk = 0;
        return todoOk;
    }

    for(int i=0; i < tam; i++){
    //fprintf(f,"%d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    fwrite( *(lista + i),sizeof(eEmpleado), 1, f);
}

fclose(f);

return todoOk;
}

