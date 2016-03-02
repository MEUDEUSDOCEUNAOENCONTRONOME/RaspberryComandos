#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <bcm2835.h>

int main(int argc, char **argv)
{
///Verifica se o arquivo existe.
FILE *arquivo;
if(arquivo = fopen("/home/pi/Executaveis/README.dat","r"))
{
	
	system("sudo rm /home/pi/Executaveis/README.dat");
	system("wget -O /home/pi/Executaveis/README.dat 'https://raw.githubusercontent.com/MEUDEUSDOCEUNAOENCONTRONOME/RaspberryComandos/master/README.md'");
	
}
else
{
	
	system("wget -O /home/pi/Executaveis/README.dat 'https://raw.githubusercontent.com/MEUDEUSDOCEUNAOENCONTRONOME/RaspberryComandos/master/README.md'");
		
}
fclose(arquivo);
float comando = 0;
char status[255];
FILE *file;
file = fopen("/home/pi/Executaveis/README.dat","r");
fscanf(file,"Comando %s\n", &status);
///printf("\n\n%s\n\n", status);
fclose(file);

comando = atof(status);
///printf("\n\n%f\n\n", comando);

if(comando == 1)
{
	///system("gcc -o RaizExecuta -l rt RaizExecuta.c -l bcm2835");
	system("sudo ./Executaveis/RaizExecuta");
	///printf("\n1\n");
	///system("wget https://raw.githubusercontent.com/MEUDEUSDOCEUNAOENCONTRONOME/RaspberryComandos/master/README.md");
}else if(comando == 0)
{
	if(!bcm2835_init())return 1;
		bcm2835_gpio_fsel(18, BCM2835_GPIO_FSEL_OUTP);
		bcm2835_gpio_fsel(21, BCM2835_GPIO_FSEL_OUTP);
		bcm2835_gpio_fsel(23, BCM2835_GPIO_FSEL_OUTP);
		
		bcm2835_gpio_clr(18);
		bcm2835_gpio_clr(21);
		bcm2835_gpio_clr(23);
		
///		printf("\n0\n");
}
	

return 0;
	
}
