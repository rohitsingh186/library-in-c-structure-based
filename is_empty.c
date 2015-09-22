#include "header.h"
enum status is_empty(struct book_record br[])
{
	enum status ret_val;
	if(br[0].publication_year==0)
	{
	    ret_val=YES;	
	}
	else
	{
	    ret_val=NO;	
	}
	return ret_val;
}
