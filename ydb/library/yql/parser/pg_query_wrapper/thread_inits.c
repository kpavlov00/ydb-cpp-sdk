#include "thread_inits.h"
static __thread int pg_thread_init_flag;
void pg_thread_init(void) {
    if (pg_thread_init_flag) return;
    pg_thread_init_flag=1;
    BackendList_init();
    CurrentTransactionState_init();
    DatabaseList_init();
    MXactCache_init();
    cached_expression_list_init();
    dsm_segment_list_init();
    lsn_mapping_init();
    mainrdata_last_init();
    pcxt_list_init();
    saved_plan_list_init();
}
