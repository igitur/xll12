// register.cpp - funcdname mangling
#include "../xll/xll.h"

using namespace xll;
Auto<Open> xao_foo2_([]{
	return Register(Args(XLL_DOUBLE, L"?foo2", L"FOO2_").Arg(XLL_DOUBLE, L"Num")).isNum();
	// #VALUE! since FOO2 is the name of a cell
	//	Excelv(xlfRegister, Args(XLL_DOUBLE, L"?foo2", L"FOO2").Arg(XLL_DOUBLE, L"Num"));
});
double WINAPI foo2(double x)
{
#pragma XLLEXPORT

	return 2*x;
}
/*
AddIn xai_foo3(
Function(XLL_DOUBLE, L"?foo3", L"FOO3_")
	.Arg(XLL_DOUBLE, L"Num")
	.Category(L"MyCategory")
	.FunctionHelp(L"Call foo3")
);
double WINAPI foo3(double x)
{
#pragma XLLEXPORT

	return 3*x;
}
*/


Auto<Open> xao_alert([]() { return Register(Args(L"?xll_alert", L"XLL.ALERT")).isNum();});
int WINAPI xll_alert()
{
#pragma XLLEXPORT

	OPER12 o;
	o = XLC(Alert, OPER12(L"Hi"));
	
	return 1;
}
//On<Doubleclick> xlodc(0, L"XLL.ALERT");

XCHAR* funcdname[64];

#define L_(x) L ## x

//#define FOO Auto<Open> xao_foo ## __COUNTER__ ([](){Excelv(xlfRegister,Arguments(L"?foo"
#if 0
template<class T>
struct xll_traits {
	static const XCHAR* type();
};
template<>
struct xll_traits<double> {
	static const XCHAR* type() { return XLL_DOUBLE; }
};

Auto<Open> xao_foo([]() { return Excelv(xlfRegister, Args(XLL_BOOL, L"?xll_foo", L"XLL.FOO")).xltype == xltypeNum; });
BOOL WINAPI xll_foo()
{
#pragma XLLEXPORT
	return TRUE;
}

Auto<Open> xao_foo1([]() { return Excelv(xlfRegister, Args(XLL_BOOL, L"?xll_foo1", L"XLL.FOO1")
	.Arg(xll_traits<double>::type(), L""))
	.xltype == xltypeNum; });
BOOL WINAPI xll_foo1(double)
{
#pragma XLLEXPORT
	return TRUE;
}


Auto<Open> xao_foo2([]() { 
	return Excelv(xlfRegister, Arguments(L"?xll_foo2", XLL_BOOL XLL_DOUBLE XLL_DOUBLE, L"XLL.FOO2"))
	.xltype == xltypeNum; });
BOOL WINAPI xll_foo2(double,double)
{
#pragma XLLEXPORT
	return TRUE;
}
#endif