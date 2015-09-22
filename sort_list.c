#include "header.h"
void sort_list(struct book_record br[])
{
	int i,j,x,y,sorted=0;
	struct book_record temp;
	for(i=0;(i<(TOTAL_RECORDS-1)) && (sorted==0);i++)
	{
	    sorted=1;
		for(j=0;j<(TOTAL_RECORDS-i-1);j++)
		{
	        x=strcmp(br[j].author_name,br[j+1].author_name);
	        if(x>0)
	        {   
			    if(br[j+1].author_name[0]!='\0') /*NOT IN ORDER*/
				{
				    temp=br[j];
					br[j]=br[j+1];
					br[j+1]=temp;
					sorted=0;	
				}
			}
			else if(x<0)
			{
				if(br[j].author_name=='\0') /*NOT IN ORDER*/
				{
		            temp=br[j];
					br[j]=br[j+1];
					br[j+1]=temp;
					sorted=0;	
				}	
			}
			else
			{
			    y=strcmp(br[j].book_name,br[j+1].book_name);
				if(y>0) /*NOT IN ORDER*/
				{
				    temp=br[j];
					br[j]=br[j+1];
					br[j+1]=temp;
					sorted=0;
				}	
			}	
		}	
	}
}
