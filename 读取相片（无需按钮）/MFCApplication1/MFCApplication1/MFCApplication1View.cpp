
// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Set.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication1View::OnRecordLast)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication1View::OnRecordNext)
END_MESSAGE_MAP()

// CMFCApplication1View ����/����

CMFCApplication1View::CMFCApplication1View()
	: CRecordView(IDD_MFCAPPLICATION1_FORM)
	, name(_T(""))
	, number(_T(""))
	, birthday(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, phoneNum(_T(""))
	, address(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCApplication1View::~CMFCApplication1View()
{
}

void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->m_6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->m_7);
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication1Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication1View ���

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View ���ݿ�֧��
CRecordset* CMFCApplication1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication1View ��Ϣ�������
void CMFCApplication1View::foo(CImage&img, int&sx, int&sy, int&w, int&h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}



void CMFCApplication1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	m_pSet->GetFieldValue(short(8), filename);
	CImage img;
	img.Load(filename);
	int sx, sy, w, h;
	if (!img.IsNull())
	{
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
		foo(img, sx, sy, w, h);//���в�ʧ����ʾ����
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}


void CMFCApplication1View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void CMFCApplication1View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);
}


void CMFCApplication1View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void CMFCApplication1View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);
}
