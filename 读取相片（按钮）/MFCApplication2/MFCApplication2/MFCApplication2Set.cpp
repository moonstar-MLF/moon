
// MFCApplication2Set.cpp : CMFCApplication2Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2Set ʵ��

// ���������� 2020��7��10��, 14:00

IMPLEMENT_DYNAMIC(CMFCApplication2Set, CRecordset)

CMFCApplication2Set::CMFCApplication2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_6 = L"";
	m_7 = L"";
	m_8 = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication2Set::GetDefaultConnect()
{
	return _T("DSN=\x5b8c\x6574\x6570\x636e\x5e93;DBQ=E:\\\x90a3\x4e9b\x4e0a\x7f51\x8bfe\x7684\x75db\x82e6\x65e5\x5b50\\Visual C++\\moon.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication2Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMFCApplication2Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);
	RFX_Text(pFX, _T("[�ֶ�6]"), m_6);
	RFX_Text(pFX, _T("[�ֶ�7]"), m_7);
	RFX_Text(pFX, _T("[�ֶ�8]"), m_8);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication2Set ���

#ifdef _DEBUG
void CMFCApplication2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

