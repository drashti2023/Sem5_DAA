#include <stdio.h>
int main(){
	int n, i=1, fact=1;
	printf("Enter a number: ");
	scanf("%d",&n);
	
	while(i<=n){
		fact *=i;
		i++;
	}
	printf("answer: %d",fact);
}
