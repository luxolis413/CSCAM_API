#pragma once

#include "extern.h"
#include "HXApi_Extern.h"
#include "HXApi_ExternAxis.h"

#if 0

// STR
#define	HX_STR_AXIS         121
#define	HX_STR_MACHINE      122
#define	HX_STR_SEQPROG      123
#define	HX_STR_ERRPROG      124
#define	HX_STR_NCPATH       125
#define	HX_STR_MAINPROG     126
#define	HX_STR_SUBPROG      127
#define	HX_STR_MDIPROG      128

#define	HX_DEVICE           129

#define	HX_STR_SYSPATH      130
#define	HX_STR_ALARMMSG     131
#define	HX_STR_OPMSG        132
#define	HX_STR_DATAPATH     133
#define	HX_STR_PLCFILE      134
#define	HX_STR_MAPFILE      135
#define	HX_STR_LANGUAGE     136
#endif

// define ����
#define PSADDR(_axis, _addr) ((_axis * MAP_MAX_PS) + _addr)


enum {HX_ETHERNET = 0, HX_RTX};
enum {HX_FAIL = 0, HX_SUCCESS = 1, HX_NONE = -1};
enum {HX_OFF = 0, HX_ON };
enum { eCW = 0, eCCW };

#define HX_SIGNALSLEEP	200

#ifdef __cplusplus
extern "C"{
#endif
	// �⺻ API ---------------------------------------------------------------------------------

	// �ʱ�ȭ, comtype : HX_ETHERNET/HX_RTX
	HXAPI_API long HXInitialize(long comtype, long ip1, long ip2, long ip3, long ip4, long port);
	
	// ����
	HXAPI_API void HXTerminate();

	// ���� ���� Ȯ��
	HXAPI_API long HXConnectState();

	HXAPI_API long HXGetRegister32(long name, long addr);
	HXAPI_API void HXSetRegister32(long name, long addr, long value);
	HXAPI_API double HXGetRegister64(long name, long addr);
	HXAPI_API void HXSetRegister64(long name, long addr, double value);
	HXAPI_API long HXGetBit(long name, long addr, long bitno);
	HXAPI_API void HXSetBit(long name, long addr, long bitno, long value);

	HXAPI_API void HXGetRegister32B(long count, long name[], long addr[], long* result);
	HXAPI_API void HXSetRegister32B(long count, long name[], long addr[], long value[]);
	HXAPI_API void HXGetRegister64B(long count, long name[], long addr[], double* result);
	HXAPI_API void HXSetRegister64B(long count, long name[], long addr[], double value[]);
	HXAPI_API void HXGetBitB(long count, long name[], long addr[], long bitno[], long* result);
	HXAPI_API void HXSetBitB(long count, long name[], long addr[], long bitno[], long value[]);

	HXAPI_API void HXGetString(int nName, char caStrVal[]);
	HXAPI_API void HXSetString(int nName, char caStrVal[]);
	// -------------------------------------------------------------------------------------------



	//----------------------------------------------// sjlee 20170717
	// Nc List
	HXAPI_API bool HXFtpConnect(char *ip);
	HXAPI_API int HXChangeDirNc();
	HXAPI_API int HXChangeDirMacro();
	HXAPI_API int HXChangeDir(char *path);
	HXAPI_API void HXGetNcIndex(int index, char *name);
	
	HXAPI_API void HXSetMainProgram(char *name);
	HXAPI_API void HXSetSubProgram(char *name);
	HXAPI_API void HXGetSystemPath(char *path);
	
	//----------------------------------------------// sjlee 20170717
	HXAPI_API void HXDownloadFile(const char* dir, const char* target, const char* name);
	HXAPI_API void HXUploadFile(const char* dir, const char* target, const char* name);
	HXAPI_API void HXDeleteFile(const char* name);

	HXAPI_API bool HXGetNcFileStr(int index, char* str);
	HXAPI_API int HXGetNcFileCount();
	


	// 2019-11-15 sisong
	
	HXAPI_API void HXSetNcPath(char *path);
	HXAPI_API void HXGetNcPath(char *path);





	// ���� ���� API ---------------------------------------------------------------------------------

	// �ʱ�ȭ, comtype : HX_ETHERNET/HX_RTX
	HXAPI_API long XHXInitialize(int ncid, long comtype, long ip1, long ip2, long ip3, long ip4, long port);

	// ����
	HXAPI_API void XHXTerminate(int ncid);

	// ���� ���� Ȯ��
	HXAPI_API long XHXConnectState(int ncid);

	HXAPI_API long XHXGetRegister32(int ncid, long name, long addr);
	HXAPI_API void XHXSetRegister32(int ncid, long name, long addr, long value);
	HXAPI_API double XHXGetRegister64(int ncid, long name, long addr);
	HXAPI_API void XHXSetRegister64(int ncid, long name, long addr, double value);
	HXAPI_API long XHXGetBit(int ncid, long name, long addr, long bitno);
	HXAPI_API void XHXSetBit(int ncid, long name, long addr, long bitno, long value);

	HXAPI_API void XHXGetRegister32B(int ncid, long count, long name[], long addr[], long* result);
	HXAPI_API void XHXSetRegister32B(int ncid, long count, long name[], long addr[], long value[]);
	HXAPI_API void XHXGetRegister64B(int ncid, long count, long name[], long addr[], double* result);
	HXAPI_API void XHXSetRegister64B(int ncid, long count, long name[], long addr[], double value[]);
	HXAPI_API void XHXGetBitB(int ncid, long count, long name[], long addr[], long bitno[], long* result);
	HXAPI_API void XHXSetBitB(int ncid, long count, long name[], long addr[], long bitno[], long value[]);

	HXAPI_API void XHXGetString(int ncid, int nName, char caStrVal[]);
	HXAPI_API void XHXSetString(int ncid, int nName, char caStrVal[]);

	HXAPI_API bool XHXAddUpdateMap(int ncid, long count, long name[], long ch[], long addr[]);
	HXAPI_API bool XHXRemoveUpdateMap(int ncid, long count, long name[], long ch[], long addr[]);
	// -------------------------------------------------------------------------------------------

	//----------------------------------------------// sjlee 20170717
	// Nc List
	HXAPI_API bool XHXFtpConnect(int ncid, char *ip);
	HXAPI_API int XHXChangeDirNc(int ncid);
	HXAPI_API int XHXChangeDirMacro(int ncid);
	HXAPI_API int XHXChangeDir(int ncid, char *path);
	HXAPI_API void XHXGetNcIndex(int ncid, int index, char *name);
	HXAPI_API void XHXSetMainProgram(int ncid, char *name);
	HXAPI_API void XHXSetSubProgram(int ncid, char *name);
	HXAPI_API void XHXGetSystemPath(int ncid, char *path);
	
	//----------------------------------------------// sjlee 20170717
	HXAPI_API void XHXDownloadFile(int ncid, const char* dir, const char* target, const char* name);
	HXAPI_API void XHXUploadFile(int ncid, const char* dir, const char* target, const char* name);
	HXAPI_API void XHXDeleteFile(int ncid, const char* name);

	//----------------------------------------------// sjlee 20170717


	// Read me - �ݵ�� �ѹ� �а� �����ϼ���. ----------------------------------------------------
	// ���ʿ� �ִ� �⺻ API�� �������� ������.
	// �Լ��� ���� �տ��� "HX"�� �ٿ��ּ���.
	// �ܾ���� ��/�ҹ��ڷ� �ϰ�, '_'(�����)�� ������� ������.
	// Ÿ���� �����Ҷ��� �ݵ�� enum�� ����ϼ���.
	// -> ���ڴ� �������, #define ���ٴ� enum����.
	// �ǹ̾��� �̸����� �Լ� ���� ������ ������.
	// �Լ�1(), �Լ�2()��.. �ǹ̸� �� �� ���� 1, 2�Ǵ� ���ڸ� �������������.
	// �� �������������. ��� �� �ʿ��ϴٸ� ����� �ǹ̸� �ּ����� ǥ�����ּ���.
	// ��, ��� �Ķ���ͷδ� long,double�� ����ϼ���. VB�� �����Ϸ��� �ݵ�� ���Ѿ��մϴ�.
	// -------------------------------------------------------------------------------------------

	// �� �Ķ���� 
	HXAPI_API long HXSetAxisParameter(U32 nAxis, U32 addr, F64 value);
	HXAPI_API double HXGetAxisParameter(U32 nAxis, U32 addr);

	// ���� �Ķ���� 
	HXAPI_API long HXSetProcessingParameter(U32 nParam, F64 dVal);	//HXMachining::
	HXAPI_API double HXGetProcessingParameter(U32 nParam);

	// �ý��� �Ķ���� 
	HXAPI_API long HXSetSystemParameter(U32 nParam, F64 dVal);
	HXAPI_API double HXGetSystemParameter(U32 nParam);

	// IO �Ķ���� 
	HXAPI_API long HXSetIOParameter(U32 nParam, F64 dVal);
	HXAPI_API double HXGetIOParameter(U32 nParam);

	// ����͸� �Ķ���� 
	HXAPI_API double HXGetStateParameter(U32 nParam);
	HXAPI_API double HXGetInfoParameter(U32 nParam);

	// NC 
	// ���α׷� �Ķ���� : ���� �� ���� 
	HXAPI_API long		HXSetProgramParameter(U32 nParam, F64 dVal);
	HXAPI_API double	HXGetProgramParameter(U32 nParam);

	// ����� �Ķ���� : ���� �� ���� 
	HXAPI_API long		HXSetUserParameter(U32 nParam, F64 dVal);
	HXAPI_API double	HXGetUserParameter(U32 nParam);

	// ��ũ�� �Ķ���� : ���� �� ���� 
	HXAPI_API long		HXSetMacroParameter(U32 nParam, F64 dVal);
	HXAPI_API double	HXGetMacroParameter(U32 nParam);

	// HMI �Ķ���� : ���� �� ���� 
	HXAPI_API long		HXSetHMIParameter(U32 nParam, F64 dVal);
	HXAPI_API double	HXGetHMIParameter(U32 nParam);

	// GF �� API 
	// 0: low, 1: high, -1: read fail

	
	// No.1 : �غ�Ϸ�			// enum HXGF_Ready
	HXAPI_API long HXGFReadySate(U32 nMode, U32 nAxis = -1);	

	// No.2 :NC ��� ����(�⺻)	// enum HXGF_ncmode
	HXAPI_API long HXSetMode(U32 nMode);
	HXAPI_API long HXGetMode();	

	// No.3 : NC ��� ����(����)	// enum HXGF_NCmodeSub
	HXAPI_API long HXSetNCSUbMode(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetNCSUbMode(U32 nMode, U32 nIndex = -1);

	// No.4 : ���� �������		//enum HXGF_Reset
	HXAPI_API long HXSetReset(U32 nMode, U32 nON); 
	HXAPI_API long HXGetReset(U32 nMode);

	// No.5 : NC ���� ��ȣ		// enum HXGF_NCRun
	HXAPI_API long HXSetNCRun(U32 nMode, U32 nON); 
	HXAPI_API long HXGetNCRun(U32 nMode);

	// NO.6 : NC ����			// enum HXGF_NCstate
	HXAPI_API long HXGetNCState(U32 nMode);

	// NO.7 : ���� ���� ���		// enum HXGF_ManualMode
	HXAPI_API long HXSetManualRunMode(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetManualRunMode(U32 nMode, U32 nIndex = -1);

	// NO.8 : ���� ���� ���		// enum HXGF_Home
	HXAPI_API long HXSetHomeMode(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetHomeMode(U32 nMode, U32 nIndex = -1);

	// NO.9 : �ܺ� ���� ��ȣ		// enum HXGF_ExternalSignal
	HXAPI_API long HXSetExternalSignal(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetExternalSignal(U32 nMode, U32 nIndex = -1);

	// NO.10 : �� ���� �׷�		// enum HXGF_AxisSetting
	HXAPI_API long HXSetMainAxis(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetMainAxis(U32 nMode, U32 nIndex = -1);

	// NO.11 : M���		// enum HXGF_M
	HXAPI_API long HXSetMFunction(U32 nMode, U32 nON);
	HXAPI_API long HXGetMFunction(U32 nMode, U32 nIndex = -1);

	// NO.12 : S���		// enum HXGF_Spindle
	HXAPI_API long HXSetSFunction(U32 nMode, U32 nON);
	HXAPI_API long HXGetSFunction(U32 nMode, U32 nIndex = -1);

	// NO.14 : T���		// enum HXGF_T
	HXAPI_API long HXSetTFunction(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetTFunction(U32 nMode, U32 nIndex = -1);

	// NO.15 : Chopping���		// enum HXGF_Chopping
	HXAPI_API long HXSetChopping(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetChopping(U32 nMode, U32 nIndex = -1);

	// NO.16 : NC ���� ����		// enum HXGF_NCInternal	
	HXAPI_API long HXGetNCInternalState(U32 nMode, U32 nIndex = -1);

	// NO.17 : ���� ����			// enum HXGF_SyncControl
	HXAPI_API long HXSetSyncControl(U32 nMode, U32 nON, U32 nIndex = -1);
	
	// NO.18 : Ŀ���� ��ũ�α��		// enum HXGF_CustomMacro
	HXAPI_API long HXSetCustomMacro(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetCustomMacro(U32 nMode, U32 nIndex = -1);
	
	// NO.19 : PLC �� ���� 		// enum HXGF_PLCAxis
	HXAPI_API long HXSetPLCAxis(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetPLCAxis(U32 nMode, U32 nIndex = -1);

	// NO.20 : Ư�� ���� 		// enum HXGF_AdvancedControl
	HXAPI_API long HXSetAdvancedControl(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetAdvancedControl(U32 nMode, U32 nIndex = -1);
	
	// NO.21 : ��ũ��/Key ���� 		// enum HXGF_SCreen
	HXAPI_API long HXSetScreen(U32 nMode, U32 nON, U32 nIndex = -1);
	HXAPI_API long HXGetScreen(U32 nMode, U32 nIndex = -1);
	
	// NO.22 : PLC �˶� 		// enum HXGF_PLCmessage
	HXAPI_API long HXSetPLCAlarm(U32 nMode, U32 nAddr, U32 nIndex, U32 nON);
	HXAPI_API long HXGetPLCAlarm(U32 nMode, U32 nAddr, U32 nIndex = 0);

	// NO.23 : Lettering ���� 		// enum HXGF_Lettering	
	HXAPI_API long HXGetLetteringState(U32 nMode);

	// NO.24 : �������� ���� 		// enum HXGF_ToolEndcontrol	
	HXAPI_API long HXGetG43Run();

	// NO.23 : C�� ���� ���� 		// enum HXGF_CPhase	
	HXAPI_API long HXGetCPhaseMeasure(U32 nMode, U32 nIndex );


	// Ȯ�� API ----------------------------------------------------------------------------------


	// ����/ ���� 
	// ���뿡 �̻��� ���� ��� ON 
	// ������ġ ���� �ΰ� ��, �ڱ� ������ �������� �Ϸ��� ��쿡 ON
	// CPU �̻� �Ǵ� �޸� �̻� �� ������ġ ��ü�� ���� ����� OFF
	HXAPI_API long HXGetReadyState();

	// ����/���ɵ� ���뿡 �̻��� ���� ��� ON
	HXAPI_API long HXGetSlaveReadyState();

	
	

	// ���� /��� ���� 
	HXAPI_API long HXGetStateReset();
	HXAPI_API long HXGetStateEMG();

	// ���� ���� ��� 
	// nDicrection 0: +, 1: - 
	// return : 1 : Moving, 0: stop 
	HXAPI_API long HXGetJogState(U32 nAxis, U32 &nDirection);
	
	// ���� ���� 
	// return ex : stateHome::HOME_RUNNING 
	// return -1 = state 
	HXAPI_API long HXGetHomeSate(U32 nAxis);

	// ���� ���� home bound üũ 
	// return : 0 : ���� ���� 
	HXAPI_API long HXCheckHomeLimit(U32 nAxis);

	//void HXMoveStart(long nAxis, double dDistance, double dFeed);	
	HXAPI_API long HXMoveStart(long nAxis, double dDistance, double dFeed);
	//void HXStop(long nAxis, double dFeed);

	// -------------------------------------------------------------------------------------------
	//----------------------------------------------

#ifdef __cplusplus
}
#endif

