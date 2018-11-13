#ifndef yla_string_h
#define yla_string_h

#include "yla_vm.h"
#include "yla_cop.h"
#include "yla_type.h"
#include "yla_test.h"
#include "yla_compliance.h"

void putNumberPost(yla_int_type **prog_ptr, yla_int_type subprog_start_addr, compliance_table *compliance, yla_int_type *prog_counter, yla_int_type global_var[]);
void putNumberPre(yla_int_type **prog_ptr, yla_int_type subprog_start_addr, compliance_table *compliance, yla_int_type *prog_counter, yla_int_type global_var[]);
void putNumberIn(yla_int_type **prog_ptr, yla_int_type subprog_start_addr, compliance_table *compliance, yla_int_type *prog_counter, yla_int_type global_var[]);

#endif