
// MFC_Login_Demo_1Dlg.h : ͷ�ļ�
//

#pragma once


// CMFC_Login_Demo_1Dlg �Ի���
class CMFC_Login_Demo_1Dlg : public CDialogEx
{
// ����
public:
	CMFC_Login_Demo_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_LOGIN_DEMO_1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();//���ȷ�����Ĵ�����
	afx_msg void OnBnClickedCancel();//���ȡ�����Ĵ�����
	CString edit_username;//������û���
	CString edit_userpassword;//���������
	CString static_state;//��¼�ɹ���ʧ�ܵ�״̬
	afx_msg void OnBnClickedBlogin();//�����¼���Ĵ�����
	afx_msg void OnEnChangeEusername();//�û����༭�����ݸı�ʱ�Ĵ�����
	afx_msg void OnEnChangeEuserpassword();//����༭�����ݸı�ʱ�Ĵ�����
};
