#pragma once

// param 
enum AxisType{ AXISNONE = 0, SERVO_AXIS, SPINDLEA_XIS};
enum AxisInterface{ IntType_AIB =1, IntType_2, IntType_ECAT, IntType_AIB32, IntType_AIB30V, IntType_AIB30P, IntType_EDIO7246};

// �ؼ� ���� 
enum {eEncCPhase =0, eEnc, eServoReady, eServoAlarm, eVelCmd, eServoOn, eServoReset};



// Spindle 
enum HXSpindle{
	AXIS_SP_MOTOR_TYPE = 21,	// ����/ ����̺� ����(1: �Ϲ� ���ɵ�, 2: DIGITAL, 3: �������� 
	AXIS_SP_GEARSTEP = 48,
	AXIS_SP_BACKLASH1STEP = 33,	//�� ������ �鷡�� �� : 1��
	AXIS_SP_BACKLASH2STEP = 34,	//�� ������ �鷡�� �� : 2��
	AXIS_SP_BACKLASH3STEP = 35,	//�� ������ �鷡�� �� : 3��
	AXIS_SP_BACKLASH4STEP = 36,	//�� ������ �鷡�� �� : 4��

	AXIS_SP_MOTOR_GEAR1STEP = 48,	//�� ������ ������ ��� �� : 1��
	AXIS_SP_MOTOR_GEAR2STEP = 49,	//�� ������ ������ ��� �� : 2��
	AXIS_SP_MOTOR_GEAR3STEP = 50,	//�� ������ ������ ��� �� : 3��
	AXIS_SP_MOTOR_GEAR4STEP = 51,	//�� ������ ������ ��� �� : 4��

	AXIS_SP_MACHINE_GEAR1STEP = 52,	//�� ������ ����� ��� �� : 1��
	AXIS_SP_MACHINE_GEAR2STEP = 53,//�� ������ ����� ��� �� : 2��
	AXIS_SP_MACHINE_GEAR3STEP = 54,//�� ������ ����� ��� �� : 3��
	AXIS_SP_MACHINE_GEAR4STEP = 55,//�� ������ ����� ��� �� : 4��

	AXIS_SP_10V_RPM1STEP = 61, //�� ���ܿ��� 10V�� �ش��ϴ� ���ɵ� ȸ���� : 1�� 
	AXIS_SP_10V_RPM2STEP = 62, //�� ���ܿ��� 10V�� �ش��ϴ� ���ɵ� ȸ���� : 2�� 
	AXIS_SP_10V_RPM3STEP = 63, //�� ���ܿ��� 10V�� �ش��ϴ� ���ɵ� ȸ���� : 3�� 
	AXIS_SP_10V_RPM4STEP = 64, //�� ���ܿ��� 10V�� �ش��ϴ� ���ɵ� ȸ���� : 4�� 

	AXIS_SP_MAX_RPM1STEP = 65, // �� ���ܿ��� �ִ� ���ɵ� ȸ���� : 1�� 
	AXIS_SP_MAX_RPM2STEP = 66, // �� ���ܿ��� �ִ� ���ɵ� ȸ���� : 2�� 
	AXIS_SP_MAX_RPM3STEP = 67, // �� ���ܿ��� �ִ� ���ɵ� ȸ���� : 3�� 
	AXIS_SP_MAX_RPM4STEP = 68, // �� ���ܿ��� �ִ� ���ɵ� ȸ���� : 4�� 

	AXIS_SP_GEAR_TRANSMISSION_RPM = 69, // ��ȯ�� ���ɵ� ȸ���� 
	AXIS_SP_ENCODER_TYPE	= 86, // ENCODER ü�� ��� (0:����,1:���ɵ���� ����,2:�ܺ�)
	AXIS_SP_ENCODER_PULSE_TYPE = 88, // ENCODER PULSE ��� ��� (0:LINEAR,1:MODULAR)
	AXIS_SP_ENCODER_RESOLUTION = 93, // ENCODER RESOLUTION(ü�� ���� RESOLUTION)

	AXIS_SP_RPM_AGREE_RANGE	= 109,    //���ɵ� ȸ���ӵ� AGREE ����
	AXIS_SP_ZERO_SPEED_AGREE_RANGE =110,   //���ɵ� ȸ���ӵ� ZERO SPEED AGREE ����
	AXIS_SP_ORIENTATION_FEED =121,   //���ɵ� ���������̼� �ӵ�
	AXIS_SP_ORIENTATION_DIRECTION =122,   //���ɵ� ���������̼� ����(0:+, 1 : -)
	AXIS_SP_ORIENTATION_OFFSET =123,   //���ɵ� ���������̼� �ɼ�
	AXIS_SP_P_GAIN_1STEP = 174,   //�� ������ ��ġ ��� P ����: 1��
	AXIS_SP_P_GAIN_2STEP = 175,   //�� ������ ��ġ ��� P ����: 2��
	AXIS_SP_P_GAIN_3STEP = 176,   //�� ������ ��ġ ��� P ����: 3��
	AXIS_SP_P_GAIN_4STEP = 177,   //�� ������ ��ġ ��� P ����: 4��
	AXIS_SP_FEEDFOWARD_GAIN_1STEP = 183,   //�� ���ܿ��� ��ġ ��� �ǵ� ������ ����: 1��
	AXIS_SP_FEEDFOWARD_GAIN_2STEP = 184,   //�� ���ܿ��� ��ġ ��� �ǵ� ������ ����: 2��
	AXIS_SP_FEEDFOWARD_GAIN_3STEP = 185,   //�� ���ܿ��� ��ġ ��� �ǵ� ������ ����: 3��
	AXIS_SP_FEEDFOWARD_GAIN_4STEP = 186,   //�� ���ܿ��� ��ġ ��� �ǵ� ������ ����: 4��
	AXIS_SP_FOLLOW_ERR_TYPEB =194,   //�������� ��� ����
	AXIS_SP_MAX_VELOCITY_COMMAND =196,   //�ӵ� ���� �ִ밪
	AXIS_SP_DA_BIT =207,   //D / A CONVERTER RESOLUTION, VELOCITY DATA SCALE
	AXIS_SP_VOLATE_OFFSET_COMPENSATION_TYPE =211,   //�Է� ���� �ɼ·� ���� ���(0:���Ͽɼ� 1 : ���߿ɼ�)
	AXIS_SP_VOLATE_OFFSET =212,   //�Է� ���� �ɼ·�(���Ͽɼ� ����� ���)
	AXIS_SP_VOLATE_OFFSET_INPUT_INTERVAL =213,   //���� �ɼ·� �Է� ����(���߿ɼ� ����� ���)
	AXIS_SP_VOLATE_OFFSET_POSITIVE_DIRECTION =214,   //+���� �Է� ���� �ɼ·�(���߿ɼ� ����� ���) : #1~#10(~223)
	AXIS_SP_VOLATE_OFFSET_NEGATIVE_DIRECTION=224,   //-���� �Է� ���� �ɼ·�(���߿ɼ� ����� ���)	: #1~#10(~233)
	AXIS_SP_POLARITY_ENCODER_CPHASE =280,   //ENCODER C�� �ؼ�(0:+, 1 : -)
	AXIS_SP_POLARITY_ENCODER = 281,   //ENCODER ����(0:+, 1 : -)
	AXIS_SP_POLARITY_SERVO_READY = 285,   //���� READY �ؼ�(0:+, 1 : -)
	AXIS_SP_POLARITY_SERVO_ALARM = 287,   //���� ALARM �ؼ�(0:+, 1 : -)
	AXIS_SP_POLARITY_VELOCITY_COMMAND = 290,   //�ӵ� ���� �ؼ�(0:+, 1 : -)
	AXIS_SP_POLARITY_SERVO_ON = 293,   //���� ON �ؼ�(0:+, 1 : -)
	AXIS_SP_POLARITY_SERVO_RESET =295,   //���� RESET �ؼ�(0:+, 1 : -)
	AXIS_SP_USE_ENCODER_OUT_ERR = 298,   //ENCODER �ܼ� �˶� ���� ����(0:����, 1 : �������)
	AXIS_SP_USE_ENCODER_PHASE_ERR =300,   //ENCODER PHASE �˶� ���� ����(0:������ 1 : �������)
	AXIS_SP_ENCODER_PHASE_ERR_LIMITCOUNT =302,   //ENCODER PHASE �˶����� �����ϴ� PHASE ERROR ��������
	AXIS_SP_EXCEPTION_ENCODER_PHASE_ERR =303,   //ENCODER PHASE �˶����� NC ����(0:X, 1 : ����, 2 : SV OFF)
	AXIS_SP_SERVO_READY_ERR_DELAYTIME =311,  //SERVO READY �˶����� �����ϴ� ��ȣ �Է� ���� �ð�

	_SP_MAX
};

// Servo 
enum HXServo{
	AXIS_TYPE									= 1,	// AXIS type 0: no Use, 1:Servo, 2:Spindle
	AXIS_PORT_NO								= 2,	// Axis Port No.
	AXIS_INTERFACE_TYPE							= 3,	// CNC & Drive Interface Type (1:Analog, 3:ECAT, 4:AIB32, 5:AIB30V, 6:AIB30P, 7:EDIO7246)
	AXIS_ECAT_NO								= 4,	// AIB No. or ECAT No.

	AXIS_FEED_TYPE								= 21,	// �� �̼� ���� - 1: ����(V), 2: ȸ��(V), 3: ����(P), 2: ȸ��(P)
	AXIS_MASTER_SLAVE_CPHASE_OFFSET				= 31,	// Master�� Slave�� C�� ���� ����:mm
	AXIS_SET_SYNC_MASTER						= 32,	// nMaster : �������� Master �� ��ȣ ����
	AXIS_SET_BACKLASHERR						= 44,	// �鷡�� �� (mm, deg)
	AXIS_SET_FRICTION_COMPENSATION				= 47,	// ���� ���� �� (mm, deg)
	AXIS_USE_PITCHERR_COMPENSATION				= 53,	// ��ġ���� ���� ��ȿ ����(0: ����, 1: �������� )
	AXIS_PITCHERR_COMP_INTERVAL					= 57,	// ��ġ���� �Է� ���� 
	AXIS_PITCHERR_ORIGIN_INDEX					= 58,	// ������ �����ϴ� ��ġ���� ���̺� �ε��� 
	AXIS_PITCH_ERR_TABLE						= 59,	// ��ġ���� ���̺�(#1~) 200��  
	AXIS_POSITIONAL_STEPOUT_COMPENSATION		= 259,	// ��ġ�� ���� Ż�� ���� ��� 
	AXIS_POSITIONAL_RESIDUALPULSE_COMPENSATION	= 260,	// ��ġ�� ���� �ܿ� �޽� ���� ��� 
	AXIS_MACHINE_GEAR_RATIO						= 269,	// ����� ����
	AXIS_MOTORS_GEAR_RATIO						= 270,	// ������ ����
	AXIS_MM_BALLSCREW_REVOLUTION		        = 271,	// Mm: 1ȸ���� �̼۰Ÿ� 
	AXIS_ENCODER_RESOLUTION						= 284,	// Encoder resolution(ü�� ���� Resolution)

	AXIS_USE_ENCODER							= 279,	// Encoder ��� ���� (0: ���, 1: ������)
	AXIS_ENCODER_TYPE							= 280,	// Encoder Ÿ�� 0:Incremental, 1:Absolute, 2:Single turn Absolute
	AXIS_ENCODER_PULSE_TYPE						= 282,	// Encoder pulse ��� ��� ( 0: Linear, 1: Modular )
	AXIS_P_GAIN									= 306, 	// ��ġ���� P ���� 
	AXIS_SYNC_ERR_COMPESATION_GAIN				= 309, 	// �������� ������� ���� ���� 
	AXIS_FEEDFORWARD_GAIN						= 312, 	// �ǵ������� ���� 
	AXIS_SET_FOLLOW_ERR_TYPEA					= 324,	// ���� �������� ��� ���� 
	AXIS_SET_FOLLOW_ERR_TYPEB					= 325,	// �������� ��� ���� 
	AXIS_SET_SYNC_ERR							= 326,	// ���������� ���� ���� ��� ���� 
	AXIS_MAX_VELOCITY_COMMAND					= 328, 	// �ӵ����� �ִ밪
	AXIS_DA_BIT									= 339, 	// D/A convert Resolutio, Velocity Data Scale (ex : 16 bit )
		
	AXIS_POLARITY_ENCODER_CPHASE				= 400,	// Encoder C Phase �ؼ� ���� ( 0: +, 1: - )
	AXIS_POLARITY_ENCODER						= 401,	// Encoder �ؼ� ���� ( 0: +, 1: - )
	AXIS_POLARITY_SERVO_READY					= 405,	// Servo Ready �ؼ� ���� ( 0: +, 1: - )
	AXIS_POLARITY_SERVO_ALARM					= 407,	// Servo Alarm �ؼ� ���� ( 0: +, 1: - )
	AXIS_POLARITY_VELOCITY_COMMAND				= 410, 	// �ӵ����� �ؼ�(0:+, 1:-)
	AXIS_POLARITY_SERVO_ON						= 413,	// Servo Ready �ؼ� ���� ( 0: +, 1: - )
	AXIS_POLARITY_SERVO_RESET					= 415,	// Servo Alarm �ؼ� ���� ( 0: +, 1: - )
	AXIS_USE_ENCODER_OUT_ERR					= 418,	// Encoder �ܼ� �˶� ���� ���� (0: ����, 1: ���� ���� ) 
	AXIS_USE_ENCODER_PHASE_ERR					= 420,	// Encoder Phase �ܼ� �˶� ���� ���� (0: ����, 1: ���� ���� ) 
	AXIS_ENCODER_PHASE_ERR_LIMITCOUNT		= 422,	// Encoder Phase �ܼ� �˶����� �����ϴ� phase error ��������
	AXIS_EXCEPTION_ENCODER_PHASE_ERR		= 423,	// Encoder Phase �ܼ� �˶����� NC ���� ( 0: ���� ����, 1: ����, 2: Servo Off )
	AXIS_USE_ENCODER_CPHASE_ERR					= 425,	// Encoder C Phase �ܼ� �˶� ���� ���� (0: ����, 1: ���� ���� ) 
	AXIS_EXCEPTION_ENCODER_CPHASE_ERR		= 428,	// Encoder C Phase �ܼ� �˶����� NC ���� ( 0: ���� ����, 1: ����, 2: Servo Off )
	AXIS_SERVO_READY_ERR_DELAYTIME			= 431,	// Servo Ready �˶����� �����ϴ� ��ȣ �Է� ���� �ð� 
	AXIS_USE_INFINIT_AXIS						= 432,	// ������ ��������(0: ������, 1: ���) 
	AXIS_FOLLOW_ERR_AUTO_COMPENSATION		= 435,	// �ڵ� ���� �ɼ� ���� (�������� �ڵ�����, 0:������, 1:�����)
	AXIS_MAX_RPM								= 436,	// Motor Max RPM
	
	_MAX
};

