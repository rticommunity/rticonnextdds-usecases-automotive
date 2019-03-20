![Image](https://www.rti.com/hubfs/RTI_Oct2016/Images/rti-logounit.png)  
 CameraImageData Generator
=====================================

## Concept
This example pub/sub pair illustrate the **Flat Data** and **Zero Copy**
optimizations for large data that are available in Connext 6.  

When sending large data samples (more than a few million bytes), a significant
portion of overhead is consumed with simple data copying during the transit 
from publisher to subscriber.  Flat Data and Zero Copy reduce the number of
times the data is copied to improve performance.

**Flat Data** takes advantage of the newly-introduced XCDR2 encoding method
to eliminate several copy operations.  Flat Data is available for Shared Memory 
or networked transports.  Note that the XCDR2 encoding is not compatible
with the CDR encoding used in prior versions of RTI Connext DDS.

**Zero Copy** is available for Shared Memory transports only, but offers a
dramatic performance increase by passing pointers to the data in shared memory, 
rather than passing the data itself.

Detailed information on Flat Data and Zero Copy is available in the RTI
Connext DDS Core Libraries User's Manual for Connext version 6 or later.


## Configuration
Several files may be edited to configure the CameraImageData pub/sub operation 
and performance:  
```
ExampleCode/src/CameraImage/CameraImageData_publisher.cxx 
ExampleCode/src/CameraImage/CameraImageData_subscriber.cxx 
ExampleCode/src/idl/automotive.idl
ExampleCode/resource/camera_image.properties
```
The application must be rebuilt for changes made to the .cxx and .idl file to take effect.  
Changes to the .properties file are read-in when the applications are launched.

**To use Flat Data or Zero Copy**  
  * Edit the publisher and subscriber .cxx files to comment or uncomment the lines:  
  `#define DDS_LARGE_DATA_FLAT_DATA` to enable Flat Data  
  `#define DDS_LARGE_DATA_ZERO_COPY` to enable Zero Copy
  * Edit the automotive.idl file to comment or uncomment (at the end of the file):  
  ```
    // uncomment next 2 lines to enable FlatData
    // @mutable
    // @language_binding(FLAT_DATA)
    
    // uncomment next line to enable ZeroCopy
    // @transfer_mode(SHMEM_REF)
  ```
  * Clean, then rebuild the applications.  
    This rebuild will re-run the RTIDDSCodeGenerator application on the updated IDL file.
    
**To change the size of the CameraImageData data array**  
  * Edit the `MAX_IMAGE_SIZE` variable at the end of the automotive.idl file to your required array size:  
  `const long MAX_IMAGE_SIZE = (1366 * 768 * 4);`
  * Clean, then rebuild the applications.  
    This rebuild will re-run the RTIDDSCodeGenerator application on the updated IDL file.
    
**To change the packet send rate, domain, packet ID, topic name, or QoS profile**  
  * Edit the `camera_image.properties` file.  
    Edits here take effect when the CameraImageData(Pub|Sub) application is launched.


