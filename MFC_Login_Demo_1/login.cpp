#include "login.h"
#include "stdafx.h"

UserData userdata[NUM];

bool UserCheck(const char UserName[], const char UserPassword[])//检测用户名与密码是否匹配
{
	unsigned char MD5Password[17];//用于存储将输入的密码进行MD5散列运算后的结果
	UserDataInit();//用户名与密码对应信息的初始化
	MD5Calc((unsigned char*)UserPassword, MD5Password, strlen(UserPassword));//将输入的密码进行MD5散列运算，将散列运算后的结果存储在MD5Password数组中
	MD5Password[16] = '\0';//数组结尾写入'\0'结束符
	for (int i = 0; i < NUM; i++)//比较输入密码经过MD5散列运算后的值与之前存储的值，与对应的用户名是否匹配
	{
		if (strcmp(UserName, userdata[i].UserName) == 0 && strcmp((const char*)MD5Password, userdata[i].UserPassword) == 0)
		{
			return true;
		}
	}
	return false;
}

void UserDataInit()//用户名与密码对应信息的初始化
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

void UserPasswordInit(char x[17],const char y[33])//信息初始化中密码字符串向十六进制的转化，为了与MD5函数算出的结果存储形式一致
{
	char high;//userdata[j].UserPassword[i]中对应的高4位
	char low;//userdata[j].UserPassword[i]中对应的低4位
	for (int i = 0; i < 16; i++)
	{
		//分别将高低位的ASC2形式的字符串型数据提取
		high = y[2*i];
		low = y[2*i+1];

		//分别对高低位进行ASC2编码向十六进制数的转换
		high = ASC2_TO_HEXNUM(high);
		low = ASC2_TO_HEXNUM(low);

		x[i] = (high << 4) | low;//将高4位与低4位合并成为1个char型变量的值并赋值给x[i]
	}

	x[16] = '\0';//数组结尾写入'\0'结束符
}

char ASC2_TO_HEXNUM(char x)//将ASC2编码的0~9和a~f和A~F的字符串转化成对应的十六进制数
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
		return -1;//之前存储的密码MD5散列运算的值出错
	}
	return x;
}
