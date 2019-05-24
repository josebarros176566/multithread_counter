

#include <pthread.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int soma = 0;
pthread_mutex_t trava;
pthread_t threads[4];
void *primo(void *arg)
{
	unsigned int a = *((unsigned int *)arg);
	int b;
	
	if(a==1 || a==0)
		return NULL;	
	for (b = 2; b < a; b++)
	{
		if (a % b == 0)
			return NULL;
	}

	pthread_mutex_lock(&trava);
	soma++;
	pthread_mutex_unlock(&trava);

	return NULL;
}

int main()
{

	unsigned int n[80];

	int i = 0, j = 0, e, k;

	do
	{
		unsigned int a;
		k = scanf("%u", &a);
		n[j] = a;
		j++;
	} while (k != EOF);

	

	j = j - 1;
	i = 0;

	while (i <= j){
			if ((j - i) >= 4){

			for (e = 0; e < 4; e++){
				unsigned int *a = malloc(sizeof(unsigned int));
				*a = n[i];
				i++;
				pthread_create(&(threads[e]), NULL, primo, (void *)a);
				//free(a);
			}

			for (e = 0; e < 4; e++)
				pthread_join(threads[e], NULL);
		}




		else if ((j - i) == 3){

			for (e = 0; e < 3; e++){
				unsigned int *a = malloc(sizeof(unsigned int));
				*a = n[i];
				i++;
				pthread_create(&(threads[e]), NULL, primo, (void *)a);
				//free(a);
			}

			for (e = 0; e < 3; e++)
				pthread_join(threads[e], NULL);
		}
		else if ((j - i) == 2)
		{
			for (e = 0; e < 2; e++)
			{
				unsigned int *a = malloc(sizeof(unsigned int));
				*a = n[i];
				i++;
				pthread_create(&(threads[e]), NULL, primo, (void *)a);
				//free(a);
			}
			for (e = 0; e < 2; e++)
				pthread_join(threads[e], NULL);
		}

		else if ((j - i) == 1)
		{

			for (e = 0; e < 1; e++)
			{
				unsigned int *a = malloc(sizeof(unsigned int));
				*a = n[i];
				i++;
				pthread_create(&(threads[e]), NULL, primo, (void *)a);
				//free(a);
			}
			for (e = 0; e < 1; e++)
				pthread_join(threads[e], NULL);
		}

		else if ((j - i) == 0)
		{
			break;
		}
	}

	printf("%d\n", soma);
}
