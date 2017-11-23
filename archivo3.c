#include <stdio.h>


struct registro{
	int cuenta;
	char nombre[30];
	int balance;

 };

int main()
 {


	FILE *cfPtr;
	struct registro CuentaR;
	//Cuenta c;

	if ((cfPtr = fopen ("cuentas.dat","r" ))==NULL){
	  printf("No se abrio el archivo\n");

	}else{
	  printf("%-6s%-16s%10s\n","No cuenta","Nombre","Balance");

		while (!feof (cfPtr)) {
			fread(&CuentaR, sizeof(struct registro),1,cfPtr);

			if(CuentaR.cuenta != 0){
			  printf("%-6d%-16s%-10d\n",CuentaR.cuenta,CuentaR.nombre,CuentaR.balance);
			
			}
		}
	}
	
	fclose (cfPtr);
	return 0;
}
