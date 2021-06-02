#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct employee
{
	char name[50];
	int yer;
	int num_otdel;
	int zp;
} employee_t;

void readMen(employee_t *st)
{
	char tmp_name[50];
	int tmp_yer = 0;
	int tmp_num_otdel = 0;
	int tmp_zp = 0;

	printf("Name?\n");
	scanf("%s", tmp_name);
	printf("Yer?\n");
	scanf("%d", &tmp_yer);
	printf("Otdel?\n");
	scanf("%d", &tmp_num_otdel);
	printf("ZP?\n");
	scanf("%d", &tmp_zp);
	printf("\n");

	st->yer = tmp_yer;
	st->num_otdel = tmp_num_otdel;
	st->zp = tmp_zp;
	strcpy(st->name, tmp_name);
}

static int cmp(const void *p1, const void *p2)
{
	employee_t * yer1 = *(employee_t**)p1;
	employee_t * yer2 = *(employee_t**)p2;
	return yer2->yer - yer1->yer;
}

void print_employee_t(employee_t *st)
{
	printf("Name: %s\n", st->name);
	printf("Yer: %d\n", st->yer);
	printf("Num Otdel: %d\n", st->num_otdel);
	printf("ZP: %d", st->zp);
	printf("\n");
}


int main(void)
{
	employee_t *buf_man[3];
	
	for(int i = 0; i < 3; i++)
	{
		buf_man[i] = (employee_t*)calloc(1, sizeof(employee_t));
		readMen(buf_man[i]);
	}

	qsort(buf_man, 3, sizeof(employee_t *), cmp);
	
	for(int i = 0; i < 3; i++)
	{
		print_employee_t(buf_man[i]);
		free(buf_man[i]);
	}
	return 0;
}