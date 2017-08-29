
// pracView.cpp : CpracView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "prac.h"
#endif

#include "pracDoc.h"
#include "pracView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpracView

IMPLEMENT_DYNCREATE(CpracView, CView)

BEGIN_MESSAGE_MAP(CpracView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CpracView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CpracView 构造/析构

CpracView::CpracView()
{
	// TODO: 在此处添加构造代码

}

CpracView::~CpracView()
{
}

BOOL CpracView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CpracView 绘制

void CpracView::OnDraw(CDC* pDC)
{
	pDC->TextOut(0, 0, _T("hello world!"));
	CpracDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CpracView 打印


void CpracView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CpracView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CpracView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CpracView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CpracView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CpracView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CpracView 诊断

#ifdef _DEBUG
void CpracView::AssertValid() const
{
	CView::AssertValid();
}

void CpracView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpracDoc* CpracView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpracDoc)));
	return (CpracDoc*)m_pDocument;
}
#endif //_DEBUG


// CpracView 消息处理程序
