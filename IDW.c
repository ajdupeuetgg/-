//IDW
#include<math.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct idwpts//散点结构体定义 
{
	double x;
	double y;//x和y坐标值 
	double f;//属性值 
}idwpts;
typedef struct ptds
{
	double dd;
}ptds;

int main()
{
	int num = 50;//定义离散点个数 
	double mx = 20;	//定义点集坐标最大范围 
	double my = 20;
	////////////////////////////////////
	idwpts* a;//定义离散点结构体指针变量 
	a = (idwpts*)malloc(num * sizeof(idwpts));//为该结构体指针变量分配空间 
	if (NULL == a)return 0;//判断是否分配错误
	srand((unsigned)time(NULL));//随机数种子 
	for (int i = 0; i < num; ++i)//循环为点集中的x和y分配随机数 
	{
		(a + i)->x = rand() / (double)(RAND_MAX / mx);
		(a + i)->y = rand() / (double)(RAND_MAX / my);//注意这里的语法格式 
		(a + i)->f = (a + i)->x + (a + i)->y;//属性值赋值 
	}
	printf("采样点集的坐标和属性值为：\n");
	for (int j = 0; j < num; ++j)
	{
		printf("(%.3f,%.3f , %.2f)\t", a[j].x, a[j].y, a[j].f);//循环打印各点 及其属性值 
		if ((j + 1) % 5 == 0)printf("\n");
	}
	////////////////////////////////////
	int dn = 10;//设定插值点数量
	idwpts* d;//定义插值点集结构体数组的指针 
	d = (idwpts*)malloc(dn * sizeof(idwpts));//为插值点分配空间
	if (NULL == d)return 0;//判误
	for (int i = 0; i < dn; ++i)//循环为点集中的x和y分配随机数 
	{
		//for(int j=0;j<)
		(d + i)->x = rand() / (double)(RAND_MAX / mx);
		(d + i)->y = rand() / (double)(RAND_MAX / my);//获取插点坐标值 
		(d + i)->f = 0;
	}
	printf("插值点的坐标和未经计算的属性值为：\n");
	for (int j = 0; j < dn; ++j)
	{
		printf("(%.3f,%.3f , %.2f)\t", d[j].x, d[j].y, d[j].f);//循环打印各点 及其属性值 
		if ((j + 1) % 5 == 0)printf("\n");
	}	
	////////////////////////////////////
	//计算插值点d[i]到所有点的距离，存储在数组ds[i]中 
	ptds** ds;
	ds = (ptds**)malloc(dn* sizeof(ptds*));//
	if (NULL == ds)return 0;
	double tmp = 0;//中间变量 
	for (int i = 0; i < dn; ++i)//注意到所有点的距离，使用num变量计数，而不是dn变量 
	{
		ds[i] = (ptds*)malloc(num * sizeof(ptds));///////////	
		if (ds[i] == NULL)return 0;
		for (int j = 0; j < num; ++j)
		{
			tmp = (a[j].x - d[i].x) * (a[j].x - d[i].x) + (a[j].y - d[i].y) * (a[j].y - d[i].y);//平方和
			ds[i][j].dd = 1.0 / sqrt(tmp);//求未知点d[i]到所有点的距离的倒数，并存储在数组ds中 
		}
	}
	////////////////////////////////////
	//计算反距离权重 
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
			sum[i] = tmpsum;//计算所有反距离的和 
		}
	}
	ptds** w;
	w = (ptds**)malloc(dn * sizeof(ptds*));//
	if (NULL == w)return 0; 
	for (int i = 0; i < dn; ++i)//注意到所有点的距离，使用num变量计数，而不是dn变量 
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
	printf("插值结果为：\n");
	for (int i = 0; i < dn; ++i)
	{
		printf("(%.3f,%.3f , %.2f)\t",d[i].x,d[i].y,d[i].f );
		if ((i + 1) % 5 == 0)printf("\n");
	}



	free(a);//释放空间 
	free(d);
	free(sum);
	for (int i = 0; i <dn; ++i)
	{
		free(ds[i]);
		free(w[i]);
	}
	free(ds);
	free(w);		

	printf("\nIDW插值结束!\n");
	return 0;
}