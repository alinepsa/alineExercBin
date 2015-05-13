// alineExercBin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void ArquivoBinario(FILE *arq, char inform[1000]);
void Inverter(FILE *arq2, char info2[1000]);

int _tmain(int argc, _TCHAR* argv[])
{
	int z = 0;

	//Crie um arquivo texto com dados de uma página de jornal (web). Noticias.txt - SALVEI NA SOURCE
	//Criar um programa que tenha uma função que leia linha por linha do arquivo Noticias.txt e imprima na tela
	//SEGUE ...
	char url[]="noticia.txt",
	     info[1000];
	FILE *arquivo;
	
	arquivo = fopen(url, "r");
	if(arquivo == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (fgets(info, sizeof(info), arquivo))!=NULL )
			printf("%s", info);
	
	fclose(arquivo);

	//chamada do metodo ArquivoBinario
	ArquivoBinario(arquivo, info);

	//chamada para inverter
	Inverter(arquivo, info);
	

	scanf("%d",z);
	return 0;
}

void ArquivoBinario(FILE *arq, char inform[1000]){

//Criar uma função que leia o arquivo Noticias.txt e o armazene em um arquivo binário Noticias.bin.
	//Segue ...
	FILE *bin;
	
	if ((arq = fopen("jornal.txt", "r")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	if ((bin = fopen("jornal.bin", "wb")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	else {


		while (!feof(arq)){

			fgets(inform, sizeof(inform), arq);
			fputs(inform, bin);
			printf("%s", inform);
		}

	}

	fclose(arq);
	fclose(bin);

}

//Para finalizar, crie uma função que leia o arquivo Noticias.bin 
//e o escreva de forma invertida em um arquivo texto, ou seja,
//a primeira linha lida será escrita na última linha do arquivo texto.
void Inverter(FILE *arq2, char info2[1000]){
	
	FILE *arq3 = NULL;

	if ((arq2 = fopen("noticiainverso.txt", "wb+")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	if ((arq3 = fopen("noticia.bin", "r")) == NULL){
		printf("Arquivo nao pode ser aberto.\n");
	}
	else {


		while (!feof(arq3)){
			fseek(arq3, 1000, SEEK_END);
			arq3 -= sizeof(info2);
			fputs(info2, arq2);
			printf("%s", info2);
		}

	}

	fclose(arq2);
}



