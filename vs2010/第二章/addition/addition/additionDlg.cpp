
// additionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "addition.h"
#include "additionDlg.h"
#include "afxdialogex.h"
#include "AddSheet.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CadditionDlg �Ի���




CadditionDlg::CadditionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CadditionDlg::IDD, pParent)
	, m_editSunnand(0)
	, m_editAddend(0)
	, m_editsum(0)
	, m_pTipDlg(NULL)
	
	
{	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


}

void CadditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//����MFCĬ�ϵ����ݽ���
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSunnand);
	//����ؼ�IDC_SUMMAND_EDIT�ͱ���m_editSummand֮������ݽ���
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	// ����ؼ�IDC_ADDEND_EDIT�ͱ���m_editAddend֮������ݽ���
	DDX_Text(pDX, IDC_SUM_EDIT, m_editsum);
	// ����ؼ�IDC_SUM_EDIT�ͱ���m_editSum֮������ݽ��� 
}

BEGIN_MESSAGE_MAP(CadditionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CadditionDlg::OnClickedAddButton)
	ON_BN_CLICKED(IDC_INSTRUCT_BUTTON, &CadditionDlg::OnBnClickedInstructButton)
END_MESSAGE_MAP()


// CadditionDlg ��Ϣ�������

BOOL CadditionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CadditionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CadditionDlg::OnPaint()
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
HCURSOR CadditionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CadditionDlg::OnClickedAddButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�����ؼ��е����ݱ��浽��Ӧ�ı���
	INT_PTR nRes;        //���ڱ���DoModal�����ķ���ֵ

	//CTipDlg tipDlg;      //����Ի�����CTipDlg��ʵ��
	nRes = MessageBox(_T("��ȷ��Ҫ���мӷ�������"),_T("�ٷ�������"),MB_OKCANCEL | MB_ICONQUESTION);
	//tipDlg.DoModal();  //�����Ի���
	if (IDCANCEL == nRes)     //�ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL,�������return,�����������ִ��
		return;
		
	//�����ؼ��е����ݱ��浽��Ӧ�ı���
	/*if (NULL == m_pTipDlg)
	{
		//������ģ̬�Ի���ʵ��
		m_pTipDlg = new CTipDlg();
	    m_pTipDlg->Create(IDD_TIP_DIALOG, this);
	}
	//������ģ̬�Ի���
	m_pTipDlg->ShowWindow(SW_SHOW);
	*/

	UpdateData(TRUE);

	//���������ͼ����ļӺ͸�ֵ��m_editsum
	m_editsum = m_editSunnand + m_editAddend;

	//���ݸ�������ֵ������Ӧ�Ŀؼ����͵ı༭�����ʾm_editSum��ֵ
	UpdateData(FALSE);

}
CadditionDlg::~CadditionDlg()   
{   
    // �����ģ̬�Ի����Ѿ�������ɾ����   
    if (NULL != m_pTipDlg)   
    {   
        // ɾ����ģ̬�Ի������   
        delete m_pTipDlg;   
   }   
}  


void CadditionDlg::OnBnClickedInstructButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�������Ա����
	CAddSheet sheet(_T("ʹ��˵��"));
	//�������ԶԻ���Ϊ�뵽�Ի���
	sheet.DoModal();
}
