/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2010 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権�?は?��以下�?�(1)�?(4)の条件を満たす場合に限り?��本ソフトウェ
 *  ア?��本ソフトウェアを改変したものを含む?��以下同じ）を使用・�?製・改
 *  変�?�再�?��??��以下，利用と呼ぶ?��することを無償で許諾する?�?
 *  (1) 本ソフトウェアをソースコード�?�形で利用する場合には?��上記�?�著�?
 *      権表示?��この利用条件および下記�?�無保証規定が?��そのままの形でソー
 *      スコード中に含まれて�?ること?�?
 *  (2) 本ソフトウェアを，ライブラリ形式など?��他�?�ソフトウェア開発に使
 *      用できる形で再�?��?する場合には?���?��?��?に伴�?ドキュメント（利用
 *      �?マニュアルなど?��に?��上記�?�著作権表示?��この利用条件および下�?
 *      の無保証規定を掲載すること?�?
 *  (3) 本ソフトウェアを，機器に�?み込むなど?��他�?�ソフトウェア開発に使
 *      用できな�?形で再�?��?する場合には?��次の�?ずれか�?�条件を満たす�?
 *      と?�?
 *    (a) 再�?��?に伴�?ドキュメント（利用�?マニュアルなど?��に?��上記�?��?
 *        作権表示?��この利用条件および下記�?�無保証規定を掲載すること?�?
 *    (b) 再�?��?の形態を?��別に定める方法によって?��TOPPERSプロジェクトに
 *        報告すること?�?
 *  (4) 本ソフトウェアの利用により直接�?また�?�間接�?に生じるいかなる損
 *      害からも，上記著作権�?およびTOPPERSプロジェクトを免責すること?�?
 *      また，本ソフトウェアのユーザまた�?�エンドユーザからの�?かなる理
 *      由に基づく請求からも?��上記著作権�?およびTOPPERSプロジェクトを
 *      免責すること?�?
 *
 *  本ソフトウェアは?��無保証で提供されて�?るものである?��上記著作権�?�?
 *  よ�?�TOPPERSプロジェクト�?�?��本ソフトウェアに関して?��特定�?�使用目�?
 *  に対する適合性も含めて?��いかなる保証も行わな�??��また，本ソフトウェ
 *  アの利用により直接�?また�?�間接�?に生じたいかなる損害に関しても，そ
 *  の責任を�?わな�??�?
 *
 *  $Id: sample1.h 2416 2012-09-07 08:06:20Z ertl-hiro $
 */

/*
 *		サンプルプログラ�?(1)のヘッダファイル
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ターゲ�?ト依存�?�定義
 */
#include "target_test.h"

/*
 *  �?タスクの優先度の定義
 */

#define MAIN_PRIORITY 5 /* メインタスクの優先度 */
                        /* HIGH_PRIORITYより高くすること */

#define HIGH_PRIORITY 9 /* 並行実行されるタスクの優先度 */
#define MID_PRIORITY 10
#define LOW_PRIORITY 11

/*
 *  ターゲ�?トに依存する可能性のある定数の定義
 */

#ifndef STACK_SIZE
#define STACK_SIZE 4096 /* タスクのスタ�?クサイズ */
#endif                  /* STACK_SIZE */

#ifndef LOOP_REF
#define LOOP_REF ULONG_C(1000000) /* 速度計測用のループ回数 */
#endif                            /* LOOP_REF */

/*
 *  関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern void task(intptr_t exinf);
extern void main_task(intptr_t exinf);
extern void robocon_task(intptr_t exinf);
extern void bt_task(intptr_t exinf);
extern void btsend_task(intptr_t exinf);
extern void balance_task(intptr_t exinf);
extern void idle_task(intptr_t exinf);

extern void drive_cyc(intptr_t unused);
// extern void	tex_routine(TEXPTN texptn, intptr_t exinf);
//#ifdef CPUEXC1
// extern void	cpuexc_handler(void *p_excinf);
//#endif /* CPUEXC1 */
// extern void	cyclic_handler(intptr_t exinf);
// extern void	alarm_handler(intptr_t exinf);
//
// extern void	gpio_handler_initialize(intptr_t exinf);
// extern void	gpio_handler(void);
extern void gpio_irq_dispatcher(intptr_t exinf);
//
// extern void	uart_sensor_monitor(intptr_t exinf);
//
// extern void	ev3_uart_cyclic_handler(intptr_t exinf);
// extern void	ev3_uart_daemon(intptr_t exinf);
// extern void	ev3_uart_port2_irq(void);
//
// extern void initialize_ev3(intptr_t exinf);
extern void get_distance(intptr_t exinf);
extern void cnt_ten_ms(intptr_t exinf);
extern void tail_cnt_ten_ms(intptr_t exinf);
extern void goto_get_distance(intptr_t exinf);
extern void seesawrunner_cnt_ten_ms(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
