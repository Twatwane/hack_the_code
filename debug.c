
#include "main.h"

/*
    int RI;// RI - Resource Identifier
	int RA;// RA - Activation Cost
	int RP;// RP - Periodic Maintenance Cost
	int RW;// RW - Number of consecutive active turns
	int RM;// RM - Number of downtime turns required after full cycle
	int RL;// RL - Total life cycle of the resource
	int RU;// RU - Number of buildings the resource can power per active turn
    char RT;// RT - Special effect type (A, B, C, D, E, or X)
    int RE;// RE - Special effect impact or accumulator capacity
    int isActive;
	int isObsolete;
*/

void	print_ressource( Resource ressource )
{
	printf("RI=%i | ", ressource.RI);
	printf("RA=%i | ", ressource.RA);
	printf("RP=%i | ", ressource.RP);
	printf("RW=%i | ", ressource.RW);
	printf("RM=%i | ", ressource.RM);
	printf("RL=%i | ", ressource.RL);
	printf("RU=%i | ", ressource.RU);
	printf("RT=%c | ", ressource.RT);
	printf("RE=%i | ", ressource.RE);
	printf("isActive=%i | ", ressource.isActive);
	printf("isObsolete=%i\n", ressource.isObsolete);
}

void	print_status( void )
{

	printf("END OF TURN n°%i\n", current_turn);
	printf("MONEY (D) = %i\n", D);
	printf("RESSOURCES WE HAVE :\n");

	for (int i = 0; i < ressources_buyed_len; i++)
	{
		print_ressource( ressources_buyed[ i ]);
	}

	printf("\n");
}
