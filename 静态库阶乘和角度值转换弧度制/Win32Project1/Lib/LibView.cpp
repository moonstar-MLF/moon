
// LibView.cpp : CLibView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CLibView ����/����

CLibView::CLibView()
{
	// TODO: �ڴ˴���ӹ������

}

CLibView::~CLibView()
{
}

BOOL CLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLibView ����

void CLibView::OnDraw(CDC* pDC)
{
	CLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CLibView ���

#ifdef _DEBUG
void CLibView::AssertValid() const
{
	CView::AssertValid();
}

void CLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLibDoc* CLibView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLibDoc)));
	return (CLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CLibView ��Ϣ�������
