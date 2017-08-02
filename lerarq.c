#include "lerarq.h"

void abrearq(char arqnome[20]){
    char info[15];
	FILE *arq;

	arq = fopen(arqnome, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fgets(info, sizeof(info), arq))!=NULL ){
			int infoint;
			infoint = atoi(info);
			if (infoint <= 999999)
            printf("%i\n", infoint);
		}

	fclose(arq);

}
