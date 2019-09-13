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
 *  荳願ｨ倩送菴懈ｨｩ閠?縺ｯ?ｼ御ｻ･荳九?ｮ(1)縲?(4)縺ｮ譚｡莉ｶ繧呈ｺ縺溘☆蝣ｴ蜷医↓髯舌ｊ?ｼ梧悽繧ｽ繝輔ヨ繧ｦ繧ｧ
 *  繧｢?ｼ域悽繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢繧呈隼螟峨＠縺溘ｂ縺ｮ繧貞性繧?ｼ惹ｻ･荳句酔縺假ｼ峨ｒ菴ｿ逕ｨ繝ｻ隍?陬ｽ繝ｻ謾ｹ
 *  螟峨?ｻ蜀埼?榊ｸ??ｼ井ｻ･荳具ｼ悟茜逕ｨ縺ｨ蜻ｼ縺ｶ?ｼ峨☆繧九％縺ｨ繧堤┌蜆溘〒險ｱ隲ｾ縺吶ｋ?ｼ?
 *  (1) 譛ｬ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢繧偵た繝ｼ繧ｹ繧ｳ繝ｼ繝峨?ｮ蠖｢縺ｧ蛻ｩ逕ｨ縺吶ｋ蝣ｴ蜷医↓縺ｯ?ｼ御ｸ願ｨ倥?ｮ闡嶺ｽ?
 *      讓ｩ陦ｨ遉ｺ?ｼ後％縺ｮ蛻ｩ逕ｨ譚｡莉ｶ縺翫ｈ縺ｳ荳玖ｨ倥?ｮ辟｡菫晁ｨｼ隕丞ｮ壹′?ｼ後◎縺ｮ縺ｾ縺ｾ縺ｮ蠖｢縺ｧ繧ｽ繝ｼ
 *      繧ｹ繧ｳ繝ｼ繝我ｸｭ縺ｫ蜷ｫ縺ｾ繧後※縺?繧九％縺ｨ?ｼ?
 *  (2) 譛ｬ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢繧抵ｼ後Λ繧､繝悶Λ繝ｪ蠖｢蠑上↑縺ｩ?ｼ御ｻ悶?ｮ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢髢狗匱縺ｫ菴ｿ
 *      逕ｨ縺ｧ縺阪ｋ蠖｢縺ｧ蜀埼?榊ｸ?縺吶ｋ蝣ｴ蜷医↓縺ｯ?ｼ悟?埼?榊ｸ?縺ｫ莨ｴ縺?繝峨く繝･繝｡繝ｳ繝茨ｼ亥茜逕ｨ
 *      閠?繝槭ル繝･繧｢繝ｫ縺ｪ縺ｩ?ｼ峨↓?ｼ御ｸ願ｨ倥?ｮ闡嶺ｽ懈ｨｩ陦ｨ遉ｺ?ｼ後％縺ｮ蛻ｩ逕ｨ譚｡莉ｶ縺翫ｈ縺ｳ荳玖ｨ?
 *      縺ｮ辟｡菫晁ｨｼ隕丞ｮ壹ｒ謗ｲ霈峨☆繧九％縺ｨ?ｼ?
 *  (3) 譛ｬ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢繧抵ｼ梧ｩ溷勣縺ｫ邨?縺ｿ霎ｼ繧縺ｪ縺ｩ?ｼ御ｻ悶?ｮ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢髢狗匱縺ｫ菴ｿ
 *      逕ｨ縺ｧ縺阪↑縺?蠖｢縺ｧ蜀埼?榊ｸ?縺吶ｋ蝣ｴ蜷医↓縺ｯ?ｼ梧ｬ｡縺ｮ縺?縺壹ｌ縺九?ｮ譚｡莉ｶ繧呈ｺ縺溘☆縺?
 *      縺ｨ?ｼ?
 *    (a) 蜀埼?榊ｸ?縺ｫ莨ｴ縺?繝峨く繝･繝｡繝ｳ繝茨ｼ亥茜逕ｨ閠?繝槭ル繝･繧｢繝ｫ縺ｪ縺ｩ?ｼ峨↓?ｼ御ｸ願ｨ倥?ｮ闡?
 *        菴懈ｨｩ陦ｨ遉ｺ?ｼ後％縺ｮ蛻ｩ逕ｨ譚｡莉ｶ縺翫ｈ縺ｳ荳玖ｨ倥?ｮ辟｡菫晁ｨｼ隕丞ｮ壹ｒ謗ｲ霈峨☆繧九％縺ｨ?ｼ?
 *    (b) 蜀埼?榊ｸ?縺ｮ蠖｢諷九ｒ?ｼ悟挨縺ｫ螳壹ａ繧区婿豕輔↓繧医▲縺ｦ?ｼ卦OPPERS繝励Ο繧ｸ繧ｧ繧ｯ繝医↓
 *        蝣ｱ蜻翫☆繧九％縺ｨ?ｼ?
 *  (4) 譛ｬ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢縺ｮ蛻ｩ逕ｨ縺ｫ繧医ｊ逶ｴ謗･逧?縺ｾ縺溘?ｯ髢捺磁逧?縺ｫ逕溘§繧九＞縺九↑繧区錐
 *      螳ｳ縺九ｉ繧ゑｼ御ｸ願ｨ倩送菴懈ｨｩ閠?縺翫ｈ縺ｳTOPPERS繝励Ο繧ｸ繧ｧ繧ｯ繝医ｒ蜈崎ｲｬ縺吶ｋ縺薙→?ｼ?
 *      縺ｾ縺滂ｼ梧悽繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢縺ｮ繝ｦ繝ｼ繧ｶ縺ｾ縺溘?ｯ繧ｨ繝ｳ繝峨Θ繝ｼ繧ｶ縺九ｉ縺ｮ縺?縺九↑繧狗炊
 *      逕ｱ縺ｫ蝓ｺ縺･縺剰ｫ区ｱゅ°繧峨ｂ?ｼ御ｸ願ｨ倩送菴懈ｨｩ閠?縺翫ｈ縺ｳTOPPERS繝励Ο繧ｸ繧ｧ繧ｯ繝医ｒ
 *      蜈崎ｲｬ縺吶ｋ縺薙→?ｼ?
 *
 *  譛ｬ繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢縺ｯ?ｼ檎┌菫晁ｨｼ縺ｧ謠蝉ｾ帙＆繧後※縺?繧九ｂ縺ｮ縺ｧ縺ゅｋ?ｼ惹ｸ願ｨ倩送菴懈ｨｩ閠?縺?
 *  繧医?ｳTOPPERS繝励Ο繧ｸ繧ｧ繧ｯ繝医?ｯ?ｼ梧悽繧ｽ繝輔ヨ繧ｦ繧ｧ繧｢縺ｫ髢｢縺励※?ｼ檎音螳壹?ｮ菴ｿ逕ｨ逶ｮ逧?
 *  縺ｫ蟇ｾ縺吶ｋ驕ｩ蜷域ｧ繧ょ性繧√※?ｼ後＞縺九↑繧倶ｿ晁ｨｼ繧り｡後ｏ縺ｪ縺??ｼ弱∪縺滂ｼ梧悽繧ｽ繝輔ヨ繧ｦ繧ｧ
 *  繧｢縺ｮ蛻ｩ逕ｨ縺ｫ繧医ｊ逶ｴ謗･逧?縺ｾ縺溘?ｯ髢捺磁逧?縺ｫ逕溘§縺溘＞縺九↑繧区錐螳ｳ縺ｫ髢｢縺励※繧ゑｼ後◎
 *  縺ｮ雋ｬ莉ｻ繧定ｲ?繧上↑縺??ｼ?
 *
 *  $Id: sample1.h 2416 2012-09-07 08:06:20Z ertl-hiro $
 */

/*
 *		繧ｵ繝ｳ繝励Ν繝励Ο繧ｰ繝ｩ繝?(1)縺ｮ繝倥ャ繝繝輔ぃ繧､繝ｫ
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  繧ｿ繝ｼ繧ｲ繝?繝井ｾ晏ｭ倥?ｮ螳夂ｾｩ
 */
#include "target_test.h"

/*
 *  蜷?繧ｿ繧ｹ繧ｯ縺ｮ蜆ｪ蜈亥ｺｦ縺ｮ螳夂ｾｩ
 */

#define MAIN_PRIORITY 5 /* 繝｡繧､繝ｳ繧ｿ繧ｹ繧ｯ縺ｮ蜆ｪ蜈亥ｺｦ */
                        /* HIGH_PRIORITY繧医ｊ鬮倥￥縺吶ｋ縺薙→ */

#define HIGH_PRIORITY 9 /* 荳ｦ陦悟ｮ溯｡後＆繧後ｋ繧ｿ繧ｹ繧ｯ縺ｮ蜆ｪ蜈亥ｺｦ */
#define MID_PRIORITY 10
#define LOW_PRIORITY 11

/*
 *  繧ｿ繝ｼ繧ｲ繝?繝医↓萓晏ｭ倥☆繧句庄閭ｽ諤ｧ縺ｮ縺ゅｋ螳壽焚縺ｮ螳夂ｾｩ
 */

#ifndef STACK_SIZE
#define STACK_SIZE 4096 /* 繧ｿ繧ｹ繧ｯ縺ｮ繧ｹ繧ｿ繝?繧ｯ繧ｵ繧､繧ｺ */
#endif                  /* STACK_SIZE */

#ifndef LOOP_REF
#define LOOP_REF ULONG_C(1000000) /* 騾溷ｺｦ險域ｸｬ逕ｨ縺ｮ繝ｫ繝ｼ繝怜屓謨ｰ */
#endif                            /* LOOP_REF */

/*
 *  髢｢謨ｰ縺ｮ繝励Ο繝医ち繧､繝怜ｮ｣險
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
extern void cnt_ten_ms(intptr_t exinf);
extern void tail_cnt_ten_ms(intptr_t exinf);
extern void goto_get_distance(intptr_t exinf);
extern void seesawrunner_cnt_ten_ms(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
