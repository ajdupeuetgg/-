//IDW
#include<math.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct idwpts//ɢ��ṹ�嶨�� 
{
	double x;
	double y;//x��y����ֵ 
	double f;//����ֵ 
}idwpts;
typedef struct ptds
{
	double dd;
}ptds;

int main()
{
	int num = 50;//������ɢ����� 
	double mx = 20;	//����㼯�������Χ 
	double my = 20;
	////////////////////////////////////
	idwpts* a;//������ɢ��ṹ��ָ����� 
	a = (idwpts*)malloc(num * sizeof(idwpts));//Ϊ�ýṹ��ָ���������ռ� 
	if (NULL == a)return 0;//�ж��Ƿ�������
	srand((unsigned)time(NULL));//��������� 
	for (int i = 0; i < num; ++i)//ѭ��Ϊ�㼯�е�x��y��������� 
	{
		(a + i)->x = rand() / (double)(RAND_MAX / mx);
		(a + i)->y = rand() / (double)(RAND_MAX / my);//ע��������﷨��ʽ 
		(a + i)->f = (a + i)->x + (a + i)->y;//����ֵ��ֵ 
	}
	printf("�����㼯�����������ֵΪ��\n");
	for (int j = 0; j < num; ++j)
	{
		printf("(%.3f,%.3f , %.2f)\t", a[j].x, a[j].y, a[j].f);//ѭ����ӡ���� ��������ֵ 
		if ((j + 1) % 5 == 0)printf("\n");
	}
	////////////////////////////////////
	int dn = 10;//�趨��ֵ������
	idwpts* d;//�����ֵ�㼯�ṹ�������ָ�� 
	d = (idwpts*)malloc(dn * sizeof(idwpts));//Ϊ��ֵ�����ռ�
	if (NULL == d)return 0;//����
	for (int i = 0; i < dn; ++i)//ѭ��Ϊ�㼯�е�x��y��������� 
	{
		//for(int j=0;j<)
		(d + i)->x = rand() / (double)(RAND_MAX / mx);
		(d + i)->y = rand() / (double)(RAND_MAX / my);//��ȡ�������ֵ 
		(d + i)->f = 0;
	}
	printf("��ֵ��������δ�����������ֵΪ��\n");
	for (int j = 0; j < dn; ++j)
	{
		printf("(%.3f,%.3f , %.2f)\t", d[j].x, d[j].y, d[j].f);//ѭ����ӡ���� ��������ֵ 
		if ((j + 1) % 5 == 0)printf("\n");
	}	
	////////////////////////////////////
	//�����ֵ��d[i]�����е�ľ��룬�洢������ds[i]�� 
	ptds** ds;
	ds = (ptds**)malloc(dn* sizeof(ptds*));//
	if (NULL == ds)return 0;
	double tmp = 0;//�м���� 
	for (int i = 0; i < dn; ++i)//ע�⵽���е�ľ��룬ʹ��num����������������dn���� 
	{
		ds[i] = (ptds*)malloc(num * sizeof(ptds));///////////	
		if (ds[i] == NULL)return 0;
		for (int j = 0; j < num; ++j)
		{
			tmp = (a[j].x - d[i].x) * (a[j].x - d[i].x) + (a[j].y - d[i].y) * (a[j].y - d[i].y);//ƽ����
			ds[i][j].dd = 1.0 / sqrt(tmp);//��δ֪��d[i]�����е�ľ���ĵ��������洢������ds�� 
		}
	}
	////////////////////////////////////
	//���㷴����Ȩ�� 
	double* sum;
	sum = (double*)malloc(dn * sizeof(double));
	if (NULL == sum)return 0;
	double tmpsum = 0;
	for (int i = 0; i < dn; ++i)
	{
		tmpsum = 0;
		for (int j = 0; j < num; ++j)
		{
			tmpsum = tmpsum + ds[i][j].dd;
			sum[i] = tmpsum;//�������з�����ĺ� 
		}
	}
	ptds** w;
	w = (ptds**)malloc(dn * sizeof(ptds*));//
	if (NULL == w)return 0; 
	for (int i = 0; i < dn; ++i)//ע�⵽���е�ľ��룬ʹ��num����������������dn���� 
	{
		w[i] = (ptds*)malloc(num * sizeof(ptds));///////////	
		if (w[i] == NULL)return 0;
		for (int j = 0; j < num; ++j)
		{
			w[i][j].dd= ds[i][j].dd / sum[i];
		}
	}
	////////////////////////////////////
	double drtmpf = 0;
	for (int i = 0; i < dn; ++i)
	{
		drtmpf = 0;
		for (int j = 0; j < num; ++j)
		{
			drtmpf = drtmpf + w[i][j].dd* a[j].f;
			d[i].f = drtmpf;
		}
	}
	printf("��ֵ���Ϊ��\n");
	for (int i = 0; i < dn; ++i)
	{
		printf("(%.3f,%.3f , %.2f)\t",d[i].x,d[i].y,d[i].f );
		if ((i + 1) % 5 == 0)printf("\n");
	}



	free(a);//�ͷſռ� 
	free(d);
	free(sum);
	for (int i = 0; i <dn; ++i)
	{
		free(ds[i]);
		free(w[i]);
	}
	free(ds);
	free(w);		

	printf("\nIDW��ֵ����!\n");
	return 0;
}