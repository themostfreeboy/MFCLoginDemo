
// MFC_Login_Demo_1Dlg.h : 头文件
//

#pragma once


// CMFC_Login_Demo_1Dlg 对话框
class CMFC_Login_Demo_1Dlg : public CDialogEx
{
// 构造
public:
	CMFC_Login_Demo_1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_LOGIN_DEMO_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();//点击确定键的处理函数
	afx_msg void OnBnClickedCancel();//点击取消键的处理函数
	CString edit_username;//输入的用户名
	CString edit_userpassword;//输入的密码
	CString static_state;//登录成功或失败的状态
	afx_msg void OnBnClickedBlogin();//点击登录键的处理函数
	afx_msg void OnEnChangeEusername();//用户名编辑框内容改变时的处理函数
	afx_msg void OnEnChangeEuserpassword();//密码编辑框内容改变时的处理函数
};
