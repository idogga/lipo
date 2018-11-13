#ifndef yla_compliance_h
#define yla_compliance_h

#include <stdlib.h>
#include "yla_cop.h"
#include "yla_type.h"

typedef struct {
	yla_int_type *mark;			
	yla_cop_type *high_byte;	
	yla_cop_type *low_byte;	
	yla_int_type size;
	yla_int_type count;
} complianceRow;

void complianceTableInit(complianceRow* array, size_t size);
void complianceDone(complianceRow* array);

yla_int_type complianceTableGetAddress(complianceRow* array, yla_int_type mark);
void complianceTableSetAddr(complianceRow* array, yla_int_type mark, size_t addr);

#endif
