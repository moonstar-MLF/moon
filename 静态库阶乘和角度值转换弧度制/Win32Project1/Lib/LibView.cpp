
// LibView.cpp : CLibView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Lib.h"
#endif

#include "LibDoc.h"
#include "LibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "win32.h"
#include<iostream>
using namespace std;

// CLibView

IMPLEMENT_DYNCREATE(CLibView, CView)

BEGIN_MESSAGE_MAP(CLibView, CView)
END_MESSAGE_MAP()

// CLibView 构造/析构

CLibView::CLibView()
{
	// TODO: 在此处添加构造代码

}

CLibView::~CLibView()
{
}

BOOL CLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLibView 绘制

void CLibView::OnDraw(CDC* pDC)
{
	CLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int r;
	CString s,ss;
	r= factorial(5);
	s.Format(_T("%d"),r);
	pDC->TextOutW(200, 200, s);

	float c;
	FAC obj;
	c = obj.convert(30.0);
	ss.Format(_T("%f"), c);
	pDC->TextOutW(200, 250, ss);
}


// CLibView 诊断

#ifdef _DEBUG
void CLibView::AssertValid() const
{
	CView::AssertValid();
}

void CLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLibDoc* CLibView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibDoc)));
	return (CLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CLibView 消息处理程序
