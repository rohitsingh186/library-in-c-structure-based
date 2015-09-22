#include "header.h"
int search_record(struct book_record br[],char author_name[],char book_name[])
{
	int num,index;
	num=get_num_records(br);
	index=find_record(br,author_name,book_name,0,(num-1)); /*CALLING ANOTHER FUNCTION*/
	return index;
}
int find_record(struct book_record br[],char author_name[],char book_name[],int lo,int hi)
{
	int ret_val=-1,mid,found=0;
	int i;
	if(lo>hi)
	{
	    ret_val=-1;	
	}
	else
	{
	    mid=(lo+hi)/2;
		if(strcmp(br[mid].author_name,author_name)==0)
		{
		    i=mid;
			while((strcmp(br[i].author_name,author_name)==0) && (found==0))
			{
			    if(strcmp(br[i].book_name,book_name)==0) /*KEY FOUND*/
				{
				    ret_val=i;
					found=1;	
				}	
				else
				{
				    i++;	
				}
			}	
			i=mid-1;
			while((strcmp(br[i].author_name,author_name)==0) && (found==0))
			{
			    if(strcmp(br[i].book_name,book_name)==0)  /*KEY FOUND*/
				{
				    ret_val=i;
					found=1;	
				}	
				else
				{
				    i--;	
				}
			}	
		}	
		else if(strcmp(br[mid].author_name,author_name)>0)
		{
		    ret_val=find_record(br,author_name,book_name,lo,(mid-1));  /*DESIRED CONDITION MAY LIE IN LEFT PART*/	
		}
		else
		{
		    ret_val=find_record(br,author_name,book_name,(mid+1),hi); /*DESIRED CONDITION MAY LIE IN RIGHT PART*/	
		}
	}
	return ret_val;
}
