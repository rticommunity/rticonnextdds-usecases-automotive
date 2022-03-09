

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from automotive.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef automotivePlugin_2097331918_h
#define automotivePlugin_2097331918_h

#include "automotive.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C"{

    #define POSIXTimestampPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define POSIXTimestampPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define POSIXTimestampPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define POSIXTimestampPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define POSIXTimestampPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern POSIXTimestamp*
    POSIXTimestampPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern POSIXTimestamp*
    POSIXTimestampPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern POSIXTimestamp*
    POSIXTimestampPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPluginSupport_copy_data(
        POSIXTimestamp *out,
        const POSIXTimestamp *in);

    NDDSUSERDllExport extern void 
    POSIXTimestampPluginSupport_destroy_data_w_params(
        POSIXTimestamp *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    POSIXTimestampPluginSupport_destroy_data_ex(
        POSIXTimestamp *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    POSIXTimestampPluginSupport_destroy_data(
        POSIXTimestamp *sample);

    NDDSUSERDllExport extern void 
    POSIXTimestampPluginSupport_print_data(
        const POSIXTimestamp *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    POSIXTimestampPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    POSIXTimestampPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    POSIXTimestampPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    POSIXTimestampPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    POSIXTimestampPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp *out,
        const POSIXTimestamp *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const POSIXTimestamp *sample); 

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const POSIXTimestamp *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_deserialize_from_cdr_buffer(
        POSIXTimestamp *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    POSIXTimestampPlugin_data_to_string(
        const POSIXTimestamp *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    POSIXTimestampPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * POSIXTimestampPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    POSIXTimestampPlugin_new(void);

    NDDSUSERDllExport extern void
    POSIXTimestampPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    IndicatorStatusEnumPluginSupport_print_data(
        const IndicatorStatusEnum *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    ClassificationEnumPluginSupport_print_data(
        const ClassificationEnum *sample, const char *desc, int indent_level);

    #define Alerts_DriverAlertsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Alerts_DriverAlertsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Alerts_DriverAlertsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Alerts_DriverAlertsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Alerts_DriverAlertsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Alerts_DriverAlerts*
    Alerts_DriverAlertsPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Alerts_DriverAlerts*
    Alerts_DriverAlertsPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Alerts_DriverAlerts*
    Alerts_DriverAlertsPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPluginSupport_copy_data(
        Alerts_DriverAlerts *out,
        const Alerts_DriverAlerts *in);

    NDDSUSERDllExport extern void 
    Alerts_DriverAlertsPluginSupport_destroy_data_w_params(
        Alerts_DriverAlerts *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Alerts_DriverAlertsPluginSupport_destroy_data_ex(
        Alerts_DriverAlerts *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Alerts_DriverAlertsPluginSupport_destroy_data(
        Alerts_DriverAlerts *sample);

    NDDSUSERDllExport extern void 
    Alerts_DriverAlertsPluginSupport_print_data(
        const Alerts_DriverAlerts *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Alerts_DriverAlertsPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Alerts_DriverAlertsPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Alerts_DriverAlertsPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Alerts_DriverAlertsPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Alerts_DriverAlertsPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts *out,
        const Alerts_DriverAlerts *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Alerts_DriverAlerts *sample); 

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Alerts_DriverAlerts *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_deserialize_from_cdr_buffer(
        Alerts_DriverAlerts *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Alerts_DriverAlertsPlugin_data_to_string(
        const Alerts_DriverAlerts *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Alerts_DriverAlertsPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Alerts_DriverAlertsPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Alerts_DriverAlertsPlugin_new(void);

    NDDSUSERDllExport extern void
    Alerts_DriverAlertsPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    Lane_ConfidenceEnumPluginSupport_print_data(
        const Lane_ConfidenceEnum *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    Lane_LaneBoundaryEnumPluginSupport_print_data(
        const Lane_LaneBoundaryEnum *sample, const char *desc, int indent_level);

    #define Lane_LaneObjectPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Lane_LaneObjectPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Lane_LaneObjectPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Lane_LaneObjectPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Lane_LaneObjectPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Lane_LaneObject*
    Lane_LaneObjectPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Lane_LaneObject*
    Lane_LaneObjectPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Lane_LaneObject*
    Lane_LaneObjectPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPluginSupport_copy_data(
        Lane_LaneObject *out,
        const Lane_LaneObject *in);

    NDDSUSERDllExport extern void 
    Lane_LaneObjectPluginSupport_destroy_data_w_params(
        Lane_LaneObject *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Lane_LaneObjectPluginSupport_destroy_data_ex(
        Lane_LaneObject *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Lane_LaneObjectPluginSupport_destroy_data(
        Lane_LaneObject *sample);

    NDDSUSERDllExport extern void 
    Lane_LaneObjectPluginSupport_print_data(
        const Lane_LaneObject *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Lane_LaneObjectPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Lane_LaneObjectPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Lane_LaneObjectPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Lane_LaneObjectPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Lane_LaneObjectPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject *out,
        const Lane_LaneObject *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lane_LaneObject *sample); 

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Lane_LaneObject *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_deserialize_from_cdr_buffer(
        Lane_LaneObject *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Lane_LaneObjectPlugin_data_to_string(
        const Lane_LaneObject *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lane_LaneObjectPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Lane_LaneObjectPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Lane_LaneObjectPlugin_new(void);

    NDDSUSERDllExport extern void
    Lane_LaneObjectPlugin_delete(struct PRESTypePlugin *);

    #define Lane_LaneSensorPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Lane_LaneSensorPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Lane_LaneSensorPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Lane_LaneSensorPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Lane_LaneSensorPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Lane_LaneSensor*
    Lane_LaneSensorPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Lane_LaneSensor*
    Lane_LaneSensorPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Lane_LaneSensor*
    Lane_LaneSensorPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPluginSupport_copy_data(
        Lane_LaneSensor *out,
        const Lane_LaneSensor *in);

    NDDSUSERDllExport extern void 
    Lane_LaneSensorPluginSupport_destroy_data_w_params(
        Lane_LaneSensor *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Lane_LaneSensorPluginSupport_destroy_data_ex(
        Lane_LaneSensor *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Lane_LaneSensorPluginSupport_destroy_data(
        Lane_LaneSensor *sample);

    NDDSUSERDllExport extern void 
    Lane_LaneSensorPluginSupport_print_data(
        const Lane_LaneSensor *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Lane_LaneSensorPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Lane_LaneSensorPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Lane_LaneSensorPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Lane_LaneSensorPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Lane_LaneSensorPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor *out,
        const Lane_LaneSensor *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lane_LaneSensor *sample); 

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Lane_LaneSensor *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_deserialize_from_cdr_buffer(
        Lane_LaneSensor *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Lane_LaneSensorPlugin_data_to_string(
        const Lane_LaneSensor *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lane_LaneSensorPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Lane_LaneSensorPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Lane_LaneSensorPlugin_new(void);

    NDDSUSERDllExport extern void
    Lane_LaneSensorPlugin_delete(struct PRESTypePlugin *);

    #define Lidar_PointPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Lidar_PointPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Lidar_PointPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Lidar_PointPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Lidar_PointPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Lidar_Point*
    Lidar_PointPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Lidar_Point*
    Lidar_PointPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Lidar_Point*
    Lidar_PointPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPluginSupport_copy_data(
        Lidar_Point *out,
        const Lidar_Point *in);

    NDDSUSERDllExport extern void 
    Lidar_PointPluginSupport_destroy_data_w_params(
        Lidar_Point *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Lidar_PointPluginSupport_destroy_data_ex(
        Lidar_Point *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Lidar_PointPluginSupport_destroy_data(
        Lidar_Point *sample);

    NDDSUSERDllExport extern void 
    Lidar_PointPluginSupport_print_data(
        const Lidar_Point *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Lidar_PointPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Lidar_PointPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Lidar_PointPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Lidar_PointPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Lidar_PointPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point *out,
        const Lidar_Point *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lidar_Point *sample); 

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Lidar_Point *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_deserialize_from_cdr_buffer(
        Lidar_Point *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Lidar_PointPlugin_data_to_string(
        const Lidar_Point *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lidar_PointPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Lidar_PointPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Lidar_PointPlugin_new(void);

    NDDSUSERDllExport extern void
    Lidar_PointPlugin_delete(struct PRESTypePlugin *);

    #define Lidar_PCloudPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Lidar_PCloudPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Lidar_PCloudPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Lidar_PCloudPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Lidar_PCloudPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Lidar_PCloud*
    Lidar_PCloudPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Lidar_PCloud*
    Lidar_PCloudPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Lidar_PCloud*
    Lidar_PCloudPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPluginSupport_copy_data(
        Lidar_PCloud *out,
        const Lidar_PCloud *in);

    NDDSUSERDllExport extern void 
    Lidar_PCloudPluginSupport_destroy_data_w_params(
        Lidar_PCloud *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Lidar_PCloudPluginSupport_destroy_data_ex(
        Lidar_PCloud *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Lidar_PCloudPluginSupport_destroy_data(
        Lidar_PCloud *sample);

    NDDSUSERDllExport extern void 
    Lidar_PCloudPluginSupport_print_data(
        const Lidar_PCloud *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Lidar_PCloudPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Lidar_PCloudPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Lidar_PCloudPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Lidar_PCloudPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Lidar_PCloudPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud *out,
        const Lidar_PCloud *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lidar_PCloud *sample); 

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Lidar_PCloud *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_deserialize_from_cdr_buffer(
        Lidar_PCloud *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Lidar_PCloudPlugin_data_to_string(
        const Lidar_PCloud *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lidar_PCloudPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Lidar_PCloudPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Lidar_PCloudPlugin_new(void);

    NDDSUSERDllExport extern void
    Lidar_PCloudPlugin_delete(struct PRESTypePlugin *);

    #define Lidar_LidarSensorPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Lidar_LidarSensorPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Lidar_LidarSensorPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Lidar_LidarSensorPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Lidar_LidarSensorPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Lidar_LidarSensor*
    Lidar_LidarSensorPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Lidar_LidarSensor*
    Lidar_LidarSensorPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Lidar_LidarSensor*
    Lidar_LidarSensorPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPluginSupport_copy_data(
        Lidar_LidarSensor *out,
        const Lidar_LidarSensor *in);

    NDDSUSERDllExport extern void 
    Lidar_LidarSensorPluginSupport_destroy_data_w_params(
        Lidar_LidarSensor *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Lidar_LidarSensorPluginSupport_destroy_data_ex(
        Lidar_LidarSensor *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Lidar_LidarSensorPluginSupport_destroy_data(
        Lidar_LidarSensor *sample);

    NDDSUSERDllExport extern void 
    Lidar_LidarSensorPluginSupport_print_data(
        const Lidar_LidarSensor *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Lidar_LidarSensorPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Lidar_LidarSensorPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Lidar_LidarSensorPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Lidar_LidarSensorPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Lidar_LidarSensorPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor *out,
        const Lidar_LidarSensor *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lidar_LidarSensor *sample); 

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Lidar_LidarSensor *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_deserialize_from_cdr_buffer(
        Lidar_LidarSensor *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Lidar_LidarSensorPlugin_data_to_string(
        const Lidar_LidarSensor *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lidar_LidarSensorPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Lidar_LidarSensorPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Lidar_LidarSensorPlugin_new(void);

    NDDSUSERDllExport extern void
    Lidar_LidarSensorPlugin_delete(struct PRESTypePlugin *);

    #define Platform_PlatformControlPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Platform_PlatformControlPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Platform_PlatformControlPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Platform_PlatformControlPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Platform_PlatformControlPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Platform_PlatformControl*
    Platform_PlatformControlPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Platform_PlatformControl*
    Platform_PlatformControlPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Platform_PlatformControl*
    Platform_PlatformControlPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPluginSupport_copy_data(
        Platform_PlatformControl *out,
        const Platform_PlatformControl *in);

    NDDSUSERDllExport extern void 
    Platform_PlatformControlPluginSupport_destroy_data_w_params(
        Platform_PlatformControl *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Platform_PlatformControlPluginSupport_destroy_data_ex(
        Platform_PlatformControl *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Platform_PlatformControlPluginSupport_destroy_data(
        Platform_PlatformControl *sample);

    NDDSUSERDllExport extern void 
    Platform_PlatformControlPluginSupport_print_data(
        const Platform_PlatformControl *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Platform_PlatformControlPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Platform_PlatformControlPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Platform_PlatformControlPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Platform_PlatformControlPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Platform_PlatformControlPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl *out,
        const Platform_PlatformControl *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Platform_PlatformControl *sample); 

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Platform_PlatformControl *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_deserialize_from_cdr_buffer(
        Platform_PlatformControl *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Platform_PlatformControlPlugin_data_to_string(
        const Platform_PlatformControl *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Platform_PlatformControlPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Platform_PlatformControlPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Platform_PlatformControlPlugin_new(void);

    NDDSUSERDllExport extern void
    Platform_PlatformControlPlugin_delete(struct PRESTypePlugin *);

    #define Platform_PlatformStatusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Platform_PlatformStatusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Platform_PlatformStatusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Platform_PlatformStatusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Platform_PlatformStatusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Platform_PlatformStatus*
    Platform_PlatformStatusPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Platform_PlatformStatus*
    Platform_PlatformStatusPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Platform_PlatformStatus*
    Platform_PlatformStatusPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPluginSupport_copy_data(
        Platform_PlatformStatus *out,
        const Platform_PlatformStatus *in);

    NDDSUSERDllExport extern void 
    Platform_PlatformStatusPluginSupport_destroy_data_w_params(
        Platform_PlatformStatus *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Platform_PlatformStatusPluginSupport_destroy_data_ex(
        Platform_PlatformStatus *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Platform_PlatformStatusPluginSupport_destroy_data(
        Platform_PlatformStatus *sample);

    NDDSUSERDllExport extern void 
    Platform_PlatformStatusPluginSupport_print_data(
        const Platform_PlatformStatus *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Platform_PlatformStatusPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Platform_PlatformStatusPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Platform_PlatformStatusPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Platform_PlatformStatusPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Platform_PlatformStatusPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus *out,
        const Platform_PlatformStatus *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Platform_PlatformStatus *sample); 

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Platform_PlatformStatus *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_deserialize_from_cdr_buffer(
        Platform_PlatformStatus *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Platform_PlatformStatusPlugin_data_to_string(
        const Platform_PlatformStatus *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Platform_PlatformStatusPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Platform_PlatformStatusPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Platform_PlatformStatusPlugin_new(void);

    NDDSUSERDllExport extern void
    Platform_PlatformStatusPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    Sensor_RangeModeEnumPluginSupport_print_data(
        const Sensor_RangeModeEnum *sample, const char *desc, int indent_level);

    #define Sensor_SensorObjectPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Sensor_SensorObjectPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Sensor_SensorObjectPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Sensor_SensorObjectPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Sensor_SensorObjectPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Sensor_SensorObject*
    Sensor_SensorObjectPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Sensor_SensorObject*
    Sensor_SensorObjectPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Sensor_SensorObject*
    Sensor_SensorObjectPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPluginSupport_copy_data(
        Sensor_SensorObject *out,
        const Sensor_SensorObject *in);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectPluginSupport_destroy_data_w_params(
        Sensor_SensorObject *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectPluginSupport_destroy_data_ex(
        Sensor_SensorObject *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectPluginSupport_destroy_data(
        Sensor_SensorObject *sample);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectPluginSupport_print_data(
        const Sensor_SensorObject *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Sensor_SensorObjectPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Sensor_SensorObjectPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Sensor_SensorObjectPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject *out,
        const Sensor_SensorObject *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Sensor_SensorObject *sample); 

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Sensor_SensorObject *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_deserialize_from_cdr_buffer(
        Sensor_SensorObject *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Sensor_SensorObjectPlugin_data_to_string(
        const Sensor_SensorObject *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Sensor_SensorObjectPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Sensor_SensorObjectPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Sensor_SensorObjectPlugin_new(void);

    NDDSUSERDllExport extern void
    Sensor_SensorObjectPlugin_delete(struct PRESTypePlugin *);

    #define Sensor_SensorObjectListPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Sensor_SensorObjectListPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Sensor_SensorObjectListPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Sensor_SensorObjectListPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Sensor_SensorObjectListPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Sensor_SensorObjectList*
    Sensor_SensorObjectListPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Sensor_SensorObjectList*
    Sensor_SensorObjectListPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Sensor_SensorObjectList*
    Sensor_SensorObjectListPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPluginSupport_copy_data(
        Sensor_SensorObjectList *out,
        const Sensor_SensorObjectList *in);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectListPluginSupport_destroy_data_w_params(
        Sensor_SensorObjectList *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectListPluginSupport_destroy_data_ex(
        Sensor_SensorObjectList *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectListPluginSupport_destroy_data(
        Sensor_SensorObjectList *sample);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectListPluginSupport_print_data(
        const Sensor_SensorObjectList *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Sensor_SensorObjectListPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectListPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Sensor_SensorObjectListPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Sensor_SensorObjectListPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Sensor_SensorObjectListPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList *out,
        const Sensor_SensorObjectList *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Sensor_SensorObjectList *sample); 

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Sensor_SensorObjectList *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_deserialize_from_cdr_buffer(
        Sensor_SensorObjectList *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Sensor_SensorObjectListPlugin_data_to_string(
        const Sensor_SensorObjectList *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Sensor_SensorObjectListPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Sensor_SensorObjectListPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Sensor_SensorObjectListPlugin_new(void);

    NDDSUSERDllExport extern void
    Sensor_SensorObjectListPlugin_delete(struct PRESTypePlugin *);

    #define Vision_VisionObjectPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Vision_VisionObjectPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Vision_VisionObjectPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Vision_VisionObjectPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Vision_VisionObjectPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Vision_VisionObject*
    Vision_VisionObjectPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Vision_VisionObject*
    Vision_VisionObjectPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Vision_VisionObject*
    Vision_VisionObjectPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPluginSupport_copy_data(
        Vision_VisionObject *out,
        const Vision_VisionObject *in);

    NDDSUSERDllExport extern void 
    Vision_VisionObjectPluginSupport_destroy_data_w_params(
        Vision_VisionObject *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Vision_VisionObjectPluginSupport_destroy_data_ex(
        Vision_VisionObject *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Vision_VisionObjectPluginSupport_destroy_data(
        Vision_VisionObject *sample);

    NDDSUSERDllExport extern void 
    Vision_VisionObjectPluginSupport_print_data(
        const Vision_VisionObject *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Vision_VisionObjectPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Vision_VisionObjectPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Vision_VisionObjectPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Vision_VisionObjectPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Vision_VisionObjectPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject *out,
        const Vision_VisionObject *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Vision_VisionObject *sample); 

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Vision_VisionObject *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_deserialize_from_cdr_buffer(
        Vision_VisionObject *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Vision_VisionObjectPlugin_data_to_string(
        const Vision_VisionObject *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Vision_VisionObjectPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Vision_VisionObjectPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Vision_VisionObjectPlugin_new(void);

    NDDSUSERDllExport extern void
    Vision_VisionObjectPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct VisionSensor
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct VisionSensor)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * VisionSensor must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct VisionSensor.
    */
    typedef  class Vision_VisionSensor Vision_VisionSensorKeyHolder;

    #define Vision_VisionSensorPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Vision_VisionSensorPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Vision_VisionSensorPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Vision_VisionSensorPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define Vision_VisionSensorPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define Vision_VisionSensorPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Vision_VisionSensorPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Vision_VisionSensor*
    Vision_VisionSensorPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Vision_VisionSensor*
    Vision_VisionSensorPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Vision_VisionSensor*
    Vision_VisionSensorPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPluginSupport_copy_data(
        Vision_VisionSensor *out,
        const Vision_VisionSensor *in);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPluginSupport_destroy_data_w_params(
        Vision_VisionSensor *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPluginSupport_destroy_data_ex(
        Vision_VisionSensor *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPluginSupport_destroy_data(
        Vision_VisionSensor *sample);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPluginSupport_print_data(
        const Vision_VisionSensor *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern Vision_VisionSensor*
    Vision_VisionSensorPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Vision_VisionSensor*
    Vision_VisionSensorPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPluginSupport_destroy_key_ex(
        Vision_VisionSensorKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPluginSupport_destroy_key(
        Vision_VisionSensorKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Vision_VisionSensorPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Vision_VisionSensorPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Vision_VisionSensorPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Vision_VisionSensorPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor *out,
        const Vision_VisionSensor *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Vision_VisionSensorPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Vision_VisionSensor *sample); 

    NDDSUSERDllExport extern RTIBool
    Vision_VisionSensorPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Vision_VisionSensor *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionSensorPlugin_deserialize_from_cdr_buffer(
        Vision_VisionSensor *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Vision_VisionSensorPlugin_data_to_string(
        const Vision_VisionSensor *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Vision_VisionSensorPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensorKeyHolder *key, 
        const Vision_VisionSensor *instance);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor *instance, 
        const Vision_VisionSensorKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * Vision_VisionSensorPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Vision_VisionSensorPlugin_new(void);

    NDDSUSERDllExport extern void
    Vision_VisionSensorPlugin_delete(struct PRESTypePlugin *);

    #define builtin_interfaces_msg_dds__Time_Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define builtin_interfaces_msg_dds__Time_Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define builtin_interfaces_msg_dds__Time_Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define builtin_interfaces_msg_dds__Time_Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define builtin_interfaces_msg_dds__Time_Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern builtin_interfaces_msg_dds__Time_*
    builtin_interfaces_msg_dds__Time_PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern builtin_interfaces_msg_dds__Time_*
    builtin_interfaces_msg_dds__Time_PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern builtin_interfaces_msg_dds__Time_*
    builtin_interfaces_msg_dds__Time_PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    builtin_interfaces_msg_dds__Time_PluginSupport_copy_data(
        builtin_interfaces_msg_dds__Time_ *out,
        const builtin_interfaces_msg_dds__Time_ *in);

    NDDSUSERDllExport extern void 
    builtin_interfaces_msg_dds__Time_PluginSupport_destroy_data_w_params(
        builtin_interfaces_msg_dds__Time_ *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    builtin_interfaces_msg_dds__Time_PluginSupport_destroy_data_ex(
        builtin_interfaces_msg_dds__Time_ *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    builtin_interfaces_msg_dds__Time_PluginSupport_destroy_data(
        builtin_interfaces_msg_dds__Time_ *sample);

    NDDSUSERDllExport extern void 
    builtin_interfaces_msg_dds__Time_PluginSupport_print_data(
        const builtin_interfaces_msg_dds__Time_ *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    builtin_interfaces_msg_dds__Time_Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    builtin_interfaces_msg_dds__Time_Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    builtin_interfaces_msg_dds__Time_Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    builtin_interfaces_msg_dds__Time_Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    builtin_interfaces_msg_dds__Time_Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        builtin_interfaces_msg_dds__Time_ *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    builtin_interfaces_msg_dds__Time_Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        builtin_interfaces_msg_dds__Time_ *out,
        const builtin_interfaces_msg_dds__Time_ *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    builtin_interfaces_msg_dds__Time_Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const builtin_interfaces_msg_dds__Time_ *sample); 

    NDDSUSERDllExport extern RTIBool
    builtin_interfaces_msg_dds__Time_Plugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const builtin_interfaces_msg_dds__Time_ *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    builtin_interfaces_msg_dds__Time_Plugin_deserialize_from_cdr_buffer(
        builtin_interfaces_msg_dds__Time_ *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    builtin_interfaces_msg_dds__Time_Plugin_data_to_string(
        const builtin_interfaces_msg_dds__Time_ *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    builtin_interfaces_msg_dds__Time_Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    builtin_interfaces_msg_dds__Time_Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    builtin_interfaces_msg_dds__Time_Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    builtin_interfaces_msg_dds__Time_Plugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    builtin_interfaces_msg_dds__Time_Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        builtin_interfaces_msg_dds__Time_ ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * builtin_interfaces_msg_dds__Time_Plugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    builtin_interfaces_msg_dds__Time_Plugin_new(void);

    NDDSUSERDllExport extern void
    builtin_interfaces_msg_dds__Time_Plugin_delete(struct PRESTypePlugin *);

    #define std_msgs_msg_dds__Header_Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define std_msgs_msg_dds__Header_Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define std_msgs_msg_dds__Header_Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define std_msgs_msg_dds__Header_Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define std_msgs_msg_dds__Header_Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern std_msgs_msg_dds__Header_*
    std_msgs_msg_dds__Header_PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern std_msgs_msg_dds__Header_*
    std_msgs_msg_dds__Header_PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern std_msgs_msg_dds__Header_*
    std_msgs_msg_dds__Header_PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    std_msgs_msg_dds__Header_PluginSupport_copy_data(
        std_msgs_msg_dds__Header_ *out,
        const std_msgs_msg_dds__Header_ *in);

    NDDSUSERDllExport extern void 
    std_msgs_msg_dds__Header_PluginSupport_destroy_data_w_params(
        std_msgs_msg_dds__Header_ *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    std_msgs_msg_dds__Header_PluginSupport_destroy_data_ex(
        std_msgs_msg_dds__Header_ *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    std_msgs_msg_dds__Header_PluginSupport_destroy_data(
        std_msgs_msg_dds__Header_ *sample);

    NDDSUSERDllExport extern void 
    std_msgs_msg_dds__Header_PluginSupport_print_data(
        const std_msgs_msg_dds__Header_ *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    std_msgs_msg_dds__Header_Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    std_msgs_msg_dds__Header_Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    std_msgs_msg_dds__Header_Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    std_msgs_msg_dds__Header_Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    std_msgs_msg_dds__Header_Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        std_msgs_msg_dds__Header_ *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    std_msgs_msg_dds__Header_Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        std_msgs_msg_dds__Header_ *out,
        const std_msgs_msg_dds__Header_ *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    std_msgs_msg_dds__Header_Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const std_msgs_msg_dds__Header_ *sample); 

    NDDSUSERDllExport extern RTIBool
    std_msgs_msg_dds__Header_Plugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const std_msgs_msg_dds__Header_ *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    std_msgs_msg_dds__Header_Plugin_deserialize_from_cdr_buffer(
        std_msgs_msg_dds__Header_ *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    std_msgs_msg_dds__Header_Plugin_data_to_string(
        const std_msgs_msg_dds__Header_ *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    std_msgs_msg_dds__Header_Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    std_msgs_msg_dds__Header_Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    std_msgs_msg_dds__Header_Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    std_msgs_msg_dds__Header_Plugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    std_msgs_msg_dds__Header_Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        std_msgs_msg_dds__Header_ ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * std_msgs_msg_dds__Header_Plugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    std_msgs_msg_dds__Header_Plugin_new(void);

    NDDSUSERDllExport extern void
    std_msgs_msg_dds__Header_Plugin_delete(struct PRESTypePlugin *);

    #define sensor_msgs_msg_dds__PointField_Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define sensor_msgs_msg_dds__PointField_Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define sensor_msgs_msg_dds__PointField_Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define sensor_msgs_msg_dds__PointField_Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define sensor_msgs_msg_dds__PointField_Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern sensor_msgs_msg_dds__PointField_*
    sensor_msgs_msg_dds__PointField_PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern sensor_msgs_msg_dds__PointField_*
    sensor_msgs_msg_dds__PointField_PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern sensor_msgs_msg_dds__PointField_*
    sensor_msgs_msg_dds__PointField_PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    sensor_msgs_msg_dds__PointField_PluginSupport_copy_data(
        sensor_msgs_msg_dds__PointField_ *out,
        const sensor_msgs_msg_dds__PointField_ *in);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointField_PluginSupport_destroy_data_w_params(
        sensor_msgs_msg_dds__PointField_ *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointField_PluginSupport_destroy_data_ex(
        sensor_msgs_msg_dds__PointField_ *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointField_PluginSupport_destroy_data(
        sensor_msgs_msg_dds__PointField_ *sample);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointField_PluginSupport_print_data(
        const sensor_msgs_msg_dds__PointField_ *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    sensor_msgs_msg_dds__PointField_Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointField_Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    sensor_msgs_msg_dds__PointField_Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointField_Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    sensor_msgs_msg_dds__PointField_Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        sensor_msgs_msg_dds__PointField_ *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    sensor_msgs_msg_dds__PointField_Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        sensor_msgs_msg_dds__PointField_ *out,
        const sensor_msgs_msg_dds__PointField_ *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    sensor_msgs_msg_dds__PointField_Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const sensor_msgs_msg_dds__PointField_ *sample); 

    NDDSUSERDllExport extern RTIBool
    sensor_msgs_msg_dds__PointField_Plugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const sensor_msgs_msg_dds__PointField_ *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    sensor_msgs_msg_dds__PointField_Plugin_deserialize_from_cdr_buffer(
        sensor_msgs_msg_dds__PointField_ *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    sensor_msgs_msg_dds__PointField_Plugin_data_to_string(
        const sensor_msgs_msg_dds__PointField_ *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    sensor_msgs_msg_dds__PointField_Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    sensor_msgs_msg_dds__PointField_Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    sensor_msgs_msg_dds__PointField_Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    sensor_msgs_msg_dds__PointField_Plugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    sensor_msgs_msg_dds__PointField_Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        sensor_msgs_msg_dds__PointField_ ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * sensor_msgs_msg_dds__PointField_Plugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    sensor_msgs_msg_dds__PointField_Plugin_new(void);

    NDDSUSERDllExport extern void
    sensor_msgs_msg_dds__PointField_Plugin_delete(struct PRESTypePlugin *);

    #define sensor_msgs_msg_dds__PointCloud2_Plugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define sensor_msgs_msg_dds__PointCloud2_Plugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define sensor_msgs_msg_dds__PointCloud2_Plugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define sensor_msgs_msg_dds__PointCloud2_Plugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define sensor_msgs_msg_dds__PointCloud2_Plugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern sensor_msgs_msg_dds__PointCloud2_*
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern sensor_msgs_msg_dds__PointCloud2_*
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern sensor_msgs_msg_dds__PointCloud2_*
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_copy_data(
        sensor_msgs_msg_dds__PointCloud2_ *out,
        const sensor_msgs_msg_dds__PointCloud2_ *in);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_destroy_data_w_params(
        sensor_msgs_msg_dds__PointCloud2_ *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_destroy_data_ex(
        sensor_msgs_msg_dds__PointCloud2_ *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_destroy_data(
        sensor_msgs_msg_dds__PointCloud2_ *sample);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointCloud2_PluginSupport_print_data(
        const sensor_msgs_msg_dds__PointCloud2_ *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    sensor_msgs_msg_dds__PointCloud2_Plugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointCloud2_Plugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    sensor_msgs_msg_dds__PointCloud2_Plugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    sensor_msgs_msg_dds__PointCloud2_Plugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    sensor_msgs_msg_dds__PointCloud2_Plugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        sensor_msgs_msg_dds__PointCloud2_ *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    sensor_msgs_msg_dds__PointCloud2_Plugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        sensor_msgs_msg_dds__PointCloud2_ *out,
        const sensor_msgs_msg_dds__PointCloud2_ *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    sensor_msgs_msg_dds__PointCloud2_Plugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const sensor_msgs_msg_dds__PointCloud2_ *sample); 

    NDDSUSERDllExport extern RTIBool
    sensor_msgs_msg_dds__PointCloud2_Plugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const sensor_msgs_msg_dds__PointCloud2_ *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    sensor_msgs_msg_dds__PointCloud2_Plugin_deserialize_from_cdr_buffer(
        sensor_msgs_msg_dds__PointCloud2_ *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    sensor_msgs_msg_dds__PointCloud2_Plugin_data_to_string(
        const sensor_msgs_msg_dds__PointCloud2_ *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    sensor_msgs_msg_dds__PointCloud2_Plugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    sensor_msgs_msg_dds__PointCloud2_Plugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    sensor_msgs_msg_dds__PointCloud2_Plugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    sensor_msgs_msg_dds__PointCloud2_Plugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    sensor_msgs_msg_dds__PointCloud2_Plugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        sensor_msgs_msg_dds__PointCloud2_ ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * sensor_msgs_msg_dds__PointCloud2_Plugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    sensor_msgs_msg_dds__PointCloud2_Plugin_new(void);

    NDDSUSERDllExport extern void
    sensor_msgs_msg_dds__PointCloud2_Plugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    ShapeFillKindPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    ShapeFillKindPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ShapeFillKindPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    ShapeFillKindPluginSupport_print_data(
        const ShapeFillKind *sample, const char *desc, int indent_level);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ShapeType
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ShapeType)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ShapeType must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ShapeType.
    */
    typedef  class ShapeType ShapeTypeKeyHolder;

    #define ShapeTypePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define ShapeTypePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ShapeTypePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ShapeTypePlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ShapeTypePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ShapeTypePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ShapeTypePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ShapeType*
    ShapeTypePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ShapeType*
    ShapeTypePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ShapeType*
    ShapeTypePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypePluginSupport_copy_data(
        ShapeType *out,
        const ShapeType *in);

    NDDSUSERDllExport extern void 
    ShapeTypePluginSupport_destroy_data_w_params(
        ShapeType *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ShapeTypePluginSupport_destroy_data_ex(
        ShapeType *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ShapeTypePluginSupport_destroy_data(
        ShapeType *sample);

    NDDSUSERDllExport extern void 
    ShapeTypePluginSupport_print_data(
        const ShapeType *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ShapeType*
    ShapeTypePluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ShapeType*
    ShapeTypePluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ShapeTypePluginSupport_destroy_key_ex(
        ShapeTypeKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ShapeTypePluginSupport_destroy_key(
        ShapeTypeKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ShapeTypePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ShapeTypePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ShapeTypePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ShapeTypePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ShapeTypePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ShapeType *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ShapeTypePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ShapeType *out,
        const ShapeType *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ShapeTypePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ShapeType *sample); 

    NDDSUSERDllExport extern RTIBool
    ShapeTypePlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const ShapeType *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    ShapeTypePlugin_deserialize_from_cdr_buffer(
        ShapeType *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    ShapeTypePlugin_data_to_string(
        const ShapeType *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    ShapeTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ShapeTypePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ShapeTypePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ShapeTypePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ShapeType ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypePlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ShapeTypeKeyHolder *key, 
        const ShapeType *instance);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypePlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ShapeType *instance, 
        const ShapeTypeKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypePlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * ShapeTypePlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ShapeTypePlugin_new(void);

    NDDSUSERDllExport extern void
    ShapeTypePlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ShapeTypeExtended
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ShapeTypeExtended)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ShapeTypeExtended must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ShapeTypeExtended.
    */
    typedef  class ShapeTypeExtended ShapeTypeExtendedKeyHolder;

    #define ShapeTypeExtendedPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define ShapeTypeExtendedPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ShapeTypeExtendedPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ShapeTypeExtendedPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ShapeTypeExtendedPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ShapeTypeExtendedPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ShapeTypeExtendedPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ShapeTypeExtended*
    ShapeTypeExtendedPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ShapeTypeExtended*
    ShapeTypeExtendedPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ShapeTypeExtended*
    ShapeTypeExtendedPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypeExtendedPluginSupport_copy_data(
        ShapeTypeExtended *out,
        const ShapeTypeExtended *in);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPluginSupport_destroy_data_w_params(
        ShapeTypeExtended *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPluginSupport_destroy_data_ex(
        ShapeTypeExtended *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPluginSupport_destroy_data(
        ShapeTypeExtended *sample);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPluginSupport_print_data(
        const ShapeTypeExtended *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ShapeTypeExtended*
    ShapeTypeExtendedPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ShapeTypeExtended*
    ShapeTypeExtendedPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPluginSupport_destroy_key_ex(
        ShapeTypeExtendedKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPluginSupport_destroy_key(
        ShapeTypeExtendedKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ShapeTypeExtendedPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ShapeTypeExtendedPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ShapeTypeExtendedPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ShapeTypeExtendedPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ShapeTypeExtended *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ShapeTypeExtendedPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ShapeTypeExtended *out,
        const ShapeTypeExtended *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ShapeTypeExtendedPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ShapeTypeExtended *sample); 

    NDDSUSERDllExport extern RTIBool
    ShapeTypeExtendedPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const ShapeTypeExtended *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    ShapeTypeExtendedPlugin_deserialize_from_cdr_buffer(
        ShapeTypeExtended *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    ShapeTypeExtendedPlugin_data_to_string(
        const ShapeTypeExtended *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    ShapeTypeExtendedPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ShapeTypeExtendedPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ShapeTypeExtendedPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ShapeTypeExtendedPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypeExtendedPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ShapeTypeExtended ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypeExtendedPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ShapeTypeExtendedKeyHolder *key, 
        const ShapeTypeExtended *instance);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypeExtendedPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ShapeTypeExtended *instance, 
        const ShapeTypeExtendedKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ShapeTypeExtendedPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * ShapeTypeExtendedPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ShapeTypeExtendedPlugin_new(void);

    NDDSUSERDllExport extern void
    ShapeTypeExtendedPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct CameraImageData
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct CameraImageData)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * CameraImageData must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct CameraImageData.
    */
    typedef  class CameraImage_CameraImageData CameraImage_CameraImageDataKeyHolder;

    #define CameraImage_CameraImageDataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define CameraImage_CameraImageDataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define CameraImage_CameraImageDataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define CameraImage_CameraImageDataPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define CameraImage_CameraImageDataPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define CameraImage_CameraImageDataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define CameraImage_CameraImageDataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern CameraImage_CameraImageData*
    CameraImage_CameraImageDataPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern CameraImage_CameraImageData*
    CameraImage_CameraImageDataPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern CameraImage_CameraImageData*
    CameraImage_CameraImageDataPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    CameraImage_CameraImageDataPluginSupport_copy_data(
        CameraImage_CameraImageData *out,
        const CameraImage_CameraImageData *in);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPluginSupport_destroy_data_w_params(
        CameraImage_CameraImageData *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPluginSupport_destroy_data_ex(
        CameraImage_CameraImageData *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPluginSupport_destroy_data(
        CameraImage_CameraImageData *sample);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPluginSupport_print_data(
        const CameraImage_CameraImageData *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern CameraImage_CameraImageData*
    CameraImage_CameraImageDataPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern CameraImage_CameraImageData*
    CameraImage_CameraImageDataPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPluginSupport_destroy_key_ex(
        CameraImage_CameraImageDataKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPluginSupport_destroy_key(
        CameraImage_CameraImageDataKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    CameraImage_CameraImageDataPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    CameraImage_CameraImageDataPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    CameraImage_CameraImageDataPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    CameraImage_CameraImageDataPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        CameraImage_CameraImageData *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    CameraImage_CameraImageDataPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        CameraImage_CameraImageData *out,
        const CameraImage_CameraImageData *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    CameraImage_CameraImageDataPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const CameraImage_CameraImageData *sample); 

    NDDSUSERDllExport extern RTIBool
    CameraImage_CameraImageDataPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const CameraImage_CameraImageData *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    CameraImage_CameraImageDataPlugin_deserialize_from_cdr_buffer(
        CameraImage_CameraImageData *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    CameraImage_CameraImageDataPlugin_data_to_string(
        const CameraImage_CameraImageData *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    CameraImage_CameraImageDataPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    CameraImage_CameraImageDataPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    CameraImage_CameraImageDataPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    CameraImage_CameraImageDataPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    CameraImage_CameraImageDataPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        CameraImage_CameraImageData ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    CameraImage_CameraImageDataPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        CameraImage_CameraImageDataKeyHolder *key, 
        const CameraImage_CameraImageData *instance);

    NDDSUSERDllExport extern RTIBool 
    CameraImage_CameraImageDataPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        CameraImage_CameraImageData *instance, 
        const CameraImage_CameraImageDataKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    CameraImage_CameraImageDataPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * CameraImage_CameraImageDataPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    CameraImage_CameraImageDataPlugin_new(void);

    NDDSUSERDllExport extern void
    CameraImage_CameraImageDataPlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* automotivePlugin_2097331918_h */

