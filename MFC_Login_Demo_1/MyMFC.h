#pragma once

#ifndef __MYMFC_H
#define __MYMFC_H

//���ھ�̬����ʹ��MFC�������Ӵ����ظ���������⣺��������->������->����->���������uafxcwd.lib��LIBCMTD.lib����������->������->����->�����ض�Ĭ�Ͽ⣺LIBCMTD.lib��uafxcwd.lib��msvcrt.lib��
#include <string>
//#include <atltime.h>//��̬����ʹ��MFC��ع���ʹ��
//#include <afx.h>//��̬����ʹ��MFC��ع���ʹ��
//#include <shlwapi.h>//PathIsDirectory����ʹ��
//#pragma comment(lib,"shlwapi.lib")//PathIsDirectory����ʹ��

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//����������

void MyCreatDirectory(std::string str);//�½��ļ���         e.g.:MyCreatDirectory("D:\\Boxing");
void MyCreatDirectory(CString cstr);//�½��ļ���
LPCTSTR MyCharToLPCTSTR(const char* szStrtemp);//char*תLPCTSTR
const char* MyCStringToConstChar(CString cstr);//CStringתconst char*
LPCTSTR MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
std::string MyCStringToString(CString cstr);//CStringתstring
CString MyStringToCString(std::string str);//stringתCString
double MyCStringToDouble(CString cstr);//CStringתdouble
const char* MyDoubleToChar(double dou);//doubleתchar*
CString MyGetTime(std::string str);//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
CString MyGetTime(CString cstr);//��ȡϵͳʱ��
char* MyGetFileName(const char* path_name);//��·���л�ȡ�ļ���
char* MyAddFileName(const char* path_name, const char* add_name);//���ļ�����׺ǰ�������ַ���
LPCWSTR MyWstringToLPCWSTR(std::wstring wstr);//wstringתLPCWSTR

#endif
