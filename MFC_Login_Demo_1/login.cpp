#include "login.h"
#include "stdafx.h"

UserData userdata[NUM];

bool UserCheck(const char UserName[], const char UserPassword[])//����û����������Ƿ�ƥ��
{
	unsigned char MD5Password[17];//���ڴ洢��������������MD5ɢ�������Ľ��
	UserDataInit();//�û����������Ӧ��Ϣ�ĳ�ʼ��
	MD5Calc((unsigned char*)UserPassword, MD5Password, strlen(UserPassword));//��������������MD5ɢ�����㣬��ɢ�������Ľ���洢��MD5Password������
	MD5Password[16] = '\0';//�����βд��'\0'������
	for (int i = 0; i < NUM; i++)//�Ƚ��������뾭��MD5ɢ��������ֵ��֮ǰ�洢��ֵ�����Ӧ���û����Ƿ�ƥ��
	{
		if (strcmp(UserName, userdata[i].UserName) == 0 && strcmp((const char*)MD5Password, userdata[i].UserPassword) == 0)
		{
			return true;
		}
	}
	return false;
}

void UserDataInit()//�û����������Ӧ��Ϣ�ĳ�ʼ��
{
	InputUserName(0, "jxl");
	InputUserPassword(0, "838ddf2b74575f929e247c8f81a14ed7");//MD5(jxl)

	InputUserName(1, "JXL");
	InputUserPassword(1, "c86979304ea7a8b0b96f90e8ffc493d3");//MD5(JXL)

	InputUserName(2, "jiaxianglong");
	InputUserPassword(2, "40c49aac32bdf4cf8b6ebe7081552b99");//MD5(jiaxianglong)

	InputUserName(3, "JIAXIANGLONG");
	InputUserPassword(3, "05e0f6724b545dbb1c3eec278995dde4");//MD5(JIAXIANGLONG)
}

void UserPasswordInit(char x[17],const char y[33])//��Ϣ��ʼ���������ַ�����ʮ�����Ƶ�ת����Ϊ����MD5��������Ľ���洢��ʽһ��
{
	char high;//userdata[j].UserPassword[i]�ж�Ӧ�ĸ�4λ
	char low;//userdata[j].UserPassword[i]�ж�Ӧ�ĵ�4λ
	for (int i = 0; i < 16; i++)
	{
		//�ֱ𽫸ߵ�λ��ASC2��ʽ���ַ�����������ȡ
		high = y[2*i];
		low = y[2*i+1];

		//�ֱ�Ըߵ�λ����ASC2������ʮ����������ת��
		high = ASC2_TO_HEXNUM(high);
		low = ASC2_TO_HEXNUM(low);

		x[i] = (high << 4) | low;//����4λ���4λ�ϲ���Ϊ1��char�ͱ�����ֵ����ֵ��x[i]
	}

	x[16] = '\0';//�����βд��'\0'������
}

char ASC2_TO_HEXNUM(char x)//��ASC2�����0~9��a~f��A~F���ַ���ת���ɶ�Ӧ��ʮ��������
{
	if (x >= '0' && x <= '9')
	{
		x = x - '0';
	}
	else if (x >= 'a' && x <= 'f')
	{
		x = x - 'a' + 10;
	}
	else if (x >= 'A' && x <= 'F')
	{
		x = x - 'A' + 10;
	}
	else
	{
		return -1;//֮ǰ�洢������MD5ɢ�������ֵ����
	}
	return x;
}
