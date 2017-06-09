

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from automotive.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef automotive_2097329646_h
#define automotive_2097329646_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *POSIXTimestampTYPENAME;

}

struct POSIXTimestampSeq;
#ifndef NDDS_STANDALONE_TYPE
class POSIXTimestampTypeSupport;
class POSIXTimestampDataWriter;
class POSIXTimestampDataReader;
#endif

class POSIXTimestamp 
{
  public:
    typedef struct POSIXTimestampSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef POSIXTimestampTypeSupport TypeSupport;
    typedef POSIXTimestampDataWriter DataWriter;
    typedef POSIXTimestampDataReader DataReader;
    #endif

    DDS_Long   s ;
    DDS_Long   ns ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* POSIXTimestamp_get_typecode(void); /* Type code */

DDS_SEQUENCE(POSIXTimestampSeq, POSIXTimestamp);                                        

NDDSUSERDllExport
RTIBool POSIXTimestamp_initialize(
    POSIXTimestamp* self);

NDDSUSERDllExport
RTIBool POSIXTimestamp_initialize_ex(
    POSIXTimestamp* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool POSIXTimestamp_initialize_w_params(
    POSIXTimestamp* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void POSIXTimestamp_finalize(
    POSIXTimestamp* self);

NDDSUSERDllExport
void POSIXTimestamp_finalize_ex(
    POSIXTimestamp* self,RTIBool deletePointers);

NDDSUSERDllExport
void POSIXTimestamp_finalize_w_params(
    POSIXTimestamp* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void POSIXTimestamp_finalize_optional_members(
    POSIXTimestamp* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool POSIXTimestamp_copy(
    POSIXTimestamp* dst,
    const POSIXTimestamp* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum IndicatorStatusEnum
{
    INDICATOR_OFF  = 0,      
    INDICATOR_LEFT  = 1,      
    INDICATOR_RIGHT  = 2,      
    INDICATOR_HAZARD  = 3     
} IndicatorStatusEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* IndicatorStatusEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(IndicatorStatusEnumSeq, IndicatorStatusEnum);                                        

NDDSUSERDllExport
RTIBool IndicatorStatusEnum_initialize(
    IndicatorStatusEnum* self);

NDDSUSERDllExport
RTIBool IndicatorStatusEnum_initialize_ex(
    IndicatorStatusEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool IndicatorStatusEnum_initialize_w_params(
    IndicatorStatusEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void IndicatorStatusEnum_finalize(
    IndicatorStatusEnum* self);

NDDSUSERDllExport
void IndicatorStatusEnum_finalize_ex(
    IndicatorStatusEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void IndicatorStatusEnum_finalize_w_params(
    IndicatorStatusEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void IndicatorStatusEnum_finalize_optional_members(
    IndicatorStatusEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool IndicatorStatusEnum_copy(
    IndicatorStatusEnum* dst,
    const IndicatorStatusEnum* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum ClassificationEnum
{
    CLASSIFICATION_UNKNOWN  = 0,      
    CLASSIFICATION_UNKNOWNSMALL  = 1,      
    CLASSIFICATION_UNKNOWNBIG  = 2,      
    CLASSIFICATION_PEDESTRIAN  = 3,      
    CLASSIFICATION_BIKE  = 4,      
    CLASSIFICATION_CAR  = 5,      
    CLASSIFICATION_TRUCK  = 6,      
    CLASSIFICATION_BARRIER  = 7     
} ClassificationEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* ClassificationEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(ClassificationEnumSeq, ClassificationEnum);                                        

NDDSUSERDllExport
RTIBool ClassificationEnum_initialize(
    ClassificationEnum* self);

NDDSUSERDllExport
RTIBool ClassificationEnum_initialize_ex(
    ClassificationEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool ClassificationEnum_initialize_w_params(
    ClassificationEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void ClassificationEnum_finalize(
    ClassificationEnum* self);

NDDSUSERDllExport
void ClassificationEnum_finalize_ex(
    ClassificationEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void ClassificationEnum_finalize_w_params(
    ClassificationEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void ClassificationEnum_finalize_optional_members(
    ClassificationEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool ClassificationEnum_copy(
    ClassificationEnum* dst,
    const ClassificationEnum* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Alerts_DriverAlertsTYPENAME;

}

struct Alerts_DriverAlertsSeq;
#ifndef NDDS_STANDALONE_TYPE
class Alerts_DriverAlertsTypeSupport;
class Alerts_DriverAlertsDataWriter;
class Alerts_DriverAlertsDataReader;
#endif

class Alerts_DriverAlerts 
{
  public:
    typedef struct Alerts_DriverAlertsSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Alerts_DriverAlertsTypeSupport TypeSupport;
    typedef Alerts_DriverAlertsDataWriter DataWriter;
    typedef Alerts_DriverAlertsDataReader DataReader;
    #endif

    DDS_Boolean   blindSpotDriver ;
    DDS_Boolean   blindSpotPassenger ;
    DDS_Boolean   frontCollision ;
    DDS_Boolean   backCollision ;
    DDS_Boolean   parkingCollision ;
    DDS_Boolean   driverAttention ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Alerts_DriverAlerts_get_typecode(void); /* Type code */

DDS_SEQUENCE(Alerts_DriverAlertsSeq, Alerts_DriverAlerts);                                        

NDDSUSERDllExport
RTIBool Alerts_DriverAlerts_initialize(
    Alerts_DriverAlerts* self);

NDDSUSERDllExport
RTIBool Alerts_DriverAlerts_initialize_ex(
    Alerts_DriverAlerts* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Alerts_DriverAlerts_initialize_w_params(
    Alerts_DriverAlerts* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Alerts_DriverAlerts_finalize(
    Alerts_DriverAlerts* self);

NDDSUSERDllExport
void Alerts_DriverAlerts_finalize_ex(
    Alerts_DriverAlerts* self,RTIBool deletePointers);

NDDSUSERDllExport
void Alerts_DriverAlerts_finalize_w_params(
    Alerts_DriverAlerts* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Alerts_DriverAlerts_finalize_optional_members(
    Alerts_DriverAlerts* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Alerts_DriverAlerts_copy(
    Alerts_DriverAlerts* dst,
    const Alerts_DriverAlerts* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum Lane_ConfidenceEnum
{
    CONFIDENCE_NONE  = 0,      
    CONFIDENCE_LOW  = 1,      
    CONFIDENCE_MED  = 2,      
    CONFIDENCE_HIGH  = 3     
} Lane_ConfidenceEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lane_ConfidenceEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lane_ConfidenceEnumSeq, Lane_ConfidenceEnum);                                        

NDDSUSERDllExport
RTIBool Lane_ConfidenceEnum_initialize(
    Lane_ConfidenceEnum* self);

NDDSUSERDllExport
RTIBool Lane_ConfidenceEnum_initialize_ex(
    Lane_ConfidenceEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lane_ConfidenceEnum_initialize_w_params(
    Lane_ConfidenceEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lane_ConfidenceEnum_finalize(
    Lane_ConfidenceEnum* self);

NDDSUSERDllExport
void Lane_ConfidenceEnum_finalize_ex(
    Lane_ConfidenceEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lane_ConfidenceEnum_finalize_w_params(
    Lane_ConfidenceEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lane_ConfidenceEnum_finalize_optional_members(
    Lane_ConfidenceEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lane_ConfidenceEnum_copy(
    Lane_ConfidenceEnum* dst,
    const Lane_ConfidenceEnum* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum Lane_LaneBoundaryEnum
{
    BOUNDRY_NONE  = 0,      
    BOUNDRY_INVALID  = 1,      
    BOUNDRY_SOLID  = 2,      
    BOUNDRY_DASHED  = 3,      
    BOUNDRY_VIRTUAL  = 4,      
    BOUNDRY_DOTS  = 5,      
    BOUNDRY_ROADEDGE  = 6,      
    BOUNDRY_UNDECIDED  = 7,      
    BOUNDRY_DOUBLEMARKER  = 8     
} Lane_LaneBoundaryEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lane_LaneBoundaryEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lane_LaneBoundaryEnumSeq, Lane_LaneBoundaryEnum);                                        

NDDSUSERDllExport
RTIBool Lane_LaneBoundaryEnum_initialize(
    Lane_LaneBoundaryEnum* self);

NDDSUSERDllExport
RTIBool Lane_LaneBoundaryEnum_initialize_ex(
    Lane_LaneBoundaryEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lane_LaneBoundaryEnum_initialize_w_params(
    Lane_LaneBoundaryEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lane_LaneBoundaryEnum_finalize(
    Lane_LaneBoundaryEnum* self);

NDDSUSERDllExport
void Lane_LaneBoundaryEnum_finalize_ex(
    Lane_LaneBoundaryEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lane_LaneBoundaryEnum_finalize_w_params(
    Lane_LaneBoundaryEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lane_LaneBoundaryEnum_finalize_optional_members(
    Lane_LaneBoundaryEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lane_LaneBoundaryEnum_copy(
    Lane_LaneBoundaryEnum* dst,
    const Lane_LaneBoundaryEnum* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Lane_LaneObjectTYPENAME;

}

struct Lane_LaneObjectSeq;
#ifndef NDDS_STANDALONE_TYPE
class Lane_LaneObjectTypeSupport;
class Lane_LaneObjectDataWriter;
class Lane_LaneObjectDataReader;
#endif

class Lane_LaneObject 
{
  public:
    typedef struct Lane_LaneObjectSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Lane_LaneObjectTypeSupport TypeSupport;
    typedef Lane_LaneObjectDataWriter DataWriter;
    typedef Lane_LaneObjectDataReader DataReader;
    #endif

    DDS_Boolean   isValid ;
    Lane_ConfidenceEnum   confidence ;
    Lane_LaneBoundaryEnum   boundaryType ;
    DDS_Float   offset ;
    DDS_Float   headingAngle ;
    DDS_Float   curvature ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lane_LaneObject_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lane_LaneObjectSeq, Lane_LaneObject);                                        

NDDSUSERDllExport
RTIBool Lane_LaneObject_initialize(
    Lane_LaneObject* self);

NDDSUSERDllExport
RTIBool Lane_LaneObject_initialize_ex(
    Lane_LaneObject* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lane_LaneObject_initialize_w_params(
    Lane_LaneObject* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lane_LaneObject_finalize(
    Lane_LaneObject* self);

NDDSUSERDllExport
void Lane_LaneObject_finalize_ex(
    Lane_LaneObject* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lane_LaneObject_finalize_w_params(
    Lane_LaneObject* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lane_LaneObject_finalize_optional_members(
    Lane_LaneObject* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lane_LaneObject_copy(
    Lane_LaneObject* dst,
    const Lane_LaneObject* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Lane_LaneSensorTYPENAME;

}

struct Lane_LaneSensorSeq;
#ifndef NDDS_STANDALONE_TYPE
class Lane_LaneSensorTypeSupport;
class Lane_LaneSensorDataWriter;
class Lane_LaneSensorDataReader;
#endif

class Lane_LaneSensor 
{
  public:
    typedef struct Lane_LaneSensorSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Lane_LaneSensorTypeSupport TypeSupport;
    typedef Lane_LaneSensorDataWriter DataWriter;
    typedef Lane_LaneSensorDataReader DataReader;
    #endif

    Lane_LaneObject   left ;
    Lane_LaneObject   right ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lane_LaneSensor_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lane_LaneSensorSeq, Lane_LaneSensor);                                        

NDDSUSERDllExport
RTIBool Lane_LaneSensor_initialize(
    Lane_LaneSensor* self);

NDDSUSERDllExport
RTIBool Lane_LaneSensor_initialize_ex(
    Lane_LaneSensor* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lane_LaneSensor_initialize_w_params(
    Lane_LaneSensor* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lane_LaneSensor_finalize(
    Lane_LaneSensor* self);

NDDSUSERDllExport
void Lane_LaneSensor_finalize_ex(
    Lane_LaneSensor* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lane_LaneSensor_finalize_w_params(
    Lane_LaneSensor* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lane_LaneSensor_finalize_optional_members(
    Lane_LaneSensor* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lane_LaneSensor_copy(
    Lane_LaneSensor* dst,
    const Lane_LaneSensor* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
static const DDS_Long Lidar_MAX_POINTS= 30000;
extern "C" {

    extern const char *Lidar_PointTYPENAME;

}

struct Lidar_PointSeq;
#ifndef NDDS_STANDALONE_TYPE
class Lidar_PointTypeSupport;
class Lidar_PointDataWriter;
class Lidar_PointDataReader;
#endif

class Lidar_Point 
{
  public:
    typedef struct Lidar_PointSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Lidar_PointTypeSupport TypeSupport;
    typedef Lidar_PointDataWriter DataWriter;
    typedef Lidar_PointDataReader DataReader;
    #endif

    DDS_Float   point [3];

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lidar_Point_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lidar_PointSeq, Lidar_Point);                                        

NDDSUSERDllExport
RTIBool Lidar_Point_initialize(
    Lidar_Point* self);

NDDSUSERDllExport
RTIBool Lidar_Point_initialize_ex(
    Lidar_Point* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lidar_Point_initialize_w_params(
    Lidar_Point* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lidar_Point_finalize(
    Lidar_Point* self);

NDDSUSERDllExport
void Lidar_Point_finalize_ex(
    Lidar_Point* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lidar_Point_finalize_w_params(
    Lidar_Point* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lidar_Point_finalize_optional_members(
    Lidar_Point* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lidar_Point_copy(
    Lidar_Point* dst,
    const Lidar_Point* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Lidar_PCloudTYPENAME;

}

struct Lidar_PCloudSeq;
#ifndef NDDS_STANDALONE_TYPE
class Lidar_PCloudTypeSupport;
class Lidar_PCloudDataWriter;
class Lidar_PCloudDataReader;
#endif

class Lidar_PCloud 
{
  public:
    typedef struct Lidar_PCloudSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Lidar_PCloudTypeSupport TypeSupport;
    typedef Lidar_PCloudDataWriter DataWriter;
    typedef Lidar_PCloudDataReader DataReader;
    #endif

    Lidar_PointSeq  Location ;
    DDS_Octet   color ;
    DDS_Float   normal ;
    DDS_Float   intensity ;
    DDS_Long   count ;
    DDS_Float   xLimits [2];
    DDS_Float   yLimits [2];
    DDS_Float   zLimits [2];

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lidar_PCloud_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lidar_PCloudSeq, Lidar_PCloud);                                        

NDDSUSERDllExport
RTIBool Lidar_PCloud_initialize(
    Lidar_PCloud* self);

NDDSUSERDllExport
RTIBool Lidar_PCloud_initialize_ex(
    Lidar_PCloud* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lidar_PCloud_initialize_w_params(
    Lidar_PCloud* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lidar_PCloud_finalize(
    Lidar_PCloud* self);

NDDSUSERDllExport
void Lidar_PCloud_finalize_ex(
    Lidar_PCloud* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lidar_PCloud_finalize_w_params(
    Lidar_PCloud* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lidar_PCloud_finalize_optional_members(
    Lidar_PCloud* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lidar_PCloud_copy(
    Lidar_PCloud* dst,
    const Lidar_PCloud* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Lidar_LidarSensorTYPENAME;

}

struct Lidar_LidarSensorSeq;
#ifndef NDDS_STANDALONE_TYPE
class Lidar_LidarSensorTypeSupport;
class Lidar_LidarSensorDataWriter;
class Lidar_LidarSensorDataReader;
#endif

class Lidar_LidarSensor 
{
  public:
    typedef struct Lidar_LidarSensorSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Lidar_LidarSensorTypeSupport TypeSupport;
    typedef Lidar_LidarSensorDataWriter DataWriter;
    typedef Lidar_LidarSensorDataReader DataReader;
    #endif

    POSIXTimestamp   timestamp ;
    Lidar_PCloud   ptCloud ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lidar_LidarSensor_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lidar_LidarSensorSeq, Lidar_LidarSensor);                                        

NDDSUSERDllExport
RTIBool Lidar_LidarSensor_initialize(
    Lidar_LidarSensor* self);

NDDSUSERDllExport
RTIBool Lidar_LidarSensor_initialize_ex(
    Lidar_LidarSensor* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lidar_LidarSensor_initialize_w_params(
    Lidar_LidarSensor* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lidar_LidarSensor_finalize(
    Lidar_LidarSensor* self);

NDDSUSERDllExport
void Lidar_LidarSensor_finalize_ex(
    Lidar_LidarSensor* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lidar_LidarSensor_finalize_w_params(
    Lidar_LidarSensor* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lidar_LidarSensor_finalize_optional_members(
    Lidar_LidarSensor* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lidar_LidarSensor_copy(
    Lidar_LidarSensor* dst,
    const Lidar_LidarSensor* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Platform_PlatformControlTYPENAME;

}

struct Platform_PlatformControlSeq;
#ifndef NDDS_STANDALONE_TYPE
class Platform_PlatformControlTypeSupport;
class Platform_PlatformControlDataWriter;
class Platform_PlatformControlDataReader;
#endif

class Platform_PlatformControl 
{
  public:
    typedef struct Platform_PlatformControlSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Platform_PlatformControlTypeSupport TypeSupport;
    typedef Platform_PlatformControlDataWriter DataWriter;
    typedef Platform_PlatformControlDataReader DataReader;
    #endif

    DDS_Long   sample_id ;
    POSIXTimestamp   timestamp ;
    DDS_Float   vehicleSteerAngle ;
    DDS_Float   speed ;
    IndicatorStatusEnum   blinkerStatus ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Platform_PlatformControl_get_typecode(void); /* Type code */

DDS_SEQUENCE(Platform_PlatformControlSeq, Platform_PlatformControl);                                        

NDDSUSERDllExport
RTIBool Platform_PlatformControl_initialize(
    Platform_PlatformControl* self);

NDDSUSERDllExport
RTIBool Platform_PlatformControl_initialize_ex(
    Platform_PlatformControl* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Platform_PlatformControl_initialize_w_params(
    Platform_PlatformControl* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Platform_PlatformControl_finalize(
    Platform_PlatformControl* self);

NDDSUSERDllExport
void Platform_PlatformControl_finalize_ex(
    Platform_PlatformControl* self,RTIBool deletePointers);

NDDSUSERDllExport
void Platform_PlatformControl_finalize_w_params(
    Platform_PlatformControl* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Platform_PlatformControl_finalize_optional_members(
    Platform_PlatformControl* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Platform_PlatformControl_copy(
    Platform_PlatformControl* dst,
    const Platform_PlatformControl* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Platform_PlatformStatusTYPENAME;

}

struct Platform_PlatformStatusSeq;
#ifndef NDDS_STANDALONE_TYPE
class Platform_PlatformStatusTypeSupport;
class Platform_PlatformStatusDataWriter;
class Platform_PlatformStatusDataReader;
#endif

class Platform_PlatformStatus 
{
  public:
    typedef struct Platform_PlatformStatusSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Platform_PlatformStatusTypeSupport TypeSupport;
    typedef Platform_PlatformStatusDataWriter DataWriter;
    typedef Platform_PlatformStatusDataReader DataReader;
    #endif

    POSIXTimestamp   timestamp ;
    DDS_Float   vehSpd ;
    IndicatorStatusEnum   blinkerStatus ;
    DDS_Float   posGasPedal ;
    DDS_Float   velocity ;
    DDS_Float   yawRate ;
    DDS_Float   vehicleSteerAngle ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Platform_PlatformStatus_get_typecode(void); /* Type code */

DDS_SEQUENCE(Platform_PlatformStatusSeq, Platform_PlatformStatus);                                        

NDDSUSERDllExport
RTIBool Platform_PlatformStatus_initialize(
    Platform_PlatformStatus* self);

NDDSUSERDllExport
RTIBool Platform_PlatformStatus_initialize_ex(
    Platform_PlatformStatus* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Platform_PlatformStatus_initialize_w_params(
    Platform_PlatformStatus* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Platform_PlatformStatus_finalize(
    Platform_PlatformStatus* self);

NDDSUSERDllExport
void Platform_PlatformStatus_finalize_ex(
    Platform_PlatformStatus* self,RTIBool deletePointers);

NDDSUSERDllExport
void Platform_PlatformStatus_finalize_w_params(
    Platform_PlatformStatus* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Platform_PlatformStatus_finalize_optional_members(
    Platform_PlatformStatus* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Platform_PlatformStatus_copy(
    Platform_PlatformStatus* dst,
    const Platform_PlatformStatus* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
static const DDS_Long Sensor_SENSOR_OBJECT_LIST_MAX_SIZE= 128;
typedef enum Sensor_RangeModeEnum
{
    RANGE_NONE  = 0,      
    RANGE_SHORT  = 1,      
    RANGE_MEDIUM  = 2,      
    RANGE_LONG  = 3     
} Sensor_RangeModeEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Sensor_RangeModeEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(Sensor_RangeModeEnumSeq, Sensor_RangeModeEnum);                                        

NDDSUSERDllExport
RTIBool Sensor_RangeModeEnum_initialize(
    Sensor_RangeModeEnum* self);

NDDSUSERDllExport
RTIBool Sensor_RangeModeEnum_initialize_ex(
    Sensor_RangeModeEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Sensor_RangeModeEnum_initialize_w_params(
    Sensor_RangeModeEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Sensor_RangeModeEnum_finalize(
    Sensor_RangeModeEnum* self);

NDDSUSERDllExport
void Sensor_RangeModeEnum_finalize_ex(
    Sensor_RangeModeEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void Sensor_RangeModeEnum_finalize_w_params(
    Sensor_RangeModeEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Sensor_RangeModeEnum_finalize_optional_members(
    Sensor_RangeModeEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Sensor_RangeModeEnum_copy(
    Sensor_RangeModeEnum* dst,
    const Sensor_RangeModeEnum* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Sensor_SensorObjectTYPENAME;

}

struct Sensor_SensorObjectSeq;
#ifndef NDDS_STANDALONE_TYPE
class Sensor_SensorObjectTypeSupport;
class Sensor_SensorObjectDataWriter;
class Sensor_SensorObjectDataReader;
#endif

class Sensor_SensorObject 
{
  public:
    typedef struct Sensor_SensorObjectSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Sensor_SensorObjectTypeSupport TypeSupport;
    typedef Sensor_SensorObjectDataWriter DataWriter;
    typedef Sensor_SensorObjectDataReader DataReader;
    #endif

    ClassificationEnum   classification ;
    DDS_Float   position [3];
    DDS_Float   velocity [3];
    DDS_Float   size [3];
    DDS_Float   amplitude ;
    Sensor_RangeModeEnum   rangeMode ;
    DDS_Float   rangeRate ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Sensor_SensorObject_get_typecode(void); /* Type code */

DDS_SEQUENCE(Sensor_SensorObjectSeq, Sensor_SensorObject);                                        

NDDSUSERDllExport
RTIBool Sensor_SensorObject_initialize(
    Sensor_SensorObject* self);

NDDSUSERDllExport
RTIBool Sensor_SensorObject_initialize_ex(
    Sensor_SensorObject* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Sensor_SensorObject_initialize_w_params(
    Sensor_SensorObject* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Sensor_SensorObject_finalize(
    Sensor_SensorObject* self);

NDDSUSERDllExport
void Sensor_SensorObject_finalize_ex(
    Sensor_SensorObject* self,RTIBool deletePointers);

NDDSUSERDllExport
void Sensor_SensorObject_finalize_w_params(
    Sensor_SensorObject* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Sensor_SensorObject_finalize_optional_members(
    Sensor_SensorObject* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Sensor_SensorObject_copy(
    Sensor_SensorObject* dst,
    const Sensor_SensorObject* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Sensor_SensorObjectListTYPENAME;

}

struct Sensor_SensorObjectListSeq;
#ifndef NDDS_STANDALONE_TYPE
class Sensor_SensorObjectListTypeSupport;
class Sensor_SensorObjectListDataWriter;
class Sensor_SensorObjectListDataReader;
#endif

class Sensor_SensorObjectList 
{
  public:
    typedef struct Sensor_SensorObjectListSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Sensor_SensorObjectListTypeSupport TypeSupport;
    typedef Sensor_SensorObjectListDataWriter DataWriter;
    typedef Sensor_SensorObjectListDataReader DataReader;
    #endif

    POSIXTimestamp   timestamp ;
    Sensor_SensorObjectSeq  objects ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Sensor_SensorObjectList_get_typecode(void); /* Type code */

DDS_SEQUENCE(Sensor_SensorObjectListSeq, Sensor_SensorObjectList);                                        

NDDSUSERDllExport
RTIBool Sensor_SensorObjectList_initialize(
    Sensor_SensorObjectList* self);

NDDSUSERDllExport
RTIBool Sensor_SensorObjectList_initialize_ex(
    Sensor_SensorObjectList* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Sensor_SensorObjectList_initialize_w_params(
    Sensor_SensorObjectList* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Sensor_SensorObjectList_finalize(
    Sensor_SensorObjectList* self);

NDDSUSERDllExport
void Sensor_SensorObjectList_finalize_ex(
    Sensor_SensorObjectList* self,RTIBool deletePointers);

NDDSUSERDllExport
void Sensor_SensorObjectList_finalize_w_params(
    Sensor_SensorObjectList* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Sensor_SensorObjectList_finalize_optional_members(
    Sensor_SensorObjectList* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Sensor_SensorObjectList_copy(
    Sensor_SensorObjectList* dst,
    const Sensor_SensorObjectList* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
static const DDS_Long Vision_VISION_OBJECT_LIST_MAX_SIZE= 10;
extern "C" {

    extern const char *Vision_VisionObjectTYPENAME;

}

struct Vision_VisionObjectSeq;
#ifndef NDDS_STANDALONE_TYPE
class Vision_VisionObjectTypeSupport;
class Vision_VisionObjectDataWriter;
class Vision_VisionObjectDataReader;
#endif

class Vision_VisionObject 
{
  public:
    typedef struct Vision_VisionObjectSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Vision_VisionObjectTypeSupport TypeSupport;
    typedef Vision_VisionObjectDataWriter DataWriter;
    typedef Vision_VisionObjectDataReader DataReader;
    #endif

    ClassificationEnum   classification ;
    DDS_Float   position [3];
    DDS_Float   velocity [3];
    DDS_Float   size [3];

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Vision_VisionObject_get_typecode(void); /* Type code */

DDS_SEQUENCE(Vision_VisionObjectSeq, Vision_VisionObject);                                        

NDDSUSERDllExport
RTIBool Vision_VisionObject_initialize(
    Vision_VisionObject* self);

NDDSUSERDllExport
RTIBool Vision_VisionObject_initialize_ex(
    Vision_VisionObject* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Vision_VisionObject_initialize_w_params(
    Vision_VisionObject* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Vision_VisionObject_finalize(
    Vision_VisionObject* self);

NDDSUSERDllExport
void Vision_VisionObject_finalize_ex(
    Vision_VisionObject* self,RTIBool deletePointers);

NDDSUSERDllExport
void Vision_VisionObject_finalize_w_params(
    Vision_VisionObject* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Vision_VisionObject_finalize_optional_members(
    Vision_VisionObject* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Vision_VisionObject_copy(
    Vision_VisionObject* dst,
    const Vision_VisionObject* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *Vision_VisionSensorTYPENAME;

}

struct Vision_VisionSensorSeq;
#ifndef NDDS_STANDALONE_TYPE
class Vision_VisionSensorTypeSupport;
class Vision_VisionSensorDataWriter;
class Vision_VisionSensorDataReader;
#endif

class Vision_VisionSensor 
{
  public:
    typedef struct Vision_VisionSensorSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Vision_VisionSensorTypeSupport TypeSupport;
    typedef Vision_VisionSensorDataWriter DataWriter;
    typedef Vision_VisionSensorDataReader DataReader;
    #endif

    DDS_Long   id ;
    POSIXTimestamp   timestamp ;
    Vision_VisionObjectSeq  objects ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Vision_VisionSensor_get_typecode(void); /* Type code */

DDS_SEQUENCE(Vision_VisionSensorSeq, Vision_VisionSensor);                                        

NDDSUSERDllExport
RTIBool Vision_VisionSensor_initialize(
    Vision_VisionSensor* self);

NDDSUSERDllExport
RTIBool Vision_VisionSensor_initialize_ex(
    Vision_VisionSensor* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Vision_VisionSensor_initialize_w_params(
    Vision_VisionSensor* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Vision_VisionSensor_finalize(
    Vision_VisionSensor* self);

NDDSUSERDllExport
void Vision_VisionSensor_finalize_ex(
    Vision_VisionSensor* self,RTIBool deletePointers);

NDDSUSERDllExport
void Vision_VisionSensor_finalize_w_params(
    Vision_VisionSensor* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Vision_VisionSensor_finalize_optional_members(
    Vision_VisionSensor* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Vision_VisionSensor_copy(
    Vision_VisionSensor* dst,
    const Vision_VisionSensor* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* automotive */

