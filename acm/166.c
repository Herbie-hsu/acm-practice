#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define	GET_MONEY_SIZE	(2000)
#define	PAY_MONEY_SIZE	(2000)
#define	COIN_NUMS	(6)

int main()
{
	//Store the get array
	int get_money[GET_MONEY_SIZE]={};
	int i,j,c;
	int coins[COIN_NUMS]={5,10,20,50,100,200};
	get_money[0]=0;
	for(i=1; i<GET_MONEY_SIZE; i++){
		int mi=0xffff;
		for(j=0; j< COIN_NUMS; j++){
			for(c=1; ;c++){
				if (i-coins[j]*c<0)		break;
				if (get_money[i-coins[j]*c]+c < mi){
					mi=get_money[i-coins[j]*c]+c;
					//printf("[%d]:%d\n",i,mi);	
				}	
			}
		}
		get_money[i]=mi;
	}

	//Store the pay array
	int p,q,sum,pay_money[PAY_MONEY_SIZE],wallet=0;
	int input[6]={0};
	for(i=0;i<6;i++){
		scanf("%d",&input[i]),
		wallet = wallet + input[i]*coins[i];
	}
	scanf("%d.%d",&p,&q);
	sum=100*p+q;
	fprintf(stderr,"The total money:%d\n",sum);
	pay_money[0]=0;
	if (sum>wallet || !wallet){
		printf("You Don't Have Enough Money!!!\n");
	}
	for(i=1;i<PAY_MONEY_SIZE;i++){
		int mi=0xffff;
		for(j=0;j<COIN_NUMS; j++){
			for(c=1;c<=input[j];c++){
				if (i<coins[j]*c)       break;
				if (pay_money[i-coins[j]*c]+c < mi){
					mi=pay_money[i-coins[j]*c]+c;
				}
			}
		}
		pay_money[i]=mi;
		//printf("[%d]:%d\n",i,pay_money[i]);
	}
	int mi=0xffff;
	for(i=sum;i<=wallet;i++){
			if(mi>(pay_money[i]+get_money[i-sum])){
				mi=pay_money[i]+get_money[i-sum];
				printf("%d %d %d\n",i,i-sum,mi);
			}
	}
	//printf("%d\n",mi);
	return 0;
}
