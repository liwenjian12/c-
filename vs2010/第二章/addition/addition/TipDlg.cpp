// TipDig.cpp : 实现文件
//

#include "stdafx.h"
#include "addition.h"
#include "TipDlg.h"
#include "afxdialogex.h"


// CTipDig 对话框

IMPLEMENT_DYNAMIC(CTipDlg, CDialogEx)

CTipDlg::CTipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTipDlg::IDD, pParent)
{

}

CTipDlg::~CTipDlg()
{
}

void CTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipDlg, CDialogEx)
END_MESSAGE_MAP()


// CTipDlg 消息处理程序
