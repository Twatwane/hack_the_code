
#include "main.h"

Resource	get_ressource_form_id(int ressource_ID )
{

	int	i = 0;
	while (i < R) // R = ressource count
	{
		if (ressources_available[i].RI == ressource_ID)
		{
			int cost = ressources_available[i].RA;

			if (D < cost)
				printf("DEBUG : ressource %i not enough money to buy !!!\n", ressource_ID);

			D -= cost;

			return (ressources_available[i]);
		}
		
		i++;
	}

	// not here if all works good
	printf("DEBUG : ressource %i not found\n", ressource_ID);
	return (ressources_available[0]); // DEFAULT

}

void	buy( int ressource_ID )
{
	if (ressource_ID == 0) {
		return ;
	} 
	Resource	new_ressource = get_ressource_form_id( ressource_ID );
	ressources_buyed[ ressources_buyed_len ] = new_ressource;
	ressources_buyed_infos[ ressources_buyed_len ] = new_ressource;
	ressources_buyed[ ressources_buyed_len ].isObsolete = 0;

	// SET ACTIVE IF RW > 0
	if ( ressources_buyed[ ressources_buyed_len ].RW > 0 )
		ressources_buyed[ ressources_buyed_len ].isActive = 1;

	ressources_buyed_len++;

	ressources_buyed[current_turn];
	nb_ressources_buyed_current_turn++;
}

void	put_output( int nb_ressources_buyed_current_turn, int* IDS_buyed_current_turn )
{
	printf("%i %i ", current_turn, nb_ressources_buyed_current_turn);

	for (int i = 0; i < nb_ressources_buyed_current_turn; i++)
	{
		printf("%i", IDS_buyed_current_turn[i]);

		if (i != nb_ressources_buyed_current_turn)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int totalRP() {
	int t = 0;
	for (int i = 0; i < ressources_buyed_len; i++) {
		if(!ressources_buyed[i].isObsolete) {
			t += ressources_buyed[i].RP * ressources_buyed[i].RL;
		}
	}
	return t;
}

int get_best_id() {
	int best_id = 0;
	int benef = 0;
	int renta = 0;
	for (int i = 0; i < R; i++) {
		if (D > ressources_available[i].RA + (ressources_available[i].RL * ressources_available[i].RP + totalRP()) * 2) {
			renta = rentability(ressources_available[i], T - current_turn, current_turn - 1);
			//printf("renta %d, id %d\n", renta, i + 1);
			if (renta > benef && renta > 0) {
				benef = renta;
				best_id = i + 1;
			}
		}
	}
	//printf("bestid %d\n",best_id);
	return best_id;
}

void	setup_current_turn(void)
{
	int	IDS_buyed_current_turn[1000];
	nb_ressources_buyed_current_turn = 0;

	// STRATEGIE D ACHAT ETC

	// exemples random pour acheter la ressource avec RI=1
	int id_to_buy = get_best_id();

	if (DEBUG_MODE)
		printf("ID to buy : %i\n", id_to_buy);

	IDS_buyed_current_turn[ nb_ressources_buyed_current_turn ] = id_to_buy;
	buy( id_to_buy );

	if (!DEBUG_MODE)
		put_output(nb_ressources_buyed_current_turn, IDS_buyed_current_turn);

}

// 4 2 2 2
// TOUR 4, BUYED 2 things, ID2 and ID2
// = T, ressources_buyed_current_turn, ID, ID