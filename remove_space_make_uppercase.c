#include "header.h"
void remove_space_make_uppercase(char name[])
{
	int i=0;
	while(name[i] != '\0')
	{
		/*MAKING UPPERCASE*/
		if((name[i]>='a') && (name[i]<='z'))
	    {
	        name[i]=name[i]+'A'-'a';	
	    }
	    /*REMOVING SPACE*/
	    if(name[i]==' ')
	    {
		    name[i]='_';	
		}
		i++;
	}
}
