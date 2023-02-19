#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

int check(int fd, int n, int m);

int main(int argc, char *argv[])
{
    int fd, n, m;
    float data[5];
    int asize = sizeof(data) / sizeof(float);
    int i = 0;

    fd = open("datos.txt", O_RDONLY);
	m = read(fd, data, sizeof(data));
	printf("El archivo contiene el siguiente arreglo:\n\n");
	
    for (i = 0; i < asize; i++) 
	{
        printf("%.1f, ", data[i]);
    }
    
    check(fd, n, m);

    return 0;
}

int check(int fd, int n, int m)
{
	fd = open("datos.txt", 1);
	printf("\nn = %d\n", n);
	
	if(n < 0)
	{
		if (errno == EACCES) 
		{
	        printf("Error: Problema de permisos del archivo\n");
	        return -1;
	    } 
		else if (errno == EAGAIN) 
		{
	        printf("Error: Archivo bloqueado\n");
	        return -1;
	    } 
		else if(errno == EBADF)
		{
	        printf("Error: Mal descriptor del archivo con codigo de error: %d: %s\n", errno, strerror(errno));
	        return -1;
	    }
	    else
		{
			printf("Error desconocido.\n");
			return -1;
		}
	}
	else 
	{
        printf("Si se pudo!\n");
        fclose(fd);
    }
    return 0;
}



