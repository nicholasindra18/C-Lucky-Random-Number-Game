#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (){
	//jumlah pemain
	int pemain;
	printf("Input number of players [1..5] : ");
	scanf("%d", &pemain);
		while (pemain < 0 || pemain > 5){
			printf("Input number of players [1..5] : ");
			scanf("%d", &pemain);
		}
		
		printf("\n");
		
	//input nama dan angka
	char nama[125][26];
	int luckynumber[100];
	int panjang;
	int i = 0;
	input:
		for(int i = 0; i < pemain; i++){
			do{
				printf("Player-%d's name [5..25] : ", i+1);
				scanf(" %[^\n]", &nama[i]);
				panjang = strlen(nama[i]);
			} while (panjang < 5 || panjang > 25);
		
		ceknama:
			for (int j = 0; j < pemain; j++){
				if(i != j){
					if(strcmp(nama[i], nama[j])==0){
						printf("Name has been used, please input another name\n");
							do{	
								printf("Player-%d's name [5..25] : ", i + 1);
								scanf("%s", &nama[i]);
								panjang = strlen(nama[i]);
							}
							while (5 > panjang || 25 < panjang);
							goto ceknama;
					}	
				}
			}
			
			do{
				printf("Player-%d's lucky number [1..9] : ", i+1);
				scanf("%d", &luckynumber[i]);
			} while(1 > luckynumber[i] || 9 < luckynumber[i]);
			
		cekangka:
			for (int j = 0; j < pemain; j++){
				if(i != j){
					if(luckynumber[i]==luckynumber[j]){
						printf("Number has been used, please input another number\n");
							do{	
								printf("Player-%d's lucky number [1..9] : ", i+1);
								scanf("%d", &luckynumber[i]);
							}
							while(1 > luckynumber[i] || 9 < luckynumber[i]);
							goto cekangka;
					}	
				}
			}
			printf("\n");
		}
		
	//menu utama
	int towin[100];
	
	for(int i = 0; i < pemain; i++){     
		towin[i] = 0;
	}
	
	menu:
		system("cls");
		printf("No.    Name        Number     Total win    \n");
		for(int i = 0; i < pemain; i++){
			printf("%-5d%-15s %-11d  %d    time(s)\n", i + 1, nama[i], luckynumber[i], towin[i]);
		}
	
		printf("\n");
		
	int nomor;
	do{
		printf("\n");
		printf("Lucky Numbers Game\n"); 
		printf("\n");
		printf("1. Change Player\n");
		printf("2. View Lucky Number\n");
		printf("3. Exit\n");
		printf("Choice : ");
		scanf(" %d", &nomor);
	} while ( 1 > nomor || 3 < nomor);
		
	//pilihan nomor
	int urutan;
	switch(nomor){
		case 1:
			do{
				printf("Input player index to change [1..%d]: ", pemain);
				scanf("%d", &urutan);
			}while(urutan < 1 || urutan > pemain);
			
			printf("\n");
			
		//newnama
			do{
				printf("Player-%d's new name [5..25] : ", urutan);
				scanf(" %[^\n]", &nama[urutan - 1]);
				panjang = strlen(nama[urutan - 1]);
			} while (panjang < 5 || panjang > 25);
		
		ceknewnama:
			for (int j = 0; j < pemain; j++){
				if(urutan - 1 != j){
					if(strcmp(nama[urutan - 1], nama[j])==0){
						printf("Name has been used, please input another name\n");
							do{	
								printf("Player-%d's new name [5..25] : ", urutan);
								scanf(" %s", &nama[urutan - 1]);
								panjang = strlen(nama[urutan - 1]);
							}
							while (5 > panjang || 25 < panjang);
							goto ceknewnama;
					}	
				}
			}
			
		//newangka
			do{
				printf("Player-%d's new lucky number [1..9] : ", urutan);
				scanf("%d", &luckynumber[urutan - 1]);
			}while(1 > luckynumber[urutan - 1] || 9 < luckynumber[urutan - 1]);
			
		ceknewangka:
			for (int j = 0; j < pemain; j++){
				if(urutan - 1 != j){
					if(luckynumber[urutan - 1]==luckynumber[j]){
						printf("Number has been used, please input another number\n");
							do{	
								printf("Player-%d's new lucky number [1..9] : ", urutan);
								scanf("%d", &luckynumber[urutan - 1]);
							}
							
							while(1 > luckynumber[urutan - 1] || 9 < luckynumber[urutan - 1]);
							goto ceknewangka;
					}	
				}
			}
		towin[urutan - 1] = 0;
		goto menu;
		break;
		
		case 2:
			int angkalucky;
			
			srand(time(NULL));
			angkalucky = rand() % 9 + 1;
			getchar();
			printf("Current lucky number is %d\n", angkalucky);

			for(int i = 0; i < pemain; i++){
				if(luckynumber[i] == angkalucky || towin[i] > 3 ){
					printf("\nThe lucky player: \n");
					printf("1. %s", nama[i]);
				}
			}
							
			for (int i = 0; i < pemain; i++){
				if(luckynumber[i] == angkalucky){
					towin[i] = towin[i] + 1;
				}
			}
			
			for(int j = 0; j < pemain; j++){
				if(towin[j] == 3){
					for(int i = 0; i < pemain; i++){
						if(towin[i] == 3){
							printf("\n\n\nCongratulations..%s has won the game\n", nama[i]);
							printf("\nThank You..");
							break;
						}
					}
				}
			}
			getchar();
			goto menu;
			break;
		
		case 3:
			printf("\n\nNice Try, Thankyou Have a Nice Day");
			break;
					
	}
	return 0;
}

