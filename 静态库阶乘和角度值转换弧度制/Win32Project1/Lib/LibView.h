
// LibView.h : CLibView ��Ľӿ�
//

#pragma once


class CLibView : public CView
{
protected: // �������л�����
	CLibView();
	DECLARE_DYNCREATE(CLibView)

// ����
public:
	CLibDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CLibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LibView.cpp �еĵ��԰汾
inline CLibDoc* CLibView::GetDocument() const
   { return reinterpret_cast<CLibDoc*>(m_pDocument); }
#endif

