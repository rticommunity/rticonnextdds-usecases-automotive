

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from automotive.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "automotive.h"

/* ========================================================================= */
const char *POSIXTimestampTYPENAME = "POSIXTimestamp";

DDS_TypeCode* POSIXTimestamp_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member POSIXTimestamp_g_tc_members[2]=
    {

        {
            (char *)"s",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"ns",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode POSIXTimestamp_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"POSIXTimestamp", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            POSIXTimestamp_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for POSIXTimestamp*/

    if (is_initialized) {
        return &POSIXTimestamp_g_tc;
    }

    POSIXTimestamp_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    POSIXTimestamp_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &POSIXTimestamp_g_tc;
}

RTIBool POSIXTimestamp_initialize(
    POSIXTimestamp* sample) {
    return POSIXTimestamp_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool POSIXTimestamp_initialize_ex(
    POSIXTimestamp* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return POSIXTimestamp_initialize_w_params(
        sample,&allocParams);

}

RTIBool POSIXTimestamp_initialize_w_params(
    POSIXTimestamp* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initLong(&sample->s)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initLong(&sample->ns)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void POSIXTimestamp_finalize(
    POSIXTimestamp* sample)
{

    POSIXTimestamp_finalize_ex(sample,RTI_TRUE);
}

void POSIXTimestamp_finalize_ex(
    POSIXTimestamp* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    POSIXTimestamp_finalize_w_params(
        sample,&deallocParams);
}

void POSIXTimestamp_finalize_w_params(
    POSIXTimestamp* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void POSIXTimestamp_finalize_optional_members(
    POSIXTimestamp* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool POSIXTimestamp_copy(
    POSIXTimestamp* dst,
    const POSIXTimestamp* src)
{

    if (!RTICdrType_copyLong (
        &dst->s, &src->s)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->ns, &src->ns)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'POSIXTimestamp' sequence class.
*/
#define T POSIXTimestamp
#define TSeq POSIXTimestampSeq
#define T_initialize_w_params POSIXTimestamp_initialize_w_params
#define T_finalize_w_params   POSIXTimestamp_finalize_w_params
#define T_copy       POSIXTimestamp_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *IndicatorStatusEnumTYPENAME = "IndicatorStatusEnum";

DDS_TypeCode* IndicatorStatusEnum_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member IndicatorStatusEnum_g_tc_members[4]=
    {

        {
            (char *)"INDICATOR_OFF",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_OFF, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"INDICATOR_LEFT",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_LEFT, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"INDICATOR_RIGHT",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_RIGHT, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"INDICATOR_HAZARD",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_HAZARD, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode IndicatorStatusEnum_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"IndicatorStatusEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            IndicatorStatusEnum_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for IndicatorStatusEnum*/

    if (is_initialized) {
        return &IndicatorStatusEnum_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &IndicatorStatusEnum_g_tc;
}

RTIBool IndicatorStatusEnum_initialize(
    IndicatorStatusEnum* sample) {
    *sample = INDICATOR_OFF;
    return RTI_TRUE;
}

RTIBool IndicatorStatusEnum_initialize_ex(
    IndicatorStatusEnum* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return IndicatorStatusEnum_initialize_w_params(
        sample,&allocParams);

}

RTIBool IndicatorStatusEnum_initialize_w_params(
    IndicatorStatusEnum* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */
    *sample = INDICATOR_OFF;
    return RTI_TRUE;
}

void IndicatorStatusEnum_finalize(
    IndicatorStatusEnum* sample)
{

    if (sample==NULL) {
        return;
    }
}

void IndicatorStatusEnum_finalize_ex(
    IndicatorStatusEnum* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    IndicatorStatusEnum_finalize_w_params(
        sample,&deallocParams);
}

void IndicatorStatusEnum_finalize_w_params(
    IndicatorStatusEnum* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void IndicatorStatusEnum_finalize_optional_members(
    IndicatorStatusEnum* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool IndicatorStatusEnum_copy(
    IndicatorStatusEnum* dst,
    const IndicatorStatusEnum* src)
{

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'IndicatorStatusEnum' sequence class.
*/
#define T IndicatorStatusEnum
#define TSeq IndicatorStatusEnumSeq
#define T_initialize_w_params IndicatorStatusEnum_initialize_w_params
#define T_finalize_w_params   IndicatorStatusEnum_finalize_w_params
#define T_copy       IndicatorStatusEnum_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *ClassificationEnumTYPENAME = "ClassificationEnum";

DDS_TypeCode* ClassificationEnum_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ClassificationEnum_g_tc_members[8]=
    {

        {
            (char *)"CLASSIFICATION_UNKNOWN",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_UNKNOWN, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_UNKNOWNSMALL",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_UNKNOWNSMALL, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_UNKNOWNBIG",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_UNKNOWNBIG, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_PEDESTRIAN",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_PEDESTRIAN, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_BIKE",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_BIKE, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_CAR",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_CAR, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_TRUCK",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_TRUCK, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CLASSIFICATION_BARRIER",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_BARRIER, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode ClassificationEnum_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ClassificationEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            8, /* Number of members */
            ClassificationEnum_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for ClassificationEnum*/

    if (is_initialized) {
        return &ClassificationEnum_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &ClassificationEnum_g_tc;
}

RTIBool ClassificationEnum_initialize(
    ClassificationEnum* sample) {
    *sample = CLASSIFICATION_UNKNOWN;
    return RTI_TRUE;
}

RTIBool ClassificationEnum_initialize_ex(
    ClassificationEnum* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ClassificationEnum_initialize_w_params(
        sample,&allocParams);

}

RTIBool ClassificationEnum_initialize_w_params(
    ClassificationEnum* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */
    *sample = CLASSIFICATION_UNKNOWN;
    return RTI_TRUE;
}

void ClassificationEnum_finalize(
    ClassificationEnum* sample)
{

    if (sample==NULL) {
        return;
    }
}

void ClassificationEnum_finalize_ex(
    ClassificationEnum* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ClassificationEnum_finalize_w_params(
        sample,&deallocParams);
}

void ClassificationEnum_finalize_w_params(
    ClassificationEnum* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void ClassificationEnum_finalize_optional_members(
    ClassificationEnum* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ClassificationEnum_copy(
    ClassificationEnum* dst,
    const ClassificationEnum* src)
{

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ClassificationEnum' sequence class.
*/
#define T ClassificationEnum
#define TSeq ClassificationEnumSeq
#define T_initialize_w_params ClassificationEnum_initialize_w_params
#define T_finalize_w_params   ClassificationEnum_finalize_w_params
#define T_copy       ClassificationEnum_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Alerts_DriverAlertsTYPENAME = "Alerts::DriverAlerts";

DDS_TypeCode* Alerts_DriverAlerts_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Alerts_DriverAlerts_g_tc_members[6]=
    {

        {
            (char *)"blindSpotDriver",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"blindSpotPassenger",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"frontCollision",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"backCollision",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"parkingCollision",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"driverAttention",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Alerts_DriverAlerts_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Alerts::DriverAlerts", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            Alerts_DriverAlerts_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Alerts_DriverAlerts*/

    if (is_initialized) {
        return &Alerts_DriverAlerts_g_tc;
    }

    Alerts_DriverAlerts_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    Alerts_DriverAlerts_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    Alerts_DriverAlerts_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    Alerts_DriverAlerts_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    Alerts_DriverAlerts_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    Alerts_DriverAlerts_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    is_initialized = RTI_TRUE;

    return &Alerts_DriverAlerts_g_tc;
}

RTIBool Alerts_DriverAlerts_initialize(
    Alerts_DriverAlerts* sample) {
    return Alerts_DriverAlerts_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Alerts_DriverAlerts_initialize_ex(
    Alerts_DriverAlerts* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Alerts_DriverAlerts_initialize_w_params(
        sample,&allocParams);

}

RTIBool Alerts_DriverAlerts_initialize_w_params(
    Alerts_DriverAlerts* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initBoolean(&sample->blindSpotDriver)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->blindSpotPassenger)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->frontCollision)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->backCollision)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->parkingCollision)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initBoolean(&sample->driverAttention)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void Alerts_DriverAlerts_finalize(
    Alerts_DriverAlerts* sample)
{

    Alerts_DriverAlerts_finalize_ex(sample,RTI_TRUE);
}

void Alerts_DriverAlerts_finalize_ex(
    Alerts_DriverAlerts* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Alerts_DriverAlerts_finalize_w_params(
        sample,&deallocParams);
}

void Alerts_DriverAlerts_finalize_w_params(
    Alerts_DriverAlerts* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void Alerts_DriverAlerts_finalize_optional_members(
    Alerts_DriverAlerts* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Alerts_DriverAlerts_copy(
    Alerts_DriverAlerts* dst,
    const Alerts_DriverAlerts* src)
{

    if (!RTICdrType_copyBoolean (
        &dst->blindSpotDriver, &src->blindSpotDriver)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->blindSpotPassenger, &src->blindSpotPassenger)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->frontCollision, &src->frontCollision)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->backCollision, &src->backCollision)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->parkingCollision, &src->parkingCollision)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyBoolean (
        &dst->driverAttention, &src->driverAttention)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Alerts_DriverAlerts' sequence class.
*/
#define T Alerts_DriverAlerts
#define TSeq Alerts_DriverAlertsSeq
#define T_initialize_w_params Alerts_DriverAlerts_initialize_w_params
#define T_finalize_w_params   Alerts_DriverAlerts_finalize_w_params
#define T_copy       Alerts_DriverAlerts_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lane_ConfidenceEnumTYPENAME = "Lane::ConfidenceEnum";

DDS_TypeCode* Lane_ConfidenceEnum_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Lane_ConfidenceEnum_g_tc_members[4]=
    {

        {
            (char *)"CONFIDENCE_NONE",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_NONE, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CONFIDENCE_LOW",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_LOW, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CONFIDENCE_MED",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_MED, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"CONFIDENCE_HIGH",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_HIGH, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lane_ConfidenceEnum_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::ConfidenceEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Lane_ConfidenceEnum_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for Lane_ConfidenceEnum*/

    if (is_initialized) {
        return &Lane_ConfidenceEnum_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &Lane_ConfidenceEnum_g_tc;
}

RTIBool Lane_ConfidenceEnum_initialize(
    Lane_ConfidenceEnum* sample) {
    *sample = CONFIDENCE_NONE;
    return RTI_TRUE;
}

RTIBool Lane_ConfidenceEnum_initialize_ex(
    Lane_ConfidenceEnum* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lane_ConfidenceEnum_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lane_ConfidenceEnum_initialize_w_params(
    Lane_ConfidenceEnum* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */
    *sample = CONFIDENCE_NONE;
    return RTI_TRUE;
}

void Lane_ConfidenceEnum_finalize(
    Lane_ConfidenceEnum* sample)
{

    if (sample==NULL) {
        return;
    }
}

void Lane_ConfidenceEnum_finalize_ex(
    Lane_ConfidenceEnum* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lane_ConfidenceEnum_finalize_w_params(
        sample,&deallocParams);
}

void Lane_ConfidenceEnum_finalize_w_params(
    Lane_ConfidenceEnum* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void Lane_ConfidenceEnum_finalize_optional_members(
    Lane_ConfidenceEnum* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Lane_ConfidenceEnum_copy(
    Lane_ConfidenceEnum* dst,
    const Lane_ConfidenceEnum* src)
{

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lane_ConfidenceEnum' sequence class.
*/
#define T Lane_ConfidenceEnum
#define TSeq Lane_ConfidenceEnumSeq
#define T_initialize_w_params Lane_ConfidenceEnum_initialize_w_params
#define T_finalize_w_params   Lane_ConfidenceEnum_finalize_w_params
#define T_copy       Lane_ConfidenceEnum_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lane_LaneBoundaryEnumTYPENAME = "Lane::LaneBoundaryEnum";

DDS_TypeCode* Lane_LaneBoundaryEnum_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Lane_LaneBoundaryEnum_g_tc_members[9]=
    {

        {
            (char *)"BOUNDRY_NONE",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_NONE, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_INVALID",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_INVALID, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_SOLID",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_SOLID, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_DASHED",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_DASHED, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_VIRTUAL",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_VIRTUAL, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_DOTS",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_DOTS, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_ROADEDGE",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_ROADEDGE, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_UNDECIDED",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_UNDECIDED, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"BOUNDRY_DOUBLEMARKER",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_DOUBLEMARKER, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lane_LaneBoundaryEnum_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::LaneBoundaryEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            9, /* Number of members */
            Lane_LaneBoundaryEnum_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for Lane_LaneBoundaryEnum*/

    if (is_initialized) {
        return &Lane_LaneBoundaryEnum_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &Lane_LaneBoundaryEnum_g_tc;
}

RTIBool Lane_LaneBoundaryEnum_initialize(
    Lane_LaneBoundaryEnum* sample) {
    *sample = BOUNDRY_NONE;
    return RTI_TRUE;
}

RTIBool Lane_LaneBoundaryEnum_initialize_ex(
    Lane_LaneBoundaryEnum* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lane_LaneBoundaryEnum_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lane_LaneBoundaryEnum_initialize_w_params(
    Lane_LaneBoundaryEnum* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */
    *sample = BOUNDRY_NONE;
    return RTI_TRUE;
}

void Lane_LaneBoundaryEnum_finalize(
    Lane_LaneBoundaryEnum* sample)
{

    if (sample==NULL) {
        return;
    }
}

void Lane_LaneBoundaryEnum_finalize_ex(
    Lane_LaneBoundaryEnum* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lane_LaneBoundaryEnum_finalize_w_params(
        sample,&deallocParams);
}

void Lane_LaneBoundaryEnum_finalize_w_params(
    Lane_LaneBoundaryEnum* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void Lane_LaneBoundaryEnum_finalize_optional_members(
    Lane_LaneBoundaryEnum* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Lane_LaneBoundaryEnum_copy(
    Lane_LaneBoundaryEnum* dst,
    const Lane_LaneBoundaryEnum* src)
{

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lane_LaneBoundaryEnum' sequence class.
*/
#define T Lane_LaneBoundaryEnum
#define TSeq Lane_LaneBoundaryEnumSeq
#define T_initialize_w_params Lane_LaneBoundaryEnum_initialize_w_params
#define T_finalize_w_params   Lane_LaneBoundaryEnum_finalize_w_params
#define T_copy       Lane_LaneBoundaryEnum_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lane_LaneObjectTYPENAME = "Lane::LaneObject";

DDS_TypeCode* Lane_LaneObject_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Lane_LaneObject_g_tc_members[6]=
    {

        {
            (char *)"isValid",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"confidence",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"boundaryType",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"offset",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"headingAngle",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"curvature",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lane_LaneObject_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::LaneObject", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            Lane_LaneObject_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Lane_LaneObject*/

    if (is_initialized) {
        return &Lane_LaneObject_g_tc;
    }

    Lane_LaneObject_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    Lane_LaneObject_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Lane_ConfidenceEnum_get_typecode();

    Lane_LaneObject_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)Lane_LaneBoundaryEnum_get_typecode();

    Lane_LaneObject_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Lane_LaneObject_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Lane_LaneObject_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    is_initialized = RTI_TRUE;

    return &Lane_LaneObject_g_tc;
}

RTIBool Lane_LaneObject_initialize(
    Lane_LaneObject* sample) {
    return Lane_LaneObject_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Lane_LaneObject_initialize_ex(
    Lane_LaneObject* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lane_LaneObject_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lane_LaneObject_initialize_w_params(
    Lane_LaneObject* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initBoolean(&sample->isValid)) {
        return RTI_FALSE;
    }     

    if (!Lane_ConfidenceEnum_initialize_w_params(&sample->confidence,
    allocParams)) {
        return RTI_FALSE;
    }
    if (!Lane_LaneBoundaryEnum_initialize_w_params(&sample->boundaryType,
    allocParams)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->offset)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->headingAngle)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->curvature)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void Lane_LaneObject_finalize(
    Lane_LaneObject* sample)
{

    Lane_LaneObject_finalize_ex(sample,RTI_TRUE);
}

void Lane_LaneObject_finalize_ex(
    Lane_LaneObject* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lane_LaneObject_finalize_w_params(
        sample,&deallocParams);
}

void Lane_LaneObject_finalize_w_params(
    Lane_LaneObject* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    Lane_ConfidenceEnum_finalize_w_params(&sample->confidence,deallocParams);

    Lane_LaneBoundaryEnum_finalize_w_params(&sample->boundaryType,deallocParams);

}

void Lane_LaneObject_finalize_optional_members(
    Lane_LaneObject* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    Lane_ConfidenceEnum_finalize_optional_members(&sample->confidence, deallocParams->delete_pointers);
    Lane_LaneBoundaryEnum_finalize_optional_members(&sample->boundaryType, deallocParams->delete_pointers);
}

RTIBool Lane_LaneObject_copy(
    Lane_LaneObject* dst,
    const Lane_LaneObject* src)
{

    if (!RTICdrType_copyBoolean (
        &dst->isValid, &src->isValid)) { 
        return RTI_FALSE;
    }
    if (!Lane_ConfidenceEnum_copy(
        &dst->confidence, &src->confidence)) {
        return RTI_FALSE;
    } 
    if (!Lane_LaneBoundaryEnum_copy(
        &dst->boundaryType, &src->boundaryType)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyFloat (
        &dst->offset, &src->offset)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->headingAngle, &src->headingAngle)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->curvature, &src->curvature)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lane_LaneObject' sequence class.
*/
#define T Lane_LaneObject
#define TSeq Lane_LaneObjectSeq
#define T_initialize_w_params Lane_LaneObject_initialize_w_params
#define T_finalize_w_params   Lane_LaneObject_finalize_w_params
#define T_copy       Lane_LaneObject_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lane_LaneSensorTYPENAME = "Lane::LaneSensor";

DDS_TypeCode* Lane_LaneSensor_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Lane_LaneSensor_g_tc_members[2]=
    {

        {
            (char *)"left",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"right",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lane_LaneSensor_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::LaneSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Lane_LaneSensor_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Lane_LaneSensor*/

    if (is_initialized) {
        return &Lane_LaneSensor_g_tc;
    }

    Lane_LaneSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)Lane_LaneObject_get_typecode();

    Lane_LaneSensor_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Lane_LaneObject_get_typecode();

    is_initialized = RTI_TRUE;

    return &Lane_LaneSensor_g_tc;
}

RTIBool Lane_LaneSensor_initialize(
    Lane_LaneSensor* sample) {
    return Lane_LaneSensor_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Lane_LaneSensor_initialize_ex(
    Lane_LaneSensor* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lane_LaneSensor_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lane_LaneSensor_initialize_w_params(
    Lane_LaneSensor* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!Lane_LaneObject_initialize_w_params(&sample->left,
    allocParams)) {
        return RTI_FALSE;
    }
    if (!Lane_LaneObject_initialize_w_params(&sample->right,
    allocParams)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Lane_LaneSensor_finalize(
    Lane_LaneSensor* sample)
{

    Lane_LaneSensor_finalize_ex(sample,RTI_TRUE);
}

void Lane_LaneSensor_finalize_ex(
    Lane_LaneSensor* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lane_LaneSensor_finalize_w_params(
        sample,&deallocParams);
}

void Lane_LaneSensor_finalize_w_params(
    Lane_LaneSensor* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    Lane_LaneObject_finalize_w_params(&sample->left,deallocParams);

    Lane_LaneObject_finalize_w_params(&sample->right,deallocParams);

}

void Lane_LaneSensor_finalize_optional_members(
    Lane_LaneSensor* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    Lane_LaneObject_finalize_optional_members(&sample->left, deallocParams->delete_pointers);
    Lane_LaneObject_finalize_optional_members(&sample->right, deallocParams->delete_pointers);
}

RTIBool Lane_LaneSensor_copy(
    Lane_LaneSensor* dst,
    const Lane_LaneSensor* src)
{

    if (!Lane_LaneObject_copy(
        &dst->left, &src->left)) {
        return RTI_FALSE;
    } 
    if (!Lane_LaneObject_copy(
        &dst->right, &src->right)) {
        return RTI_FALSE;
    } 

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lane_LaneSensor' sequence class.
*/
#define T Lane_LaneSensor
#define TSeq Lane_LaneSensorSeq
#define T_initialize_w_params Lane_LaneSensor_initialize_w_params
#define T_finalize_w_params   Lane_LaneSensor_finalize_w_params
#define T_copy       Lane_LaneSensor_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lidar_PointTYPENAME = "Lidar::Point";

DDS_TypeCode* Lidar_Point_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Lidar_Point_g_tc_point_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode_Member Lidar_Point_g_tc_members[1]=
    {

        {
            (char *)"point",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lidar_Point_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lidar::Point", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            Lidar_Point_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Lidar_Point*/

    if (is_initialized) {
        return &Lidar_Point_g_tc;
    }

    Lidar_Point_g_tc_point_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Lidar_Point_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& Lidar_Point_g_tc_point_array;

    is_initialized = RTI_TRUE;

    return &Lidar_Point_g_tc;
}

RTIBool Lidar_Point_initialize(
    Lidar_Point* sample) {
    return Lidar_Point_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Lidar_Point_initialize_ex(
    Lidar_Point* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lidar_Point_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lidar_Point_initialize_w_params(
    Lidar_Point* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initArray(
        sample->point, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Lidar_Point_finalize(
    Lidar_Point* sample)
{

    Lidar_Point_finalize_ex(sample,RTI_TRUE);
}

void Lidar_Point_finalize_ex(
    Lidar_Point* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lidar_Point_finalize_w_params(
        sample,&deallocParams);
}

void Lidar_Point_finalize_w_params(
    Lidar_Point* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void Lidar_Point_finalize_optional_members(
    Lidar_Point* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Lidar_Point_copy(
    Lidar_Point* dst,
    const Lidar_Point* src)
{

    if (!RTICdrType_copyArray(
        dst->point ,src->point,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lidar_Point' sequence class.
*/
#define T Lidar_Point
#define TSeq Lidar_PointSeq
#define T_initialize_w_params Lidar_Point_initialize_w_params
#define T_finalize_w_params   Lidar_Point_finalize_w_params
#define T_copy       Lidar_Point_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lidar_PCloudTYPENAME = "Lidar::PCloud";

DDS_TypeCode* Lidar_PCloud_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Lidar_PCloud_g_tc_Location_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((Lidar_MAX_POINTS)),NULL);
    static DDS_TypeCode Lidar_PCloud_g_tc_xLimits_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,2, NULL,NULL);
    static DDS_TypeCode Lidar_PCloud_g_tc_yLimits_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,2, NULL,NULL);
    static DDS_TypeCode Lidar_PCloud_g_tc_zLimits_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,2, NULL,NULL);
    static DDS_TypeCode_Member Lidar_PCloud_g_tc_members[8]=
    {

        {
            (char *)"Location",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"color",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"normal",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"intensity",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"count",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"xLimits",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"yLimits",/* Member name */
            {
                6,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"zLimits",/* Member name */
            {
                7,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lidar_PCloud_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lidar::PCloud", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            8, /* Number of members */
            Lidar_PCloud_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Lidar_PCloud*/

    if (is_initialized) {
        return &Lidar_PCloud_g_tc;
    }

    Lidar_PCloud_g_tc_Location_sequence._data._typeCode = (RTICdrTypeCode *)Lidar_Point_get_typecode();

    Lidar_PCloud_g_tc_xLimits_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Lidar_PCloud_g_tc_yLimits_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Lidar_PCloud_g_tc_zLimits_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Lidar_PCloud_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_Location_sequence;
    Lidar_PCloud_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

    Lidar_PCloud_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Lidar_PCloud_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Lidar_PCloud_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    Lidar_PCloud_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_xLimits_array;
    Lidar_PCloud_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_yLimits_array;
    Lidar_PCloud_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_zLimits_array;

    is_initialized = RTI_TRUE;

    return &Lidar_PCloud_g_tc;
}

RTIBool Lidar_PCloud_initialize(
    Lidar_PCloud* sample) {
    return Lidar_PCloud_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Lidar_PCloud_initialize_ex(
    Lidar_PCloud* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lidar_PCloud_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lidar_PCloud_initialize_w_params(
    Lidar_PCloud* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (allocParams) {} /* To avoid warnings */

    if (allocParams->allocate_memory) {
        Lidar_PointSeq_initialize(&sample->Location );
        Lidar_PointSeq_set_element_allocation_params(&sample->Location ,allocParams);
        if (!Lidar_PointSeq_set_maximum(&sample->Location, ((Lidar_MAX_POINTS)))) {
            return RTI_FALSE;
        }
    } else { 
        Lidar_PointSeq_set_length(&sample->Location, 0);
    }

    if (!RTICdrType_initOctet(&sample->color)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->normal)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->intensity)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initLong(&sample->count)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initArray(
        sample->xLimits, (2), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->yLimits, (2), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->zLimits, (2), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Lidar_PCloud_finalize(
    Lidar_PCloud* sample)
{

    Lidar_PCloud_finalize_ex(sample,RTI_TRUE);
}

void Lidar_PCloud_finalize_ex(
    Lidar_PCloud* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lidar_PCloud_finalize_w_params(
        sample,&deallocParams);
}

void Lidar_PCloud_finalize_w_params(
    Lidar_PCloud* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    Lidar_PointSeq_set_element_deallocation_params(
        &sample->Location,deallocParams);
    Lidar_PointSeq_finalize(&sample->Location);

}

void Lidar_PCloud_finalize_optional_members(
    Lidar_PCloud* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    {
        DDS_UnsignedLong i, length;
        length = Lidar_PointSeq_get_length(
            &sample->Location);

        for (i = 0; i < length; i++) {
            Lidar_Point_finalize_optional_members(
                Lidar_PointSeq_get_reference(
                    &sample->Location, i), deallocParams->delete_pointers);
        }
    }  

}

RTIBool Lidar_PCloud_copy(
    Lidar_PCloud* dst,
    const Lidar_PCloud* src)
{

    if (!Lidar_PointSeq_copy(&dst->Location ,
    &src->Location )) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyOctet (
        &dst->color, &src->color)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->normal, &src->normal)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->intensity, &src->intensity)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->count, &src->count)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->xLimits ,src->xLimits,(2), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->yLimits ,src->yLimits,(2), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->zLimits ,src->zLimits,(2), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lidar_PCloud' sequence class.
*/
#define T Lidar_PCloud
#define TSeq Lidar_PCloudSeq
#define T_initialize_w_params Lidar_PCloud_initialize_w_params
#define T_finalize_w_params   Lidar_PCloud_finalize_w_params
#define T_copy       Lidar_PCloud_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Lidar_LidarSensorTYPENAME = "Lidar::LidarSensor";

DDS_TypeCode* Lidar_LidarSensor_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Lidar_LidarSensor_g_tc_members[2]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"ptCloud",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Lidar_LidarSensor_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lidar::LidarSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Lidar_LidarSensor_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Lidar_LidarSensor*/

    if (is_initialized) {
        return &Lidar_LidarSensor_g_tc;
    }

    Lidar_LidarSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();

    Lidar_LidarSensor_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Lidar_PCloud_get_typecode();

    is_initialized = RTI_TRUE;

    return &Lidar_LidarSensor_g_tc;
}

RTIBool Lidar_LidarSensor_initialize(
    Lidar_LidarSensor* sample) {
    return Lidar_LidarSensor_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Lidar_LidarSensor_initialize_ex(
    Lidar_LidarSensor* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Lidar_LidarSensor_initialize_w_params(
        sample,&allocParams);

}

RTIBool Lidar_LidarSensor_initialize_w_params(
    Lidar_LidarSensor* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }
    if (!Lidar_PCloud_initialize_w_params(&sample->ptCloud,
    allocParams)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Lidar_LidarSensor_finalize(
    Lidar_LidarSensor* sample)
{

    Lidar_LidarSensor_finalize_ex(sample,RTI_TRUE);
}

void Lidar_LidarSensor_finalize_ex(
    Lidar_LidarSensor* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Lidar_LidarSensor_finalize_w_params(
        sample,&deallocParams);
}

void Lidar_LidarSensor_finalize_w_params(
    Lidar_LidarSensor* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    Lidar_PCloud_finalize_w_params(&sample->ptCloud,deallocParams);

}

void Lidar_LidarSensor_finalize_optional_members(
    Lidar_LidarSensor* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    POSIXTimestamp_finalize_optional_members(&sample->timestamp, deallocParams->delete_pointers);
    Lidar_PCloud_finalize_optional_members(&sample->ptCloud, deallocParams->delete_pointers);
}

RTIBool Lidar_LidarSensor_copy(
    Lidar_LidarSensor* dst,
    const Lidar_LidarSensor* src)
{

    if (!POSIXTimestamp_copy(
        &dst->timestamp, &src->timestamp)) {
        return RTI_FALSE;
    } 
    if (!Lidar_PCloud_copy(
        &dst->ptCloud, &src->ptCloud)) {
        return RTI_FALSE;
    } 

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Lidar_LidarSensor' sequence class.
*/
#define T Lidar_LidarSensor
#define TSeq Lidar_LidarSensorSeq
#define T_initialize_w_params Lidar_LidarSensor_initialize_w_params
#define T_finalize_w_params   Lidar_LidarSensor_finalize_w_params
#define T_copy       Lidar_LidarSensor_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Platform_PlatformControlTYPENAME = "Platform::PlatformControl";

DDS_TypeCode* Platform_PlatformControl_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Platform_PlatformControl_g_tc_members[5]=
    {

        {
            (char *)"sample_id",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"timestamp",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"vehicleSteerAngle",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"speed",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"blinkerStatus",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Platform_PlatformControl_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Platform::PlatformControl", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            5, /* Number of members */
            Platform_PlatformControl_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Platform_PlatformControl*/

    if (is_initialized) {
        return &Platform_PlatformControl_g_tc;
    }

    Platform_PlatformControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    Platform_PlatformControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();

    Platform_PlatformControl_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Platform_PlatformControl_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Platform_PlatformControl_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)IndicatorStatusEnum_get_typecode();

    is_initialized = RTI_TRUE;

    return &Platform_PlatformControl_g_tc;
}

RTIBool Platform_PlatformControl_initialize(
    Platform_PlatformControl* sample) {
    return Platform_PlatformControl_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Platform_PlatformControl_initialize_ex(
    Platform_PlatformControl* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Platform_PlatformControl_initialize_w_params(
        sample,&allocParams);

}

RTIBool Platform_PlatformControl_initialize_w_params(
    Platform_PlatformControl* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initLong(&sample->sample_id)) {
        return RTI_FALSE;
    }     

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->vehicleSteerAngle)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->speed)) {
        return RTI_FALSE;
    }     

    if (!IndicatorStatusEnum_initialize_w_params(&sample->blinkerStatus,
    allocParams)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Platform_PlatformControl_finalize(
    Platform_PlatformControl* sample)
{

    Platform_PlatformControl_finalize_ex(sample,RTI_TRUE);
}

void Platform_PlatformControl_finalize_ex(
    Platform_PlatformControl* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Platform_PlatformControl_finalize_w_params(
        sample,&deallocParams);
}

void Platform_PlatformControl_finalize_w_params(
    Platform_PlatformControl* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    IndicatorStatusEnum_finalize_w_params(&sample->blinkerStatus,deallocParams);

}

void Platform_PlatformControl_finalize_optional_members(
    Platform_PlatformControl* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    POSIXTimestamp_finalize_optional_members(&sample->timestamp, deallocParams->delete_pointers);
    IndicatorStatusEnum_finalize_optional_members(&sample->blinkerStatus, deallocParams->delete_pointers);
}

RTIBool Platform_PlatformControl_copy(
    Platform_PlatformControl* dst,
    const Platform_PlatformControl* src)
{

    if (!RTICdrType_copyLong (
        &dst->sample_id, &src->sample_id)) { 
        return RTI_FALSE;
    }
    if (!POSIXTimestamp_copy(
        &dst->timestamp, &src->timestamp)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyFloat (
        &dst->vehicleSteerAngle, &src->vehicleSteerAngle)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->speed, &src->speed)) { 
        return RTI_FALSE;
    }
    if (!IndicatorStatusEnum_copy(
        &dst->blinkerStatus, &src->blinkerStatus)) {
        return RTI_FALSE;
    } 

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Platform_PlatformControl' sequence class.
*/
#define T Platform_PlatformControl
#define TSeq Platform_PlatformControlSeq
#define T_initialize_w_params Platform_PlatformControl_initialize_w_params
#define T_finalize_w_params   Platform_PlatformControl_finalize_w_params
#define T_copy       Platform_PlatformControl_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Platform_PlatformStatusTYPENAME = "Platform::PlatformStatus";

DDS_TypeCode* Platform_PlatformStatus_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Platform_PlatformStatus_g_tc_members[7]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"vehSpd",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"blinkerStatus",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"posGasPedal",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"velocity",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"yawRate",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"vehicleSteerAngle",/* Member name */
            {
                6,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Platform_PlatformStatus_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Platform::PlatformStatus", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            7, /* Number of members */
            Platform_PlatformStatus_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Platform_PlatformStatus*/

    if (is_initialized) {
        return &Platform_PlatformStatus_g_tc;
    }

    Platform_PlatformStatus_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();

    Platform_PlatformStatus_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Platform_PlatformStatus_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)IndicatorStatusEnum_get_typecode();

    Platform_PlatformStatus_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Platform_PlatformStatus_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Platform_PlatformStatus_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Platform_PlatformStatus_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    is_initialized = RTI_TRUE;

    return &Platform_PlatformStatus_g_tc;
}

RTIBool Platform_PlatformStatus_initialize(
    Platform_PlatformStatus* sample) {
    return Platform_PlatformStatus_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Platform_PlatformStatus_initialize_ex(
    Platform_PlatformStatus* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Platform_PlatformStatus_initialize_w_params(
        sample,&allocParams);

}

RTIBool Platform_PlatformStatus_initialize_w_params(
    Platform_PlatformStatus* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->vehSpd)) {
        return RTI_FALSE;
    }     

    if (!IndicatorStatusEnum_initialize_w_params(&sample->blinkerStatus,
    allocParams)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->posGasPedal)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->velocity)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->yawRate)) {
        return RTI_FALSE;
    }     

    if (!RTICdrType_initFloat(&sample->vehicleSteerAngle)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void Platform_PlatformStatus_finalize(
    Platform_PlatformStatus* sample)
{

    Platform_PlatformStatus_finalize_ex(sample,RTI_TRUE);
}

void Platform_PlatformStatus_finalize_ex(
    Platform_PlatformStatus* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Platform_PlatformStatus_finalize_w_params(
        sample,&deallocParams);
}

void Platform_PlatformStatus_finalize_w_params(
    Platform_PlatformStatus* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    IndicatorStatusEnum_finalize_w_params(&sample->blinkerStatus,deallocParams);

}

void Platform_PlatformStatus_finalize_optional_members(
    Platform_PlatformStatus* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    POSIXTimestamp_finalize_optional_members(&sample->timestamp, deallocParams->delete_pointers);
    IndicatorStatusEnum_finalize_optional_members(&sample->blinkerStatus, deallocParams->delete_pointers);
}

RTIBool Platform_PlatformStatus_copy(
    Platform_PlatformStatus* dst,
    const Platform_PlatformStatus* src)
{

    if (!POSIXTimestamp_copy(
        &dst->timestamp, &src->timestamp)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyFloat (
        &dst->vehSpd, &src->vehSpd)) { 
        return RTI_FALSE;
    }
    if (!IndicatorStatusEnum_copy(
        &dst->blinkerStatus, &src->blinkerStatus)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyFloat (
        &dst->posGasPedal, &src->posGasPedal)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->velocity, &src->velocity)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->yawRate, &src->yawRate)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->vehicleSteerAngle, &src->vehicleSteerAngle)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Platform_PlatformStatus' sequence class.
*/
#define T Platform_PlatformStatus
#define TSeq Platform_PlatformStatusSeq
#define T_initialize_w_params Platform_PlatformStatus_initialize_w_params
#define T_finalize_w_params   Platform_PlatformStatus_finalize_w_params
#define T_copy       Platform_PlatformStatus_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Sensor_RangeModeEnumTYPENAME = "Sensor::RangeModeEnum";

DDS_TypeCode* Sensor_RangeModeEnum_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Sensor_RangeModeEnum_g_tc_members[4]=
    {

        {
            (char *)"RANGE_NONE",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_NONE, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"RANGE_SHORT",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_SHORT, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"RANGE_MEDIUM",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_MEDIUM, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"RANGE_LONG",/* Member name */
            {
                0, /* Ignored */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_LONG, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Sensor_RangeModeEnum_g_tc =
    {{
            DDS_TK_ENUM,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Sensor::RangeModeEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Sensor_RangeModeEnum_g_tc_members, /* Members */
            DDS_VM_NONE   /* Type Modifier */        
        }}; /* Type code for Sensor_RangeModeEnum*/

    if (is_initialized) {
        return &Sensor_RangeModeEnum_g_tc;
    }

    is_initialized = RTI_TRUE;

    return &Sensor_RangeModeEnum_g_tc;
}

RTIBool Sensor_RangeModeEnum_initialize(
    Sensor_RangeModeEnum* sample) {
    *sample = RANGE_NONE;
    return RTI_TRUE;
}

RTIBool Sensor_RangeModeEnum_initialize_ex(
    Sensor_RangeModeEnum* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Sensor_RangeModeEnum_initialize_w_params(
        sample,&allocParams);

}

RTIBool Sensor_RangeModeEnum_initialize_w_params(
    Sensor_RangeModeEnum* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */
    *sample = RANGE_NONE;
    return RTI_TRUE;
}

void Sensor_RangeModeEnum_finalize(
    Sensor_RangeModeEnum* sample)
{

    if (sample==NULL) {
        return;
    }
}

void Sensor_RangeModeEnum_finalize_ex(
    Sensor_RangeModeEnum* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Sensor_RangeModeEnum_finalize_w_params(
        sample,&deallocParams);
}

void Sensor_RangeModeEnum_finalize_w_params(
    Sensor_RangeModeEnum* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

}

void Sensor_RangeModeEnum_finalize_optional_members(
    Sensor_RangeModeEnum* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Sensor_RangeModeEnum_copy(
    Sensor_RangeModeEnum* dst,
    const Sensor_RangeModeEnum* src)
{

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Sensor_RangeModeEnum' sequence class.
*/
#define T Sensor_RangeModeEnum
#define TSeq Sensor_RangeModeEnumSeq
#define T_initialize_w_params Sensor_RangeModeEnum_initialize_w_params
#define T_finalize_w_params   Sensor_RangeModeEnum_finalize_w_params
#define T_copy       Sensor_RangeModeEnum_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Sensor_SensorObjectTYPENAME = "Sensor::SensorObject";

DDS_TypeCode* Sensor_SensorObject_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Sensor_SensorObject_g_tc_position_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode Sensor_SensorObject_g_tc_velocity_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode Sensor_SensorObject_g_tc_size_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode_Member Sensor_SensorObject_g_tc_members[7]=
    {

        {
            (char *)"classification",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"position",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"velocity",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"size",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"amplitude",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"rangeMode",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"rangeRate",/* Member name */
            {
                6,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Sensor_SensorObject_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Sensor::SensorObject", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            7, /* Number of members */
            Sensor_SensorObject_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Sensor_SensorObject*/

    if (is_initialized) {
        return &Sensor_SensorObject_g_tc;
    }

    Sensor_SensorObject_g_tc_position_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Sensor_SensorObject_g_tc_velocity_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Sensor_SensorObject_g_tc_size_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Sensor_SensorObject_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ClassificationEnum_get_typecode();

    Sensor_SensorObject_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObject_g_tc_position_array;
    Sensor_SensorObject_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObject_g_tc_velocity_array;
    Sensor_SensorObject_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObject_g_tc_size_array;
    Sensor_SensorObject_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    Sensor_SensorObject_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)Sensor_RangeModeEnum_get_typecode();

    Sensor_SensorObject_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    is_initialized = RTI_TRUE;

    return &Sensor_SensorObject_g_tc;
}

RTIBool Sensor_SensorObject_initialize(
    Sensor_SensorObject* sample) {
    return Sensor_SensorObject_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Sensor_SensorObject_initialize_ex(
    Sensor_SensorObject* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Sensor_SensorObject_initialize_w_params(
        sample,&allocParams);

}

RTIBool Sensor_SensorObject_initialize_w_params(
    Sensor_SensorObject* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!ClassificationEnum_initialize_w_params(&sample->classification,
    allocParams)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->position, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->velocity, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->size, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->amplitude)) {
        return RTI_FALSE;
    }     

    if (!Sensor_RangeModeEnum_initialize_w_params(&sample->rangeMode,
    allocParams)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->rangeRate)) {
        return RTI_FALSE;
    }     

    return RTI_TRUE;
}

void Sensor_SensorObject_finalize(
    Sensor_SensorObject* sample)
{

    Sensor_SensorObject_finalize_ex(sample,RTI_TRUE);
}

void Sensor_SensorObject_finalize_ex(
    Sensor_SensorObject* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Sensor_SensorObject_finalize_w_params(
        sample,&deallocParams);
}

void Sensor_SensorObject_finalize_w_params(
    Sensor_SensorObject* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    ClassificationEnum_finalize_w_params(&sample->classification,deallocParams);

    Sensor_RangeModeEnum_finalize_w_params(&sample->rangeMode,deallocParams);

}

void Sensor_SensorObject_finalize_optional_members(
    Sensor_SensorObject* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    ClassificationEnum_finalize_optional_members(&sample->classification, deallocParams->delete_pointers);
    Sensor_RangeModeEnum_finalize_optional_members(&sample->rangeMode, deallocParams->delete_pointers);
}

RTIBool Sensor_SensorObject_copy(
    Sensor_SensorObject* dst,
    const Sensor_SensorObject* src)
{

    if (!ClassificationEnum_copy(
        &dst->classification, &src->classification)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyArray(
        dst->position ,src->position,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->velocity ,src->velocity,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->size ,src->size,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->amplitude, &src->amplitude)) { 
        return RTI_FALSE;
    }
    if (!Sensor_RangeModeEnum_copy(
        &dst->rangeMode, &src->rangeMode)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyFloat (
        &dst->rangeRate, &src->rangeRate)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Sensor_SensorObject' sequence class.
*/
#define T Sensor_SensorObject
#define TSeq Sensor_SensorObjectSeq
#define T_initialize_w_params Sensor_SensorObject_initialize_w_params
#define T_finalize_w_params   Sensor_SensorObject_finalize_w_params
#define T_copy       Sensor_SensorObject_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Sensor_SensorObjectListTYPENAME = "Sensor::SensorObjectList";

DDS_TypeCode* Sensor_SensorObjectList_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Sensor_SensorObjectList_g_tc_objects_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((Sensor_SENSOR_OBJECT_LIST_MAX_SIZE)),NULL);
    static DDS_TypeCode_Member Sensor_SensorObjectList_g_tc_members[2]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"objects",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Sensor_SensorObjectList_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Sensor::SensorObjectList", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Sensor_SensorObjectList_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Sensor_SensorObjectList*/

    if (is_initialized) {
        return &Sensor_SensorObjectList_g_tc;
    }

    Sensor_SensorObjectList_g_tc_objects_sequence._data._typeCode = (RTICdrTypeCode *)Sensor_SensorObject_get_typecode();

    Sensor_SensorObjectList_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();

    Sensor_SensorObjectList_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObjectList_g_tc_objects_sequence;

    is_initialized = RTI_TRUE;

    return &Sensor_SensorObjectList_g_tc;
}

RTIBool Sensor_SensorObjectList_initialize(
    Sensor_SensorObjectList* sample) {
    return Sensor_SensorObjectList_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Sensor_SensorObjectList_initialize_ex(
    Sensor_SensorObjectList* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Sensor_SensorObjectList_initialize_w_params(
        sample,&allocParams);

}

RTIBool Sensor_SensorObjectList_initialize_w_params(
    Sensor_SensorObjectList* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (allocParams) {} /* To avoid warnings */

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }
    if (allocParams->allocate_memory) {
        Sensor_SensorObjectSeq_initialize(&sample->objects );
        Sensor_SensorObjectSeq_set_element_allocation_params(&sample->objects ,allocParams);
        if (!Sensor_SensorObjectSeq_set_maximum(&sample->objects, ((Sensor_SENSOR_OBJECT_LIST_MAX_SIZE)))) {
            return RTI_FALSE;
        }
    } else { 
        Sensor_SensorObjectSeq_set_length(&sample->objects, 0);
    }
    return RTI_TRUE;
}

void Sensor_SensorObjectList_finalize(
    Sensor_SensorObjectList* sample)
{

    Sensor_SensorObjectList_finalize_ex(sample,RTI_TRUE);
}

void Sensor_SensorObjectList_finalize_ex(
    Sensor_SensorObjectList* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Sensor_SensorObjectList_finalize_w_params(
        sample,&deallocParams);
}

void Sensor_SensorObjectList_finalize_w_params(
    Sensor_SensorObjectList* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    Sensor_SensorObjectSeq_set_element_deallocation_params(
        &sample->objects,deallocParams);
    Sensor_SensorObjectSeq_finalize(&sample->objects);

}

void Sensor_SensorObjectList_finalize_optional_members(
    Sensor_SensorObjectList* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    POSIXTimestamp_finalize_optional_members(&sample->timestamp, deallocParams->delete_pointers);
    {
        DDS_UnsignedLong i, length;
        length = Sensor_SensorObjectSeq_get_length(
            &sample->objects);

        for (i = 0; i < length; i++) {
            Sensor_SensorObject_finalize_optional_members(
                Sensor_SensorObjectSeq_get_reference(
                    &sample->objects, i), deallocParams->delete_pointers);
        }
    }  

}

RTIBool Sensor_SensorObjectList_copy(
    Sensor_SensorObjectList* dst,
    const Sensor_SensorObjectList* src)
{

    if (!POSIXTimestamp_copy(
        &dst->timestamp, &src->timestamp)) {
        return RTI_FALSE;
    } 
    if (!Sensor_SensorObjectSeq_copy(&dst->objects ,
    &src->objects )) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Sensor_SensorObjectList' sequence class.
*/
#define T Sensor_SensorObjectList
#define TSeq Sensor_SensorObjectListSeq
#define T_initialize_w_params Sensor_SensorObjectList_initialize_w_params
#define T_finalize_w_params   Sensor_SensorObjectList_finalize_w_params
#define T_copy       Sensor_SensorObjectList_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Vision_VisionObjectTYPENAME = "Vision::VisionObject";

DDS_TypeCode* Vision_VisionObject_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Vision_VisionObject_g_tc_position_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode Vision_VisionObject_g_tc_velocity_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode Vision_VisionObject_g_tc_size_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3, NULL,NULL);
    static DDS_TypeCode_Member Vision_VisionObject_g_tc_members[4]=
    {

        {
            (char *)"classification",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"position",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"velocity",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"size",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Vision_VisionObject_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Vision::VisionObject", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Vision_VisionObject_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Vision_VisionObject*/

    if (is_initialized) {
        return &Vision_VisionObject_g_tc;
    }

    Vision_VisionObject_g_tc_position_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Vision_VisionObject_g_tc_velocity_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Vision_VisionObject_g_tc_size_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float;

    Vision_VisionObject_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ClassificationEnum_get_typecode();

    Vision_VisionObject_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionObject_g_tc_position_array;
    Vision_VisionObject_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionObject_g_tc_velocity_array;
    Vision_VisionObject_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionObject_g_tc_size_array;

    is_initialized = RTI_TRUE;

    return &Vision_VisionObject_g_tc;
}

RTIBool Vision_VisionObject_initialize(
    Vision_VisionObject* sample) {
    return Vision_VisionObject_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Vision_VisionObject_initialize_ex(
    Vision_VisionObject* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Vision_VisionObject_initialize_w_params(
        sample,&allocParams);

}

RTIBool Vision_VisionObject_initialize_w_params(
    Vision_VisionObject* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (allocParams) {} /* To avoid warnings */

    if (!ClassificationEnum_initialize_w_params(&sample->classification,
    allocParams)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->position, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->velocity, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_initArray(
        sample->size, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Vision_VisionObject_finalize(
    Vision_VisionObject* sample)
{

    Vision_VisionObject_finalize_ex(sample,RTI_TRUE);
}

void Vision_VisionObject_finalize_ex(
    Vision_VisionObject* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Vision_VisionObject_finalize_w_params(
        sample,&deallocParams);
}

void Vision_VisionObject_finalize_w_params(
    Vision_VisionObject* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    ClassificationEnum_finalize_w_params(&sample->classification,deallocParams);

}

void Vision_VisionObject_finalize_optional_members(
    Vision_VisionObject* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    ClassificationEnum_finalize_optional_members(&sample->classification, deallocParams->delete_pointers);
}

RTIBool Vision_VisionObject_copy(
    Vision_VisionObject* dst,
    const Vision_VisionObject* src)
{

    if (!ClassificationEnum_copy(
        &dst->classification, &src->classification)) {
        return RTI_FALSE;
    } 
    if (!RTICdrType_copyArray(
        dst->position ,src->position,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->velocity ,src->velocity,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    if (!RTICdrType_copyArray(
        dst->size ,src->size,(3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Vision_VisionObject' sequence class.
*/
#define T Vision_VisionObject
#define TSeq Vision_VisionObjectSeq
#define T_initialize_w_params Vision_VisionObject_initialize_w_params
#define T_finalize_w_params   Vision_VisionObject_finalize_w_params
#define T_copy       Vision_VisionObject_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

/* ========================================================================= */
const char *Vision_VisionSensorTYPENAME = "Vision::VisionSensor";

DDS_TypeCode* Vision_VisionSensor_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Vision_VisionSensor_g_tc_objects_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((Vision_VISION_OBJECT_LIST_MAX_SIZE)),NULL);
    static DDS_TypeCode_Member Vision_VisionSensor_g_tc_members[3]=
    {

        {
            (char *)"id",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"timestamp",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"objects",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode Vision_VisionSensor_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Vision::VisionSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            Vision_VisionSensor_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for Vision_VisionSensor*/

    if (is_initialized) {
        return &Vision_VisionSensor_g_tc;
    }

    Vision_VisionSensor_g_tc_objects_sequence._data._typeCode = (RTICdrTypeCode *)Vision_VisionObject_get_typecode();

    Vision_VisionSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    Vision_VisionSensor_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();

    Vision_VisionSensor_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionSensor_g_tc_objects_sequence;

    is_initialized = RTI_TRUE;

    return &Vision_VisionSensor_g_tc;
}

RTIBool Vision_VisionSensor_initialize(
    Vision_VisionSensor* sample) {
    return Vision_VisionSensor_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Vision_VisionSensor_initialize_ex(
    Vision_VisionSensor* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Vision_VisionSensor_initialize_w_params(
        sample,&allocParams);

}

RTIBool Vision_VisionSensor_initialize_w_params(
    Vision_VisionSensor* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (allocParams) {} /* To avoid warnings */

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }     

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }
    if (allocParams->allocate_memory) {
        Vision_VisionObjectSeq_initialize(&sample->objects );
        Vision_VisionObjectSeq_set_element_allocation_params(&sample->objects ,allocParams);
        if (!Vision_VisionObjectSeq_set_maximum(&sample->objects, ((Vision_VISION_OBJECT_LIST_MAX_SIZE)))) {
            return RTI_FALSE;
        }
    } else { 
        Vision_VisionObjectSeq_set_length(&sample->objects, 0);
    }
    return RTI_TRUE;
}

void Vision_VisionSensor_finalize(
    Vision_VisionSensor* sample)
{

    Vision_VisionSensor_finalize_ex(sample,RTI_TRUE);
}

void Vision_VisionSensor_finalize_ex(
    Vision_VisionSensor* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Vision_VisionSensor_finalize_w_params(
        sample,&deallocParams);
}

void Vision_VisionSensor_finalize_w_params(
    Vision_VisionSensor* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }
    if (deallocParams) {} /* To avoid warnings */

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    Vision_VisionObjectSeq_set_element_deallocation_params(
        &sample->objects,deallocParams);
    Vision_VisionObjectSeq_finalize(&sample->objects);

}

void Vision_VisionSensor_finalize_optional_members(
    Vision_VisionSensor* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    POSIXTimestamp_finalize_optional_members(&sample->timestamp, deallocParams->delete_pointers);
    {
        DDS_UnsignedLong i, length;
        length = Vision_VisionObjectSeq_get_length(
            &sample->objects);

        for (i = 0; i < length; i++) {
            Vision_VisionObject_finalize_optional_members(
                Vision_VisionObjectSeq_get_reference(
                    &sample->objects, i), deallocParams->delete_pointers);
        }
    }  

}

RTIBool Vision_VisionSensor_copy(
    Vision_VisionSensor* dst,
    const Vision_VisionSensor* src)
{

    if (!RTICdrType_copyLong (
        &dst->id, &src->id)) { 
        return RTI_FALSE;
    }
    if (!POSIXTimestamp_copy(
        &dst->timestamp, &src->timestamp)) {
        return RTI_FALSE;
    } 
    if (!Vision_VisionObjectSeq_copy(&dst->objects ,
    &src->objects )) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Vision_VisionSensor' sequence class.
*/
#define T Vision_VisionSensor
#define TSeq Vision_VisionSensorSeq
#define T_initialize_w_params Vision_VisionSensor_initialize_w_params
#define T_finalize_w_params   Vision_VisionSensor_finalize_w_params
#define T_copy       Vision_VisionSensor_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params
#undef T_initialize_w_params
#undef TSeq
#undef T

