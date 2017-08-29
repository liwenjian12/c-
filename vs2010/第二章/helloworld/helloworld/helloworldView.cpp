
// helloworldView.cpp : implementation of the ChelloworldView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "helloworld.h"
#endif

#include "helloworldDoc.h"
#include "helloworldView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChelloworldView

IMPLEMENT_DYNCREATE(ChelloworldView, CView)

BEGIN_MESSAGE_MAP(ChelloworldView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ChelloworldView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChelloworldView construction/destruction

ChelloworldView::ChelloworldView()
{
	// TODO: add construction code here

}

ChelloworldView::~ChelloworldView()
{
}

BOOL ChelloworldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ChelloworldView drawing

void ChelloworldView::OnDraw(CDC* /*pDC*/)
{
	ChelloworldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// ChelloworldView printing


void ChelloworldView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ChelloworldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void ChelloworldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void ChelloworldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void ChelloworldView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ChelloworldView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ChelloworldView diagnostics

#ifdef _DEBUG
void ChelloworldView::AssertValid() const
{
	CView::AssertValid();
}

void ChelloworldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChelloworldDoc* ChelloworldView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChelloworldDoc)));
	return (ChelloworldDoc*)m_pDocument;
}
#endif //_DEBUG


// ChelloworldView message handlers
