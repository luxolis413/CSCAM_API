#pragma once

#include "extern.h"
#include "HXApi.h"


extern "C" {

	
	HXAPI_API long HXServoOn();			
	HXAPI_API long HXServoAlramReset();
	HXAPI_API long HXCycleStart();
	HXAPI_API long HXCycleStop();
	HXAPI_API long HXReset();
	HXAPI_API long HXEMG();
	HXAPI_API long HXEMGClear();
	HXAPI_API long HXPowerOff();

	// Jog �̼� 
	// ���� : JOG ��忡���� �۵� �մϴ�. 
	HXAPI_API long HXJOGMove(U32 nAxis, U32 nDirection = eCCW, U32 nMove = HX_ON);

	// ���� �̼� �ӵ� ���̺� (1~32)
	HXAPI_API long HXSetManualFeedIndex(U32 nIndex);

	// Rapid jog ( 0: Off, 1: On)
	HXAPI_API long HXSetRapidJog(U32 nOn);
	HXAPI_API long HXGetRapidJog();

	// Step �̼� �Ÿ� ���̺� (1~32)
	HXAPI_API long HXSetStepDistanceIndex(U32 nIndex);
	
	// MPG ���� (0: X1, 1: X10, 2: X100)
	HXAPI_API long HXMPGMultiplier(U32 nIndex);

	// �� 1MPG�� ���� ���� �̼� �� ���� 
	HXAPI_API long HXMPGAxis(U32 nIndex);

	// �� 1MPG interrup�� ���� ���� �̼� �� ���� 
	HXAPI_API long HXMPGInterruptAxis(U32 nIndex);

// �ܺ� ���� --------------------
	// Over Tavel 
	HXAPI_API long HXOverTravel(U32 nAxis, U32 nDirection = eCCW, U32 nMove = HX_ON);

	// interlock
	HXAPI_API long HXInterLock(U32 nAxis, U32 nDirection = eCCW, U32 nLock = HX_ON);

	// ��� �� interlock
	HXAPI_API long HXInterLockAll(U32 nDirection = eCCW, U32 nLock= HX_ON);

	// ���� �� close 
	HXAPI_API long HXSetServoClose(U32 nAxis, U32 nOk);

	// ���� �� servo off
	HXAPI_API long HXSetServoOff(U32 nAxis, U32 nOk);

	// ���� �� ���� ���� ���� Ȯ�� 
	HXAPI_API long HXGetServoReady(U32 nAxis);

	// �޼� �̼� override index ���� 
	HXAPI_API long HXSetRapidOverrideIndex(U32 nIndex);

	// �̼� feed index ���� 
	HXAPI_API long HXSetFeedOverrideIndex(U32 nIndex);

	//���ɵ� override index ���� 
	HXAPI_API long HXSetSpindleOverrideIndex(U32 nIndex);

	// ����Ʈ ����Ʈ OFF 
	HXAPI_API long HXOffSoftLimit(U32 nAxis, U32 nDirection = eCCW, U32 nLock = HX_ON);

	// �ܺ� ���� OFF
	HXAPI_API long HXOuternalDeccel(U32 nAxis, U32 nDirection = eCCW, U32 nLock = HX_ON);

// �� ���� �׷� 
	//HXAPI_API long HXSetMainSpindle(U32 nAxis);
	//HXAPI_API long HXGetMainSpindle();
	////HXAPI_API long HXSetZAxis(U32 nAxis);
	//HXAPI_API long HXGetZAxis();

// S �� ���ɵ� ��� 
	// ���� ���� ���ɵ� RPM 

	// Ʈ�� ���̺� �������� 
	// nMaster :  ������ �� 
	// nSlave :  �����̺� �� 
	// nType : 0: �Ϲ� ���� , 1: ������ �ܵ� ����, 2: �����̺� �ܵ� ����, 3: ���� ���� 
	HXAPI_API long HXTwinTable(U32 nMaster, U32 nSlave, U32 nType);
//-------------------------------------------

	//PLC�� �������� ������ ������� �˷���
	HXAPI_API long HXGetPLCRunSate();

	//CNC ���뿡 �̻��� ���� ��� ON
	//������ġ ���� �ΰ� ��, �ڱ������� �������� �Ϸ��� ��쿡 ON
	HXAPI_API long HXGetCNCRunSate();

	//����/���ɵ� ���뿡 �̻��� ���� ��� ON
	//EM-STOP, ���� OFF, ���� Alarm �� ��� 
	HXAPI_API long HXGetSubSystemRunSate();

	
	
	// PLC �� ------------------------------------------------------------------------------------
	// �ش� ���� PLC ������ �����ϰ� �ʱ�ȭ , �ʱ�ӵ� 100 
	HXAPI_API long HXMotionAxisInit(int nAxis); 

	// �� ���� ���� 
	HXAPI_API long HXMovingStart(U32 nAxis, F64 dDist, F64 dFeed );

	// �� ���� ���� 
	HXAPI_API long HXMovingStop(U32 nAxis);

	// �� ���� ��� 
	HXAPI_API long HXMoveCancel(U32 nAxis);

	
	// Homing 
	// dFeed : �������� �ӵ�
	// dDecel1st : 1�� ���� �ӵ� 
	// dDecel2nd : 2�� ���� �ӵ� 
	// dAccer: ������ 
	// bUseArbitraryOrig : 0: ���� ���� ��� 1: ������ 
	// bUseDog : 0: Dog ������  1: ���
	// nDirection : homing ���� 
	HXAPI_API long HXHoming(U32 nAxis, F64  dFeed, F64 dDecel1st, F64 dDecel2nd, F64 dAcce
		, U32 bUseArbitraryOrig = 0, U32 bUseDog = 0, U32 nDirection = eCW);

	// Goto ���� : ���� 
	// dPosmm : �̵� ��ų ��ġ �� 
	// dFeed : ���� �ӵ� 
	HXAPI_API long HXGoto_INC(U32 nAxis, double dPosmm, double dFeed);

	// Goto ���� : ���� 
	// dPosmm : �̵���ų ���� ��ġ
	// dFeed : ���� �ӵ� 
	HXAPI_API long HXGoto_ABS(U32 nAxis, double dPosmm, double dFeed);
	


}