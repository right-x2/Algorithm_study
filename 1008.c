#include <stdio.h>
int main(){
	double A;
	double B;
	scanf("%lf %lf",&A,&B);
	printf("%.9lf",A/B);
	int C;
	int D;
	scanf("%f %f",&C,&D);
	printf("%.1f",(float)C/D);
}