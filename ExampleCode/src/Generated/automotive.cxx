

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
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
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

#ifndef NDDS_STANDALONE_TYPE
#include "automotivePlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *POSIXTimestampTYPENAME = "POSIXTimestamp";

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode POSIXTimestamp_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"POSIXTimestamp", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            POSIXTimestamp_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for POSIXTimestamp*/

    if (is_initialized) {
        return &POSIXTimestamp_g_tc;
    }

    POSIXTimestamp_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    POSIXTimestamp_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    POSIXTimestamp_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;

    /* Initialize the values for member annotations. */
    POSIXTimestamp_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    POSIXTimestamp_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    POSIXTimestamp_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    POSIXTimestamp_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    POSIXTimestamp_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    POSIXTimestamp_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    POSIXTimestamp_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    POSIXTimestamp_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    POSIXTimestamp_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    POSIXTimestamp_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    POSIXTimestamp_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    POSIXTimestamp_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    POSIXTimestamp_g_tc._data._sampleAccessInfo =
    POSIXTimestamp_get_sample_access_info();
    POSIXTimestamp_g_tc._data._typePlugin =
    POSIXTimestamp_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &POSIXTimestamp_g_tc;
}

#define TSeq POSIXTimestampSeq
#define T POSIXTimestamp
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *POSIXTimestamp_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo POSIXTimestamp_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(POSIXTimestampSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        POSIXTimestampSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &POSIXTimestamp_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *POSIXTimestamp_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    POSIXTimestamp *sample;

    static RTIXCdrMemberAccessInfo POSIXTimestamp_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo POSIXTimestamp_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &POSIXTimestamp_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        POSIXTimestamp);
    if (sample == NULL) {
        return NULL;
    }

    POSIXTimestamp_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->s - (char *)sample);

    POSIXTimestamp_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->ns - (char *)sample);

    POSIXTimestamp_g_sampleAccessInfo.memberAccessInfos = 
    POSIXTimestamp_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(POSIXTimestamp);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            POSIXTimestamp_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            POSIXTimestamp_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    POSIXTimestamp_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    POSIXTimestamp_g_sampleAccessInfo.getMemberValuePointerFcn = 
    POSIXTimestamp_get_member_value_pointer;

    POSIXTimestamp_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &POSIXTimestamp_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *POSIXTimestamp_get_type_plugin_info()
{
    static RTIXCdrTypePlugin POSIXTimestamp_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        POSIXTimestamp_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        POSIXTimestamp_finalize_w_return,
        NULL
    };

    return &POSIXTimestamp_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->s = 0;

    sample->ns = 0;

    return RTI_TRUE;
}

RTIBool POSIXTimestamp_finalize_w_return(
    POSIXTimestamp* sample)
{
    POSIXTimestamp_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->s, &src->s)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->ns, &src->ns)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            INDICATOR_OFF, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"INDICATOR_LEFT",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_LEFT, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"INDICATOR_RIGHT",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_RIGHT, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"INDICATOR_HAZARD",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            INDICATOR_HAZARD, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode IndicatorStatusEnum_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"IndicatorStatusEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            IndicatorStatusEnum_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for IndicatorStatusEnum*/

    if (is_initialized) {
        return &IndicatorStatusEnum_g_tc;
    }

    IndicatorStatusEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    IndicatorStatusEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    IndicatorStatusEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

    IndicatorStatusEnum_g_tc._data._sampleAccessInfo =
    IndicatorStatusEnum_get_sample_access_info();
    IndicatorStatusEnum_g_tc._data._typePlugin =
    IndicatorStatusEnum_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &IndicatorStatusEnum_g_tc;
}

#define TSeq IndicatorStatusEnumSeq
#define T IndicatorStatusEnum
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *IndicatorStatusEnum_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo IndicatorStatusEnum_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(IndicatorStatusEnumSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        IndicatorStatusEnumSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &IndicatorStatusEnum_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *IndicatorStatusEnum_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo IndicatorStatusEnum_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo IndicatorStatusEnum_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &IndicatorStatusEnum_g_sampleAccessInfo;
    }

    IndicatorStatusEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    IndicatorStatusEnum_g_sampleAccessInfo.memberAccessInfos = 
    IndicatorStatusEnum_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(IndicatorStatusEnum);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            IndicatorStatusEnum_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            IndicatorStatusEnum_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    IndicatorStatusEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    IndicatorStatusEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
    IndicatorStatusEnum_get_member_value_pointer;

    IndicatorStatusEnum_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &IndicatorStatusEnum_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *IndicatorStatusEnum_get_type_plugin_info()
{
    static RTIXCdrTypePlugin IndicatorStatusEnum_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        IndicatorStatusEnum_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        IndicatorStatusEnum_finalize_w_return,
        NULL
    };

    return &IndicatorStatusEnum_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = INDICATOR_OFF;
    return RTI_TRUE;
}

RTIBool IndicatorStatusEnum_finalize_w_return(
    IndicatorStatusEnum* sample)
{
    if (sample) {} /* To avoid warnings */

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            CLASSIFICATION_UNKNOWN, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_UNKNOWNSMALL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_UNKNOWNSMALL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_UNKNOWNBIG",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_UNKNOWNBIG, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_PEDESTRIAN",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_PEDESTRIAN, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_BIKE",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_BIKE, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_CAR",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_CAR, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_TRUCK",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_TRUCK, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CLASSIFICATION_BARRIER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CLASSIFICATION_BARRIER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ClassificationEnum_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ClassificationEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            8, /* Number of members */
            ClassificationEnum_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ClassificationEnum*/

    if (is_initialized) {
        return &ClassificationEnum_g_tc;
    }

    ClassificationEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    ClassificationEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ClassificationEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

    ClassificationEnum_g_tc._data._sampleAccessInfo =
    ClassificationEnum_get_sample_access_info();
    ClassificationEnum_g_tc._data._typePlugin =
    ClassificationEnum_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ClassificationEnum_g_tc;
}

#define TSeq ClassificationEnumSeq
#define T ClassificationEnum
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ClassificationEnum_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ClassificationEnum_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ClassificationEnumSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ClassificationEnumSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ClassificationEnum_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ClassificationEnum_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo ClassificationEnum_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ClassificationEnum_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ClassificationEnum_g_sampleAccessInfo;
    }

    ClassificationEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    ClassificationEnum_g_sampleAccessInfo.memberAccessInfos = 
    ClassificationEnum_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ClassificationEnum);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ClassificationEnum_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ClassificationEnum_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ClassificationEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ClassificationEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ClassificationEnum_get_member_value_pointer;

    ClassificationEnum_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ClassificationEnum_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ClassificationEnum_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ClassificationEnum_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ClassificationEnum_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ClassificationEnum_finalize_w_return,
        NULL
    };

    return &ClassificationEnum_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = CLASSIFICATION_UNKNOWN;
    return RTI_TRUE;
}

RTIBool ClassificationEnum_finalize_w_return(
    ClassificationEnum* sample)
{
    if (sample) {} /* To avoid warnings */

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Alerts_DriverAlerts_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Alerts::DriverAlerts", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            Alerts_DriverAlerts_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Alerts_DriverAlerts*/

    if (is_initialized) {
        return &Alerts_DriverAlerts_g_tc;
    }

    Alerts_DriverAlerts_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Alerts_DriverAlerts_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    Alerts_DriverAlerts_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    Alerts_DriverAlerts_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    Alerts_DriverAlerts_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    Alerts_DriverAlerts_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    Alerts_DriverAlerts_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;

    /* Initialize the values for member annotations. */
    Alerts_DriverAlerts_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Alerts_DriverAlerts_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

    Alerts_DriverAlerts_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Alerts_DriverAlerts_g_tc_members[1]._annotations._defaultValue._u.boolean_value = 0;

    Alerts_DriverAlerts_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Alerts_DriverAlerts_g_tc_members[2]._annotations._defaultValue._u.boolean_value = 0;

    Alerts_DriverAlerts_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Alerts_DriverAlerts_g_tc_members[3]._annotations._defaultValue._u.boolean_value = 0;

    Alerts_DriverAlerts_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Alerts_DriverAlerts_g_tc_members[4]._annotations._defaultValue._u.boolean_value = 0;

    Alerts_DriverAlerts_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Alerts_DriverAlerts_g_tc_members[5]._annotations._defaultValue._u.boolean_value = 0;

    Alerts_DriverAlerts_g_tc._data._sampleAccessInfo =
    Alerts_DriverAlerts_get_sample_access_info();
    Alerts_DriverAlerts_g_tc._data._typePlugin =
    Alerts_DriverAlerts_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Alerts_DriverAlerts_g_tc;
}

#define TSeq Alerts_DriverAlertsSeq
#define T Alerts_DriverAlerts
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Alerts_DriverAlerts_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Alerts_DriverAlerts_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Alerts_DriverAlertsSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Alerts_DriverAlertsSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Alerts_DriverAlerts_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Alerts_DriverAlerts_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Alerts_DriverAlerts *sample;

    static RTIXCdrMemberAccessInfo Alerts_DriverAlerts_g_memberAccessInfos[6] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Alerts_DriverAlerts_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Alerts_DriverAlerts_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Alerts_DriverAlerts);
    if (sample == NULL) {
        return NULL;
    }

    Alerts_DriverAlerts_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->blindSpotDriver - (char *)sample);

    Alerts_DriverAlerts_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->blindSpotPassenger - (char *)sample);

    Alerts_DriverAlerts_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->frontCollision - (char *)sample);

    Alerts_DriverAlerts_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->backCollision - (char *)sample);

    Alerts_DriverAlerts_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->parkingCollision - (char *)sample);

    Alerts_DriverAlerts_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->driverAttention - (char *)sample);

    Alerts_DriverAlerts_g_sampleAccessInfo.memberAccessInfos = 
    Alerts_DriverAlerts_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Alerts_DriverAlerts);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Alerts_DriverAlerts_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Alerts_DriverAlerts_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Alerts_DriverAlerts_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Alerts_DriverAlerts_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Alerts_DriverAlerts_get_member_value_pointer;

    Alerts_DriverAlerts_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Alerts_DriverAlerts_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Alerts_DriverAlerts_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Alerts_DriverAlerts_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Alerts_DriverAlerts_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Alerts_DriverAlerts_finalize_w_return,
        NULL
    };

    return &Alerts_DriverAlerts_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->blindSpotDriver = 0;

    sample->blindSpotPassenger = 0;

    sample->frontCollision = 0;

    sample->backCollision = 0;

    sample->parkingCollision = 0;

    sample->driverAttention = 0;

    return RTI_TRUE;
}

RTIBool Alerts_DriverAlerts_finalize_w_return(
    Alerts_DriverAlerts* sample)
{
    Alerts_DriverAlerts_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

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

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            CONFIDENCE_NONE, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CONFIDENCE_LOW",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_LOW, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CONFIDENCE_MED",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_MED, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"CONFIDENCE_HIGH",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            CONFIDENCE_HIGH, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lane_ConfidenceEnum_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::ConfidenceEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Lane_ConfidenceEnum_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lane_ConfidenceEnum*/

    if (is_initialized) {
        return &Lane_ConfidenceEnum_g_tc;
    }

    Lane_ConfidenceEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    Lane_ConfidenceEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Lane_ConfidenceEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

    Lane_ConfidenceEnum_g_tc._data._sampleAccessInfo =
    Lane_ConfidenceEnum_get_sample_access_info();
    Lane_ConfidenceEnum_g_tc._data._typePlugin =
    Lane_ConfidenceEnum_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lane_ConfidenceEnum_g_tc;
}

#define TSeq Lane_ConfidenceEnumSeq
#define T Lane_ConfidenceEnum
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lane_ConfidenceEnum_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lane_ConfidenceEnum_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lane_ConfidenceEnumSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lane_ConfidenceEnumSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lane_ConfidenceEnum_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lane_ConfidenceEnum_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Lane_ConfidenceEnum_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lane_ConfidenceEnum_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lane_ConfidenceEnum_g_sampleAccessInfo;
    }

    Lane_ConfidenceEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    Lane_ConfidenceEnum_g_sampleAccessInfo.memberAccessInfos = 
    Lane_ConfidenceEnum_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lane_ConfidenceEnum);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lane_ConfidenceEnum_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lane_ConfidenceEnum_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lane_ConfidenceEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lane_ConfidenceEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lane_ConfidenceEnum_get_member_value_pointer;

    Lane_ConfidenceEnum_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lane_ConfidenceEnum_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lane_ConfidenceEnum_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lane_ConfidenceEnum_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lane_ConfidenceEnum_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lane_ConfidenceEnum_finalize_w_return,
        NULL
    };

    return &Lane_ConfidenceEnum_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = CONFIDENCE_NONE;
    return RTI_TRUE;
}

RTIBool Lane_ConfidenceEnum_finalize_w_return(
    Lane_ConfidenceEnum* sample)
{
    if (sample) {} /* To avoid warnings */

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            BOUNDRY_NONE, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_INVALID",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_INVALID, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_SOLID",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_SOLID, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_DASHED",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_DASHED, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_VIRTUAL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_VIRTUAL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_DOTS",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_DOTS, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_ROADEDGE",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_ROADEDGE, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_UNDECIDED",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_UNDECIDED, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOUNDRY_DOUBLEMARKER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOUNDRY_DOUBLEMARKER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lane_LaneBoundaryEnum_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::LaneBoundaryEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            9, /* Number of members */
            Lane_LaneBoundaryEnum_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lane_LaneBoundaryEnum*/

    if (is_initialized) {
        return &Lane_LaneBoundaryEnum_g_tc;
    }

    Lane_LaneBoundaryEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    Lane_LaneBoundaryEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Lane_LaneBoundaryEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

    Lane_LaneBoundaryEnum_g_tc._data._sampleAccessInfo =
    Lane_LaneBoundaryEnum_get_sample_access_info();
    Lane_LaneBoundaryEnum_g_tc._data._typePlugin =
    Lane_LaneBoundaryEnum_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lane_LaneBoundaryEnum_g_tc;
}

#define TSeq Lane_LaneBoundaryEnumSeq
#define T Lane_LaneBoundaryEnum
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lane_LaneBoundaryEnum_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lane_LaneBoundaryEnum_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lane_LaneBoundaryEnumSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lane_LaneBoundaryEnumSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lane_LaneBoundaryEnum_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lane_LaneBoundaryEnum_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Lane_LaneBoundaryEnum_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lane_LaneBoundaryEnum_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lane_LaneBoundaryEnum_g_sampleAccessInfo;
    }

    Lane_LaneBoundaryEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    Lane_LaneBoundaryEnum_g_sampleAccessInfo.memberAccessInfos = 
    Lane_LaneBoundaryEnum_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lane_LaneBoundaryEnum);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lane_LaneBoundaryEnum_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lane_LaneBoundaryEnum_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lane_LaneBoundaryEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lane_LaneBoundaryEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lane_LaneBoundaryEnum_get_member_value_pointer;

    Lane_LaneBoundaryEnum_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lane_LaneBoundaryEnum_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lane_LaneBoundaryEnum_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lane_LaneBoundaryEnum_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lane_LaneBoundaryEnum_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lane_LaneBoundaryEnum_finalize_w_return,
        NULL
    };

    return &Lane_LaneBoundaryEnum_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = BOUNDRY_NONE;
    return RTI_TRUE;
}

RTIBool Lane_LaneBoundaryEnum_finalize_w_return(
    Lane_LaneBoundaryEnum* sample)
{
    if (sample) {} /* To avoid warnings */

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lane_LaneObject_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::LaneObject", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            Lane_LaneObject_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lane_LaneObject*/

    if (is_initialized) {
        return &Lane_LaneObject_g_tc;
    }

    Lane_LaneObject_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Lane_LaneObject_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    Lane_LaneObject_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Lane_ConfidenceEnum_get_typecode();
    Lane_LaneObject_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)Lane_LaneBoundaryEnum_get_typecode();
    Lane_LaneObject_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lane_LaneObject_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lane_LaneObject_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    Lane_LaneObject_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Lane_LaneObject_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

    Lane_LaneObject_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Lane_LaneObject_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

    Lane_LaneObject_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Lane_LaneObject_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;

    Lane_LaneObject_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    Lane_LaneObject_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Lane_LaneObject_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Lane_LaneObject_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[4]._annotations._defaultValue._u.float_value = 0.0f;
    Lane_LaneObject_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[4]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Lane_LaneObject_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[4]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Lane_LaneObject_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[5]._annotations._defaultValue._u.float_value = 0.0f;
    Lane_LaneObject_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[5]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Lane_LaneObject_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Lane_LaneObject_g_tc_members[5]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Lane_LaneObject_g_tc._data._sampleAccessInfo =
    Lane_LaneObject_get_sample_access_info();
    Lane_LaneObject_g_tc._data._typePlugin =
    Lane_LaneObject_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lane_LaneObject_g_tc;
}

#define TSeq Lane_LaneObjectSeq
#define T Lane_LaneObject
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lane_LaneObject_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lane_LaneObject_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lane_LaneObjectSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lane_LaneObjectSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lane_LaneObject_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lane_LaneObject_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Lane_LaneObject *sample;

    static RTIXCdrMemberAccessInfo Lane_LaneObject_g_memberAccessInfos[6] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lane_LaneObject_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lane_LaneObject_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Lane_LaneObject);
    if (sample == NULL) {
        return NULL;
    }

    Lane_LaneObject_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->isValid - (char *)sample);

    Lane_LaneObject_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->confidence - (char *)sample);

    Lane_LaneObject_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->boundaryType - (char *)sample);

    Lane_LaneObject_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->offset - (char *)sample);

    Lane_LaneObject_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->headingAngle - (char *)sample);

    Lane_LaneObject_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->curvature - (char *)sample);

    Lane_LaneObject_g_sampleAccessInfo.memberAccessInfos = 
    Lane_LaneObject_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lane_LaneObject);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lane_LaneObject_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lane_LaneObject_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lane_LaneObject_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lane_LaneObject_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lane_LaneObject_get_member_value_pointer;

    Lane_LaneObject_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lane_LaneObject_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lane_LaneObject_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lane_LaneObject_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lane_LaneObject_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lane_LaneObject_finalize_w_return,
        NULL
    };

    return &Lane_LaneObject_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->isValid = 0;

    sample->confidence = CONFIDENCE_NONE;
    sample->boundaryType = BOUNDRY_NONE;

    sample->offset = 0.0f;

    sample->headingAngle = 0.0f;

    sample->curvature = 0.0f;

    return RTI_TRUE;
}

RTIBool Lane_LaneObject_finalize_w_return(
    Lane_LaneObject* sample)
{
    Lane_LaneObject_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyBoolean (
            &dst->isValid, &src->isValid)) { 
            return RTI_FALSE;
        }
        if (!Lane_ConfidenceEnum_copy(
            &dst->confidence,(const Lane_ConfidenceEnum*)&src->confidence)) {
            return RTI_FALSE;
        } 
        if (!Lane_LaneBoundaryEnum_copy(
            &dst->boundaryType,(const Lane_LaneBoundaryEnum*)&src->boundaryType)) {
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

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lane_LaneSensor_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lane::LaneSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Lane_LaneSensor_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lane_LaneSensor*/

    if (is_initialized) {
        return &Lane_LaneSensor_g_tc;
    }

    Lane_LaneSensor_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Lane_LaneSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)Lane_LaneObject_get_typecode();
    Lane_LaneSensor_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Lane_LaneObject_get_typecode();

    /* Initialize the values for member annotations. */

    Lane_LaneSensor_g_tc._data._sampleAccessInfo =
    Lane_LaneSensor_get_sample_access_info();
    Lane_LaneSensor_g_tc._data._typePlugin =
    Lane_LaneSensor_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lane_LaneSensor_g_tc;
}

#define TSeq Lane_LaneSensorSeq
#define T Lane_LaneSensor
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lane_LaneSensor_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lane_LaneSensor_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lane_LaneSensorSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lane_LaneSensorSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lane_LaneSensor_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lane_LaneSensor_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Lane_LaneSensor *sample;

    static RTIXCdrMemberAccessInfo Lane_LaneSensor_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lane_LaneSensor_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lane_LaneSensor_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Lane_LaneSensor);
    if (sample == NULL) {
        return NULL;
    }

    Lane_LaneSensor_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->left - (char *)sample);

    Lane_LaneSensor_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->right - (char *)sample);

    Lane_LaneSensor_g_sampleAccessInfo.memberAccessInfos = 
    Lane_LaneSensor_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lane_LaneSensor);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lane_LaneSensor_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lane_LaneSensor_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lane_LaneSensor_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lane_LaneSensor_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lane_LaneSensor_get_member_value_pointer;

    Lane_LaneSensor_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lane_LaneSensor_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lane_LaneSensor_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lane_LaneSensor_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lane_LaneSensor_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lane_LaneSensor_finalize_w_return,
        NULL
    };

    return &Lane_LaneSensor_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

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

RTIBool Lane_LaneSensor_finalize_w_return(
    Lane_LaneSensor* sample)
{
    Lane_LaneSensor_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!Lane_LaneObject_copy(
            &dst->left,(const Lane_LaneObject*)&src->left)) {
            return RTI_FALSE;
        } 
        if (!Lane_LaneObject_copy(
            &dst->right,(const Lane_LaneObject*)&src->right)) {
            return RTI_FALSE;
        } 

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lidar_Point_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lidar::Point", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            Lidar_Point_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lidar_Point*/

    if (is_initialized) {
        return &Lidar_Point_g_tc;
    }

    Lidar_Point_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Lidar_Point_g_tc_point_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lidar_Point_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& Lidar_Point_g_tc_point_array;

    /* Initialize the values for member annotations. */

    Lidar_Point_g_tc._data._sampleAccessInfo =
    Lidar_Point_get_sample_access_info();
    Lidar_Point_g_tc._data._typePlugin =
    Lidar_Point_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lidar_Point_g_tc;
}

#define TSeq Lidar_PointSeq
#define T Lidar_Point
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lidar_Point_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lidar_Point_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lidar_PointSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lidar_PointSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lidar_Point_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lidar_Point_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Lidar_Point *sample;

    static RTIXCdrMemberAccessInfo Lidar_Point_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lidar_Point_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lidar_Point_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Lidar_Point);
    if (sample == NULL) {
        return NULL;
    }

    Lidar_Point_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->point - (char *)sample);

    Lidar_Point_g_sampleAccessInfo.memberAccessInfos = 
    Lidar_Point_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lidar_Point);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lidar_Point_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lidar_Point_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lidar_Point_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lidar_Point_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lidar_Point_get_member_value_pointer;

    Lidar_Point_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lidar_Point_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lidar_Point_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lidar_Point_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lidar_Point_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lidar_Point_finalize_w_return,
        NULL
    };

    return &Lidar_Point_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initArray(
        sample->point, (3), RTI_CDR_FLOAT_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool Lidar_Point_finalize_w_return(
    Lidar_Point* sample)
{
    Lidar_Point_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyArray(
            dst->point ,src->point,(3), RTI_CDR_FLOAT_SIZE)) {
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lidar_PCloud_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lidar::PCloud", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            8, /* Number of members */
            Lidar_PCloud_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lidar_PCloud*/

    if (is_initialized) {
        return &Lidar_PCloud_g_tc;
    }

    Lidar_PCloud_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Lidar_PCloud_g_tc_Location_sequence._data._typeCode = (RTICdrTypeCode *)Lidar_Point_get_typecode();
    Lidar_PCloud_g_tc_Location_sequence._data._sampleAccessInfo = Lidar_Point_get_sample_seq_access_info();
    Lidar_PCloud_g_tc_xLimits_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lidar_PCloud_g_tc_yLimits_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lidar_PCloud_g_tc_zLimits_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lidar_PCloud_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_Location_sequence;
    Lidar_PCloud_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet_w_new;
    Lidar_PCloud_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lidar_PCloud_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Lidar_PCloud_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    Lidar_PCloud_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_xLimits_array;
    Lidar_PCloud_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_yLimits_array;
    Lidar_PCloud_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)& Lidar_PCloud_g_tc_zLimits_array;

    /* Initialize the values for member annotations. */

    Lidar_PCloud_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
    Lidar_PCloud_g_tc_members[1]._annotations._defaultValue._u.octet_value = 0;
    Lidar_PCloud_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
    Lidar_PCloud_g_tc_members[1]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
    Lidar_PCloud_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
    Lidar_PCloud_g_tc_members[1]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

    Lidar_PCloud_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Lidar_PCloud_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    Lidar_PCloud_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Lidar_PCloud_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Lidar_PCloud_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Lidar_PCloud_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Lidar_PCloud_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Lidar_PCloud_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    Lidar_PCloud_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Lidar_PCloud_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Lidar_PCloud_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Lidar_PCloud_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Lidar_PCloud_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Lidar_PCloud_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
    Lidar_PCloud_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Lidar_PCloud_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Lidar_PCloud_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Lidar_PCloud_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Lidar_PCloud_g_tc._data._sampleAccessInfo =
    Lidar_PCloud_get_sample_access_info();
    Lidar_PCloud_g_tc._data._typePlugin =
    Lidar_PCloud_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lidar_PCloud_g_tc;
}

#define TSeq Lidar_PCloudSeq
#define T Lidar_PCloud
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lidar_PCloud_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lidar_PCloud_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lidar_PCloudSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lidar_PCloudSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lidar_PCloud_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lidar_PCloud_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Lidar_PCloud *sample;

    static RTIXCdrMemberAccessInfo Lidar_PCloud_g_memberAccessInfos[8] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lidar_PCloud_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lidar_PCloud_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Lidar_PCloud);
    if (sample == NULL) {
        return NULL;
    }

    Lidar_PCloud_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->Location - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->color - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->normal - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->intensity - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->count - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->xLimits - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->yLimits - (char *)sample);

    Lidar_PCloud_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->zLimits - (char *)sample);

    Lidar_PCloud_g_sampleAccessInfo.memberAccessInfos = 
    Lidar_PCloud_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lidar_PCloud);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lidar_PCloud_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lidar_PCloud_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lidar_PCloud_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lidar_PCloud_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lidar_PCloud_get_member_value_pointer;

    Lidar_PCloud_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lidar_PCloud_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lidar_PCloud_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lidar_PCloud_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lidar_PCloud_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lidar_PCloud_finalize_w_return,
        NULL
    };

    return &Lidar_PCloud_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        if(!Lidar_PointSeq_initialize(&sample->Location )){
            return RTI_FALSE;
        };
        if(!Lidar_PointSeq_set_element_allocation_params(&sample->Location ,allocParams)){
            return RTI_FALSE;
        };
        if(!Lidar_PointSeq_set_absolute_maximum(&sample->Location , ((Lidar_MAX_POINTS)))){
            return RTI_FALSE;
        }
        if (!Lidar_PointSeq_set_maximum(&sample->Location, ((Lidar_MAX_POINTS)))) {
            return RTI_FALSE;
        }
    } else { 
        if(!Lidar_PointSeq_set_length(&sample->Location, 0)){
            return RTI_FALSE;
        }    
    }

    sample->color = 0;

    sample->normal = 0.0f;

    sample->intensity = 0.0f;

    sample->count = 0;

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

RTIBool Lidar_PCloud_finalize_w_return(
    Lidar_PCloud* sample)
{
    Lidar_PCloud_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

    if(!Lidar_PointSeq_set_element_deallocation_params(
        &sample->Location,deallocParams)){
        return; 
    }
    if(!Lidar_PointSeq_finalize(&sample->Location)){
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

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

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Lidar_LidarSensor_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Lidar::LidarSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Lidar_LidarSensor_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Lidar_LidarSensor*/

    if (is_initialized) {
        return &Lidar_LidarSensor_g_tc;
    }

    Lidar_LidarSensor_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Lidar_LidarSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();
    Lidar_LidarSensor_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Lidar_PCloud_get_typecode();

    /* Initialize the values for member annotations. */

    Lidar_LidarSensor_g_tc._data._sampleAccessInfo =
    Lidar_LidarSensor_get_sample_access_info();
    Lidar_LidarSensor_g_tc._data._typePlugin =
    Lidar_LidarSensor_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Lidar_LidarSensor_g_tc;
}

#define TSeq Lidar_LidarSensorSeq
#define T Lidar_LidarSensor
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Lidar_LidarSensor_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Lidar_LidarSensor_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Lidar_LidarSensorSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Lidar_LidarSensorSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Lidar_LidarSensor_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Lidar_LidarSensor_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Lidar_LidarSensor *sample;

    static RTIXCdrMemberAccessInfo Lidar_LidarSensor_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Lidar_LidarSensor_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Lidar_LidarSensor_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Lidar_LidarSensor);
    if (sample == NULL) {
        return NULL;
    }

    Lidar_LidarSensor_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    Lidar_LidarSensor_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->ptCloud - (char *)sample);

    Lidar_LidarSensor_g_sampleAccessInfo.memberAccessInfos = 
    Lidar_LidarSensor_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Lidar_LidarSensor);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Lidar_LidarSensor_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Lidar_LidarSensor_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Lidar_LidarSensor_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Lidar_LidarSensor_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Lidar_LidarSensor_get_member_value_pointer;

    Lidar_LidarSensor_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Lidar_LidarSensor_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Lidar_LidarSensor_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Lidar_LidarSensor_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Lidar_LidarSensor_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Lidar_LidarSensor_finalize_w_return,
        NULL
    };

    return &Lidar_LidarSensor_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

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

RTIBool Lidar_LidarSensor_finalize_w_return(
    Lidar_LidarSensor* sample)
{
    Lidar_LidarSensor_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!POSIXTimestamp_copy(
            &dst->timestamp,(const POSIXTimestamp*)&src->timestamp)) {
            return RTI_FALSE;
        } 
        if (!Lidar_PCloud_copy(
            &dst->ptCloud,(const Lidar_PCloud*)&src->ptCloud)) {
            return RTI_FALSE;
        } 

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Platform_PlatformControl_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Platform::PlatformControl", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            5, /* Number of members */
            Platform_PlatformControl_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Platform_PlatformControl*/

    if (is_initialized) {
        return &Platform_PlatformControl_g_tc;
    }

    Platform_PlatformControl_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Platform_PlatformControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    Platform_PlatformControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();
    Platform_PlatformControl_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Platform_PlatformControl_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Platform_PlatformControl_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)IndicatorStatusEnum_get_typecode();

    /* Initialize the values for member annotations. */
    Platform_PlatformControl_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Platform_PlatformControl_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    Platform_PlatformControl_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Platform_PlatformControl_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Platform_PlatformControl_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Platform_PlatformControl_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Platform_PlatformControl_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformControl_g_tc_members[2]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformControl_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformControl_g_tc_members[2]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformControl_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformControl_g_tc_members[2]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformControl_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformControl_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformControl_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformControl_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformControl_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformControl_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformControl_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Platform_PlatformControl_g_tc_members[4]._annotations._defaultValue._u.enumerated_value = 0;

    Platform_PlatformControl_g_tc._data._sampleAccessInfo =
    Platform_PlatformControl_get_sample_access_info();
    Platform_PlatformControl_g_tc._data._typePlugin =
    Platform_PlatformControl_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Platform_PlatformControl_g_tc;
}

#define TSeq Platform_PlatformControlSeq
#define T Platform_PlatformControl
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Platform_PlatformControl_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Platform_PlatformControl_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Platform_PlatformControlSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Platform_PlatformControlSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Platform_PlatformControl_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Platform_PlatformControl_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Platform_PlatformControl *sample;

    static RTIXCdrMemberAccessInfo Platform_PlatformControl_g_memberAccessInfos[5] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Platform_PlatformControl_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Platform_PlatformControl_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Platform_PlatformControl);
    if (sample == NULL) {
        return NULL;
    }

    Platform_PlatformControl_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->sample_id - (char *)sample);

    Platform_PlatformControl_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    Platform_PlatformControl_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->vehicleSteerAngle - (char *)sample);

    Platform_PlatformControl_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->speed - (char *)sample);

    Platform_PlatformControl_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->blinkerStatus - (char *)sample);

    Platform_PlatformControl_g_sampleAccessInfo.memberAccessInfos = 
    Platform_PlatformControl_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Platform_PlatformControl);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Platform_PlatformControl_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Platform_PlatformControl_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Platform_PlatformControl_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Platform_PlatformControl_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Platform_PlatformControl_get_member_value_pointer;

    Platform_PlatformControl_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Platform_PlatformControl_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Platform_PlatformControl_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Platform_PlatformControl_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Platform_PlatformControl_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Platform_PlatformControl_finalize_w_return,
        NULL
    };

    return &Platform_PlatformControl_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->sample_id = 0;

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }

    sample->vehicleSteerAngle = 0.0f;

    sample->speed = 0.0f;

    sample->blinkerStatus = INDICATOR_OFF;
    return RTI_TRUE;
}

RTIBool Platform_PlatformControl_finalize_w_return(
    Platform_PlatformControl* sample)
{
    Platform_PlatformControl_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->sample_id, &src->sample_id)) { 
            return RTI_FALSE;
        }
        if (!POSIXTimestamp_copy(
            &dst->timestamp,(const POSIXTimestamp*)&src->timestamp)) {
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
            &dst->blinkerStatus,(const IndicatorStatusEnum*)&src->blinkerStatus)) {
            return RTI_FALSE;
        } 

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Platform_PlatformStatus_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Platform::PlatformStatus", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            7, /* Number of members */
            Platform_PlatformStatus_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Platform_PlatformStatus*/

    if (is_initialized) {
        return &Platform_PlatformStatus_g_tc;
    }

    Platform_PlatformStatus_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Platform_PlatformStatus_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();
    Platform_PlatformStatus_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Platform_PlatformStatus_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)IndicatorStatusEnum_get_typecode();
    Platform_PlatformStatus_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Platform_PlatformStatus_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Platform_PlatformStatus_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Platform_PlatformStatus_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */

    Platform_PlatformStatus_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformStatus_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformStatus_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformStatus_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Platform_PlatformStatus_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;

    Platform_PlatformStatus_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformStatus_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformStatus_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformStatus_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[4]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformStatus_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[4]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformStatus_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[4]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformStatus_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[5]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformStatus_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[5]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformStatus_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[5]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformStatus_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[6]._annotations._defaultValue._u.float_value = 0.0f;
    Platform_PlatformStatus_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[6]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Platform_PlatformStatus_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Platform_PlatformStatus_g_tc_members[6]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Platform_PlatformStatus_g_tc._data._sampleAccessInfo =
    Platform_PlatformStatus_get_sample_access_info();
    Platform_PlatformStatus_g_tc._data._typePlugin =
    Platform_PlatformStatus_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Platform_PlatformStatus_g_tc;
}

#define TSeq Platform_PlatformStatusSeq
#define T Platform_PlatformStatus
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Platform_PlatformStatus_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Platform_PlatformStatus_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Platform_PlatformStatusSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Platform_PlatformStatusSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Platform_PlatformStatus_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Platform_PlatformStatus_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Platform_PlatformStatus *sample;

    static RTIXCdrMemberAccessInfo Platform_PlatformStatus_g_memberAccessInfos[7] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Platform_PlatformStatus_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Platform_PlatformStatus_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Platform_PlatformStatus);
    if (sample == NULL) {
        return NULL;
    }

    Platform_PlatformStatus_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    Platform_PlatformStatus_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->vehSpd - (char *)sample);

    Platform_PlatformStatus_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->blinkerStatus - (char *)sample);

    Platform_PlatformStatus_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->posGasPedal - (char *)sample);

    Platform_PlatformStatus_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->velocity - (char *)sample);

    Platform_PlatformStatus_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->yawRate - (char *)sample);

    Platform_PlatformStatus_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->vehicleSteerAngle - (char *)sample);

    Platform_PlatformStatus_g_sampleAccessInfo.memberAccessInfos = 
    Platform_PlatformStatus_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Platform_PlatformStatus);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Platform_PlatformStatus_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Platform_PlatformStatus_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Platform_PlatformStatus_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Platform_PlatformStatus_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Platform_PlatformStatus_get_member_value_pointer;

    Platform_PlatformStatus_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Platform_PlatformStatus_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Platform_PlatformStatus_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Platform_PlatformStatus_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Platform_PlatformStatus_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Platform_PlatformStatus_finalize_w_return,
        NULL
    };

    return &Platform_PlatformStatus_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }

    sample->vehSpd = 0.0f;

    sample->blinkerStatus = INDICATOR_OFF;

    sample->posGasPedal = 0.0f;

    sample->velocity = 0.0f;

    sample->yawRate = 0.0f;

    sample->vehicleSteerAngle = 0.0f;

    return RTI_TRUE;
}

RTIBool Platform_PlatformStatus_finalize_w_return(
    Platform_PlatformStatus* sample)
{
    Platform_PlatformStatus_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!POSIXTimestamp_copy(
            &dst->timestamp,(const POSIXTimestamp*)&src->timestamp)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyFloat (
            &dst->vehSpd, &src->vehSpd)) { 
            return RTI_FALSE;
        }
        if (!IndicatorStatusEnum_copy(
            &dst->blinkerStatus,(const IndicatorStatusEnum*)&src->blinkerStatus)) {
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

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            RANGE_NONE, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"RANGE_SHORT",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_SHORT, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"RANGE_MEDIUM",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_MEDIUM, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"RANGE_LONG",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            RANGE_LONG, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Sensor_RangeModeEnum_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Sensor::RangeModeEnum", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Sensor_RangeModeEnum_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Sensor_RangeModeEnum*/

    if (is_initialized) {
        return &Sensor_RangeModeEnum_g_tc;
    }

    Sensor_RangeModeEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    Sensor_RangeModeEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Sensor_RangeModeEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

    Sensor_RangeModeEnum_g_tc._data._sampleAccessInfo =
    Sensor_RangeModeEnum_get_sample_access_info();
    Sensor_RangeModeEnum_g_tc._data._typePlugin =
    Sensor_RangeModeEnum_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Sensor_RangeModeEnum_g_tc;
}

#define TSeq Sensor_RangeModeEnumSeq
#define T Sensor_RangeModeEnum
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Sensor_RangeModeEnum_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Sensor_RangeModeEnum_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Sensor_RangeModeEnumSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Sensor_RangeModeEnumSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Sensor_RangeModeEnum_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Sensor_RangeModeEnum_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Sensor_RangeModeEnum_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Sensor_RangeModeEnum_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Sensor_RangeModeEnum_g_sampleAccessInfo;
    }

    Sensor_RangeModeEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    Sensor_RangeModeEnum_g_sampleAccessInfo.memberAccessInfos = 
    Sensor_RangeModeEnum_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Sensor_RangeModeEnum);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Sensor_RangeModeEnum_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Sensor_RangeModeEnum_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Sensor_RangeModeEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Sensor_RangeModeEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Sensor_RangeModeEnum_get_member_value_pointer;

    Sensor_RangeModeEnum_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Sensor_RangeModeEnum_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Sensor_RangeModeEnum_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Sensor_RangeModeEnum_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Sensor_RangeModeEnum_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Sensor_RangeModeEnum_finalize_w_return,
        NULL
    };

    return &Sensor_RangeModeEnum_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = RANGE_NONE;
    return RTI_TRUE;
}

RTIBool Sensor_RangeModeEnum_finalize_w_return(
    Sensor_RangeModeEnum* sample)
{
    if (sample) {} /* To avoid warnings */

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Sensor_SensorObject_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Sensor::SensorObject", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            7, /* Number of members */
            Sensor_SensorObject_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Sensor_SensorObject*/

    if (is_initialized) {
        return &Sensor_SensorObject_g_tc;
    }

    Sensor_SensorObject_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Sensor_SensorObject_g_tc_position_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Sensor_SensorObject_g_tc_velocity_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Sensor_SensorObject_g_tc_size_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Sensor_SensorObject_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ClassificationEnum_get_typecode();
    Sensor_SensorObject_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObject_g_tc_position_array;
    Sensor_SensorObject_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObject_g_tc_velocity_array;
    Sensor_SensorObject_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObject_g_tc_size_array;
    Sensor_SensorObject_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Sensor_SensorObject_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)Sensor_RangeModeEnum_get_typecode();
    Sensor_SensorObject_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    Sensor_SensorObject_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Sensor_SensorObject_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

    Sensor_SensorObject_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Sensor_SensorObject_g_tc_members[4]._annotations._defaultValue._u.float_value = 0.0f;
    Sensor_SensorObject_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Sensor_SensorObject_g_tc_members[4]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Sensor_SensorObject_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Sensor_SensorObject_g_tc_members[4]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Sensor_SensorObject_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Sensor_SensorObject_g_tc_members[5]._annotations._defaultValue._u.enumerated_value = 0;

    Sensor_SensorObject_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Sensor_SensorObject_g_tc_members[6]._annotations._defaultValue._u.float_value = 0.0f;
    Sensor_SensorObject_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Sensor_SensorObject_g_tc_members[6]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Sensor_SensorObject_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Sensor_SensorObject_g_tc_members[6]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Sensor_SensorObject_g_tc._data._sampleAccessInfo =
    Sensor_SensorObject_get_sample_access_info();
    Sensor_SensorObject_g_tc._data._typePlugin =
    Sensor_SensorObject_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Sensor_SensorObject_g_tc;
}

#define TSeq Sensor_SensorObjectSeq
#define T Sensor_SensorObject
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Sensor_SensorObject_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Sensor_SensorObject_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Sensor_SensorObjectSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Sensor_SensorObjectSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Sensor_SensorObject_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Sensor_SensorObject_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Sensor_SensorObject *sample;

    static RTIXCdrMemberAccessInfo Sensor_SensorObject_g_memberAccessInfos[7] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Sensor_SensorObject_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Sensor_SensorObject_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Sensor_SensorObject);
    if (sample == NULL) {
        return NULL;
    }

    Sensor_SensorObject_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->classification - (char *)sample);

    Sensor_SensorObject_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->position - (char *)sample);

    Sensor_SensorObject_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->velocity - (char *)sample);

    Sensor_SensorObject_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->size - (char *)sample);

    Sensor_SensorObject_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->amplitude - (char *)sample);

    Sensor_SensorObject_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->rangeMode - (char *)sample);

    Sensor_SensorObject_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->rangeRate - (char *)sample);

    Sensor_SensorObject_g_sampleAccessInfo.memberAccessInfos = 
    Sensor_SensorObject_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Sensor_SensorObject);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Sensor_SensorObject_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Sensor_SensorObject_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Sensor_SensorObject_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Sensor_SensorObject_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Sensor_SensorObject_get_member_value_pointer;

    Sensor_SensorObject_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Sensor_SensorObject_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Sensor_SensorObject_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Sensor_SensorObject_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Sensor_SensorObject_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Sensor_SensorObject_finalize_w_return,
        NULL
    };

    return &Sensor_SensorObject_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->classification = CLASSIFICATION_UNKNOWN;
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

    sample->amplitude = 0.0f;

    sample->rangeMode = RANGE_NONE;

    sample->rangeRate = 0.0f;

    return RTI_TRUE;
}

RTIBool Sensor_SensorObject_finalize_w_return(
    Sensor_SensorObject* sample)
{
    Sensor_SensorObject_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!ClassificationEnum_copy(
            &dst->classification,(const ClassificationEnum*)&src->classification)) {
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
            &dst->rangeMode,(const Sensor_RangeModeEnum*)&src->rangeMode)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyFloat (
            &dst->rangeRate, &src->rangeRate)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Sensor_SensorObjectList_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Sensor::SensorObjectList", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Sensor_SensorObjectList_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Sensor_SensorObjectList*/

    if (is_initialized) {
        return &Sensor_SensorObjectList_g_tc;
    }

    Sensor_SensorObjectList_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Sensor_SensorObjectList_g_tc_objects_sequence._data._typeCode = (RTICdrTypeCode *)Sensor_SensorObject_get_typecode();
    Sensor_SensorObjectList_g_tc_objects_sequence._data._sampleAccessInfo = Sensor_SensorObject_get_sample_seq_access_info();
    Sensor_SensorObjectList_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();
    Sensor_SensorObjectList_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Sensor_SensorObjectList_g_tc_objects_sequence;

    /* Initialize the values for member annotations. */

    Sensor_SensorObjectList_g_tc._data._sampleAccessInfo =
    Sensor_SensorObjectList_get_sample_access_info();
    Sensor_SensorObjectList_g_tc._data._typePlugin =
    Sensor_SensorObjectList_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Sensor_SensorObjectList_g_tc;
}

#define TSeq Sensor_SensorObjectListSeq
#define T Sensor_SensorObjectList
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Sensor_SensorObjectList_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Sensor_SensorObjectList_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Sensor_SensorObjectListSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Sensor_SensorObjectListSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Sensor_SensorObjectList_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Sensor_SensorObjectList_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Sensor_SensorObjectList *sample;

    static RTIXCdrMemberAccessInfo Sensor_SensorObjectList_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Sensor_SensorObjectList_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Sensor_SensorObjectList_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Sensor_SensorObjectList);
    if (sample == NULL) {
        return NULL;
    }

    Sensor_SensorObjectList_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    Sensor_SensorObjectList_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->objects - (char *)sample);

    Sensor_SensorObjectList_g_sampleAccessInfo.memberAccessInfos = 
    Sensor_SensorObjectList_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Sensor_SensorObjectList);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Sensor_SensorObjectList_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Sensor_SensorObjectList_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Sensor_SensorObjectList_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Sensor_SensorObjectList_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Sensor_SensorObjectList_get_member_value_pointer;

    Sensor_SensorObjectList_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Sensor_SensorObjectList_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Sensor_SensorObjectList_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Sensor_SensorObjectList_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Sensor_SensorObjectList_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Sensor_SensorObjectList_finalize_w_return,
        NULL
    };

    return &Sensor_SensorObjectList_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }
    if (allocParams->allocate_memory) {
        if(!Sensor_SensorObjectSeq_initialize(&sample->objects )){
            return RTI_FALSE;
        };
        if(!Sensor_SensorObjectSeq_set_element_allocation_params(&sample->objects ,allocParams)){
            return RTI_FALSE;
        };
        if(!Sensor_SensorObjectSeq_set_absolute_maximum(&sample->objects , ((Sensor_SENSOR_OBJECT_LIST_MAX_SIZE)))){
            return RTI_FALSE;
        }
        if (!Sensor_SensorObjectSeq_set_maximum(&sample->objects, ((Sensor_SENSOR_OBJECT_LIST_MAX_SIZE)))) {
            return RTI_FALSE;
        }
    } else { 
        if(!Sensor_SensorObjectSeq_set_length(&sample->objects, 0)){
            return RTI_FALSE;
        }    
    }
    return RTI_TRUE;
}

RTIBool Sensor_SensorObjectList_finalize_w_return(
    Sensor_SensorObjectList* sample)
{
    Sensor_SensorObjectList_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    if(!Sensor_SensorObjectSeq_set_element_deallocation_params(
        &sample->objects,deallocParams)){
        return; 
    }
    if(!Sensor_SensorObjectSeq_finalize(&sample->objects)){
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!POSIXTimestamp_copy(
            &dst->timestamp,(const POSIXTimestamp*)&src->timestamp)) {
            return RTI_FALSE;
        } 
        if (!Sensor_SensorObjectSeq_copy(&dst->objects ,
        &src->objects )) {
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Vision_VisionObject_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Vision::VisionObject", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            Vision_VisionObject_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Vision_VisionObject*/

    if (is_initialized) {
        return &Vision_VisionObject_g_tc;
    }

    Vision_VisionObject_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Vision_VisionObject_g_tc_position_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Vision_VisionObject_g_tc_velocity_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Vision_VisionObject_g_tc_size_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_float_w_new;
    Vision_VisionObject_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ClassificationEnum_get_typecode();
    Vision_VisionObject_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionObject_g_tc_position_array;
    Vision_VisionObject_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionObject_g_tc_velocity_array;
    Vision_VisionObject_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionObject_g_tc_size_array;

    /* Initialize the values for member annotations. */
    Vision_VisionObject_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    Vision_VisionObject_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

    Vision_VisionObject_g_tc._data._sampleAccessInfo =
    Vision_VisionObject_get_sample_access_info();
    Vision_VisionObject_g_tc._data._typePlugin =
    Vision_VisionObject_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Vision_VisionObject_g_tc;
}

#define TSeq Vision_VisionObjectSeq
#define T Vision_VisionObject
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Vision_VisionObject_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Vision_VisionObject_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Vision_VisionObjectSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Vision_VisionObjectSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Vision_VisionObject_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Vision_VisionObject_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Vision_VisionObject *sample;

    static RTIXCdrMemberAccessInfo Vision_VisionObject_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Vision_VisionObject_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Vision_VisionObject_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Vision_VisionObject);
    if (sample == NULL) {
        return NULL;
    }

    Vision_VisionObject_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->classification - (char *)sample);

    Vision_VisionObject_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->position - (char *)sample);

    Vision_VisionObject_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->velocity - (char *)sample);

    Vision_VisionObject_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->size - (char *)sample);

    Vision_VisionObject_g_sampleAccessInfo.memberAccessInfos = 
    Vision_VisionObject_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Vision_VisionObject);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Vision_VisionObject_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Vision_VisionObject_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Vision_VisionObject_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Vision_VisionObject_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Vision_VisionObject_get_member_value_pointer;

    Vision_VisionObject_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Vision_VisionObject_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Vision_VisionObject_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Vision_VisionObject_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Vision_VisionObject_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Vision_VisionObject_finalize_w_return,
        NULL
    };

    return &Vision_VisionObject_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->classification = CLASSIFICATION_UNKNOWN;
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

RTIBool Vision_VisionObject_finalize_w_return(
    Vision_VisionObject* sample)
{
    Vision_VisionObject_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!ClassificationEnum_copy(
            &dst->classification,(const ClassificationEnum*)&src->classification)) {
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

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

#ifndef NDDS_STANDALONE_TYPE
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Vision_VisionSensor_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Vision::VisionSensor", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            Vision_VisionSensor_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Vision_VisionSensor*/

    if (is_initialized) {
        return &Vision_VisionSensor_g_tc;
    }

    Vision_VisionSensor_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Vision_VisionSensor_g_tc_objects_sequence._data._typeCode = (RTICdrTypeCode *)Vision_VisionObject_get_typecode();
    Vision_VisionSensor_g_tc_objects_sequence._data._sampleAccessInfo = Vision_VisionObject_get_sample_seq_access_info();
    Vision_VisionSensor_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    Vision_VisionSensor_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)POSIXTimestamp_get_typecode();
    Vision_VisionSensor_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Vision_VisionSensor_g_tc_objects_sequence;

    /* Initialize the values for member annotations. */
    Vision_VisionSensor_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    Vision_VisionSensor_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    Vision_VisionSensor_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    Vision_VisionSensor_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    Vision_VisionSensor_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    Vision_VisionSensor_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    Vision_VisionSensor_g_tc._data._sampleAccessInfo =
    Vision_VisionSensor_get_sample_access_info();
    Vision_VisionSensor_g_tc._data._typePlugin =
    Vision_VisionSensor_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Vision_VisionSensor_g_tc;
}

#define TSeq Vision_VisionSensorSeq
#define T Vision_VisionSensor
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Vision_VisionSensor_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Vision_VisionSensor_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Vision_VisionSensorSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Vision_VisionSensorSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Vision_VisionSensor_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Vision_VisionSensor_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Vision_VisionSensor *sample;

    static RTIXCdrMemberAccessInfo Vision_VisionSensor_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Vision_VisionSensor_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Vision_VisionSensor_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Vision_VisionSensor);
    if (sample == NULL) {
        return NULL;
    }

    Vision_VisionSensor_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->id - (char *)sample);

    Vision_VisionSensor_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    Vision_VisionSensor_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->objects - (char *)sample);

    Vision_VisionSensor_g_sampleAccessInfo.memberAccessInfos = 
    Vision_VisionSensor_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Vision_VisionSensor);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Vision_VisionSensor_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Vision_VisionSensor_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Vision_VisionSensor_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Vision_VisionSensor_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Vision_VisionSensor_get_member_value_pointer;

    Vision_VisionSensor_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Vision_VisionSensor_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Vision_VisionSensor_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Vision_VisionSensor_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Vision_VisionSensor_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Vision_VisionSensor_finalize_w_return,
        NULL
    };

    return &Vision_VisionSensor_g_typePlugin;
}
#endif

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

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->id = 0;

    if (!POSIXTimestamp_initialize_w_params(&sample->timestamp,
    allocParams)) {
        return RTI_FALSE;
    }
    if (allocParams->allocate_memory) {
        if(!Vision_VisionObjectSeq_initialize(&sample->objects )){
            return RTI_FALSE;
        };
        if(!Vision_VisionObjectSeq_set_element_allocation_params(&sample->objects ,allocParams)){
            return RTI_FALSE;
        };
        if(!Vision_VisionObjectSeq_set_absolute_maximum(&sample->objects , ((Vision_VISION_OBJECT_LIST_MAX_SIZE)))){
            return RTI_FALSE;
        }
        if (!Vision_VisionObjectSeq_set_maximum(&sample->objects, ((Vision_VISION_OBJECT_LIST_MAX_SIZE)))) {
            return RTI_FALSE;
        }
    } else { 
        if(!Vision_VisionObjectSeq_set_length(&sample->objects, 0)){
            return RTI_FALSE;
        }    
    }
    return RTI_TRUE;
}

RTIBool Vision_VisionSensor_finalize_w_return(
    Vision_VisionSensor* sample)
{
    Vision_VisionSensor_finalize_ex(sample, RTI_TRUE);

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

    if (deallocParams == NULL) {
        return;
    }

    POSIXTimestamp_finalize_w_params(&sample->timestamp,deallocParams);

    if(!Vision_VisionObjectSeq_set_element_deallocation_params(
        &sample->objects,deallocParams)){
        return; 
    }
    if(!Vision_VisionObjectSeq_finalize(&sample->objects)){
        return;
    }

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
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->id, &src->id)) { 
            return RTI_FALSE;
        }
        if (!POSIXTimestamp_copy(
            &dst->timestamp,(const POSIXTimestamp*)&src->timestamp)) {
            return RTI_FALSE;
        } 
        if (!Vision_VisionObjectSeq_copy(&dst->objects ,
        &src->objects )) {
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
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

/* ========================================================================= */
const char *builtin_interfaces_msg_dds__Time_TYPENAME = "builtin_interfaces::msg::dds_::Time_";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* builtin_interfaces_msg_dds__Time__get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member builtin_interfaces_msg_dds__Time__g_tc_members[2]=
    {

        {
            (char *)"sec_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"nanosec_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode builtin_interfaces_msg_dds__Time__g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"builtin_interfaces::msg::dds_::Time_", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            builtin_interfaces_msg_dds__Time__g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for builtin_interfaces_msg_dds__Time_*/

    if (is_initialized) {
        return &builtin_interfaces_msg_dds__Time__g_tc;
    }

    builtin_interfaces_msg_dds__Time__g_tc._data._annotations._allowedDataRepresentationMask = 5;

    builtin_interfaces_msg_dds__Time__g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    builtin_interfaces_msg_dds__Time__g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;

    /* Initialize the values for member annotations. */
    builtin_interfaces_msg_dds__Time__g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    builtin_interfaces_msg_dds__Time__g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    builtin_interfaces_msg_dds__Time__g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    builtin_interfaces_msg_dds__Time__g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    builtin_interfaces_msg_dds__Time__g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    builtin_interfaces_msg_dds__Time__g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    builtin_interfaces_msg_dds__Time__g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    builtin_interfaces_msg_dds__Time__g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
    builtin_interfaces_msg_dds__Time__g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    builtin_interfaces_msg_dds__Time__g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    builtin_interfaces_msg_dds__Time__g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    builtin_interfaces_msg_dds__Time__g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    builtin_interfaces_msg_dds__Time__g_tc._data._sampleAccessInfo =
    builtin_interfaces_msg_dds__Time__get_sample_access_info();
    builtin_interfaces_msg_dds__Time__g_tc._data._typePlugin =
    builtin_interfaces_msg_dds__Time__get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &builtin_interfaces_msg_dds__Time__g_tc;
}

#define TSeq builtin_interfaces_msg_dds__Time_Seq
#define T builtin_interfaces_msg_dds__Time_
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *builtin_interfaces_msg_dds__Time__get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo builtin_interfaces_msg_dds__Time__g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(builtin_interfaces_msg_dds__Time_Seq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        builtin_interfaces_msg_dds__Time_Seq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &builtin_interfaces_msg_dds__Time__g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *builtin_interfaces_msg_dds__Time__get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    builtin_interfaces_msg_dds__Time_ *sample;

    static RTIXCdrMemberAccessInfo builtin_interfaces_msg_dds__Time__g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo builtin_interfaces_msg_dds__Time__g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &builtin_interfaces_msg_dds__Time__g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        builtin_interfaces_msg_dds__Time_);
    if (sample == NULL) {
        return NULL;
    }

    builtin_interfaces_msg_dds__Time__g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->sec_ - (char *)sample);

    builtin_interfaces_msg_dds__Time__g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->nanosec_ - (char *)sample);

    builtin_interfaces_msg_dds__Time__g_sampleAccessInfo.memberAccessInfos = 
    builtin_interfaces_msg_dds__Time__g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(builtin_interfaces_msg_dds__Time_);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            builtin_interfaces_msg_dds__Time__g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            builtin_interfaces_msg_dds__Time__g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    builtin_interfaces_msg_dds__Time__g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    builtin_interfaces_msg_dds__Time__g_sampleAccessInfo.getMemberValuePointerFcn = 
    builtin_interfaces_msg_dds__Time__get_member_value_pointer;

    builtin_interfaces_msg_dds__Time__g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &builtin_interfaces_msg_dds__Time__g_sampleAccessInfo;
}

RTIXCdrTypePlugin *builtin_interfaces_msg_dds__Time__get_type_plugin_info()
{
    static RTIXCdrTypePlugin builtin_interfaces_msg_dds__Time__g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        builtin_interfaces_msg_dds__Time__initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        builtin_interfaces_msg_dds__Time__finalize_w_return,
        NULL
    };

    return &builtin_interfaces_msg_dds__Time__g_typePlugin;
}
#endif

RTIBool builtin_interfaces_msg_dds__Time__initialize(
    builtin_interfaces_msg_dds__Time_* sample) {
    return builtin_interfaces_msg_dds__Time__initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool builtin_interfaces_msg_dds__Time__initialize_ex(
    builtin_interfaces_msg_dds__Time_* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return builtin_interfaces_msg_dds__Time__initialize_w_params(
        sample,&allocParams);

}

RTIBool builtin_interfaces_msg_dds__Time__initialize_w_params(
    builtin_interfaces_msg_dds__Time_* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->sec_ = 0;

    sample->nanosec_ = 0u;

    return RTI_TRUE;
}

RTIBool builtin_interfaces_msg_dds__Time__finalize_w_return(
    builtin_interfaces_msg_dds__Time_* sample)
{
    builtin_interfaces_msg_dds__Time__finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void builtin_interfaces_msg_dds__Time__finalize(
    builtin_interfaces_msg_dds__Time_* sample)
{

    builtin_interfaces_msg_dds__Time__finalize_ex(sample,RTI_TRUE);
}

void builtin_interfaces_msg_dds__Time__finalize_ex(
    builtin_interfaces_msg_dds__Time_* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    builtin_interfaces_msg_dds__Time__finalize_w_params(
        sample,&deallocParams);
}

void builtin_interfaces_msg_dds__Time__finalize_w_params(
    builtin_interfaces_msg_dds__Time_* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void builtin_interfaces_msg_dds__Time__finalize_optional_members(
    builtin_interfaces_msg_dds__Time_* sample, RTIBool deletePointers)
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

RTIBool builtin_interfaces_msg_dds__Time__copy(
    builtin_interfaces_msg_dds__Time_* dst,
    const builtin_interfaces_msg_dds__Time_* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->sec_, &src->sec_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->nanosec_, &src->nanosec_)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'builtin_interfaces_msg_dds__Time_' sequence class.
*/
#define T builtin_interfaces_msg_dds__Time_
#define TSeq builtin_interfaces_msg_dds__Time_Seq

#define T_initialize_w_params builtin_interfaces_msg_dds__Time__initialize_w_params

#define T_finalize_w_params   builtin_interfaces_msg_dds__Time__finalize_w_params
#define T_copy       builtin_interfaces_msg_dds__Time__copy

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
const char *std_msgs_msg_dds__Header_TYPENAME = "std_msgs::msg::dds_::Header_";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* std_msgs_msg_dds__Header__get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode std_msgs_msg_dds__Header__g_tc_frame_id__string = DDS_INITIALIZE_STRING_TYPECODE((255));

    static DDS_TypeCode_Member std_msgs_msg_dds__Header__g_tc_members[2]=
    {

        {
            (char *)"stamp_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"frame_id_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode std_msgs_msg_dds__Header__g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"std_msgs::msg::dds_::Header_", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            std_msgs_msg_dds__Header__g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for std_msgs_msg_dds__Header_*/

    if (is_initialized) {
        return &std_msgs_msg_dds__Header__g_tc;
    }

    std_msgs_msg_dds__Header__g_tc._data._annotations._allowedDataRepresentationMask = 5;

    std_msgs_msg_dds__Header__g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)builtin_interfaces_msg_dds__Time__get_typecode();
    std_msgs_msg_dds__Header__g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&std_msgs_msg_dds__Header__g_tc_frame_id__string;

    /* Initialize the values for member annotations. */

    std_msgs_msg_dds__Header__g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    std_msgs_msg_dds__Header__g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    std_msgs_msg_dds__Header__g_tc._data._sampleAccessInfo =
    std_msgs_msg_dds__Header__get_sample_access_info();
    std_msgs_msg_dds__Header__g_tc._data._typePlugin =
    std_msgs_msg_dds__Header__get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &std_msgs_msg_dds__Header__g_tc;
}

#define TSeq std_msgs_msg_dds__Header_Seq
#define T std_msgs_msg_dds__Header_
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *std_msgs_msg_dds__Header__get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo std_msgs_msg_dds__Header__g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(std_msgs_msg_dds__Header_Seq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        std_msgs_msg_dds__Header_Seq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &std_msgs_msg_dds__Header__g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *std_msgs_msg_dds__Header__get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    std_msgs_msg_dds__Header_ *sample;

    static RTIXCdrMemberAccessInfo std_msgs_msg_dds__Header__g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo std_msgs_msg_dds__Header__g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &std_msgs_msg_dds__Header__g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        std_msgs_msg_dds__Header_);
    if (sample == NULL) {
        return NULL;
    }

    std_msgs_msg_dds__Header__g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->stamp_ - (char *)sample);

    std_msgs_msg_dds__Header__g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->frame_id_ - (char *)sample);

    std_msgs_msg_dds__Header__g_sampleAccessInfo.memberAccessInfos = 
    std_msgs_msg_dds__Header__g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(std_msgs_msg_dds__Header_);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            std_msgs_msg_dds__Header__g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            std_msgs_msg_dds__Header__g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    std_msgs_msg_dds__Header__g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    std_msgs_msg_dds__Header__g_sampleAccessInfo.getMemberValuePointerFcn = 
    std_msgs_msg_dds__Header__get_member_value_pointer;

    std_msgs_msg_dds__Header__g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &std_msgs_msg_dds__Header__g_sampleAccessInfo;
}

RTIXCdrTypePlugin *std_msgs_msg_dds__Header__get_type_plugin_info()
{
    static RTIXCdrTypePlugin std_msgs_msg_dds__Header__g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        std_msgs_msg_dds__Header__initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        std_msgs_msg_dds__Header__finalize_w_return,
        NULL
    };

    return &std_msgs_msg_dds__Header__g_typePlugin;
}
#endif

RTIBool std_msgs_msg_dds__Header__initialize(
    std_msgs_msg_dds__Header_* sample) {
    return std_msgs_msg_dds__Header__initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool std_msgs_msg_dds__Header__initialize_ex(
    std_msgs_msg_dds__Header_* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return std_msgs_msg_dds__Header__initialize_w_params(
        sample,&allocParams);

}

RTIBool std_msgs_msg_dds__Header__initialize_w_params(
    std_msgs_msg_dds__Header_* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!builtin_interfaces_msg_dds__Time__initialize_w_params(&sample->stamp_,
    allocParams)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->frame_id_ = DDS_String_alloc((255));
        RTICdrType_copyStringEx(
            &sample->frame_id_,
            "",
            (255),
            RTI_FALSE);
        if (sample->frame_id_ == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->frame_id_ != NULL) {
            RTICdrType_copyStringEx(
                &sample->frame_id_,
                "",
                (255),
                RTI_FALSE);
            if (sample->frame_id_ == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}

RTIBool std_msgs_msg_dds__Header__finalize_w_return(
    std_msgs_msg_dds__Header_* sample)
{
    std_msgs_msg_dds__Header__finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void std_msgs_msg_dds__Header__finalize(
    std_msgs_msg_dds__Header_* sample)
{

    std_msgs_msg_dds__Header__finalize_ex(sample,RTI_TRUE);
}

void std_msgs_msg_dds__Header__finalize_ex(
    std_msgs_msg_dds__Header_* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    std_msgs_msg_dds__Header__finalize_w_params(
        sample,&deallocParams);
}

void std_msgs_msg_dds__Header__finalize_w_params(
    std_msgs_msg_dds__Header_* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    builtin_interfaces_msg_dds__Time__finalize_w_params(&sample->stamp_,deallocParams);

    if (sample->frame_id_ != NULL) {
        DDS_String_free(sample->frame_id_);
        sample->frame_id_=NULL;

    }
}

void std_msgs_msg_dds__Header__finalize_optional_members(
    std_msgs_msg_dds__Header_* sample, RTIBool deletePointers)
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

    builtin_interfaces_msg_dds__Time__finalize_optional_members(&sample->stamp_, deallocParams->delete_pointers);
}

RTIBool std_msgs_msg_dds__Header__copy(
    std_msgs_msg_dds__Header_* dst,
    const std_msgs_msg_dds__Header_* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!builtin_interfaces_msg_dds__Time__copy(
            &dst->stamp_,(const builtin_interfaces_msg_dds__Time_*)&src->stamp_)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyStringEx (
            &dst->frame_id_, src->frame_id_, 
            (255) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'std_msgs_msg_dds__Header_' sequence class.
*/
#define T std_msgs_msg_dds__Header_
#define TSeq std_msgs_msg_dds__Header_Seq

#define T_initialize_w_params std_msgs_msg_dds__Header__initialize_w_params

#define T_finalize_w_params   std_msgs_msg_dds__Header__finalize_w_params
#define T_copy       std_msgs_msg_dds__Header__copy

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
const char *sensor_msgs_msg_dds__PointField_TYPENAME = "sensor_msgs::msg::dds_::PointField_";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* sensor_msgs_msg_dds__PointField__get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode sensor_msgs_msg_dds__PointField__g_tc_name__string = DDS_INITIALIZE_STRING_TYPECODE((255));

    static DDS_TypeCode_Member sensor_msgs_msg_dds__PointField__g_tc_members[4]=
    {

        {
            (char *)"name_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"offset_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"datatype_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"count_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode sensor_msgs_msg_dds__PointField__g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"sensor_msgs::msg::dds_::PointField_", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            sensor_msgs_msg_dds__PointField__g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for sensor_msgs_msg_dds__PointField_*/

    if (is_initialized) {
        return &sensor_msgs_msg_dds__PointField__g_tc;
    }

    sensor_msgs_msg_dds__PointField__g_tc._data._annotations._allowedDataRepresentationMask = 5;

    sensor_msgs_msg_dds__PointField__g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&sensor_msgs_msg_dds__PointField__g_tc_name__string;
    sensor_msgs_msg_dds__PointField__g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    sensor_msgs_msg_dds__PointField__g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet_w_new;
    sensor_msgs_msg_dds__PointField__g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;

    /* Initialize the values for member annotations. */
    sensor_msgs_msg_dds__PointField__g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    sensor_msgs_msg_dds__PointField__g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    sensor_msgs_msg_dds__PointField__g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointField__g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
    sensor_msgs_msg_dds__PointField__g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointField__g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    sensor_msgs_msg_dds__PointField__g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointField__g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    sensor_msgs_msg_dds__PointField__g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
    sensor_msgs_msg_dds__PointField__g_tc_members[2]._annotations._defaultValue._u.octet_value = 0;
    sensor_msgs_msg_dds__PointField__g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
    sensor_msgs_msg_dds__PointField__g_tc_members[2]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
    sensor_msgs_msg_dds__PointField__g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
    sensor_msgs_msg_dds__PointField__g_tc_members[2]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

    sensor_msgs_msg_dds__PointField__g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointField__g_tc_members[3]._annotations._defaultValue._u.ulong_value = 0u;
    sensor_msgs_msg_dds__PointField__g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointField__g_tc_members[3]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    sensor_msgs_msg_dds__PointField__g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointField__g_tc_members[3]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    sensor_msgs_msg_dds__PointField__g_tc._data._sampleAccessInfo =
    sensor_msgs_msg_dds__PointField__get_sample_access_info();
    sensor_msgs_msg_dds__PointField__g_tc._data._typePlugin =
    sensor_msgs_msg_dds__PointField__get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &sensor_msgs_msg_dds__PointField__g_tc;
}

#define TSeq sensor_msgs_msg_dds__PointField_Seq
#define T sensor_msgs_msg_dds__PointField_
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *sensor_msgs_msg_dds__PointField__get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo sensor_msgs_msg_dds__PointField__g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(sensor_msgs_msg_dds__PointField_Seq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        sensor_msgs_msg_dds__PointField_Seq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &sensor_msgs_msg_dds__PointField__g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *sensor_msgs_msg_dds__PointField__get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    sensor_msgs_msg_dds__PointField_ *sample;

    static RTIXCdrMemberAccessInfo sensor_msgs_msg_dds__PointField__g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo sensor_msgs_msg_dds__PointField__g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &sensor_msgs_msg_dds__PointField__g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        sensor_msgs_msg_dds__PointField_);
    if (sample == NULL) {
        return NULL;
    }

    sensor_msgs_msg_dds__PointField__g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->name_ - (char *)sample);

    sensor_msgs_msg_dds__PointField__g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->offset_ - (char *)sample);

    sensor_msgs_msg_dds__PointField__g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->datatype_ - (char *)sample);

    sensor_msgs_msg_dds__PointField__g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->count_ - (char *)sample);

    sensor_msgs_msg_dds__PointField__g_sampleAccessInfo.memberAccessInfos = 
    sensor_msgs_msg_dds__PointField__g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(sensor_msgs_msg_dds__PointField_);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            sensor_msgs_msg_dds__PointField__g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            sensor_msgs_msg_dds__PointField__g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    sensor_msgs_msg_dds__PointField__g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    sensor_msgs_msg_dds__PointField__g_sampleAccessInfo.getMemberValuePointerFcn = 
    sensor_msgs_msg_dds__PointField__get_member_value_pointer;

    sensor_msgs_msg_dds__PointField__g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &sensor_msgs_msg_dds__PointField__g_sampleAccessInfo;
}

RTIXCdrTypePlugin *sensor_msgs_msg_dds__PointField__get_type_plugin_info()
{
    static RTIXCdrTypePlugin sensor_msgs_msg_dds__PointField__g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        sensor_msgs_msg_dds__PointField__initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        sensor_msgs_msg_dds__PointField__finalize_w_return,
        NULL
    };

    return &sensor_msgs_msg_dds__PointField__g_typePlugin;
}
#endif

RTIBool sensor_msgs_msg_dds__PointField__initialize(
    sensor_msgs_msg_dds__PointField_* sample) {
    return sensor_msgs_msg_dds__PointField__initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool sensor_msgs_msg_dds__PointField__initialize_ex(
    sensor_msgs_msg_dds__PointField_* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return sensor_msgs_msg_dds__PointField__initialize_w_params(
        sample,&allocParams);

}

RTIBool sensor_msgs_msg_dds__PointField__initialize_w_params(
    sensor_msgs_msg_dds__PointField_* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->name_ = DDS_String_alloc((255));
        RTICdrType_copyStringEx(
            &sample->name_,
            "",
            (255),
            RTI_FALSE);
        if (sample->name_ == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->name_ != NULL) {
            RTICdrType_copyStringEx(
                &sample->name_,
                "",
                (255),
                RTI_FALSE);
            if (sample->name_ == NULL) {
                return RTI_FALSE;
            }
        }
    }

    sample->offset_ = 0u;

    sample->datatype_ = 0;

    sample->count_ = 0u;

    return RTI_TRUE;
}

RTIBool sensor_msgs_msg_dds__PointField__finalize_w_return(
    sensor_msgs_msg_dds__PointField_* sample)
{
    sensor_msgs_msg_dds__PointField__finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void sensor_msgs_msg_dds__PointField__finalize(
    sensor_msgs_msg_dds__PointField_* sample)
{

    sensor_msgs_msg_dds__PointField__finalize_ex(sample,RTI_TRUE);
}

void sensor_msgs_msg_dds__PointField__finalize_ex(
    sensor_msgs_msg_dds__PointField_* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    sensor_msgs_msg_dds__PointField__finalize_w_params(
        sample,&deallocParams);
}

void sensor_msgs_msg_dds__PointField__finalize_w_params(
    sensor_msgs_msg_dds__PointField_* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->name_ != NULL) {
        DDS_String_free(sample->name_);
        sample->name_=NULL;

    }

}

void sensor_msgs_msg_dds__PointField__finalize_optional_members(
    sensor_msgs_msg_dds__PointField_* sample, RTIBool deletePointers)
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

RTIBool sensor_msgs_msg_dds__PointField__copy(
    sensor_msgs_msg_dds__PointField_* dst,
    const sensor_msgs_msg_dds__PointField_* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->name_, src->name_, 
            (255) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->offset_, &src->offset_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyOctet (
            &dst->datatype_, &src->datatype_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->count_, &src->count_)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'sensor_msgs_msg_dds__PointField_' sequence class.
*/
#define T sensor_msgs_msg_dds__PointField_
#define TSeq sensor_msgs_msg_dds__PointField_Seq

#define T_initialize_w_params sensor_msgs_msg_dds__PointField__initialize_w_params

#define T_finalize_w_params   sensor_msgs_msg_dds__PointField__finalize_w_params
#define T_copy       sensor_msgs_msg_dds__PointField__copy

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
const char *sensor_msgs_msg_dds__PointCloud2_TYPENAME = "sensor_msgs::msg::dds_::PointCloud2_";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* sensor_msgs_msg_dds__PointCloud2__get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode sensor_msgs_msg_dds__PointCloud2__g_tc_fields__sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((4),NULL);
    static DDS_TypeCode sensor_msgs_msg_dds__PointCloud2__g_tc_data__sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((368640),NULL);

    static DDS_TypeCode_Member sensor_msgs_msg_dds__PointCloud2__g_tc_members[9]=
    {

        {
            (char *)"header_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"height_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"width_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"fields_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"is_bigendian_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"point_step_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"row_step_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"data_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"is_dense_",/* Member name */
            {
                8,/* Representation ID */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode sensor_msgs_msg_dds__PointCloud2__g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"sensor_msgs::msg::dds_::PointCloud2_", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            9, /* Number of members */
            sensor_msgs_msg_dds__PointCloud2__g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for sensor_msgs_msg_dds__PointCloud2_*/

    if (is_initialized) {
        return &sensor_msgs_msg_dds__PointCloud2__g_tc;
    }

    sensor_msgs_msg_dds__PointCloud2__g_tc._data._annotations._allowedDataRepresentationMask = 5;

    sensor_msgs_msg_dds__PointCloud2__g_tc_fields__sequence._data._typeCode = (RTICdrTypeCode *)sensor_msgs_msg_dds__PointField__get_typecode();
    sensor_msgs_msg_dds__PointCloud2__g_tc_fields__sequence._data._sampleAccessInfo = sensor_msgs_msg_dds__PointField__get_sample_seq_access_info();
    sensor_msgs_msg_dds__PointCloud2__g_tc_data__sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet_w_new;
    sensor_msgs_msg_dds__PointCloud2__g_tc_data__sequence._data._sampleAccessInfo = &DDS_g_sai_octet_seq;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)std_msgs_msg_dds__Header__get_typecode();
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& sensor_msgs_msg_dds__PointCloud2__g_tc_fields__sequence;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)& sensor_msgs_msg_dds__PointCloud2__g_tc_data__sequence;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean_w_new;

    /* Initialize the values for member annotations. */

    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._annotations._defaultValue._u.ulong_value = 0u;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[2]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    sensor_msgs_msg_dds__PointCloud2__g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[4]._annotations._defaultValue._u.boolean_value = 0;

    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._annotations._defaultValue._u.ulong_value = 0u;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[5]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._annotations._defaultValue._u.ulong_value = 0u;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[6]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    sensor_msgs_msg_dds__PointCloud2__g_tc_members[8]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    sensor_msgs_msg_dds__PointCloud2__g_tc_members[8]._annotations._defaultValue._u.boolean_value = 0;

    sensor_msgs_msg_dds__PointCloud2__g_tc._data._sampleAccessInfo =
    sensor_msgs_msg_dds__PointCloud2__get_sample_access_info();
    sensor_msgs_msg_dds__PointCloud2__g_tc._data._typePlugin =
    sensor_msgs_msg_dds__PointCloud2__get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &sensor_msgs_msg_dds__PointCloud2__g_tc;
}

#define TSeq sensor_msgs_msg_dds__PointCloud2_Seq
#define T sensor_msgs_msg_dds__PointCloud2_
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *sensor_msgs_msg_dds__PointCloud2__get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo sensor_msgs_msg_dds__PointCloud2__g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(sensor_msgs_msg_dds__PointCloud2_Seq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        sensor_msgs_msg_dds__PointCloud2_Seq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &sensor_msgs_msg_dds__PointCloud2__g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *sensor_msgs_msg_dds__PointCloud2__get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    sensor_msgs_msg_dds__PointCloud2_ *sample;

    static RTIXCdrMemberAccessInfo sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[9] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        sensor_msgs_msg_dds__PointCloud2_);
    if (sample == NULL) {
        return NULL;
    }

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->header_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->height_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->width_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->fields_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->is_bigendian_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->point_step_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->row_step_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->data_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->is_dense_ - (char *)sample);

    sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo.memberAccessInfos = 
    sensor_msgs_msg_dds__PointCloud2__g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(sensor_msgs_msg_dds__PointCloud2_);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo.getMemberValuePointerFcn = 
    sensor_msgs_msg_dds__PointCloud2__get_member_value_pointer;

    sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &sensor_msgs_msg_dds__PointCloud2__g_sampleAccessInfo;
}

RTIXCdrTypePlugin *sensor_msgs_msg_dds__PointCloud2__get_type_plugin_info()
{
    static RTIXCdrTypePlugin sensor_msgs_msg_dds__PointCloud2__g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        sensor_msgs_msg_dds__PointCloud2__initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        sensor_msgs_msg_dds__PointCloud2__finalize_w_return,
        NULL
    };

    return &sensor_msgs_msg_dds__PointCloud2__g_typePlugin;
}
#endif

RTIBool sensor_msgs_msg_dds__PointCloud2__initialize(
    sensor_msgs_msg_dds__PointCloud2_* sample) {
    return sensor_msgs_msg_dds__PointCloud2__initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool sensor_msgs_msg_dds__PointCloud2__initialize_ex(
    sensor_msgs_msg_dds__PointCloud2_* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return sensor_msgs_msg_dds__PointCloud2__initialize_w_params(
        sample,&allocParams);

}

RTIBool sensor_msgs_msg_dds__PointCloud2__initialize_w_params(
    sensor_msgs_msg_dds__PointCloud2_* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!std_msgs_msg_dds__Header__initialize_w_params(&sample->header_,
    allocParams)) {
        return RTI_FALSE;
    }

    sample->height_ = 0u;

    sample->width_ = 0u;

    if (allocParams->allocate_memory) {
        if(!sensor_msgs_msg_dds__PointField_Seq_initialize(&sample->fields_ )){
            return RTI_FALSE;
        };
        if(!sensor_msgs_msg_dds__PointField_Seq_set_element_allocation_params(&sample->fields_ ,allocParams)){
            return RTI_FALSE;
        };
        if(!sensor_msgs_msg_dds__PointField_Seq_set_absolute_maximum(&sample->fields_ , (4))){
            return RTI_FALSE;
        }
        if (!sensor_msgs_msg_dds__PointField_Seq_set_maximum(&sample->fields_, (4))) {
            return RTI_FALSE;
        }
    } else { 
        if(!sensor_msgs_msg_dds__PointField_Seq_set_length(&sample->fields_, 0)){
            return RTI_FALSE;
        }    
    }

    sample->is_bigendian_ = 0;

    sample->point_step_ = 0u;

    sample->row_step_ = 0u;

    if (allocParams->allocate_memory) {
        if(!DDS_OctetSeq_initialize(&sample->data_  )){
            return RTI_FALSE;
        }
        if(!DDS_OctetSeq_set_absolute_maximum(&sample->data_ , (368640))){
            return RTI_FALSE;
        }
        if (!DDS_OctetSeq_set_maximum(&sample->data_ , (368640))) {
            return RTI_FALSE;
        }
    } else { 
        if(!DDS_OctetSeq_set_length(&sample->data_, 0)){
            return RTI_FALSE;
        }    
    }

    sample->is_dense_ = 0;

    return RTI_TRUE;
}

RTIBool sensor_msgs_msg_dds__PointCloud2__finalize_w_return(
    sensor_msgs_msg_dds__PointCloud2_* sample)
{
    sensor_msgs_msg_dds__PointCloud2__finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void sensor_msgs_msg_dds__PointCloud2__finalize(
    sensor_msgs_msg_dds__PointCloud2_* sample)
{

    sensor_msgs_msg_dds__PointCloud2__finalize_ex(sample,RTI_TRUE);
}

void sensor_msgs_msg_dds__PointCloud2__finalize_ex(
    sensor_msgs_msg_dds__PointCloud2_* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    sensor_msgs_msg_dds__PointCloud2__finalize_w_params(
        sample,&deallocParams);
}

void sensor_msgs_msg_dds__PointCloud2__finalize_w_params(
    sensor_msgs_msg_dds__PointCloud2_* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    std_msgs_msg_dds__Header__finalize_w_params(&sample->header_,deallocParams);

    if(!sensor_msgs_msg_dds__PointField_Seq_set_element_deallocation_params(
        &sample->fields_,deallocParams)){
        return; 
    }
    if(!sensor_msgs_msg_dds__PointField_Seq_finalize(&sample->fields_)){
        return;
    }

    if(!DDS_OctetSeq_finalize(&sample->data_)){
        return;
    }

}

void sensor_msgs_msg_dds__PointCloud2__finalize_optional_members(
    sensor_msgs_msg_dds__PointCloud2_* sample, RTIBool deletePointers)
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

    std_msgs_msg_dds__Header__finalize_optional_members(&sample->header_, deallocParams->delete_pointers);
    {
        DDS_UnsignedLong i, length;
        length = sensor_msgs_msg_dds__PointField_Seq_get_length(
            &sample->fields_);

        for (i = 0; i < length; i++) {
            sensor_msgs_msg_dds__PointField__finalize_optional_members(
                sensor_msgs_msg_dds__PointField_Seq_get_reference(
                    &sample->fields_, i), deallocParams->delete_pointers);
        }
    }  

}

RTIBool sensor_msgs_msg_dds__PointCloud2__copy(
    sensor_msgs_msg_dds__PointCloud2_* dst,
    const sensor_msgs_msg_dds__PointCloud2_* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!std_msgs_msg_dds__Header__copy(
            &dst->header_,(const std_msgs_msg_dds__Header_*)&src->header_)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyUnsignedLong (
            &dst->height_, &src->height_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->width_, &src->width_)) { 
            return RTI_FALSE;
        }
        if (!sensor_msgs_msg_dds__PointField_Seq_copy(&dst->fields_ ,
        &src->fields_ )) {
            return RTI_FALSE;
        }
        if (!RTICdrType_copyBoolean (
            &dst->is_bigendian_, &src->is_bigendian_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->point_step_, &src->point_step_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->row_step_, &src->row_step_)) { 
            return RTI_FALSE;
        }
        if (!DDS_OctetSeq_copy(&dst->data_ ,
        &src->data_ )) {
            return RTI_FALSE;
        }
        if (!RTICdrType_copyBoolean (
            &dst->is_dense_, &src->is_dense_)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'sensor_msgs_msg_dds__PointCloud2_' sequence class.
*/
#define T sensor_msgs_msg_dds__PointCloud2_
#define TSeq sensor_msgs_msg_dds__PointCloud2_Seq

#define T_initialize_w_params sensor_msgs_msg_dds__PointCloud2__initialize_w_params

#define T_finalize_w_params   sensor_msgs_msg_dds__PointCloud2__finalize_w_params
#define T_copy       sensor_msgs_msg_dds__PointCloud2__copy

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
const char *ShapeFillKindTYPENAME = "ShapeFillKind";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ShapeFillKind_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ShapeFillKind_g_tc_members[4]=
    {

        {
            (char *)"SOLID_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            SOLID_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"TRANSPARENT_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            TRANSPARENT_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"HORIZONTAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            HORIZONTAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"VERTICAL_HATCH_FILL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            VERTICAL_HATCH_FILL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeFillKind_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeFillKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ShapeFillKind_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeFillKind*/

    if (is_initialized) {
        return &ShapeFillKind_g_tc;
    }

    ShapeFillKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    ShapeFillKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ShapeFillKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

    ShapeFillKind_g_tc._data._sampleAccessInfo =
    ShapeFillKind_get_sample_access_info();
    ShapeFillKind_g_tc._data._typePlugin =
    ShapeFillKind_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ShapeFillKind_g_tc;
}

#define TSeq ShapeFillKindSeq
#define T ShapeFillKind
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeFillKind_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeFillKind_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeFillKindSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeFillKindSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeFillKind_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeFillKind_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo ShapeFillKind_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeFillKind_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ShapeFillKind_g_sampleAccessInfo;
    }

    ShapeFillKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    ShapeFillKind_g_sampleAccessInfo.memberAccessInfos = 
    ShapeFillKind_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeFillKind);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ShapeFillKind_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ShapeFillKind_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeFillKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeFillKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeFillKind_get_member_value_pointer;

    ShapeFillKind_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ShapeFillKind_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ShapeFillKind_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeFillKind_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeFillKind_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeFillKind_finalize_w_return,
        NULL
    };

    return &ShapeFillKind_g_typePlugin;
}
#endif

RTIBool ShapeFillKind_initialize(
    ShapeFillKind* sample) {
    *sample = SOLID_FILL;
    return RTI_TRUE;
}

RTIBool ShapeFillKind_initialize_ex(
    ShapeFillKind* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeFillKind_initialize_w_params(
        sample,&allocParams);

}

RTIBool ShapeFillKind_initialize_w_params(
    ShapeFillKind* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = SOLID_FILL;
    return RTI_TRUE;
}

RTIBool ShapeFillKind_finalize_w_return(
    ShapeFillKind* sample)
{
    if (sample) {} /* To avoid warnings */

    return RTI_TRUE;
}

void ShapeFillKind_finalize(
    ShapeFillKind* sample)
{

    if (sample==NULL) {
        return;
    }
}

void ShapeFillKind_finalize_ex(
    ShapeFillKind* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeFillKind_finalize_w_params(
        sample,&deallocParams);
}

void ShapeFillKind_finalize_w_params(
    ShapeFillKind* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void ShapeFillKind_finalize_optional_members(
    ShapeFillKind* sample, RTIBool deletePointers)
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

RTIBool ShapeFillKind_copy(
    ShapeFillKind* dst,
    const ShapeFillKind* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeFillKind' sequence class.
*/
#define T ShapeFillKind
#define TSeq ShapeFillKindSeq

#define T_initialize_w_params ShapeFillKind_initialize_w_params

#define T_finalize_w_params   ShapeFillKind_finalize_w_params
#define T_copy       ShapeFillKind_copy

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
const char *ShapeTypeTYPENAME = "ShapeType";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ShapeType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode ShapeType_g_tc_color_string = DDS_INITIALIZE_STRING_TYPECODE((128));

    static DDS_TypeCode_Member ShapeType_g_tc_members[4]=
    {

        {
            (char *)"color",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"x",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"y",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"shapesize",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeType_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeType", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            4, /* Number of members */
            ShapeType_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeType*/

    if (is_initialized) {
        return &ShapeType_g_tc;
    }

    ShapeType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ShapeType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ShapeType_g_tc_color_string;
    ShapeType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    ShapeType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    ShapeType_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;

    /* Initialize the values for member annotations. */
    ShapeType_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    ShapeType_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    ShapeType_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    ShapeType_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeType_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    ShapeType_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
    ShapeType_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeType_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    ShapeType_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
    ShapeType_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    ShapeType_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    ShapeType_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    ShapeType_g_tc._data._sampleAccessInfo =
    ShapeType_get_sample_access_info();
    ShapeType_g_tc._data._typePlugin =
    ShapeType_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ShapeType_g_tc;
}

#define TSeq ShapeTypeSeq
#define T ShapeType
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeType_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeType_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeTypeSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeTypeSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeType_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeType_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    ShapeType *sample;

    static RTIXCdrMemberAccessInfo ShapeType_g_memberAccessInfos[4] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeType_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ShapeType_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ShapeType);
    if (sample == NULL) {
        return NULL;
    }

    ShapeType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->color - (char *)sample);

    ShapeType_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->x - (char *)sample);

    ShapeType_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->y - (char *)sample);

    ShapeType_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->shapesize - (char *)sample);

    ShapeType_g_sampleAccessInfo.memberAccessInfos = 
    ShapeType_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeType);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ShapeType_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ShapeType_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeType_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeType_get_member_value_pointer;

    ShapeType_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ShapeType_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ShapeType_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeType_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeType_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeType_finalize_w_return,
        NULL
    };

    return &ShapeType_g_typePlugin;
}
#endif

RTIBool ShapeType_initialize(
    ShapeType* sample) {
    return ShapeType_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ShapeType_initialize_ex(
    ShapeType* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeType_initialize_w_params(
        sample,&allocParams);

}

RTIBool ShapeType_initialize_w_params(
    ShapeType* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->color = DDS_String_alloc((128));
        RTICdrType_copyStringEx(
            &sample->color,
            "",
            (128),
            RTI_FALSE);
        if (sample->color == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->color != NULL) {
            RTICdrType_copyStringEx(
                &sample->color,
                "",
                (128),
                RTI_FALSE);
            if (sample->color == NULL) {
                return RTI_FALSE;
            }
        }
    }

    sample->x = 0;

    sample->y = 0;

    sample->shapesize = 0;

    return RTI_TRUE;
}

RTIBool ShapeType_finalize_w_return(
    ShapeType* sample)
{
    ShapeType_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void ShapeType_finalize(
    ShapeType* sample)
{

    ShapeType_finalize_ex(sample,RTI_TRUE);
}

void ShapeType_finalize_ex(
    ShapeType* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeType_finalize_w_params(
        sample,&deallocParams);
}

void ShapeType_finalize_w_params(
    ShapeType* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->color != NULL) {
        DDS_String_free(sample->color);
        sample->color=NULL;

    }

}

void ShapeType_finalize_optional_members(
    ShapeType* sample, RTIBool deletePointers)
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

RTIBool ShapeType_copy(
    ShapeType* dst,
    const ShapeType* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->color, src->color, 
            (128) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->x, &src->x)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->y, &src->y)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->shapesize, &src->shapesize)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeType' sequence class.
*/
#define T ShapeType
#define TSeq ShapeTypeSeq

#define T_initialize_w_params ShapeType_initialize_w_params

#define T_finalize_w_params   ShapeType_finalize_w_params
#define T_copy       ShapeType_copy

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
const char *ShapeTypeExtendedTYPENAME = "ShapeTypeExtended";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ShapeTypeExtended_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ShapeTypeExtended_g_tc_members[2]=
    {

        {
            (char *)"fillKind",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"angle",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ShapeTypeExtended_g_tc =
    {{
            DDS_TK_VALUE, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ShapeTypeExtended", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            ShapeTypeExtended_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ShapeTypeExtended*/

    if (is_initialized) {
        return &ShapeTypeExtended_g_tc;
    }

    ShapeTypeExtended_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    ShapeTypeExtended_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)ShapeFillKind_get_typecode();
    ShapeTypeExtended_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float_w_new;

    /* Initialize the values for member annotations. */
    ShapeTypeExtended_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ShapeTypeExtended_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

    ShapeTypeExtended_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    ShapeTypeExtended_g_tc_members[1]._annotations._defaultValue._u.float_value = 0.0f;
    ShapeTypeExtended_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    ShapeTypeExtended_g_tc_members[1]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    ShapeTypeExtended_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    ShapeTypeExtended_g_tc_members[1]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    ShapeTypeExtended_g_tc._data._typeCode = (RTICdrTypeCode *)ShapeType_get_typecode(); /* Base class */

    ShapeTypeExtended_g_tc._data._sampleAccessInfo =
    ShapeTypeExtended_get_sample_access_info();
    ShapeTypeExtended_g_tc._data._typePlugin =
    ShapeTypeExtended_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ShapeTypeExtended_g_tc;
}

#define TSeq ShapeTypeExtendedSeq
#define T ShapeTypeExtended
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *ShapeTypeExtended_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo ShapeTypeExtended_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(ShapeTypeExtendedSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        ShapeTypeExtendedSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &ShapeTypeExtended_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *ShapeTypeExtended_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    ShapeTypeExtended *sample;

    static RTIXCdrMemberAccessInfo ShapeTypeExtended_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ShapeTypeExtended_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ShapeTypeExtended_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ShapeTypeExtended);
    if (sample == NULL) {
        return NULL;
    }

    ShapeTypeExtended_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->fillKind - (char *)sample);

    ShapeTypeExtended_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->angle - (char *)sample);

    ShapeTypeExtended_g_sampleAccessInfo.memberAccessInfos = 
    ShapeTypeExtended_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ShapeTypeExtended);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ShapeTypeExtended_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ShapeTypeExtended_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ShapeTypeExtended_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    ShapeTypeExtended_g_sampleAccessInfo.getMemberValuePointerFcn = 
    ShapeTypeExtended_get_member_value_pointer;

    ShapeTypeExtended_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ShapeTypeExtended_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ShapeTypeExtended_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ShapeTypeExtended_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ShapeTypeExtended_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ShapeTypeExtended_finalize_w_return,
        NULL
    };

    return &ShapeTypeExtended_g_typePlugin;
}
#endif

RTIBool ShapeTypeExtended_initialize(
    ShapeTypeExtended* sample) {
    return ShapeTypeExtended_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ShapeTypeExtended_initialize_ex(
    ShapeTypeExtended* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ShapeTypeExtended_initialize_w_params(
        sample,&allocParams);

}

RTIBool ShapeTypeExtended_initialize_w_params(
    ShapeTypeExtended* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    if (!ShapeType_initialize_w_params((ShapeType*)sample,allocParams)) {
        return RTI_FALSE;
    }

    sample->fillKind = SOLID_FILL;

    sample->angle = 0.0f;

    return RTI_TRUE;
}

RTIBool ShapeTypeExtended_finalize_w_return(
    ShapeTypeExtended* sample)
{
    ShapeTypeExtended_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void ShapeTypeExtended_finalize(
    ShapeTypeExtended* sample)
{

    ShapeTypeExtended_finalize_ex(sample,RTI_TRUE);
}

void ShapeTypeExtended_finalize_ex(
    ShapeTypeExtended* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ShapeTypeExtended_finalize_w_params(
        sample,&deallocParams);
}

void ShapeTypeExtended_finalize_w_params(
    ShapeTypeExtended* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }
    ShapeType_finalize_w_params((ShapeType*)sample,deallocParams);

    ShapeFillKind_finalize_w_params(&sample->fillKind,deallocParams);

}

void ShapeTypeExtended_finalize_optional_members(
    ShapeTypeExtended* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    ShapeType_finalize_optional_members((ShapeType*)sample,deletePointers);

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    ShapeFillKind_finalize_optional_members(&sample->fillKind, deallocParams->delete_pointers);
}

RTIBool ShapeTypeExtended_copy(
    ShapeTypeExtended* dst,
    const ShapeTypeExtended* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if(!ShapeType_copy((ShapeType*)dst,(const ShapeType*)src)) {
            return RTI_FALSE;
        }

        if (!ShapeFillKind_copy(
            &dst->fillKind,(const ShapeFillKind*)&src->fillKind)) {
            return RTI_FALSE;
        } 
        if (!RTICdrType_copyFloat (
            &dst->angle, &src->angle)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ShapeTypeExtended' sequence class.
*/
#define T ShapeTypeExtended
#define TSeq ShapeTypeExtendedSeq

#define T_initialize_w_params ShapeTypeExtended_initialize_w_params

#define T_finalize_w_params   ShapeTypeExtended_finalize_w_params
#define T_copy       ShapeTypeExtended_copy

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
const char *CameraImage_CameraImageDataTYPENAME = "CameraImage::CameraImageData";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* CameraImage_CameraImageData_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode CameraImage_CameraImageData_g_tc_data_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,(MAX_IMAGE_SIZE), NULL,NULL);

    static DDS_TypeCode_Member CameraImage_CameraImageData_g_tc_members[5]=
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"sec_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"nanosec_",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"seqnum",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"data",/* Member name */
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
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode CameraImage_CameraImageData_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"CameraImage::CameraImageData", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            5, /* Number of members */
            CameraImage_CameraImageData_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for CameraImage_CameraImageData*/

    if (is_initialized) {
        return &CameraImage_CameraImageData_g_tc;
    }

    CameraImage_CameraImageData_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    CameraImage_CameraImageData_g_tc_data_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_octet_w_new;
    CameraImage_CameraImageData_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    CameraImage_CameraImageData_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    CameraImage_CameraImageData_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    CameraImage_CameraImageData_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    CameraImage_CameraImageData_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)& CameraImage_CameraImageData_g_tc_data_array;

    /* Initialize the values for member annotations. */
    CameraImage_CameraImageData_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[0]._annotations._defaultValue._u.ulong_value = 0u;
    CameraImage_CameraImageData_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[0]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    CameraImage_CameraImageData_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[0]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    CameraImage_CameraImageData_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    CameraImage_CameraImageData_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
    CameraImage_CameraImageData_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    CameraImage_CameraImageData_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    CameraImage_CameraImageData_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    CameraImage_CameraImageData_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

    CameraImage_CameraImageData_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[2]._annotations._defaultValue._u.ulong_value = 0u;
    CameraImage_CameraImageData_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[2]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    CameraImage_CameraImageData_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[2]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    CameraImage_CameraImageData_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[3]._annotations._defaultValue._u.ulong_value = 0u;
    CameraImage_CameraImageData_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[3]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    CameraImage_CameraImageData_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    CameraImage_CameraImageData_g_tc_members[3]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    CameraImage_CameraImageData_g_tc._data._sampleAccessInfo =
    CameraImage_CameraImageData_get_sample_access_info();
    CameraImage_CameraImageData_g_tc._data._typePlugin =
    CameraImage_CameraImageData_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &CameraImage_CameraImageData_g_tc;
}

#define TSeq CameraImage_CameraImageDataSeq
#define T CameraImage_CameraImageData
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *CameraImage_CameraImageData_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo CameraImage_CameraImageData_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(CameraImage_CameraImageDataSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        CameraImage_CameraImageDataSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &CameraImage_CameraImageData_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *CameraImage_CameraImageData_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    CameraImage_CameraImageData *sample;

    static RTIXCdrMemberAccessInfo CameraImage_CameraImageData_g_memberAccessInfos[5] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo CameraImage_CameraImageData_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &CameraImage_CameraImageData_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        CameraImage_CameraImageData);
    if (sample == NULL) {
        return NULL;
    }

    CameraImage_CameraImageData_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->id - (char *)sample);

    CameraImage_CameraImageData_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->sec_ - (char *)sample);

    CameraImage_CameraImageData_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->nanosec_ - (char *)sample);

    CameraImage_CameraImageData_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->seqnum - (char *)sample);

    CameraImage_CameraImageData_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->data - (char *)sample);

    CameraImage_CameraImageData_g_sampleAccessInfo.memberAccessInfos = 
    CameraImage_CameraImageData_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(CameraImage_CameraImageData);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            CameraImage_CameraImageData_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            CameraImage_CameraImageData_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    CameraImage_CameraImageData_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    CameraImage_CameraImageData_g_sampleAccessInfo.getMemberValuePointerFcn = 
    CameraImage_CameraImageData_get_member_value_pointer;

    CameraImage_CameraImageData_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &CameraImage_CameraImageData_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *CameraImage_CameraImageData_get_type_plugin_info()
{
    static RTIXCdrTypePlugin CameraImage_CameraImageData_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        CameraImage_CameraImageData_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        CameraImage_CameraImageData_finalize_w_return,
        NULL
    };

    return &CameraImage_CameraImageData_g_typePlugin;
}
#endif

RTIBool CameraImage_CameraImageData_initialize(
    CameraImage_CameraImageData* sample) {
    return CameraImage_CameraImageData_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool CameraImage_CameraImageData_initialize_ex(
    CameraImage_CameraImageData* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return CameraImage_CameraImageData_initialize_w_params(
        sample,&allocParams);

}

RTIBool CameraImage_CameraImageData_initialize_w_params(
    CameraImage_CameraImageData* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->id = 0u;

    sample->sec_ = 0;

    sample->nanosec_ = 0u;

    sample->seqnum = 0u;

    if (!RTICdrType_initArray(
        sample->data, ((MAX_IMAGE_SIZE)), RTI_CDR_OCTET_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool CameraImage_CameraImageData_finalize_w_return(
    CameraImage_CameraImageData* sample)
{
    CameraImage_CameraImageData_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void CameraImage_CameraImageData_finalize(
    CameraImage_CameraImageData* sample)
{

    CameraImage_CameraImageData_finalize_ex(sample,RTI_TRUE);
}

void CameraImage_CameraImageData_finalize_ex(
    CameraImage_CameraImageData* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    CameraImage_CameraImageData_finalize_w_params(
        sample,&deallocParams);
}

void CameraImage_CameraImageData_finalize_w_params(
    CameraImage_CameraImageData* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void CameraImage_CameraImageData_finalize_optional_members(
    CameraImage_CameraImageData* sample, RTIBool deletePointers)
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

RTIBool CameraImage_CameraImageData_copy(
    CameraImage_CameraImageData* dst,
    const CameraImage_CameraImageData* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyUnsignedLong (
            &dst->id, &src->id)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->sec_, &src->sec_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->nanosec_, &src->nanosec_)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->seqnum, &src->seqnum)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyArray(
            dst->data ,src->data,((MAX_IMAGE_SIZE)), RTI_CDR_OCTET_SIZE)) {
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'CameraImage_CameraImageData' sequence class.
*/
#define T CameraImage_CameraImageData
#define TSeq CameraImage_CameraImageDataSeq

#define T_initialize_w_params CameraImage_CameraImageData_initialize_w_params

#define T_finalize_w_params   CameraImage_CameraImageData_finalize_w_params
#define T_copy       CameraImage_CameraImageData_copy

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

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<POSIXTimestamp>::get() 
        {
            return (const RTIXCdrTypeCode *) POSIXTimestamp_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Alerts_DriverAlerts>::get() 
        {
            return (const RTIXCdrTypeCode *) Alerts_DriverAlerts_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Lane_LaneObject>::get() 
        {
            return (const RTIXCdrTypeCode *) Lane_LaneObject_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Lane_LaneSensor>::get() 
        {
            return (const RTIXCdrTypeCode *) Lane_LaneSensor_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Lidar_Point>::get() 
        {
            return (const RTIXCdrTypeCode *) Lidar_Point_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Lidar_PCloud>::get() 
        {
            return (const RTIXCdrTypeCode *) Lidar_PCloud_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Lidar_LidarSensor>::get() 
        {
            return (const RTIXCdrTypeCode *) Lidar_LidarSensor_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Platform_PlatformControl>::get() 
        {
            return (const RTIXCdrTypeCode *) Platform_PlatformControl_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Platform_PlatformStatus>::get() 
        {
            return (const RTIXCdrTypeCode *) Platform_PlatformStatus_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Sensor_SensorObject>::get() 
        {
            return (const RTIXCdrTypeCode *) Sensor_SensorObject_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Sensor_SensorObjectList>::get() 
        {
            return (const RTIXCdrTypeCode *) Sensor_SensorObjectList_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Vision_VisionObject>::get() 
        {
            return (const RTIXCdrTypeCode *) Vision_VisionObject_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Vision_VisionSensor>::get() 
        {
            return (const RTIXCdrTypeCode *) Vision_VisionSensor_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<builtin_interfaces_msg_dds__Time_>::get() 
        {
            return (const RTIXCdrTypeCode *) builtin_interfaces_msg_dds__Time__get_typecode();
        }

        const RTIXCdrTypeCode * type_code<std_msgs_msg_dds__Header_>::get() 
        {
            return (const RTIXCdrTypeCode *) std_msgs_msg_dds__Header__get_typecode();
        }

        const RTIXCdrTypeCode * type_code<sensor_msgs_msg_dds__PointField_>::get() 
        {
            return (const RTIXCdrTypeCode *) sensor_msgs_msg_dds__PointField__get_typecode();
        }

        const RTIXCdrTypeCode * type_code<sensor_msgs_msg_dds__PointCloud2_>::get() 
        {
            return (const RTIXCdrTypeCode *) sensor_msgs_msg_dds__PointCloud2__get_typecode();
        }

        const RTIXCdrTypeCode * type_code<ShapeType>::get() 
        {
            return (const RTIXCdrTypeCode *) ShapeType_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<ShapeTypeExtended>::get() 
        {
            return (const RTIXCdrTypeCode *) ShapeTypeExtended_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<CameraImage_CameraImageData>::get() 
        {
            return (const RTIXCdrTypeCode *) CameraImage_CameraImageData_get_typecode();
        }

    } 
}
#endif
