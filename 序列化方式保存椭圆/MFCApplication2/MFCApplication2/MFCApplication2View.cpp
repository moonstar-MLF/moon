
// MFCApplication2View.cpp : CMFCApplication2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApplication2View ����/����

CMFCApplication2View::CMFCApplication2View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View ����

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int n = pDoc->ca.GetCount();
	for (int i = 0; i < n; i++)
	{
		pDC->Ellipse(pDoc->ca[i]);
	}
	pDC->Ellipse(cr);
}


// CMFCApplication2View ���

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View ��Ϣ�������


void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication2Doc* pDoc = GetDocument();
	flag = 1;
	originpoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��
	CMFCApplication2Doc* pDoc = GetDocument();
	flag = 0;
	pDoc->ca.Add(cr);
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCApplication2Doc* pDoc = GetDocument();
	if (flag == 1)
	{
		cr.right = point.x;
		cr.bottom = point.y;
		cr.left = originpoint.x;
		cr.top = originpoint.y;
		
		InvalidateRect(&cr);
	}
	
	CView::OnMouseMove(nFlags, point);
}
