
// MFCApplication1Set.cpp : CMFCApplication1Set 类的实现
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Set 实现

// 代码生成在 2020年7月10日, 14:41

IMPLEMENT_DYNAMIC(CMFCApplication1Set, CRecordset)

CMFCApplication1Set::CMFCApplication1Set(CDatabase* pdb)
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
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCApplication1Set::GetDefaultConnect()
{
	return _T("DSN=\x5b8c\x6574\x6570\x636e\x5e93;DBQ=E:\\\x90a3\x4e9b\x4e0a\x7f51\x8bfe\x7684\x75db\x82e6\x65e5\x5b50\\Visual C++\\moon.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication1Set::GetDefaultSQL()
{
	return _T("[学生信息表]");
}

void CMFCApplication1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);
	RFX_Text(pFX, _T("[字段2]"), m_2);
	RFX_Text(pFX, _T("[字段3]"), m_3);
	RFX_Text(pFX, _T("[字段4]"), m_4);
	RFX_Text(pFX, _T("[字段5]"), m_5);
	RFX_Text(pFX, _T("[字段6]"), m_6);
	RFX_Text(pFX, _T("[字段7]"), m_7);
	RFX_Text(pFX, _T("[字段8]"), m_8);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication1Set 诊断

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

