#include <stdio.h>
int myPow(int a, int b);

int main(){

int to_convert=0;
int coefftab[5]={0,0,0,0,0}; //Numbers between 0 and 99999 So the max loop value is 6 for checking on the indice
short ind =0;
int inter=0;
int coeffDiv=0;


/*Scan the number to_convert*/
printf("Enter a value to decompose around Please\n");
scanf("%d",&to_convert);
printf("to_convert=%d\n",to_convert);


/*Algorithm starts here*/

	/*Finding the indice value*/
	for(int e=0;e<6;e++){
		int test=0;
		test=to_convert-myPow(10,e);
			if(test<0){
				ind=e-1; break;
			}	
			
	}
	//printf("ind :%d\n",ind);
	inter=to_convert;	
	
	while(1){
		if(inter==0){break;}
		coeffDiv=inter/myPow(10,ind);
		//printf("to_convert : %d\n",inter);
		coefftab[ind]=coeffDiv;
		inter=inter-myPow(10,ind)*coeffDiv;
		//printf("inter : %d\n",inter);
		//printf("coefftab[%d]=%d\n",ind,coefftab[ind]);
		/*Find the indice value one more time*/		
		for(int d=0;d<6;d++){
			int test2=0;
			test2=inter-myPow(10,d);
			if(test2<0){
				ind=d-1; break;
			}	
			
		}
		//printf("indice_deuxieme=%d\n",ind);
		if(ind==0){
			coefftab[0]=inter;
			break;
		}
		
	}

	/*Print the result array to check it*/
	for(int h=0;h<5;h++){
		printf("coefftab[%d]=%d\n",h,coefftab[h]);

	}

	
	return 0;

}

int myPow(int a, int b){

	int number=1;
	for(int k=0;k<b;k++){
		number=number*a;
	}
	return number;
}
