

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from automotive.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef automotive_2097329537_h
#define automotive_2097329537_h

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
typedef enum IndicatorStatus
{
    INDICATOR_OFF  = 0,      
    INDICATOR_LEFT  = 1,      
    INDICATOR_RIGHT  = 2,      
    INDICATOR_HAZARD  = 3     
} IndicatorStatus;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* IndicatorStatus_get_typecode(void); /* Type code */

DDS_SEQUENCE(IndicatorStatusSeq, IndicatorStatus);                                        

NDDSUSERDllExport
RTIBool IndicatorStatus_initialize(
    IndicatorStatus* self);

NDDSUSERDllExport
RTIBool IndicatorStatus_initialize_ex(
    IndicatorStatus* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool IndicatorStatus_initialize_w_params(
    IndicatorStatus* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void IndicatorStatus_finalize(
    IndicatorStatus* self);

NDDSUSERDllExport
void IndicatorStatus_finalize_ex(
    IndicatorStatus* self,RTIBool deletePointers);

NDDSUSERDllExport
void IndicatorStatus_finalize_w_params(
    IndicatorStatus* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void IndicatorStatus_finalize_optional_members(
    IndicatorStatus* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool IndicatorStatus_copy(
    IndicatorStatus* dst,
    const IndicatorStatus* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum classificationEnum
{
    Classification_Unknown  = 0,      
    Classification_UnknownSmall  = 1,      
    Classification_UnknownBig  = 2,      
    Classification_Pedestrian  = 3,      
    Classification_Bike  = 4,      
    Classification_Car  = 5,      
    Classification_Truck  = 6,      
    Classification_Barrier  = 7     
} classificationEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* classificationEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(classificationEnumSeq, classificationEnum);                                        

NDDSUSERDllExport
RTIBool classificationEnum_initialize(
    classificationEnum* self);

NDDSUSERDllExport
RTIBool classificationEnum_initialize_ex(
    classificationEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool classificationEnum_initialize_w_params(
    classificationEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void classificationEnum_finalize(
    classificationEnum* self);

NDDSUSERDllExport
void classificationEnum_finalize_ex(
    classificationEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void classificationEnum_finalize_w_params(
    classificationEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void classificationEnum_finalize_optional_members(
    classificationEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool classificationEnum_copy(
    classificationEnum* dst,
    const classificationEnum* src);

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

    DDS_Boolean   BlindSpotDriver ;
    DDS_Boolean   BlindSpotPassenger ;
    DDS_Boolean   FrontCollision ;
    DDS_Boolean   BackCollision ;
    DDS_Boolean   ParkingCollision ;
    DDS_Boolean   DriverAttention ;

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
typedef enum Lane_confidenceEnum
{
    Confidence_None  = 0,      
    Confidence_Low  = 1,      
    Confidence_Med  = 2,      
    Confidence_High  = 3     
} Lane_confidenceEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lane_confidenceEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lane_confidenceEnumSeq, Lane_confidenceEnum);                                        

NDDSUSERDllExport
RTIBool Lane_confidenceEnum_initialize(
    Lane_confidenceEnum* self);

NDDSUSERDllExport
RTIBool Lane_confidenceEnum_initialize_ex(
    Lane_confidenceEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lane_confidenceEnum_initialize_w_params(
    Lane_confidenceEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lane_confidenceEnum_finalize(
    Lane_confidenceEnum* self);

NDDSUSERDllExport
void Lane_confidenceEnum_finalize_ex(
    Lane_confidenceEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lane_confidenceEnum_finalize_w_params(
    Lane_confidenceEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lane_confidenceEnum_finalize_optional_members(
    Lane_confidenceEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lane_confidenceEnum_copy(
    Lane_confidenceEnum* dst,
    const Lane_confidenceEnum* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
typedef enum Lane_laneBoundaryEnum
{
    Boundry_None  = 0,      
    Boundry_Invalid  = 1,      
    Boundry_Solid  = 2,      
    Boundry_Dashed  = 3,      
    Boundry_Virtual  = 4,      
    Boundry_Dots  = 5,      
    Boundry_RoadEdge  = 6,      
    Boundry_Undecided  = 7,      
    Boundry_DoubleMarker  = 8     
} Lane_laneBoundaryEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Lane_laneBoundaryEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(Lane_laneBoundaryEnumSeq, Lane_laneBoundaryEnum);                                        

NDDSUSERDllExport
RTIBool Lane_laneBoundaryEnum_initialize(
    Lane_laneBoundaryEnum* self);

NDDSUSERDllExport
RTIBool Lane_laneBoundaryEnum_initialize_ex(
    Lane_laneBoundaryEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Lane_laneBoundaryEnum_initialize_w_params(
    Lane_laneBoundaryEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Lane_laneBoundaryEnum_finalize(
    Lane_laneBoundaryEnum* self);

NDDSUSERDllExport
void Lane_laneBoundaryEnum_finalize_ex(
    Lane_laneBoundaryEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void Lane_laneBoundaryEnum_finalize_w_params(
    Lane_laneBoundaryEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Lane_laneBoundaryEnum_finalize_optional_members(
    Lane_laneBoundaryEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Lane_laneBoundaryEnum_copy(
    Lane_laneBoundaryEnum* dst,
    const Lane_laneBoundaryEnum* src);

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

    DDS_Octet   isValid ;
    Lane_confidenceEnum   confidence ;
    Lane_laneBoundaryEnum   boundaryType ;
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
    DDS_Octet   Color ;
    DDS_Float   Normal ;
    DDS_Float   Intensity ;
    DDS_Double   Count ;
    DDS_Float   XLimits [2];
    DDS_Float   YLimits [2];
    DDS_Float   ZLimits [2];

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
    DDS_Float   vehicle_steer_angle ;
    DDS_Float   speed ;
    IndicatorStatus   blinker_status ;

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
    IndicatorStatus   blinkerStatus ;
    DDS_Float   posGasPedal ;
    DDS_Float   velocity ;
    DDS_Float   yawRate ;
    DDS_Float   vehicle_steer_angle ;

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
typedef enum Sensor_rangeModeEnum
{
    None  = 0,      
    Short  = 1,      
    Medium  = 2,      
    Long  = 3     
} Sensor_rangeModeEnum;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* Sensor_rangeModeEnum_get_typecode(void); /* Type code */

DDS_SEQUENCE(Sensor_rangeModeEnumSeq, Sensor_rangeModeEnum);                                        

NDDSUSERDllExport
RTIBool Sensor_rangeModeEnum_initialize(
    Sensor_rangeModeEnum* self);

NDDSUSERDllExport
RTIBool Sensor_rangeModeEnum_initialize_ex(
    Sensor_rangeModeEnum* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Sensor_rangeModeEnum_initialize_w_params(
    Sensor_rangeModeEnum* self,
    const struct DDS_TypeAllocationParams_t * allocParams);        

NDDSUSERDllExport
void Sensor_rangeModeEnum_finalize(
    Sensor_rangeModeEnum* self);

NDDSUSERDllExport
void Sensor_rangeModeEnum_finalize_ex(
    Sensor_rangeModeEnum* self,RTIBool deletePointers);

NDDSUSERDllExport
void Sensor_rangeModeEnum_finalize_w_params(
    Sensor_rangeModeEnum* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Sensor_rangeModeEnum_finalize_optional_members(
    Sensor_rangeModeEnum* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Sensor_rangeModeEnum_copy(
    Sensor_rangeModeEnum* dst,
    const Sensor_rangeModeEnum* src);

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

    classificationEnum   classification ;
    DDS_Float   position [3];
    DDS_Float   velocity [3];
    DDS_Float   size [3];
    DDS_Float   amplitude ;
    Sensor_rangeModeEnum   rangeMode ;
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

    classificationEnum   classification ;
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

