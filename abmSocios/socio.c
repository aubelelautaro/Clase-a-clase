#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "prestamos.h"
#include "libros.h"
#include "autores.h"
#include "socio.h"

void eSocio_init(eSocio socios[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        socios[i].codigo = 0;
        socios[i].estado = 0;
    }
}

void eSocio_initDatos(eSocio socios[], int tam)
{
    int i;
    eSocio_init(socios,tam);
    eSocio auxSocios[]={
    {1,"AAA","AAA",'F',"111-123","ASD@GMAIL.COM",{22,12,2016},1},
    {2,"BBB","BBB",'M',"415-523","BBB@GMAIL.COM",{7,8,2017},1},
    {3,"CCC","CCC",'F',"715-893","CCC@GMAIL.COM",{7,8,2018},1},
    {4,"DDD","DDD",'F',"914-763","CCC@GMAIL.COM",{2,1,2020},1},
    {5,"EEE","EEE",'M',"213-328","CCC@GMAIL.COM",{3,2,2016},1},
    {6,"FFF","FFF",'M',"312-235","CCC@GMAIL.COM",{4,3,2017},1},
    {7,"HHZ","HZZ",'M',"419-164","CCC@GMAIL.COM",{5,4,2018},1},
    {8,"HHA","HAA",'F',"216-473","CCC@GMAIL.COM",{7,8,2019},1},
    {9,"HHN","ZZZ",'M',"369-615","CCC@GMAIL.COM",{7,6,2018},1},
    {10,"HHM","MMM",'F',"498-493","CCC@GMAIL.COM",{1,7,2020},1}};
    for(i=0;i<tam;i++)
    {
        socios[i]=auxSocios[i];
    }
}
void eSocio_mostrarUno(eSocio socios, int tam)
{
    if(socios.estado == 1)
    {
        printf("%d        %s      %s      %c      %s     %s    %d/%d/%d\n",socios.codigo,socios.apellido,socios.nombre,socios.sexo,socios.telefono,socios.eMail,socios.fechaAsociado.dia,socios.fechaAsociado.mes,socios.fechaAsociado.anio);
    }
}

int eSocio_mostrarTodos(eSocio socios[], int tam)
{
    int flag =0;
    int i;
    printf("CODIGO  APELLIDO  NOMBRE   SEXO   TELEFONO    EMAIL          FECHA ASOCIADO\n");
    for(i=0; i<tam; i++)
    {
        if(socios[i].estado == 1)
        {
            eSocio_mostrarUno(socios[i],tam);
            flag =1;
        }
    }
    if(flag ==0)
    {
        printf("NO HAY SOCIOS");
    }
    return flag;
}

int eSocio_buscarLibre(eSocio socios[],int tam)
{
    int index = -1;
    int i =0;
    for(i=0; i<tam; i++)
    {
        if (socios[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int eSocio_buscar(eSocio socios[], int tam, int codigo)
{
    int index = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(socios[i].codigo == codigo && socios[i].estado ==1)
        {
            index=i;
            break;
        }
    }

    return index;
}

int eSocio_siguienteId(eSocio socios[],int tam)
{
    int retorno = 0;
    int i;

        for(i=0; i<tam; i++)
        {
            if(socios[i].codigo>retorno && socios[i].estado == 1)
            {
                 retorno=socios[i].codigo;
            }
        }

    return retorno+1;
}

void eSocio_alta(eSocio socios[], int tam)
{
    int auxCodigo;
    int validar,dia,mes,anio;
    char auxDia[3],auxMes[3],auxAnio[5];
    char auxNombre[31];
    char auxApellido[31];
    char auxSexo='.';
    char auxTelefono[16];
    char auxMail[31];

    int index = eSocio_buscarLibre(socios, tam);

    if(index == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        auxCodigo = eSocio_siguienteId(socios,tam);
        printf("Codigo de socio: %d\n",auxCodigo);

        validar = getStringLetras("Ingrese apellido: ",auxApellido);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
        }
        strcpy(socios[index].apellido,auxApellido);

        validar = getStringLetras("Ingrese nombre: ",auxNombre);
        while(validar == 0)
        {
            validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
        }
        strcpy(socios[index].nombre,auxNombre);

        auxSexo = getChar("Ingrese sexo (M/F):", auxSexo);
        auxSexo = toupper(auxSexo);
        while((auxSexo!= 'F') && (auxSexo!= 'M'))
        {
            auxSexo = getChar("\nError, ingrese F o M solamente",auxSexo);
            auxSexo = toupper(auxSexo);
        }
        socios[index].sexo = auxSexo;

        getStringTelefono("\nIngrese telefono: ",auxTelefono);
        while(!esTelefono(auxTelefono))
        {
            printf("Ingrese un telefono valido (1234-5678): ");
            fflush(stdin);
            gets(auxTelefono);
        }
        strcpy(socios[index].telefono,auxTelefono);

        getStringMail("Ingrese mail: ",auxMail);
        while(!esMail(auxMail))
        {
            printf("Ingrese un mail valido (asd.123@xxxxx.com) :");
            fflush(stdin);
            gets(auxMail);
        }
        strcpy(socios[index].eMail,auxMail);

        do
        {
            getStringNumeros("Ingrese dia entre 1 y 31: ",auxDia);
            dia =atoi(auxDia);
        }while(dia>31 || dia <1);
        socios[index].fechaAsociado.dia = dia;

        do
        {
            getStringNumeros("Ingrese mes entre 1 y 12: ",auxMes);
            mes =atoi(auxMes);
        }while(mes>12 || mes <1);
        socios[index].fechaAsociado.mes = mes;

        do
        {
            getStringNumeros("Ingrese anio entre 2016 y 2020: ",auxAnio);
            anio =atoi(auxAnio);
        }while(anio>2020 || anio <2016);
        socios[index].fechaAsociado.anio = anio;
        socios[index].estado = 1;
        socios[index].codigo = auxCodigo;
        auxCodigo++;
        printf("ALTA EXITOSA!\n\n");
    }
}

void eSocio_baja(eSocio socios[], int tam)
{
    int index;
    int codigo;
    char confirma = '.';
    int retorno = eSocio_mostrarTodos(socios,tam);
    if(retorno==0)
    {
        printf(" PARA DAR DE BAJA\n");
    }
    else
    {
        printf("Ingrese codigo: ");
        scanf("%d", &codigo);
        index = eSocio_buscar(socios,tam,codigo);

        if(index== -1)
        {
            printf("No se encontro al socio\n");
        }
        else
        {
            confirma = getChar("Desea dar de baja el socio? (S/N): ", confirma);
            confirma = toupper(confirma);
            while((confirma!= 'S') && (confirma!= 'N'))
            {
                confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                confirma = toupper(confirma);
            }
            if(confirma=='S')
            {
                socios[index].estado =0;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("No se dio de baja al socio.\n");
            }
        }
    }
}

void eSocio_listar(eSocio socios[],int tam)
{
    eSocio_ordenarPorApellido(socios,tam);
    eSocio_mostrarTodos(socios,tam);
}

void eSocio_ordenarPorApellido(eSocio socios[],int tam)
{
    int i,j;
    eSocio aux;

    for(i=0;i<tam-1;i++)
    {

        for(j=i+1;j<tam;j++)
        {
            if(strcmp(socios[i].apellido,socios[j].apellido)>0)
            {
                aux = socios[i];
                socios[i]= socios[j];
                socios[j]= aux;
            }
            else if(strcmp(socios[j].apellido,socios[i].apellido) == 0)
            {
                if(strcmp(socios[i].nombre,socios[j].nombre)>0)
                {
                    aux = socios[i];
                    socios[i]= socios[j];
                    socios[j]= aux;
                }
            }
        }
    }
}

int eSocio_menuModificacion()
{
    char opcion = '0';

    printf("\n----Modificacion----\n");
    printf("1.Apellido\n");
    printf("2.Nombre\n");
    printf("3.Sexo\n");
    printf("4.Telefono\n");
    printf("5.eMail\n");
    printf("6.Cancelar\n");

    opcion = getOpcion("\nIngrese opcion entre 1 y 6: ", opcion,'1','6');
    return opcion;
}

void eSocio_modificarCampo(eSocio socios[], int tam)
{
    int codigo;
    int index;
    int validar;
    char auxApellido[31];
    char auxNombre[31];
    char auxSexo;
    char auxTelefono[16];
    char auxMail[31];
    int retorno = eSocio_mostrarTodos(socios,tam);
    char confirma='N';
    if(retorno==0)
    {
        printf(" PARA MODIFICAR");
    }else
    {
        printf("Ingrese codigo del socio a modificar: ");
        scanf("%d",&codigo);
        index = eSocio_buscar(socios,tam,codigo);
        if(index==-1)
        {
            printf("No se encontro el socio\n");
        }else{
            do{
                switch(eSocio_menuModificacion())
                {
                case '1':
                    printf("El apellido actual es: %s\n",socios[index].apellido);
                    validar = getStringLetras("Ingrese nuevo apellido: ",auxApellido);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxApellido);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].apellido,auxApellido);
                    }
                    break;

                case '2':
                    printf("El nombre actual es: %s\n",socios[index].nombre);
                    validar = getStringLetras("Ingrese nuevo nombre: ",auxNombre);
                    while(validar == 0)
                    {
                        validar = getStringLetras("ERROR, ingrese solo letras: ",auxNombre);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].nombre,auxNombre);
                    }
                    system("pause");
                    break;

                case '3':
                    printf("El Sexo actual es: %c\n",socios[index].sexo);

                    auxSexo = getChar("Ingrese sexo (M/F):", auxSexo);
                    auxSexo = toupper(auxSexo);
                    while((auxSexo!= 'F') && (auxSexo!= 'M'))
                    {
                        auxSexo = getChar("\nError, ingrese F o M solamente: ",auxSexo);
                        auxSexo = toupper(auxSexo);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                       socios[index].sexo = auxSexo;
                    }
                    system("pause");
                    break;

                case '4':
                    printf("El telefono actual es: %s\n",socios[index].telefono);
                    validar = getStringTelefono("Ingrese nuevo telefono: ",auxTelefono);
                    while(validar == 0)
                    {
                        validar = getStringTelefono("ERROR, ingrese solo Telefono (4xxx-xxxx): ",auxTelefono);
                    }

                    confirma = getChar("\nSeguro quiere modificarlo? (N/S):", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("Error, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].telefono,auxTelefono);
                    }
                    system("pause");
                    break;

                case '5':
                    printf("El eMail actual es: %s\n",socios[index].eMail);
                    validar = getStringMail("Ingrese nuevo eMail: ",auxMail);
                    while(validar == 0)
                    {
                        validar = getStringMail("ERROR, ingrese mail valido (asda@xxxx.com): ",auxMail);
                    }

                    confirma = getChar("Seguro quiere modificarlo? (N/S): ", confirma);
                    confirma = toupper(confirma);
                    while((confirma!= 'S') && (confirma!= 'N'))
                    {
                        confirma = getChar("\nError, ingrese S o N solamente: ",confirma);
                        confirma = toupper(confirma);
                    }
                    if(confirma == 'S')
                    {
                        strcpy(socios[index].eMail,auxMail);
                    }
                    system("pause");
                    break;
                case '6':
                    break;
                default:
                    printf("Ingrese opcion correcta \n");
                    system("pause");
                }
            }while (confirma == 'S');
        }
    }
}

int menu()
{
    char opcion = '.';

    printf("\n----MENU----\n");
    printf("A.Alta\n");
    printf("B.Modificar\n");
    printf("C.Baja\n");
    printf("D.Listar socios por Apellido\n");
    printf("E.MENU LIBROS\n");
    printf("F.MENU AUTORES\n");
    printf("G.Alta prestamo\n");
    printf("H.Listar e Informar\n");
    printf("I.Salir\n");

    opcion=getChar("Elija una opcion: \n",opcion);
    opcion = toupper(opcion);

    return opcion;
}

void eSocio_solicitaronUnLibro(eSocio socios[], int tamSocios, eLibro libros[], int tamLibros,ePrestamo prestamos[],int tamPrestamos)
{
    int i,j,k;
    int codigo;
    int flag=0;
    int contador=ePrestamo_cantidadPrestamos(prestamos,tamPrestamos);

    if(contador!=0)
    {
        eLibro_listar(libros,tamLibros);
        printf("Ingrese codigo de libro: ");
        scanf("%d",&codigo);

        printf("\nCodigo Prestamo  Codigo Socio  Nombre Apellido   Libro  Codigo Libro  FECHA\n\n");
        for(i=0;i<tamPrestamos;i++)
        {
            if(prestamos[i].estado && (prestamos[i].codigoLibro == codigo))
            {
                for(j=0;j<tamSocios;j++)
                {
                    if((prestamos[i].codigoSocio == socios[j].codigo) && socios[j].estado)
                    {
                        for(k=0;k<tamLibros;k++)
                        {
                            if(libros[k].estado && libros[k].codigo == prestamos[i].codigoLibro)
                            {
                                printf("%d                 %d            %s    %s     %s   %d      %d/%d/%d.\n",prestamos[i].codigo,socios[j].codigo,socios[j].nombre,socios[j].apellido,libros[k].titulo,prestamos[i].codigoLibro,prestamos[i].fechaPrestamo.dia,prestamos[i].fechaPrestamo.mes,prestamos[i].fechaPrestamo.anio);
                                flag=1;
                            }
                        }
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("No se encontro algun prestamo de este libro.\n");
        }
    }else
    {
        printf("No hay prestamos.\n");
    }

}

void eSocio_insertionSort(eSocio socios[], int tam)
{
	int i,j;
	eSocio auxiliar;
	for(i = 1; i < tam; i++)
    {
		auxiliar = socios[i];
		j = i-1;
		while(j >= 0 && strcmp(auxiliar.apellido, socios[i].apellido)>0)
        {
			socios[j+1] = socios[j];
			j--;
		}
		socios[j+1] = auxiliar;
	}
	eSocio_mostrarTodos(socios,tam);
}

void eSocio_socioConMasPrestamos(eSocio socios[], int tam, ePrestamo prestamos[], int tamPrestamos)
{
    int max;
    int flag=0;
    int contador;
    int i,j,k,l;
    int valida=ePrestamo_cantidadPrestamos(prestamos,tamPrestamos);

    if(valida!= 0)
    {
        for (i=0;i<tam;i++)
        {
            if(socios[i].estado)
            {
                contador=0;
                for (j=0;j<tamPrestamos;j++)
                {
                    if (socios[i].codigo==prestamos[j].codigoSocio && prestamos[j].estado)
                    {
                        contador++;
                    }
                }
                if(flag==0 && contador!=0)
                {
                    max = contador;
                    flag=1;
                }else if(contador>max && contador!=0)
                {
                    max = contador;
                }

            }

        }
        if (flag==1)
        {
            printf("Codigo   Nombre  Apellido  Cantidad de prestamos\n");

            for (k=0;k<tam;k++)
            {
                if(socios[k].estado)
                {
                    contador=0;
                    for (l=0;l<tamPrestamos;l++)
                    {
                        if (socios[k].codigo==prestamos[l].codigoSocio && prestamos[l].estado)
                        {
                            contador++;
                        }
                    }
                    if(contador== max)
                    {
                         printf("%d         %s   %s         %d\n",socios[k].codigo,socios[k].nombre,socios[k].apellido,max);
                    }
                }
            }
        }
        else
        {
            printf("\nNo hay nada que listar.\n");
        }
    }else
    {
        printf("No hay prestamos.\n");
    }
}

void eSocio_socioConAlgunPrestamo(eSocio socios[], int tam, ePrestamo prestamos[], int tamPrestamos)
{
    int flag=0;
    int dia=0,mes=0,anio=0;
    int i,j;
    int valida=ePrestamo_cantidadPrestamos(prestamos,tamPrestamos);

    if(valida!=0)
    {
        dia =getInt("Ingrese dia: ",dia,1,31);
        mes = getInt("Ingrese mes: ",mes,1,12);
        anio = getInt("Ingrese anio: ",anio,2016,2020);

        printf("\nCODIGO SOCIO  NOMBRE  APELLIDO   FECHA DE PRESTAMO\n");
        for (i=0;i<tam;i++)
        {
            if(socios[i].estado)
            {
                for (j=0;j<tamPrestamos;j++)
                {
                    if (socios[i].codigo == prestamos[j].codigoSocio && prestamos[j].fechaPrestamo.dia== dia && prestamos[j].fechaPrestamo.mes == mes && prestamos[j].fechaPrestamo.anio == anio && prestamos[j].estado)
                    {
                        printf("%d             %s      %s      %d/%d/%d\n",socios[i].codigo,socios[i].nombre,socios[i].apellido,prestamos[j].fechaPrestamo.dia,prestamos[j].fechaPrestamo.mes,prestamos[j].fechaPrestamo.anio);
                        flag=1;
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("No hay socios con prestamos para esta fecha.\n");
        }
    }else
    {
        printf("No hay prestamos.\n");
    }
}
