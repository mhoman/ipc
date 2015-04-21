/*
*	IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
*
*	By downloading, copying, installing or using the software you agree to this license.
*	If you do not agree to this license, do not download, install,
*	Copy or use the software.
*
*	Copyright (C) 2011, ANTS, Inc, All Rights Reserved.
*
*	Project Name:ServerCore
*	File Name:AntsServerSDK.h
*
*	Writed by ItmanLee at 2011 - 02 - 08 Ants,WuHan,HuBei,China
*/
#ifndef __ANTS_SERVER_SDK_H__
#define __ANTS_SERVER_SDK_H__
#include "AntsMidLayerSDK.h"

#if (defined(_WIN32)||defined(WIN32)) 
#ifdef ANTSSERVERSDK_EXPORTS
#define ANTS_SERVER_API __declspec(dllexport)
#else
#define ANTS_SERVER_API __declspec(dllimport)
#endif
#else
#define __stdcall 
#define CALLBACK
#define ANTS_SERVER_API extern "C"
#endif

typedef enum AntsLogDest{
	AntsLog2File,
	AntsLog2Console,
	AntsLog2Socket
}eANTS_LOG_DEST;

typedef enum {
	eG711A=1,
	eG711U=2,
	eG722=3,
	eG726=4,
	eG723=5,
	eAMRNB=6,
	eAMRWB=7,
	eADPCM=8,
	ePCM=9,
	eADPCMC1=10,
	eG72616K=11,	
}eANTS_AUDIOCODEC_ID;

typedef struct{
	DWORD dwLogDest;
	DWORD dwListenPort;
	DWORD dwMainStreamBufferNum;
	DWORD dwMainStreamBlockSize;
	DWORD dwSubStreamBufferNum;
	DWORD dwSubStreamBlockSize;
	BYTE byRes[128];	
}ANTS_SERVER_PARAM,*LPANTS_SERVER_PARAM;

typedef struct{
	fSetParameter fpSetParameter;//!�������û�ȡ������
	fGetParameter fpGetParameter;
	fPtzControl fpPtzControl;//!PTZ����
	fPtzPreset fpPtzPreset;
	fPtzTrack fpPtzTrack;
	fPtzCruise fpPtzCruise;
	fPtzTrans fpPtzTrans;
	fPtz3D fpPtz3D;
	fGetPtzCruise fpGetPtzCruise;
	fCaptureJpeg fpCaptureJpeg;//!Jpegץͼ����
	fGetChannelBitRate fpGetChannelBitRate;//!��ȡͨ��ʵʱ����������������Ϣ
	fGetAlarmInfo fpGetAlarmInfo;//��ѯ����
	fGetAlarmOut fpGetAlarmOut;//!�������״̬��ȡ������
	fSetAlarmOut fpSetAlarmOut;
	fStartVoice fpStartVoice;//!�����Խ�����
	fStopVoice fpStopVoice;
	fSendVoiceData fpSendVoiceData;
	fReboot fpReboot;
	fGetSDKVersion fpGetSDKVersion;//!SDK�汾��Ϣ��ȡ��������ȡ
	fGetLastError fpGetLastError;
	fCheckPassword fpCheckPassword;
}ANTS_SERVER_FUNCTION_CONFIG,*LPANTS_SERVER_FUNCTION_CONFIG;

#ifdef __cplusplus
extern "C"{
#endif

void __stdcall ANTS_SERVER_Initialize(LPANTS_SERVER_PARAM lpServerParam,LPANTS_SERVER_FUNCTION_CONFIG lpServerFunctionConfig);
void __stdcall ANTS_SERVER_InputData(DWORD dwStreamType,DWORD dwChannel,BYTE *lpBuffer,DWORD dwSize,BYTE byFrameType);
void __stdcall ANTS_SERVER_InputDataV2(DWORD dwStreamType,DWORD dwChannel,BYTE *lpBuffer,DWORD dwSize,BYTE byFrameType,WORD wWidth,WORD wHeight);
void __stdcall ANTS_SERVER_InputDataV3(DWORD dwStreamType,DWORD dwChannel,BYTE *lpBuffer,DWORD dwSize,BYTE byFrameType,WORD wWidth,WORD wHeight,DWORD dwSecond,DWORD dwUSecond);
void __stdcall ANTS_SERVER_InputOneAudioFrame(DWORD dwStreamType,DWORD dwChannel,BYTE *lpBuffer,DWORD dwSize,BYTE byAudioCodecId);//!������Ƶ��������
void __stdcall ANTS_SERVER_InputOneFrame(DWORD dwStreamType,DWORD dwChannel,BYTE *lpBuffer,DWORD dwSize,BYTE byFrameType);//!�ڲ�ר���������ӿ�
void __stdcall ANTS_SERVER_InputAlarmData(DWORD dwCommand,BYTE *lpBuffer,DWORD dwSize);
void __stdcall ANTS_SERVER_Release( );

#ifdef __cplusplus
}
#endif

#endif
