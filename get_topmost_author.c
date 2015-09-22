#include "header.h"
int get_topmost_author(struct book_record br[],char book_name[])
{
	int i,index,num,num_topmost;
	i=0;
	index=-1;
	num_topmost=0;
	num=get_num_records(br);
	while(i<num)
	{
	    if(strcmp(br[i].book_name,book_name)==0)
		{
		    if(br[i].copies_available>num_topmost)
			{
			    index=i;
				num_topmost=br[i].copies_available;	
			}	
		}	
		i++;
	}
	return index;
}
