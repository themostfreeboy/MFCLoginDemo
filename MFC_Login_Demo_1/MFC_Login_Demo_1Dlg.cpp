
// MFC_Login_Demo_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Login_Demo_1.h"
#include "MFC_Login_Demo_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_Login_Demo_1Dlg �Ի���




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


// CMFC_Login_Demo_1Dlg ��Ϣ�������

BOOL CMFC_Login_Demo_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_Login_Demo_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_Login_Demo_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Login_Demo_1Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CMFC_Login_Demo_1Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void CMFC_Login_Demo_1Dlg::OnBnClickedBlogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bool state=UserCheck(MyCStringToConstChar(edit_username),MyCStringToConstChar(edit_userpassword));
	if(state==true)//��¼�ɹ�
	{
		SetDlgItemText(IDC_SSTATE,_T("��¼�ɹ�"));
		//static_state="��¼�ɹ�";
		//UpdateData(FALSE);
		AfxMessageBox(_T("��¼�ɹ�"),MB_OK,NULL);
	}
	else if(state==false)//��¼ʧ��
	{
		SetDlgItemText(IDC_SSTATE,_T("��¼ʧ��"));
		//static_state="��¼ʧ��";
		//UpdateData(FALSE);
		SetDlgItemText(IDC_EUSERNAME,_T(""));
		SetDlgItemText(IDC_EUSERPASSWORD,_T(""));
		AfxMessageBox(_T("��¼ʧ��"),MB_OK,NULL);
	}
}


void CMFC_Login_Demo_1Dlg::OnEnChangeEusername()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}


void CMFC_Login_Demo_1Dlg::OnEnChangeEuserpassword()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}
