#include "header.h"
enum status insert_record(struct book_record br[],char author_name[],char book_name[],unsigned int publication_year,unsigned int copies_available)
{
	struct book_record temp;
	int index,j,num,sorted=0;
	enum status insert;
	printf("Check Point");
	index=search_record(br,author_name,book_name);  /*SEARCHING RECORD*/
	if(index!=-1) /*FOUND -- UPDATING DATA*/
	{
	    br[index].publication_year=publication_year;
		br[index].copies_available=copies_available;
		insert=YES;
	}
	else  /*NOT FOUND -- INSERTING DATA*/
	{
		num=get_num_records(br);
		if(num<TOTAL_RECORDS)
		{
		    strcpy(br[num].author_name,author_name);
			strcpy(br[num].book_name,book_name);
			br[num].publication_year=publication_year;
			br[num].copies_available=copies_available;
			/*MAKING SORTED*/
			j=num;
			while((j>0) && (sorted==0))
			{
			    if(strcmp(br[j-1].author_name,br[j].author_name)>0)
			    {
				    temp=br[j-1];
					br[j-1]=br[j];
					br[j]=temp;
					j--;
				}
				else
				{
				    sorted=1;	
				}
			}	
			if(sorted==1)
			{
			    sorted=0;
				while((j>0) && (sorted==0))
			    {
			        if((strcmp(br[j-1].author_name,br[j].author_name)==0) && (strcmp(br[j-1].book_name,br[j].book_name)>0))
			        {
				        temp=br[j-1];
					    br[j-1]=br[j];
					    br[j]=temp;
					    j--;
				    }
				    else
				    {
				        sorted=1;	
				    }
			    }		
			}
			insert=YES;
		}
		else
		{
		  	insert=NO;
		}	
	}
	return insert;
}
