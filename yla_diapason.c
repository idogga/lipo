#include "yla_diapason.h"

void putNumberIn(yla_int_type **prog_ptr, yla_int_type subprog_start_addr, complianceRow *compliance, yla_int_type *prog_counter, yla_int_type global_var[])
{
	yla_int_type prog_count = *prog_counter;
	
	yla_int_type ret = global_var[0];
	yla_int_type i = global_var[1];
	
	complianceTableSetAddr(compliance, subprog_start_addr, prog_count);
	
	put_commd(prog_ptr, CSAVE);						
	prog_count++;
	put_value(prog_ptr, ret);						
	prog_count += 2;
	
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0003);
	prog_count += 2;
	put_commd(prog_ptr, CSAVE);						
	prog_count++;
	put_value(prog_ptr, i);
	prog_count += 2;
	
	complianceTableSetAddr(compliance, 0x0091, prog_count);
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0001);					
	prog_count += 2;
	put_commd(prog_ptr, CLOAD);						
	prog_count++;
	put_value(prog_ptr, i);							
	prog_count += 2;
	
	put_commd(prog_ptr, CJG);						
	prog_count++;
	put_value(prog_ptr, 0x0098);					
	prog_count += 2;	
	put_commd(prog_ptr, CSTK);						
	prog_count++;
	put_value(prog_ptr, 0x0002);					
	prog_count += 2;
	
	put_commd(prog_ptr, CLOAD);						
	prog_count++;
	put_value(prog_ptr, i);							
	prog_count += 2;
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0001);					
	prog_count += 2;
	put_commd(prog_ptr, CCMP);						
	prog_count++;
	put_commd(prog_ptr, CJNZ);						
	prog_count++;
	put_value(prog_ptr, 0x0097);					
	prog_count += 2;
	put_commd(prog_ptr, CSTK);						
	prog_count++;
	put_value(prog_ptr, 0x0001);					
	prog_count += 2;
	
	put_commd(prog_ptr, CLOAD);						
	prog_count++;
	put_value(prog_ptr, i);							
	prog_count += 2;
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0003);					
	prog_count += 2;
	put_commd(prog_ptr, CADD);						
	prog_count++;
	put_commd(prog_ptr, CSAVE);						
	prog_count++;
	put_value(prog_ptr, i);							
	prog_count += 2;
	put_commd(prog_ptr, CJMP);						
	prog_count++;
	put_value(prog_ptr, 0x0091);					
	prog_count += 2;
	complianceTableSetAddr(compliance, 0x0097, prog_count);
	put_commd(prog_ptr, CSTK);						
	prog_count++;
	put_value(prog_ptr, 0x0001);					
	prog_count += 2;
	put_commd(prog_ptr, CPUSH);						
	prog_count++;
	put_value(prog_ptr, 0x0001);					
	prog_count += 2;
	put_commd(prog_ptr, CJMP);						
	prog_count++;
	put_value(prog_ptr, 0x0099);					
	prog_count += 2;	
	complianceTableSetAddr(compliance, 0x0098, prog_count);
	put_commd(prog_ptr, CSTK);						
	prog_count++;
	put_value(prog_ptr, 0x0002);					
	
	prog_count += 2;
	put_commd(prog_ptr, CPUSH);						
	prog_count++;
	put_value(prog_ptr, 0x0000);					
	prog_count += 2;
	put_commd(prog_ptr, CJMP);						
	prog_count++;
	put_value(prog_ptr, 0x0099);					
	prog_count += 2;	
	complianceTableSetAddr(compliance, 0x0099, prog_count);
	put_commd(prog_ptr, CLOAD);						
	prog_count++;
	put_value(prog_ptr, ret);						
	prog_count += 2;
	put_commd(prog_ptr, CRET);						
	prog_count++;
	
	*prog_counter = prog_count;
}

void putNumberPost(yla_int_type **prog_ptr, yla_int_type subprog_start_addr, complianceRow *compliance, yla_int_type *prog_counter, yla_int_type global_var[])
{
	yla_int_type prog_count = *prog_counter;
	
	yla_int_type ret = global_var[0];
	
	complianceTableSetAddr(compliance, subprog_start_addr, prog_count);
	
	put_commd(prog_ptr, CSAVE);						
	prog_count++;
	put_value(prog_ptr, ret);						
	prog_count += 2;
	

	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0000);					
	prog_count += 2;
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0004);					
	prog_count += 2;
	put_commd(prog_ptr, CMULT);						
	prog_count++;
	put_commd(prog_ptr, CDEEP);						
	prog_count++;
	put_value(prog_ptr, 0x0003);					
	prog_count += 2;
	
	// Multiplicate end of diapason
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0000);					
	prog_count += 2;
	put_commd(prog_ptr, CDUP);						
	prog_count++;
	put_value(prog_ptr, 0x0002);					
	prog_count += 2;
	put_commd(prog_ptr, CMULT);						
	prog_count++;
	put_commd(prog_ptr, CDEEP);						
	prog_count++;
	put_value(prog_ptr, 0x0001);					
	prog_count += 2;
	
	// Ret subprogram
	put_commd(prog_ptr, CLOAD);						
	prog_count++;
	put_value(prog_ptr, ret);						
	prog_count += 2;
	put_commd(prog_ptr, CRET);						
	prog_count++;
	
	*prog_counter = prog_count;
}

void putNumberPre(yla_int_type **prog_ptr, yla_int_type subprog_start_addr, complianceRow *compliance, yla_int_type *prog_counter, yla_int_type global_var[])
{
	yla_int_type prog_count = *prog_counter;
	
	yla_int_type ret = global_var[0];
	yla_int_type i = global_var[1];
	
	complianceTableSetAddr(compliance, subprog_start_addr, prog_count);
	
	put_commd(prog_ptr, CSAVE);						
	prog_count++;
	put_value(prog_ptr, ret);						
	prog_count += 2;
	put_commd(prog_ptr, CPUSH);						
	prog_count++;
	put_value(prog_ptr, 0x0003);
	prog_count += 2;
	put_commd(prog_ptr, CSAVE);
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;

	put_commd(prog_ptr, CDUP);
	prog_count++;
	put_value(prog_ptr, 0x0003);
	prog_count += 2;
	put_commd(prog_ptr, CDUP);
	prog_count++;
	put_value(prog_ptr, 0x0003);
	prog_count += 2;
	put_commd(prog_ptr, CMULT);	
	prog_count++;
	put_commd(prog_ptr, CDEEP);
	prog_count++;
	put_value(prog_ptr, 0x0002);
	prog_count += 2;
	

	put_commd(prog_ptr, CDUP);	
	prog_count++;
	put_value(prog_ptr, 0x0003);
	prog_count += 2;
	put_commd(prog_ptr, CDUP);	
	prog_count++;
	put_value(prog_ptr, 0x0001);
	prog_count += 2;
	put_commd(prog_ptr, CMULT);
	prog_count++;
	put_commd(prog_ptr, CDEEP);
	prog_count++;
	put_value(prog_ptr, 0x0000);
	prog_count += 2;
	

	complianceTableSetAddr(compliance, 0x0081, prog_count);
	put_commd(prog_ptr, CLOAD);
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;
	put_commd(prog_ptr, CJZ);
	prog_count++;
	put_value(prog_ptr, 0x0089);
	prog_count += 2;

	put_commd(prog_ptr, CSTK);	
	prog_count++;
	put_value(prog_ptr, 0x0001);
	prog_count += 2;

	put_commd(prog_ptr, CLOAD);	
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;
	put_commd(prog_ptr, CPUSH);	
	prog_count++;
	put_value(prog_ptr, 0x0001);
	prog_count += 2;
	put_commd(prog_ptr, CSUB);	
	prog_count++;
	put_commd(prog_ptr, CSAVE);	
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;

	put_commd(prog_ptr, CGDUP);
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;

	put_commd(prog_ptr, CLOAD);	
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;
	put_commd(prog_ptr, CPUSH);
	prog_count++;
	put_value(prog_ptr, 0x0001);
	prog_count += 2;
	put_commd(prog_ptr, CADD);	
	prog_count++;
	put_commd(prog_ptr, CSAVE);	
	prog_count++;
	put_value(prog_ptr, i);	
	prog_count += 2;

	put_commd(prog_ptr, CGDEEP);
	prog_count++;
	put_value(prog_ptr, i);		
	prog_count += 2;
	

	put_commd(prog_ptr, CLOAD);	
	prog_count++;
	put_value(prog_ptr, i);		
	prog_count += 2;
	put_commd(prog_ptr, CPUSH);
	prog_count++;
	put_value(prog_ptr, 0x0001);
	prog_count += 2;
	put_commd(prog_ptr, CSUB);	
	prog_count++;
	put_commd(prog_ptr, CSAVE);
	prog_count++;
	put_value(prog_ptr, i);		
	prog_count += 2;
	

	put_commd(prog_ptr, CJMP);	
	prog_count++;
	put_value(prog_ptr, 0x0081);
	prog_count += 2;

	complianceTableSetAddr(compliance, 0x0089, prog_count);
	put_commd(prog_ptr, CSTK);
	prog_count++;
	put_value(prog_ptr, 0x0002);
	prog_count += 2;
	put_commd(prog_ptr, CLOAD);
	prog_count++;
	put_value(prog_ptr, ret);
	prog_count += 2;
	put_commd(prog_ptr, CRET);
	prog_count++;
	
	*prog_counter = prog_count;
}