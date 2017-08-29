
// additionDlg.h : 头文件
//
#include "TipDlg.h"
#pragma once


// CadditionDlg 对话框
class CadditionDlg : public CDialogEx
{
// 构造
public:
	CadditionDlg(CWnd* pParent = NULL);	~CadditionDlg();// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ADDITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
