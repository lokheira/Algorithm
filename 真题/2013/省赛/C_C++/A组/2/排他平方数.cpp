//		题目标题: 排它平方数
//		
//		    小明正看着 203879 这个数字发呆。
//		
//		    原来，203879 * 203879 = 41566646641
//		
//		    这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数位上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。
//		
//		    具有这样特点的6位数还有一个，请你找出它！
//		
//		    再归纳一下筛选要求：
//		    1. 6位正整数
//		    2. 每个数位上的数字不同
//		    3. 其平方数的每个数位不含原数字的任何组成数位
//		
//		答案是一个6位的正整数。
//		
//		请通过浏览器提交答案。
//		注意：只提交另一6位数，题中已经给出的这个不要提交。
//		注意：不要书写其它的内容（比如：说明性的文字）。
#include <stdio.h>
#include <string.h>
#include <cstdlib>

int a,b,c,d,e,f;
int check(char[],char[]);
int main()
{
	for(a=1;a<10;a++)
		for(b=0;b<10;b++)
			if(b!=a)
				for(c=0;c<10;c++)
					if(c!=a&&c!=b)
						for(d=0;d<10;d++)
							if(d!=a && d!=b && d!=c)
								for(e=0;e<10;e++)
									if(e!=a && e!=b && e!=c && e!=d)
										for(f=1;f<10;f++)
										 if(f!=a && f!=b && f!=c && f!=d && f!=e)
										 	{
										 		long long num=f+e*10+d*100+c*1000+b*10000+a*100000;
										 		long long total=num*num;
										 		char arr[12];
										 		char _num[6];
										 		sprintf(arr,"%lld",total);
										 		sprintf(_num,"%d",num);
										 		if(check(arr,_num))
										 		{
										 			printf("%d\n",num);
												 }
											 }
	return 0;	
	
}

int check(char arr[12],char _num[6])
{
	int flag=1;
	int k=strlen(arr);
	for(int i=k-1;i>0;i--)	
	{
		for(int j=0;j<6;j++)
		{
			if(arr[i]==_num[j])
			{
				flag=0;
				break;
			}
		}
		if(!flag)
			break;
	}
	
	if(flag)
		for(int j=0;j<6;j++)
			if(arr[0]==_num[j])
			{
				flag=0;
				break;
			}
	return flag;	
}
