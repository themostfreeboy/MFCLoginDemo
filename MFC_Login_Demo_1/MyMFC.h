#pragma once

#ifndef __MYMFC_H
#define __MYMFC_H

//如在静态库中使用MFC出现链接错误重复定义等问题：配置属性->链接器->输入->附加依赖项：uafxcwd.lib；LIBCMTD.lib；配置属性->链接器->输入->忽略特定默认库：LIBCMTD.lib；uafxcwd.lib；msvcrt.lib。
#include <string>
//#include <atltime.h>//动态库中使用MFC相关功能使用
//#include <afx.h>//静态库中使用MFC相关功能使用
//#include <shlwapi.h>//PathIsDirectory函数使用
//#pragma comment(lib,"shlwapi.lib")//PathIsDirectory函数使用

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//隐藏主窗口

void MyCreatDirectory(std::string str);//新建文件夹         e.g.:MyCreatDirectory("D:\\Boxing");
void MyCreatDirectory(CString cstr);//新建文件夹
LPCTSTR MyCharToLPCTSTR(const char* szStrtemp);//char*转LPCTSTR
const char* MyCStringToConstChar(CString cstr);//CString转const char*
LPCTSTR MyCStringToLPCTSTR(CString cstr);//CString转LPCTSTR
std::string MyCStringToString(CString cstr);//CString转string
CString MyStringToCString(std::string str);//string转CString
double MyCStringToDouble(CString cstr);//CString转double
const char* MyDoubleToChar(double dou);//double转char*
CString MyGetTime(std::string str);//获取系统时间       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
CString MyGetTime(CString cstr);//获取系统时间
char* MyGetFileName(const char* path_name);//从路径中获取文件名
char* MyAddFileName(const char* path_name, const char* add_name);//在文件名后缀前增加新字符串
LPCWSTR MyWstringToLPCWSTR(std::wstring wstr);//wstring转LPCWSTR

#endif
