
// MFC_Login_Demo_1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login_Demo_1.h"
#include "MFC_Login_Demo_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_Login_Demo_1Dlg 对话框




CMFC_Login_Demo_1Dlg::CMFC_Login_Demo_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_Login_Demo_1Dlg::IDD, pParent)
	, edit_username(_T(""))
	, edit_userpassword(_T(""))
	, static_state(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Login_Demo_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EUSERNAME, edit_username);
	DDV_MaxChars(pDX, edit_username, 100);
	DDX_Text(pDX, IDC_EUSERPASSWORD, edit_userpassword);
	DDX_Text(pDX, IDC_SSTATE, static_state);
	DDV_MaxChars(pDX, static_state, 100);
}

BEGIN_MESSAGE_MAP(CMFC_Login_Demo_1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC_Login_Demo_1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFC_Login_Demo_1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BLOGIN, &CMFC_Login_Demo_1Dlg::OnBnClickedBlogin)
	ON_EN_CHANGE(IDC_EUSERNAME, &CMFC_Login_Demo_1Dlg::OnEnChangeEusername)
	ON_EN_CHANGE(IDC_EUSERPASSWORD, &CMFC_Login_Demo_1Dlg::OnEnChangeEuserpassword)
END_MESSAGE_MAP()


// CMFC_Login_Demo_1Dlg 消息处理程序

BOOL CMFC_Login_Demo_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_Login_Demo_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_Login_Demo_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Login_Demo_1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	exit(0);
}


void CMFC_Login_Demo_1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}


void CMFC_Login_Demo_1Dlg::OnBnClickedBlogin()
{
	// TODO: 在此添加控件通知处理程序代码
	bool state=UserCheck(MyCStringToConstChar(edit_username),MyCStringToConstChar(edit_userpassword));
	if(state==true)//登录成功
	{
		SetDlgItemText(IDC_SSTATE,_T("登录成功"));
		//static_state="登录成功";
		//UpdateData(FALSE);
		AfxMessageBox(_T("登录成功"),MB_OK,NULL);
	}
	else if(state==false)//登录失败
	{
		SetDlgItemText(IDC_SSTATE,_T("登录失败"));
		//static_state="登录失败";
		//UpdateData(FALSE);
		SetDlgItemText(IDC_EUSERNAME,_T(""));
		SetDlgItemText(IDC_EUSERPASSWORD,_T(""));
		AfxMessageBox(_T("登录失败"),MB_OK,NULL);
	}
}


void CMFC_Login_Demo_1Dlg::OnEnChangeEusername()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


void CMFC_Login_Demo_1Dlg::OnEnChangeEuserpassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}
