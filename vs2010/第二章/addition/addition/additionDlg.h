
// additionDlg.h : ͷ�ļ�
//
#include "TipDlg.h"
#pragma once


// CadditionDlg �Ի���
class CadditionDlg : public CDialogEx
{
// ����
public:
	CadditionDlg(CWnd* pParent = NULL);	~CadditionDlg();// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ADDITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	double m_editSunnand;
	double m_editAddend;
	double m_editsum;
	afx_msg void OnClickedAddButton();



private:
//	int TipDlg m_pTipDlg;
//	CTipDlg *m_pTipDlg;
	CTipDlg *m_pTipDlg;
public:
	afx_msg void OnBnClickedInstructButton();
};
