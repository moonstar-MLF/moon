
// MFCApplication1Doc.h : CMFCApplication1Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication1Set.h"


class CMFCApplication1Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication1Doc();
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// ����
public:
	CMFCApplication1Set m_MFCApplication1Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
