
#ifdef IsDebug
#define IncludeRS232
#define debugMain
//#define debugWriteValueReq
#define DebugTQ
//#define debugSwitchDimmer
//#define debugRTC
#define debug_CheckKurzschluss
#define debug_CheckSpannungsausfall
//#define SetDimmverfahren
#define debug_restart_hw
#define debug_restart_app
//#define debug_SendRueckmeldung
#define debug_SetDimmverfahren
//#define debug_process_tel
#endif
#define	DSig1_ON	P1_2 = 1
#define	DSig1_OFF	P1_2 = 0
#define DSig1(x)    P1_2 = x

#define	DSig2_ON	P1_3 = 1
#define	DSig2_OFF	P1_3 = 0
#define DSig2(x)    P1_3 = x
