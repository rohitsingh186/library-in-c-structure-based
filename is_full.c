#include "header.h"
enum status is_full(struct book_record br[])
{
	enum status full;
	if(br[TOTAL_RECORDS-1].publication_year!=0)
	{
	    full=YES;	
	}
	else
	{
	    full=NO;	
	}
	return full;
}
