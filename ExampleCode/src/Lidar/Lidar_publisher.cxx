/** ------------------------------------------------------------------------
 * Lidar_publisher.cxx
 * Publishes LiDAR data (PointCloud2 type) in positions and
 * surfaces derived from data supplied by RTI Shapes Demo
 *
 * (c) 2005-2018 Copyright, Real-Time Innovations, Inc.  All rights reserved.    	                             
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software.  Licensee has the right to distribute object form
 * only for use with RTI products.  The Software is provided 'as is', with no
 * arranty of any type, including any warranty for fitness for any purpose. RTI
 * is under no obligation to maintain or support the Software.  RTI shall not
 * be liable for any incidental or consequential damages arising out of the
 * use or inability to use the software.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#ifdef WIN32
#include <ctime>
#else
#include <sys/time.h>           // timestamps
#endif
#include <cmath>
#include "Utils.h"
#include "automotive.h"
#include "automotiveSupport.h"
#include "ndds/ndds_cpp.h"

#define PCLOUD_BYTES_PER_POINT  (16)    // 4 float32's (for x,y,z,rgb)
#define PI                      ((float)3.14159265359)

typedef struct {
    float x;
    float y;
    float z;
}point;

typedef struct {
    float   start;      // in radians
    float   range;      // in radians
    int     steps;
}srParms;

typedef struct {
    srParms azim;
    srParms polar;
}scanRange;

typedef struct {
    point       obs;        // observer position
    scanRange   scan;       // range and resolution of scan
    int         ptType;     // type of point: 0(mono), 1(RGB)
    int         ptCount;    // count of points
    float       *ptArray;   // array of points
}ptCloud;

typedef struct {
    uint32_t    color;
    int32_t     x;
    int32_t     y;
    int32_t     shapesize;
} shapeType;

// array of [9] circle shapes (1 per color, plus error)
shapeType shapeList[9] = { 0 };
// enum for indexing the above
enum sColor {
    SC_BLUE = 0, SC_GREEN, SC_RED, SC_YELLOW, SC_CYAN, SC_MAGENTA, SC_PURPLE, SC_ORANGE, SC_ERROR, SC_MAX
};

// -- prototypes -----------------------------------------------
void  shapesToPointCloud(shapeType *shapes, ptCloud *ptc);

class ShapeTypeExtendedListener : public DDSDataReaderListener {
public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}

    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* reader);
};

void ShapeTypeExtendedListener::on_data_available(DDSDataReader* reader)
{
    ShapeTypeExtendedDataReader *ShapeTypeExtended_reader = NULL;
    ShapeTypeExtendedSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;
    int i;

    ShapeTypeExtended_reader = ShapeTypeExtendedDataReader::narrow(reader);
    if (ShapeTypeExtended_reader == NULL) {
        fprintf(stderr, "DataReader narrow error\n");
        return;
    }

    retcode = ShapeTypeExtended_reader->take(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    }
    else if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "take error %d\n", retcode);
        return;
    }

    for (i = 0; i < data_seq.length(); ++i) {
        if (info_seq[i].valid_data) {
        /* Shapes data is received here.
           Scaling will be performed during render, but set the color here*/
            if(strcmp(data_seq[i].color, "BLUE") == 0) {
                shapeList[SC_BLUE].x = data_seq[i].x;
                shapeList[SC_BLUE].y = data_seq[i].y;
                shapeList[SC_BLUE].shapesize = data_seq[i].shapesize;
                shapeList[SC_BLUE].color = 0xff;
            } else if(strcmp(data_seq[i].color, "GREEN") == 0) {
                shapeList[SC_GREEN].x = data_seq[i].x;
                shapeList[SC_GREEN].y = data_seq[i].y;
                shapeList[SC_GREEN].shapesize = data_seq[i].shapesize;
                shapeList[SC_GREEN].color = 0xff00;
            } else if(strcmp(data_seq[i].color, "RED") == 0) {
                shapeList[SC_RED].x = data_seq[i].x;
                shapeList[SC_RED].y = data_seq[i].y;
                shapeList[SC_RED].shapesize = data_seq[i].shapesize;
                shapeList[SC_RED].color = 0xff0000;
            } else if(strcmp(data_seq[i].color, "PURPLE") == 0) {
                shapeList[SC_PURPLE].x = data_seq[i].x;
                shapeList[SC_PURPLE].y = data_seq[i].y;
                shapeList[SC_PURPLE].shapesize = data_seq[i].shapesize;
                shapeList[SC_PURPLE].color = 0x800080;
            } else if(strcmp(data_seq[i].color, "YELLOW") == 0) {
                shapeList[SC_YELLOW].x = data_seq[i].x;
                shapeList[SC_YELLOW].y = data_seq[i].y;
                shapeList[SC_YELLOW].shapesize = data_seq[i].shapesize;
                shapeList[SC_YELLOW].color = 0xffff00;
            } else if(strcmp(data_seq[i].color, "CYAN") == 0) {
                shapeList[SC_CYAN].x = data_seq[i].x;
                shapeList[SC_CYAN].y = data_seq[i].y;
                shapeList[SC_CYAN].shapesize = data_seq[i].shapesize;
                shapeList[SC_CYAN].color = 0x00ffff;
            } else if(strcmp(data_seq[i].color, "MAGENTA") == 0) {
                shapeList[SC_MAGENTA].x = data_seq[i].x;
                shapeList[SC_MAGENTA].y = data_seq[i].y;
                shapeList[SC_MAGENTA].shapesize = data_seq[i].shapesize;
                shapeList[SC_MAGENTA].color = 0xff00ff;
            } else if(strcmp(data_seq[i].color, "ORANGE") == 0) {
                shapeList[SC_ORANGE].x = data_seq[i].x;
                shapeList[SC_ORANGE].y = data_seq[i].y;
                shapeList[SC_ORANGE].shapesize = data_seq[i].shapesize;
                shapeList[SC_ORANGE].color = 0xff5733;
            } else {        // use WHITE for error
                shapeList[SC_ERROR].x = data_seq[i].x;
                shapeList[SC_ERROR].y = data_seq[i].y;
                shapeList[SC_ERROR].shapesize = data_seq[i].shapesize;
                shapeList[SC_ERROR].color =  0xffffff;
            }
        }
    }

    retcode = ShapeTypeExtended_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}
/* Delete all entities */
static int publisher_shutdown(
    DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
    domain participant factory for people who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode); 
        status = -1;
    }
    */
    return status;
}

/** ---------------------------------------------------
 publisher_main()
 **/
 extern "C" int publisher_main(void)
{
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSTopic *pointCloudTopic = NULL;
    DDSTopic *shapeTopic = NULL;
    DDSDataWriter *writer = NULL;
    sensor_msgs_msg_dds__PointCloud2_DataWriter * Lidar_LidarSensor_writer = NULL;
    sensor_msgs_msg_dds__PointCloud2_ *instance = NULL;
    ShapeTypeExtendedListener *reader_listener = NULL;
    DDSDataReader *reader = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *pointcloud_type_name = NULL;
    const char *shape_type_name = NULL;
    int domainId = 0;
    DDS_Duration_t send_period = {4,0};
    ptCloud topLidar;       // to hold LiDAR data
    topLidar.obs.x = 0;
    topLidar.obs.y = 0;
    topLidar.obs.z = 1;
    topLidar.ptType = 1;

    /* Get the properties and configure it */
    PropertyUtil* prop = new PropertyUtil("lidar.properties");

    long period = prop->getLongProperty("config.pubInterval");
    send_period.sec = period / 1000;
    send_period.nanosec = (period % 1000) * 1000 * 1000;

    domainId = prop->getLongProperty("config.domainId");
    std::string topicName = prop->getStringProperty("topic.Sensor");
    if (topicName == "") {
        printf("No topic name specified\n");
        return -1;
    }
    std::string qosLibrary = prop->getStringProperty("qos.Library");
    if (qosLibrary == "") {
        printf("No QoS Library specified\n");
        return -1;
    }
    std::string qosProfile = prop->getStringProperty("qos.Profile");
    if (qosProfile == "") {
        printf("No QoS Profile specified\n");
        return -1;
    }

    // LiDAR scan range and steps (convert degrees to radians)
    long scanTmp = prop->getLongProperty("config.azimStart");
    topLidar.scan.azim.start = ((float)scanTmp * PI) / 180;
    scanTmp = prop->getLongProperty("config.azimRange");
    topLidar.scan.azim.range = ((float)scanTmp * PI) / 180;
    scanTmp = prop->getLongProperty("config.azimSteps");
    topLidar.scan.azim.steps = scanTmp;
    scanTmp = prop->getLongProperty("config.polarStart");
    topLidar.scan.polar.start = ((float)scanTmp * PI) / 180;
    scanTmp = prop->getLongProperty("config.polarRange");
    topLidar.scan.polar.range = ((float)scanTmp * PI) / 180;
    scanTmp = prop->getLongProperty("config.polarSteps");
    topLidar.scan.polar.steps = scanTmp;

    /* Initialize the random number generator */
    srand((unsigned int)time(NULL));

    /* Create the participant */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        domainId, qosLibrary.c_str(), qosProfile.c_str(),
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create the publisher. Since the topic is larger the 
       QoS has to be set to use asynchronous publisher
     */
    publisher = participant->create_publisher_with_profile(
        qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }
    
    /* To customize the subscriber QoS, use
    the configuration file USER_QOS_PROFILES.xml */
    subscriber = participant->create_subscriber(
        DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        fprintf(stderr, "create_subscriber error\n");
        publisher_shutdown(participant);
        return -1;
    }    

    /* Register types before creating topics */
    pointcloud_type_name = sensor_msgs_msg_dds__PointCloud2_TypeSupport::get_type_name();
    retcode = sensor_msgs_msg_dds__PointCloud2_TypeSupport::register_type(
        participant, pointcloud_type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "pointcloud register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }

    shape_type_name = ShapeTypeExtendedTypeSupport::get_type_name();
    retcode = ShapeTypeExtendedTypeSupport::register_type(
        participant, shape_type_name);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "shape register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }
    /* Create the topic */
    pointCloudTopic = participant->create_topic_with_profile(
        topicName.c_str(),
        pointcloud_type_name, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (pointCloudTopic == NULL) {
        printf("create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    shapeTopic = participant->create_topic(
        "Circle",
        shape_type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (shapeTopic == NULL) {
        fprintf(stderr, "shape create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create the data writer */
    writer = publisher->create_datawriter_with_profile(
        pointCloudTopic, qosLibrary.c_str(), qosProfile.c_str(), NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }

    Lidar_LidarSensor_writer = sensor_msgs_msg_dds__PointCloud2_DataWriter::narrow(writer);
    if (Lidar_LidarSensor_writer == NULL) {
        printf("DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create a data reader listener */
    reader_listener = new ShapeTypeExtendedListener();

    /* To customize the data reader QoS, use
    the configuration file USER_QOS_PROFILES.xml */
    reader = subscriber->create_datareader(
        shapeTopic, DDS_DATAREADER_QOS_DEFAULT, reader_listener,
        DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        fprintf(stderr, "shape create_datareader error\n");
        publisher_shutdown(participant);
        delete reader_listener;
        return -1;
    }

    /* Create data sample for writing */
    instance = sensor_msgs_msg_dds__PointCloud2_TypeSupport::create_data();
    if (instance == NULL) {
        printf("Lidar_LidarSensorTypeSupport::create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }


    /* initialize the LiDAR data elements here */
    instance->is_bigendian_ = false;
    instance->is_dense_ = true;          // true=no invalid datapoints
    instance->point_step_ = PCLOUD_BYTES_PER_POINT;
    instance->row_step_ = (PCLOUD_BYTES_PER_POINT * topLidar.scan.azim.steps);
    instance->fields_.length(4);
    instance->fields_[0].name_ = (char *)"x";
    instance->fields_[0].offset_ = 0;
    instance->fields_[0].datatype_ = 7;      // 2=UINT8, 7=float32
    instance->fields_[0].count_ = 1;
    instance->fields_[1].name_ = (char *)"y";
    instance->fields_[1].offset_ = 4;
    instance->fields_[1].datatype_ = 7;
    instance->fields_[1].count_ = 1;
    instance->fields_[2].name_ = (char *)"z";
    instance->fields_[2].offset_ = 8;
    instance->fields_[2].datatype_ = 7;
    instance->fields_[2].count_ = 1;
    instance->fields_[3].name_ = (char *)"rgb";
    instance->fields_[3].offset_ = 12;
    instance->fields_[3].datatype_ = 7;
    instance->fields_[3].count_ = 1;
    instance->header_.frame_id_ = (DDS_Char *) "map";

    int dataPointCount = (topLidar.scan.azim.steps * topLidar.scan.polar.steps);
    instance->height_ = topLidar.scan.azim.steps;
    instance->width_ = topLidar.scan.polar.steps;
    instance->data_.length(dataPointCount * PCLOUD_BYTES_PER_POINT);
    topLidar.ptCount = dataPointCount;
    topLidar.ptArray = (float *)&instance->data_[0];    // put data into PointCloud2 instance buffer


    /* Main loop */
    while(1) {
        /* get the data */
        shapesToPointCloud(&shapeList[0], &topLidar);

        /* Set the timestamp */
        TimestampUtil::getTimestamp(&(instance->header_.stamp_.sec_), 
                      (((DDS_Long *)&(instance->header_.stamp_.nanosec_))));

        /* And send it */
        retcode = Lidar_LidarSensor_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }

        NDDSUtility::sleep(send_period);
    }

    /* Delete data sample */
    retcode = sensor_msgs_msg_dds__PointCloud2_TypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "sensor_msgs_msg_dds__PointCloud2_TypeSupport::delete_data error %d\n", retcode);
    }

    /* Delete all entities */
    return publisher_shutdown(participant);
}

/** --------------------------------------------------------
 * findHitDist()
 * given a sphere radius and an x,y from its center, 
 * return the depth to the center plane
 **/
float findHitDist(float radius, float x, float y)
{
    // get the squares of radius, x, and y
    float rSquared = pow(radius, 2);
    float xSquared = pow(x, 2);
    float ySquared = pow(y, 2);
    float zSquared = -1 * (xSquared + ySquared - rSquared);
    if (zSquared > 0) {
        zSquared = sqrt(zSquared);
    }
    else {
        zSquared = 0;
    }
    return zSquared;
}

/** --------------------------------------------------------
 * shapesToPointCloud()
 * render shapes to pointcloud, from observers' perspective
 * This keeps the points in an APR format 
 * (will need to convert to XYZ before publishing)
 **/
void shapesToPointCloud(shapeType *shapes, ptCloud *ptc)
{
    // init the points to azimuth,polar,INFINITY,0
    float azim = ptc->scan.azim.start;
    float polar = ptc->scan.polar.start;
    float aStep = ptc->scan.azim.range / ptc->scan.azim.steps;
    float pStep = ptc->scan.polar.range / ptc->scan.polar.steps;
    float *fbuf = &ptc->ptArray[0];
    int i = 0;
    uint32_t greyPoint = 0x393939;
    float posNoise = 0;
    for (int a = 0; a < ptc->scan.azim.steps; a++)
    {
        for (int p = 0; p < ptc->scan.polar.steps; p++)
        {
            // order in buffer is X,Y,Z,Color <--> Azim,Polar,Radius,Color
            fbuf[i++] = azim + (a * aStep) + posNoise;      // azimuth
            fbuf[i++] = polar + (p * pStep) + posNoise;     // polar
            fbuf[i++] = (float)8.5;                         // radius
            fbuf[i++] = *reinterpret_cast<float*>(&greyPoint); // color
            // add a little noise to the position
            posNoise = (((float)(rand() % 4096)) / 2000000);
        }
    }

    // for each shape in shapelist that has a size
    for (int i = 0; i < SC_MAX; i++)
    {
        if (shapeList[i].shapesize)
        {
            // except for YELLOW -- it gets to be the observer.
            if (shapeList[i].color == 0xffff00)
            {
                ptc->obs.x = ((float)(shapeList[i].x - 120)) / 24;
                ptc->obs.y = ((float)(shapeList[i].y - 135)) / 27;
                ptc->obs.z = ((float)shapeList[i].shapesize) / 30;
            }
            else {
                // find all scan points that hit the shape
                // first: get the xyz and azimuth/polar/radius of the shape center
                float shapeX = (((float)(shapeList[i].x - 120)) / 24);
                float shapeY = (((float)(shapeList[i].y - 135)) / 27);
                float shapeZ = (((float)shapeList[i].shapesize) / 60);
                float radCtr = sqrt(pow(shapeX - ptc->obs.x, 2)
                    + pow(shapeY - ptc->obs.y, 2)
                    + pow(shapeZ - ptc->obs.z, 2));
                float azCtr = atan2((shapeY - ptc->obs.y), (shapeX - ptc->obs.x)) + PI;
                float polCtr = acos((shapeZ - ptc->obs.z) / radCtr);

                // is this shape within the (azimuth) scan range?
                if (((azCtr) > ptc->scan.azim.start) && (azCtr <= (ptc->scan.azim.start + ptc->scan.azim.range)))
                {
                    // find the column(azimuth) of this center position
                    int m = ((int)(((azCtr - ptc->scan.azim.start) * ptc->scan.azim.steps * ptc->scan.polar.steps * 4) 
                        / ptc->scan.azim.range) & ~0x3);

                    // cover the azimuth span of the shape size at its current distance from observer
                    float azSpan = atan2(shapeZ, radCtr);
                    float azStart = azCtr - azSpan;
                    float azStop = azCtr + azSpan;
                    int mStart = ((int)(((azStart - ptc->scan.azim.start) * ptc->scan.azim.steps * ptc->scan.polar.steps * 4)
                        / ptc->scan.azim.range) & ~0x3);
                    int mStop = ((int)(((azStop - ptc->scan.azim.start) * ptc->scan.azim.steps * ptc->scan.polar.steps * 4)
                        / ptc->scan.azim.range) & ~0x3);
                    int mRange = (ptc->scan.azim.steps * ptc->scan.polar.steps * 4);
                    int s = mStop - mStart;
                    if (mStart < 0) mStart += mRange;
                    if (mStop > mRange) mStop -= mRange;

                    m = mStart;
                    while(s > 0) {
                        // find this scans' angle off of the sphere center
                        float azDiff = azCtr - fbuf[m + 0];
                        if (abs(azDiff) > 5) {
                            if (azDiff > 0)
                                azDiff -= (2 * PI);
                            else
                                azDiff += (2 * PI);
                        }
                        float scanCtrAngle = sqrt(pow(azDiff, 2) + pow(polCtr - fbuf[m + 1], 2));
                        // find the remaining angle (Pi - rtAngle - scanCtrAngle)
                        float scanRemAngle = (PI / 2) - scanCtrAngle;
                        // find the center-offset length of the point on the sphere
                        float scanPtOffset = sin(scanCtrAngle) * radCtr / sin(scanRemAngle);

                        // use that offset to find the distance to the hit
                        float distOffset = findHitDist(shapeZ, 0, scanPtOffset);

                        // is it inside the sphere?
                        if ((distOffset < (2 * shapeZ)) && (distOffset > 0)) {
                            fbuf[m + 2] = radCtr - distOffset;
                            fbuf[m + 3] = *reinterpret_cast<float*>(&shapeList[i].color);
                        }
                        s -= 4;
                        m += 4;
                        if (m >= mRange) {
                            m = 0;
                        }
                    }
                }
            }
        }
    }

    // now convert all from APR to XYZ
    i = 0;
    for (int a = 0; a < ptc->scan.azim.steps; a++)
    {
        for (int p = 0; p < ptc->scan.polar.steps; p++)
        {
            // order in buffer is Azim,Polar,Radius,Color --> X,Y,Z,Color
            float tmpAz  = fbuf[i + 0];
            float tmpPol = fbuf[i + 1];
            float tmpRad = fbuf[i + 2];
            fbuf[i + 0] = (tmpRad * sin(tmpPol) * cos(tmpAz) - ptc->obs.x);     // X
            fbuf[i + 1] = -(tmpRad * sin(tmpPol) * sin(tmpAz) - ptc->obs.y);    // Y
            fbuf[i + 2] = ((tmpRad * cos(tmpPol)) + ptc->obs.z);                // Z
            // limit Z to ground level and change dot color
            if (fbuf[i + 2] < 0) {
                fbuf[i + 2] = 0;
                uint32_t tmpColor = 0x404040;
                fbuf[i+3] = *reinterpret_cast<float*>(&tmpColor);
            }
            i += 4;
        }
    }
}

/** -----------------------------------------------------
 * main()
 **/
int main(int argc, char *argv[])
{
    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
    set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
    NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */

    return publisher_main();
}

