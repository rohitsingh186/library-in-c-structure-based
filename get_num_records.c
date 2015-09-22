#include "header.h"
int get_num_records(struct book_record br[])
{
	int num;
	num=num_records(br,0,(TOTAL_RECORDS-1)); /*CALLING ANOTHER FUNCTION*/
	return num;
}
int num_records(struct book_record br[],int lo,int hi)
{
	int mid,num_rec;
	if(lo>hi) /*EITHER FULL OR EMPTY*/
	{
	    if(br[0].publication_year==0)
		{
		    num_rec=0;	
		}	
		else
		{
		    num_rec=TOTAL_RECORDS;	
		}
	}
	else
	{
	    mid=(lo+hi)/2;
		if((br[mid].publication_year!=0) && (br[mid+1].publication_year==0)) /*POSITION FOUND*/
		{
		    num_rec=mid+1; 
		}	
		else
		{
		    if(br[mid].publication_year==0)
			{
			    num_rec=num_records(br,lo,(mid-1));  /*DESIRED CONDITION MAY LIE IN LEFT PART*/	
			}	
			else
			{
			    num_rec=num_records(br,(mid+1),hi);	 /*DESIRED CONDITION MAY LIE IN RIGHT PART*/
			}
		}
	}
	return num_rec;
}
