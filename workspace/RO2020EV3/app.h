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
 *  荳願ｨ倩送菴懈ｨ?���??縺?��??��御?��?��荳�???��(1)縲?(4)縺?��譚｡莉ｶ繧呈ｺ縺溘�??蝣?��蜷医↓髯舌�???��梧悽繧?��繝輔ヨ繧?��繧?��
 *  繧?��??��域悽繧?��繝輔ヨ繧?��繧?��繧?��繧呈隼螟峨?�?縺溘ｂ縺?��繧貞性繧??��惹?��?��荳句酔縺�??��峨?��菴?��逕ｨ繝ｻ�??陬?��繝ｻ謾?��
 *  螟峨??��蜀埼?榊ｸ???��井ｻ?��荳具?��悟茜逕ｨ縺?��蜻?��縺?��??��峨�?繧九�?縺?��繧堤┌蜆溘〒險?��隲?��縺吶?�???��?
 *  (1) 譛ｬ繧?��繝輔ヨ繧?��繧?��繧?��繧偵た繝ｼ繧?��繧?��繝ｼ繝峨??��蠖｢縺?��蛻?��逕ｨ縺吶?��蝣?��蜷医↓縺?��??��御?��願ｨ倥??��闡嶺?��?
 *      讓ｩ陦?��遉ｺ??��後�?縺?��蛻?��逕ｨ譚｡莉ｶ縺翫?��縺?��荳玖ｨ倥??��辟｡菫�??��?��隕丞ｮ壹′??��後◎縺?��縺?��縺?��縺?��蠖｢縺?��繧?��繝ｼ
 *      繧?��繧?��繝ｼ繝�?�ｸ?��縺?��蜷?��縺?��繧後※縺?繧九�?縺?��??��?
 *  (2) 譛ｬ繧?��繝輔ヨ繧?��繧?��繧?��繧抵?��後Λ繧?��繝悶Λ繝ｪ蠖｢蠑上�?�縺?��??��御?��悶??��繧?��繝輔ヨ繧?��繧?��繧?��髢狗匱縺?��菴?��
 *      逕ｨ縺?��縺阪?���?�｢縺?��蜀埼?榊ｸ?縺吶?��蝣?��蜷医↓縺?��??���??埼?榊ｸ?縺?��莨?��縺?繝峨く繝･繝｡繝ｳ繝茨?��亥茜逕ｨ
 *      �??繝槭ル繝･繧?��繝ｫ縺?��縺?��??��峨�???��御?��願ｨ倥??��闡嶺?��懈ｨ?��陦?��遉ｺ??��後�?縺?��蛻?��逕ｨ譚｡莉ｶ縺翫?��縺?��荳玖ｨ?
 *      縺?��辟｡菫�??��?��隕丞ｮ壹?��謗ｲ霈峨�?繧九�?縺?��??��?
 *  (3) 譛ｬ繧?��繝輔ヨ繧?��繧?��繧?��繧抵?��梧?��溷勣縺?��邨?縺?��霎ｼ繧縺?��縺?��??��御?��悶??��繧?��繝輔ヨ繧?��繧?��繧?��髢狗匱縺?��菴?��
 *      逕ｨ縺?��縺阪↑縺?蠖｢縺?��蜀埼?榊ｸ?縺吶?��蝣?��蜷医↓縺?��??��梧?��?��縺?��縺?縺壹?��縺�???��譚｡莉ｶ繧呈ｺ縺溘�??縺?
 *      縺?��??��?
 *    (a) 蜀埼?榊ｸ?縺?��莨?��縺?繝峨く繝･繝｡繝ｳ繝茨?��亥茜逕ｨ�??繝槭ル繝･繧?��繝ｫ縺?��縺?��??��峨�???��御?��願ｨ倥??��闡?
 *        菴懈ｨ?��陦?��遉ｺ??��後�?縺?��蛻?��逕ｨ譚｡莉ｶ縺翫?��縺?��荳玖ｨ倥??��辟｡菫�??��?��隕丞ｮ壹?��謗ｲ霈峨�?繧九�?縺?��??��?
 *    (b) 蜀埼?榊ｸ?縺?��蠖｢諷九�???��悟挨縺?��螳壹?��繧区婿豕輔�?�繧医▲縺?��??��卦OPPERS繝励Ο繧?��繧?��繧?��繝医�?
 *        蝣?��蜻翫�?繧九�?縺?��??��?
 *  (4) 譛ｬ繧?��繝輔ヨ繧?��繧?��繧?��縺?��蛻?��逕ｨ縺?��繧医?��逶?��謗･逧?縺?��縺�???��髢捺�?逧?縺?��逕溘§繧九＞縺九�?�繧区�?
 *      螳?��縺九ｉ繧ゑｼ御?��願ｨ倩送菴懈ｨ?���??縺翫?��縺?��TOPPERS繝励Ο繧?��繧?��繧?��繝医?��蜈崎ｲ?��縺吶?��縺薙�????��?
 *      縺?��縺滂ｼ梧悽繧?��繝輔ヨ繧?��繧?��繧?��縺?��繝ｦ繝ｼ繧?��縺?��縺�???��繧?��繝ｳ繝峨Θ繝ｼ繧?��縺九ｉ縺?��縺?縺九�?�繧狗炊
 *      逕ｱ縺?��蝓ｺ縺?��縺剰?��区?���?°繧峨?�???��御?��願ｨ倩送菴懈ｨ?���??縺翫?��縺?��TOPPERS繝励Ο繧?��繧?��繧?��繝医?�?
 *      蜈崎ｲ?��縺吶?��縺薙�????��?
 *
 *  譛ｬ繧?��繝輔ヨ繧?��繧?��繧?��縺?��??��檎┌菫�??��?��縺?���?蝉ｾ帙�?繧後※縺?繧九ｂ縺?��縺?��縺�??�???��惹?��願ｨ倩送菴懈ｨ?���??縺?
 *  繧医??��TOPPERS繝励Ο繧?��繧?��繧?��繝医??��??��梧悽繧?��繝輔ヨ繧?��繧?��繧?��縺?��髢?��縺励※??��檎音螳壹??��菴?��逕ｨ逶?��逧?
 *  縺?���??��縺吶?��驕ｩ蜷�??��繧�?性繧√※??��後＞縺九�?�繧倶?���??��?��繧り｡後ｏ縺?��縺???��弱∪縺滂ｼ梧悽繧?��繝輔ヨ繧?��繧?��
 *  繧?��縺?��蛻?��逕ｨ縺?��繧医?��逶?��謗･逧?縺?��縺�???��髢捺�?逧?縺?��逕溘§縺溘＞縺九�?�繧区錐螳?��縺?��髢?��縺励※繧ゑｼ後◎
 *  縺?��雋ｬ莉ｻ繧定ｲ?繧上�?�縺???��?
 *
 *  $Id: sample1.h 2416 2012-09-07 08:06:20Z ertl-hiro $
 */

/*
 *		繧?��繝ｳ繝励Ν繝励Ο繧?��繝ｩ�??(1)縺?��繝倥ャ�?繝輔ぃ繧?��繝ｫ
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  繧?��繝ｼ繧?���??繝井ｾ晏ｭ倥??��螳夂ｾ?��
 */
#include "target_test.h"

/*
 *  蜷?繧?��繧?��繧?��縺?���??��蜈亥?��?��縺?��螳夂ｾ?��
 */

#define MAIN_PRIORITY 5 /* 繝｡繧?��繝ｳ繧?��繧?��繧?��縺?���??��蜈亥?��?�� */
                        /* HIGH_PRIORITY繧医?��鬮倥?��縺吶?��縺薙�?? */

#define HIGH_PRIORITY 9 /* 荳?��陦悟ｮ溯?��後�?繧後ｋ繧?��繧?��繧?��縺?���??��蜈亥?��?�� */
#define MID_PRIORITY 10
#define LOW_PRIORITY 11

/*
 *  繧?��繝ｼ繧?���??繝医↓萓晏ｭ倥�?繧句�?閭?��諤?��縺?��縺�??��螳壽焚縺?��螳夂ｾ?��
 */

#ifndef STACK_SIZE
#define STACK_SIZE 4096 /* 繧?��繧?��繧?��縺?��繧?��繧?���??繧?��繧?��繧?��繧?�� */
#endif                  /* STACK_SIZE */

#ifndef LOOP_REF
#define LOOP_REF ULONG_C(1000000) /* 騾溷?��?��險域ｸ?��逕ｨ縺?��繝ｫ繝ｼ繝怜屓謨?�� */
#endif                            /* LOOP_REF */

/*
 *  髢?��謨?��縺?��繝励Ο繝医ち繧?��繝怜ｮ?��險
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
//extern void initialize_ev3(intptr_t exinf);

extern void sonar_cyc(intptr_t exinf);
extern void color_cyc(intptr_t exinf);
// extern void initialize_ev3(intptr_t exinf);
//extern void get_distance(intptr_t exinf);
extern void goto_get_distance(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif