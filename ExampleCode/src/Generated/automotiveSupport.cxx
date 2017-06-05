
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from automotive.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "automotiveSupport.h"
#include "automotivePlugin.h"

#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'POSIXTimestamp' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   POSIXTimestampTYPENAME

/* Defines */
#define TDataWriter POSIXTimestampDataWriter
#define TData       POSIXTimestamp

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   POSIXTimestampTYPENAME

/* Defines */
#define TDataReader POSIXTimestampDataReader
#define TDataSeq    POSIXTimestampSeq
#define TData       POSIXTimestamp

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    POSIXTimestampTYPENAME
#define TPlugin_new  POSIXTimestampPlugin_new
#define TPlugin_delete  POSIXTimestampPlugin_delete

/* Defines */
#define TTypeSupport POSIXTimestampTypeSupport
#define TData        POSIXTimestamp
#define TDataReader  POSIXTimestampDataReader
#define TDataWriter  POSIXTimestampDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Alerts_DriverAlerts' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Alerts_DriverAlertsTYPENAME

/* Defines */
#define TDataWriter Alerts_DriverAlertsDataWriter
#define TData       Alerts_DriverAlerts

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Alerts_DriverAlertsTYPENAME

/* Defines */
#define TDataReader Alerts_DriverAlertsDataReader
#define TDataSeq    Alerts_DriverAlertsSeq
#define TData       Alerts_DriverAlerts

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Alerts_DriverAlertsTYPENAME
#define TPlugin_new  Alerts_DriverAlertsPlugin_new
#define TPlugin_delete  Alerts_DriverAlertsPlugin_delete

/* Defines */
#define TTypeSupport Alerts_DriverAlertsTypeSupport
#define TData        Alerts_DriverAlerts
#define TDataReader  Alerts_DriverAlertsDataReader
#define TDataWriter  Alerts_DriverAlertsDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Lane_LaneObject' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Lane_LaneObjectTYPENAME

/* Defines */
#define TDataWriter Lane_LaneObjectDataWriter
#define TData       Lane_LaneObject

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Lane_LaneObjectTYPENAME

/* Defines */
#define TDataReader Lane_LaneObjectDataReader
#define TDataSeq    Lane_LaneObjectSeq
#define TData       Lane_LaneObject

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Lane_LaneObjectTYPENAME
#define TPlugin_new  Lane_LaneObjectPlugin_new
#define TPlugin_delete  Lane_LaneObjectPlugin_delete

/* Defines */
#define TTypeSupport Lane_LaneObjectTypeSupport
#define TData        Lane_LaneObject
#define TDataReader  Lane_LaneObjectDataReader
#define TDataWriter  Lane_LaneObjectDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Lane_LaneSensor' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Lane_LaneSensorTYPENAME

/* Defines */
#define TDataWriter Lane_LaneSensorDataWriter
#define TData       Lane_LaneSensor

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Lane_LaneSensorTYPENAME

/* Defines */
#define TDataReader Lane_LaneSensorDataReader
#define TDataSeq    Lane_LaneSensorSeq
#define TData       Lane_LaneSensor

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Lane_LaneSensorTYPENAME
#define TPlugin_new  Lane_LaneSensorPlugin_new
#define TPlugin_delete  Lane_LaneSensorPlugin_delete

/* Defines */
#define TTypeSupport Lane_LaneSensorTypeSupport
#define TData        Lane_LaneSensor
#define TDataReader  Lane_LaneSensorDataReader
#define TDataWriter  Lane_LaneSensorDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Lidar_Point' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Lidar_PointTYPENAME

/* Defines */
#define TDataWriter Lidar_PointDataWriter
#define TData       Lidar_Point

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Lidar_PointTYPENAME

/* Defines */
#define TDataReader Lidar_PointDataReader
#define TDataSeq    Lidar_PointSeq
#define TData       Lidar_Point

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Lidar_PointTYPENAME
#define TPlugin_new  Lidar_PointPlugin_new
#define TPlugin_delete  Lidar_PointPlugin_delete

/* Defines */
#define TTypeSupport Lidar_PointTypeSupport
#define TData        Lidar_Point
#define TDataReader  Lidar_PointDataReader
#define TDataWriter  Lidar_PointDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Lidar_PCloud' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Lidar_PCloudTYPENAME

/* Defines */
#define TDataWriter Lidar_PCloudDataWriter
#define TData       Lidar_PCloud

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Lidar_PCloudTYPENAME

/* Defines */
#define TDataReader Lidar_PCloudDataReader
#define TDataSeq    Lidar_PCloudSeq
#define TData       Lidar_PCloud

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Lidar_PCloudTYPENAME
#define TPlugin_new  Lidar_PCloudPlugin_new
#define TPlugin_delete  Lidar_PCloudPlugin_delete

/* Defines */
#define TTypeSupport Lidar_PCloudTypeSupport
#define TData        Lidar_PCloud
#define TDataReader  Lidar_PCloudDataReader
#define TDataWriter  Lidar_PCloudDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Lidar_LidarSensor' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Lidar_LidarSensorTYPENAME

/* Defines */
#define TDataWriter Lidar_LidarSensorDataWriter
#define TData       Lidar_LidarSensor

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Lidar_LidarSensorTYPENAME

/* Defines */
#define TDataReader Lidar_LidarSensorDataReader
#define TDataSeq    Lidar_LidarSensorSeq
#define TData       Lidar_LidarSensor

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Lidar_LidarSensorTYPENAME
#define TPlugin_new  Lidar_LidarSensorPlugin_new
#define TPlugin_delete  Lidar_LidarSensorPlugin_delete

/* Defines */
#define TTypeSupport Lidar_LidarSensorTypeSupport
#define TData        Lidar_LidarSensor
#define TDataReader  Lidar_LidarSensorDataReader
#define TDataWriter  Lidar_LidarSensorDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Platform_PlatformControl' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Platform_PlatformControlTYPENAME

/* Defines */
#define TDataWriter Platform_PlatformControlDataWriter
#define TData       Platform_PlatformControl

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Platform_PlatformControlTYPENAME

/* Defines */
#define TDataReader Platform_PlatformControlDataReader
#define TDataSeq    Platform_PlatformControlSeq
#define TData       Platform_PlatformControl

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Platform_PlatformControlTYPENAME
#define TPlugin_new  Platform_PlatformControlPlugin_new
#define TPlugin_delete  Platform_PlatformControlPlugin_delete

/* Defines */
#define TTypeSupport Platform_PlatformControlTypeSupport
#define TData        Platform_PlatformControl
#define TDataReader  Platform_PlatformControlDataReader
#define TDataWriter  Platform_PlatformControlDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Platform_PlatformStatus' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Platform_PlatformStatusTYPENAME

/* Defines */
#define TDataWriter Platform_PlatformStatusDataWriter
#define TData       Platform_PlatformStatus

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Platform_PlatformStatusTYPENAME

/* Defines */
#define TDataReader Platform_PlatformStatusDataReader
#define TDataSeq    Platform_PlatformStatusSeq
#define TData       Platform_PlatformStatus

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Platform_PlatformStatusTYPENAME
#define TPlugin_new  Platform_PlatformStatusPlugin_new
#define TPlugin_delete  Platform_PlatformStatusPlugin_delete

/* Defines */
#define TTypeSupport Platform_PlatformStatusTypeSupport
#define TData        Platform_PlatformStatus
#define TDataReader  Platform_PlatformStatusDataReader
#define TDataWriter  Platform_PlatformStatusDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Sensor_SensorObject' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Sensor_SensorObjectTYPENAME

/* Defines */
#define TDataWriter Sensor_SensorObjectDataWriter
#define TData       Sensor_SensorObject

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Sensor_SensorObjectTYPENAME

/* Defines */
#define TDataReader Sensor_SensorObjectDataReader
#define TDataSeq    Sensor_SensorObjectSeq
#define TData       Sensor_SensorObject

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Sensor_SensorObjectTYPENAME
#define TPlugin_new  Sensor_SensorObjectPlugin_new
#define TPlugin_delete  Sensor_SensorObjectPlugin_delete

/* Defines */
#define TTypeSupport Sensor_SensorObjectTypeSupport
#define TData        Sensor_SensorObject
#define TDataReader  Sensor_SensorObjectDataReader
#define TDataWriter  Sensor_SensorObjectDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Sensor_SensorObjectList' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Sensor_SensorObjectListTYPENAME

/* Defines */
#define TDataWriter Sensor_SensorObjectListDataWriter
#define TData       Sensor_SensorObjectList

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Sensor_SensorObjectListTYPENAME

/* Defines */
#define TDataReader Sensor_SensorObjectListDataReader
#define TDataSeq    Sensor_SensorObjectListSeq
#define TData       Sensor_SensorObjectList

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Sensor_SensorObjectListTYPENAME
#define TPlugin_new  Sensor_SensorObjectListPlugin_new
#define TPlugin_delete  Sensor_SensorObjectListPlugin_delete

/* Defines */
#define TTypeSupport Sensor_SensorObjectListTypeSupport
#define TData        Sensor_SensorObjectList
#define TDataReader  Sensor_SensorObjectListDataReader
#define TDataWriter  Sensor_SensorObjectListDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Vision_VisionObject' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Vision_VisionObjectTYPENAME

/* Defines */
#define TDataWriter Vision_VisionObjectDataWriter
#define TData       Vision_VisionObject

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Vision_VisionObjectTYPENAME

/* Defines */
#define TDataReader Vision_VisionObjectDataReader
#define TDataSeq    Vision_VisionObjectSeq
#define TData       Vision_VisionObject

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Vision_VisionObjectTYPENAME
#define TPlugin_new  Vision_VisionObjectPlugin_new
#define TPlugin_delete  Vision_VisionObjectPlugin_delete

/* Defines */
#define TTypeSupport Vision_VisionObjectTypeSupport
#define TData        Vision_VisionObject
#define TDataReader  Vision_VisionObjectDataReader
#define TDataWriter  Vision_VisionObjectDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'Vision_VisionSensor' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   Vision_VisionSensorTYPENAME

/* Defines */
#define TDataWriter Vision_VisionSensorDataWriter
#define TData       Vision_VisionSensor

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   Vision_VisionSensorTYPENAME

/* Defines */
#define TDataReader Vision_VisionSensorDataReader
#define TDataSeq    Vision_VisionSensorSeq
#define TData       Vision_VisionSensor

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    Vision_VisionSensorTYPENAME
#define TPlugin_new  Vision_VisionSensorPlugin_new
#define TPlugin_delete  Vision_VisionSensorPlugin_delete

/* Defines */
#define TTypeSupport Vision_VisionSensorTypeSupport
#define TData        Vision_VisionSensor
#define TDataReader  Vision_VisionSensorDataReader
#define TDataWriter  Vision_VisionSensorDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

