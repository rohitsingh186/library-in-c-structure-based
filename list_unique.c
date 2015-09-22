#include "header.h"
void list_unique(struct book_record br[])
{
	int i,num;
	num=get_num_records(br);
	i=1;
	while(i<num)
	{
		if(strcmp(br[i].author_name,br[i-1].author_name)==0)
		{
		    if(strcmp(br[i].book_name,br[i-1].book_name)==0) /*KEY FOUND*/
			{
			    if(br[i].publication_year>br[i-1].publication_year)
				{
				    delete_list_unique(br,(i-1)); /*ONE DATA DELETED*/
					i--;	
				}	
				else
				{
				    delete_list_unique(br,i); /*ONE DATA DELETED*/
					i--;	
				}
			}	
		}
		i++;
		num=get_num_records(br);
	}
}
void delete_list_unique(struct book_record br[],int i)
{
	int num;
	num=get_num_records(br);
	while(i<(num-1))
	{
	    br[i]=br[i+1];
		i++;	
	}
	initialize_record(br,(num-1));
}
