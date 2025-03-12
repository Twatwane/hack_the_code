
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
	Resource	new_ressource = get_ressource_form_id( ressource_ID );
	ressources_buyed[ ressources_buyed_len ] = new_ressource;
	ressources_buyed[ ressources_buyed_len ].isObsolete = 0;
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

void	setup_current_turn(void)
{
	int	IDS_buyed_current_turn[1000];
	nb_ressources_buyed_current_turn = 0;

	// STRATEGIE D ACHAT ETC

	// exemples random pour acheter la ressource avec RI=1
	int id_to_buy = 2;
	IDS_buyed_current_turn[ nb_ressources_buyed_current_turn ] = id_to_buy;
	buy( id_to_buy );

	put_output(nb_ressources_buyed_current_turn, IDS_buyed_current_turn);

}

// 4 2 2 2
// TOUR 4, BUYED 2 things, ID2 and ID2
// = T, ressources_buyed_current_turn, ID, ID