#pragma once

#ifndef LOGIN_H
#define LOGIN_H

#include "md5.h"
#include "string.h"

#define NUM 4//�û����������ƥ������Ŀ

//Ϊ�˳�ʼ���û��������뷽�����õĺ궨��
#define InputUserName(NUMBER, NAME) strcpy_s(userdata[NUMBER].UserName, NAME)
#define InputUserPassword(NUMBER, PASSWORD) UserPasswordInit(userdata[NUMBER].UserPassword, (const char*)(PASSWORD))

class UserData//�洢��Ӧ���û���������
{
public:
	char UserName[200];
	char UserPassword[17];
};

bool UserCheck(const char UserName[], const char UserPassword[]);//����û����������Ƿ�ƥ��

void UserDataInit();//�û����������Ӧ��Ϣ�ĳ�ʼ��

void UserPasswordInit(char x[17], const char y[33]);//��Ϣ��ʼ���������ַ�����ʮ�����Ƶ�ת����Ϊ����MD5��������Ľ���洢��ʽһ��

char ASC2_TO_HEXNUM(char x);//��ASC2�����0~9��a~f��A~F���ַ���ת���ɶ�Ӧ��ʮ��������

#endif
