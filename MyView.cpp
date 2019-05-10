// MyView.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgAddView.h"
#include "MyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CView)
END_MESSAGE_MAP()


// CMyView 绘图

void CMyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	
	pDC->MoveTo(0,50);
	pDC->LineTo(200,200);

	CRect rt(0,50,200,200);
	pDC->DrawText(_T("00这是在对话框上创建的视图"),&rt,DT_LEFT);

}


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyView 消息处理程序
