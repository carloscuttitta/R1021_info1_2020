#include <stdio.h>

int main(void){
	int t0, t1, t2, t3, t4;
	int i, d;
	float prom;
	
	for (i=0; i<5; i++){
		printf("temp %d? ", i+1);
		scanf("%d", &d);
		switch(i){
			case 0:
				t0 = d;
				break;
			case 1:
				t1 = d;
				break;
			case 2:
				t2 = d;
				break;
			case 3:
				t3 = d;
				break;
			case 4:
				t4 = d;
				break;
			default:
				break;
		}
	}
	printf("temps %d %d %d %d %d\n", t0, t1, t2, t3, t4);
	prom = (float)(t0 + t1 + t2 + t3 + t4) / 5;
	printf("prom = %.2f\n", prom);
	return 0;
}
