#include<stdio.h>
int main()
{
	float molar_mass;
	float volume;
	float mass_of_solute;
	float molarity;
	float moles_of_solute;
	printf("enter molarmass:\n");
	printf("enter mass_of_solute:\n");
	printf("enter volume:\n");
	scanf("%f%f%f",&molar_mass,&mass_of_solute,&volume);
	moles_of_solute=mass_of_solute/molar_mass;
	molarity=moles_of_solute/volume;
	printf("molarity:%f",molarity);
	return 0;
}
