#include "grammer.h"

GEN_FUN(is_keyword,(int)FUN,(int)ASG)
GEN_FUN(is_type, (int)I32,(int)ASG)
GEN_FUN(is_operator_infix,(int) ASG,(int) IN)
GEN_FUN(is_operator_assign,(int) ASG,(int) MNS) 
GEN_FUN(is_operator_arthimatic,(int) MNS,(int) GT)
GEN_FUN(is_operator_relational, (int) GT, (int) NEQ)
GEN_FUN(is_operator_logical, (int) NOT, (int) BNT)
GEN_FUN(is_operator_bitwise, (int) BNT, (int) SHR)
GEN_FUN(is_operator_membership, (int) IN, (int) PMS)
GEN_FUN(is_operator_unary, (int) PMS, (int) DOT)
GEN_FUN(is_operator_member_access, (int) DOT, (int) TCO)
GEN_FUN(is_operator_type_cast, (int) TCO, (int) ARW)
GEN_FUN(is_puctation, (int) ARW,(int) INT)
GEN_FUN(is_liter,(int) INT,(int) COLLECTION)
GEN_FUN(is_identifer,(int) ID,(int) EOF_)


