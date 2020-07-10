
// MFCApplication1Set.cpp : CMFCApplication1Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Set ʵ��

// ���������� 2020��7��10��, 11:12

IMPLEMENT_DYNAMIC(CMFCApplication1Set, CRecordset)

CMFCApplication1Set::CMFCApplication1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_6 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication1Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x56fe\x7247;DBQ=E:\\\x90a3\x4e9b\x4e0a\x7f51\x8bfe\x7684\x75db\x82e6\x65e5\x5b50\\Visual C++\\\x7efc\x5408\x5b9e\x9a8c\x4e00\\moon.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication1Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMFCApplication1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�6]"), m_6);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication1Set ���

#ifdef _DEBUG
void CMFCApplication1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

