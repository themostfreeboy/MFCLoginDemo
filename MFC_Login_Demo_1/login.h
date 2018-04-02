#pragma once

#ifndef LOGIN_H
#define LOGIN_H

#include "md5.h"
#include "string.h"

#define NUM 4//用户名和密码的匹配总数目

//为了初始化用户名和密码方便所用的宏定义
#define InputUserName(NUMBER, NAME) strcpy_s(userdata[NUMBER].UserName, NAME)
#define InputUserPassword(NUMBER, PASSWORD) UserPasswordInit(userdata[NUMBER].UserPassword, (const char*)(PASSWORD))

class UserData//存储对应的用户名和密码
{
public:
	char UserName[200];
	char UserPassword[17];
};

bool UserCheck(const char UserName[], const char UserPassword[]);//检测用户名与密码是否匹配

void UserDataInit();//用户名与密码对应信息的初始化

void UserPasswordInit(char x[17], const char y[33]);//信息初始化中密码字符串向十六进制的转化，为了与MD5函数算出的结果存储形式一致

char ASC2_TO_HEXNUM(char x);//将ASC2编码的0~9和a~f和A~F的字符串转化成对应的十六进制数

#endif
