//		��Ŀ����: ����ƽ����
//		
//		    С�������� 203879 ������ַ�����
//		
//		    ԭ����203879 * 203879 = 41566646641
//		
//		    ����ʲô�����أ���ϸ�۲죬203879 �Ǹ�6λ������������ÿ����λ�ϵ����ֶ��ǲ�ͬ�ģ�������ƽ�����������λ�϶��������������������֡�
//		
//		    ���������ص��6λ������һ���������ҳ�����
//		
//		    �ٹ���һ��ɸѡҪ��
//		    1. 6λ������
//		    2. ÿ����λ�ϵ����ֲ�ͬ
//		    3. ��ƽ������ÿ����λ����ԭ���ֵ��κ������λ
//		
//		����һ��6λ����������
//		
//		��ͨ��������ύ�𰸡�
//		ע�⣺ֻ�ύ��һ6λ���������Ѿ������������Ҫ�ύ��
//		ע�⣺��Ҫ��д���������ݣ����磺˵���Ե����֣���
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
