#include "header.h"
int list_symmetric_difference(struct book_record br1[],struct book_record br2[],struct book_record br3[],struct book_record br4[],struct book_record br5[])
{
	int num;
	num=list_difference(br1,br2,br4);
    num=list_difference(br2,br1,br5);
    num=list_union(br4,br5,br3);
    return num;
}
