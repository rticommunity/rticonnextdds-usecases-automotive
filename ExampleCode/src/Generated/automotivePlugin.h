

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from automotive.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef automotivePlugin_2097329646_h
#define automotivePlugin_2097329646_h

#include "automotive.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C" {

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
    POSIXTimestampPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const POSIXTimestamp *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const POSIXTimestamp *sample); 

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_deserialize_from_cdr_buffer(
        POSIXTimestamp *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    POSIXTimestampPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const POSIXTimestamp * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    POSIXTimestampPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    POSIXTimestampPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const POSIXTimestamp *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    POSIXTimestampPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    POSIXTimestampPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        POSIXTimestamp *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    POSIXTimestampPlugin_new(void);

    NDDSUSERDllExport extern void
    POSIXTimestampPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    IndicatorStatusEnumPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const IndicatorStatusEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    IndicatorStatusEnumPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        IndicatorStatusEnum *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    IndicatorStatusEnumPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    IndicatorStatusEnumPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const IndicatorStatusEnum * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    IndicatorStatusEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    IndicatorStatusEnumPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const IndicatorStatusEnum *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    IndicatorStatusEnumPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        IndicatorStatusEnum * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    IndicatorStatusEnumPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        IndicatorStatusEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    IndicatorStatusEnumPluginSupport_print_data(
        const IndicatorStatusEnum *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    ClassificationEnumPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const ClassificationEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ClassificationEnumPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        ClassificationEnum *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ClassificationEnumPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    ClassificationEnumPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const ClassificationEnum * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ClassificationEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ClassificationEnumPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const ClassificationEnum *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ClassificationEnumPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        ClassificationEnum * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ClassificationEnumPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ClassificationEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Alerts_DriverAlertsPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Alerts_DriverAlerts *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Alerts_DriverAlerts *sample); 

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_deserialize_from_cdr_buffer(
        Alerts_DriverAlerts *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Alerts_DriverAlertsPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Alerts_DriverAlerts * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Alerts_DriverAlertsPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Alerts_DriverAlertsPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Alerts_DriverAlerts *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Alerts_DriverAlertsPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Alerts_DriverAlertsPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Alerts_DriverAlerts *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Alerts_DriverAlertsPlugin_new(void);

    NDDSUSERDllExport extern void
    Alerts_DriverAlertsPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    Lane_ConfidenceEnumPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_ConfidenceEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_ConfidenceEnumPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_ConfidenceEnum *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_ConfidenceEnumPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lane_ConfidenceEnumPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lane_ConfidenceEnum * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_ConfidenceEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lane_ConfidenceEnumPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_ConfidenceEnum *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_ConfidenceEnumPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_ConfidenceEnum * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_ConfidenceEnumPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_ConfidenceEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    Lane_ConfidenceEnumPluginSupport_print_data(
        const Lane_ConfidenceEnum *sample, const char *desc, int indent_level);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneBoundaryEnumPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_LaneBoundaryEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneBoundaryEnumPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneBoundaryEnum *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneBoundaryEnumPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lane_LaneBoundaryEnumPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lane_LaneBoundaryEnum * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneBoundaryEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneBoundaryEnumPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_LaneBoundaryEnum *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneBoundaryEnumPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneBoundaryEnum * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneBoundaryEnumPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneBoundaryEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Lane_LaneObjectPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_LaneObject *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lane_LaneObject *sample); 

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_deserialize_from_cdr_buffer(
        Lane_LaneObject *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lane_LaneObjectPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lane_LaneObject * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lane_LaneObjectPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneObjectPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_LaneObject *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneObjectPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneObjectPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneObject *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Lane_LaneSensorPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_LaneSensor *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lane_LaneSensor *sample); 

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_deserialize_from_cdr_buffer(
        Lane_LaneSensor *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lane_LaneSensorPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lane_LaneSensor * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lane_LaneSensorPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lane_LaneSensorPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lane_LaneSensor *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lane_LaneSensorPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lane_LaneSensorPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lane_LaneSensor *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Lidar_PointPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lidar_Point *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lidar_Point *sample); 

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_deserialize_from_cdr_buffer(
        Lidar_Point *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lidar_PointPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lidar_Point * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lidar_PointPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PointPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lidar_Point *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PointPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_PointPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_Point *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Lidar_PCloudPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lidar_PCloud *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lidar_PCloud *sample); 

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_deserialize_from_cdr_buffer(
        Lidar_PCloud *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lidar_PCloudPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lidar_PCloud * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lidar_PCloudPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_PCloudPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lidar_PCloud *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_PCloudPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_PCloudPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_PCloud *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Lidar_LidarSensorPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Lidar_LidarSensor *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Lidar_LidarSensor *sample); 

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_deserialize_from_cdr_buffer(
        Lidar_LidarSensor *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Lidar_LidarSensorPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Lidar_LidarSensor * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Lidar_LidarSensorPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Lidar_LidarSensorPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Lidar_LidarSensor *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Lidar_LidarSensorPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Lidar_LidarSensorPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Lidar_LidarSensor *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Platform_PlatformControlPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Platform_PlatformControl *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Platform_PlatformControl *sample); 

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_deserialize_from_cdr_buffer(
        Platform_PlatformControl *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Platform_PlatformControlPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Platform_PlatformControl * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Platform_PlatformControlPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformControlPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Platform_PlatformControl *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformControlPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformControlPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformControl *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Platform_PlatformStatusPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Platform_PlatformStatus *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Platform_PlatformStatus *sample); 

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_deserialize_from_cdr_buffer(
        Platform_PlatformStatus *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Platform_PlatformStatusPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Platform_PlatformStatus * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Platform_PlatformStatusPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Platform_PlatformStatusPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Platform_PlatformStatus *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Platform_PlatformStatusPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Platform_PlatformStatusPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Platform_PlatformStatus *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Platform_PlatformStatusPlugin_new(void);

    NDDSUSERDllExport extern void
    Platform_PlatformStatusPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    Sensor_RangeModeEnumPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Sensor_RangeModeEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_RangeModeEnumPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_RangeModeEnum *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_RangeModeEnumPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Sensor_RangeModeEnumPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Sensor_RangeModeEnum * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_RangeModeEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Sensor_RangeModeEnumPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Sensor_RangeModeEnum *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_RangeModeEnumPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_RangeModeEnum * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_RangeModeEnumPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_RangeModeEnum *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Sensor_SensorObjectPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Sensor_SensorObject *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Sensor_SensorObject *sample); 

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_deserialize_from_cdr_buffer(
        Sensor_SensorObject *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Sensor_SensorObjectPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Sensor_SensorObject * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Sensor_SensorObjectPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Sensor_SensorObject *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObject *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Sensor_SensorObjectListPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Sensor_SensorObjectList *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Sensor_SensorObjectList *sample); 

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_deserialize_from_cdr_buffer(
        Sensor_SensorObjectList *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Sensor_SensorObjectListPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Sensor_SensorObjectList * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Sensor_SensorObjectListPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Sensor_SensorObjectListPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Sensor_SensorObjectList *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Sensor_SensorObjectListPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Sensor_SensorObjectListPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Sensor_SensorObjectList *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Vision_VisionObjectPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Vision_VisionObject *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Vision_VisionObject *sample); 

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_deserialize_from_cdr_buffer(
        Vision_VisionObject *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Vision_VisionObjectPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Vision_VisionObject * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Vision_VisionObjectPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionObjectPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Vision_VisionObject *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionObjectPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionObjectPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionObject *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

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
    Vision_VisionSensorPlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const Vision_VisionSensor *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionSensorPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Vision_VisionSensor *sample); 

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Vision_VisionSensorPlugin_deserialize_from_cdr_buffer(
        Vision_VisionSensor *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern RTIBool
    Vision_VisionSensorPlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    Vision_VisionSensorPlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const Vision_VisionSensor * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Vision_VisionSensorPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Vision_VisionSensorPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const Vision_VisionSensor *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

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
    Vision_VisionSensorPlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Vision_VisionSensor *sample,
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
    Vision_VisionSensorPlugin_instance_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        DDS_KeyHash_t *keyhash,
        const Vision_VisionSensor *instance);

    NDDSUSERDllExport extern RTIBool 
    Vision_VisionSensorPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Vision_VisionSensorPlugin_new(void);

    NDDSUSERDllExport extern void
    Vision_VisionSensorPlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* automotivePlugin_2097329646_h */

