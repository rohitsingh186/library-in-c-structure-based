#include "header.h"
int list_union(struct book_record br1[],struct book_record br2[],struct book_record br3[])
{
	int num1,num2;
	int i=0,j=0,k=0;
	num1=get_num_records(br1);
    num2=get_num_records(br2);
	while((i<num1) && (j<num2))
	{
	    if(strcmp(br1[i].author_name,br2[j].author_name)<0) 
		{
		    br3[k]=br1[i];
			k++;
			i++;	
		}	
		else if(strcmp(br1[i].author_name,br2[j].author_name)>0)
		{
		    br3[k]=br2[j];
			k++;
			j++;	
		}
		else
		{
		    if(strcmp(br1[i].book_name,br2[j].book_name)>0)
		    {
		        br3[k]=br2[j];
			    k++;
			    j++;	
		    }	
		    else if(strcmp(br1[i].book_name,br2[j].book_name)<0)
        	{
		        br3[k]=br1[i];
			    k++;
			    i++;	
		    }  	
		    else
		    {
			    if(br1[i].publication_year<br2[j].publication_year)	
			    {
				   br3[k]=br2[j];
			       k++;
			       j++;
				   i++; 	
				}
				else
				{
				    br3[k]=br1[i];
			        k++;
			        i++;
					j++;   	
				}
			}
		}
	}
	while(i<num1)
	{
	    br3[k]=br1[i];
		k++;
		i++;	
	}
	while(j<num2)
	{
	    br3[k]=br2[j];
		k++;
		j++;	
	}
	return k;
}
