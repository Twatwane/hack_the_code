
#include "main.h"

Resource	get_ressource_form_id( ressource_ID )
{

	int	i = 0;
	while (i < R) // R = ressource count
	{
		if (resources_available[i].RI == ressource_ID)
			return (resources_available[i]);
		
		i++;
	}

	// not here if all works good
	printf("DEBUG : ressource %i not found\n", ressource_ID);
	return (resources_available[0]); // DEFAULT

}

void	buy( ressource_ID )
{
	Resource	new_ressource = get_ressource_form_id( ressource_ID );

	ressources_buyed[ ressources_buyed_len ] = new_ressource;
}

void	setup_current_turn(void)
{

	// STRATEGIE D ACHAT ETC

	// exemples random
	buy( 1 );


}


