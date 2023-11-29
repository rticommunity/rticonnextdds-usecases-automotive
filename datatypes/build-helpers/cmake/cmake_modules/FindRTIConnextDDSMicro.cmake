# (c) 2020 Copyright, Real-Time Innovations, Inc.  All rights reserved.
# No duplications, whole or partial, manual or electronic, may be made
# without express written permission.  Any such copies, or revisions thereof,
# must display this notice unaltered.
# This code contains trade secrets of Real-Time Innovations, Inc.


#####################################################################
# Helper Functions                                                  #
#####################################################################
function(_get_version_number_field FIELD)
    file(STRINGS
        "${CONNEXTDDSMICRO_DIR}/include/dds_c/dds_c_config.h"
        build_id_line
        REGEX "#define ${FIELD}.*"
    )

    string(REGEX MATCH
        "[0-9]+"
        number
        "${build_id_line}"
    )
    set("${FIELD}" ${number} PARENT_SCOPE)
endfunction()

function(_get_connextdds_micro_version)
    _get_version_number_field("RTIME_DDS_VERSION_MAJOR")
    _get_version_number_field("RTIME_DDS_VERSION_MINOR")
    _get_version_number_field("RTIME_DDS_VERSION_RELEASE")
    _get_version_number_field("RTIME_DDS_VERSION_REVISION")
    set(RTICONNEXTDDSMICRO_VERSION
        "${RTIME_DDS_VERSION_MAJOR}.${RTIME_DDS_VERSION_MINOR}"
    )
    set(RTICONNEXTDDSMICRO_VERSION
        "${RTICONNEXTDDSMICRO_VERSION}.${RTIME_DDS_VERSION_RELEASE}"
    )
    set(RTICONNEXTDDSMICRO_VERSION
        "${RTICONNEXTDDSMICRO_VERSION}.${RTIME_DDS_VERSION_REVISION}"
        PARENT_SCOPE
    )
endfunction()

function(create_connext_micro_imported_target)
    set(options "")
    set(single_value_args "TARGET" "LIB")
    set(multi_value_args "DEPENDENCIES")
    cmake_parse_arguments(_CONNEXT
        "${options}"
        "${single_value_args}"
        "${multi_value_args}"
        ${ARGN}
    )

    set(target_name RTIConnextDDSMicro::${_CONNEXT_TARGET})
    if(TARGET ${target_name})
        return() # Nothing to be done
    endif()

    if(WIN32 AND BUILD_SHARED_LIBS)
        set(location_property IMPORTED_IMPLIB)
    else()
        set(location_property IMPORTED_LOCATION)
    endif()

    if(BUILD_SHARED_LIBS)
        set(link_type SHARED)
        set(static_suffix)
    else()
        set(link_type STATIC)
        set(static_suffix "z")
    endif()

    add_library(${target_name} ${link_type} IMPORTED)

    foreach(build_type release debug)
        set(lib_name "${_CONNEXT_LIB}${static_suffix}")

        if(${build_type} STREQUAL "debug")
            set(lib_name "${lib_name}d")
        endif()

        find_library(${_CONNEXT_LIB}_${build_type}
            NAME "${lib_name}"
            HINTS
                "${CONNEXTDDSMICRO_DIR}/lib/${CONNEXTDDSMICRO_ARCH}"
        )

        string(TOUPPER "${build_type}" build_mode)

        set_target_properties(${target_name}
            PROPERTIES
                ${location_property}_${build_mode}
                    "${${_CONNEXT_LIB}_${build_type}}"
        )
    endforeach()

    # Library to use for the default mode
    set(monoconf_lib "${_CONNEXT_LIB}")
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(monoconf_lib "${monoconf_lib}_release")
    else()
        set(monoconf_lib "${monoconf_lib}_debug")
    endif()


    # Set properties for all the targets
    set_target_properties(${target_name}
        PROPERTIES
            ${location_property} ${${monoconf_lib}}
            MAP_IMPORTED_CONFIG_MINSIZEREL Release
            MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
    )

    
    # Add dependencies
    if(_CONNEXT_DEPENDENCIES)
        set_target_properties(${target_name}
            PROPERTIES
                INTERFACE_LINK_LIBRARIES
                   "${_CONNEXT_DEPENDENCIES}"
        )
    endif()


endfunction()


# Find the ConnextDDS Micro installation ####################################
if(NOT CONNEXTDDSMICRO_DIR)
    if(RTIMEHOME)
        set(CONNEXTDDSMICRO_DIR "${RTIMEHOME}")
    elseif(DEFINED ENV{RTIMEHOME})
        set(CONNEXTDDSMICRO_DIR "$ENV{RTIMEHOME}")
    else()
        set(msg
            "CONNEXTDDSMICRO_DIR not provided. Please, provide it to CMake "
            "using -DCONNEXTDDSMICRO_DIR="
        )
        message(FATAL_ERROR ${msg})
    endif()
endif()

message(STATUS
    "RTI Connext DDS Micro installation directory: ${CONNEXTDDSMICRO_DIR}"
)

# Find the ConnextDDS Micro Codegen ##########################################
set(codegen_name "rtiddsgen")
if(WIN32)
    set(codegen_name "${codegen_name}.bat")
endif()

find_path(RTICODEGENMICRO_DIR
    NAME "${codegen_name}"
    HINTS
        "${CONNEXTDDSMICRO_DIR}/rtiddsgen/scripts/")

if(NOT RTICODEGENMICRO_DIR)
    set(warning
        "Codegen was not found. Please, check if rtiddsgen is under your "
        "NDDSHOME/bin directory or provide it to CMake using "
        "-DRTICODEGENMICRO_DIR"
    )
        message(WARNING ${warning})
else()
    set(RTICODEGENMICRO
        "${RTICODEGENMICRO_DIR}/${codegen_name}"
        CACHE PATH
        "Path to RTI Codegen Micro"
    )
endif()

# Find the ConnextDDS Micro architecture #####################################
if(NOT CONNEXTDDSMICRO_ARCH)
    file(GLOB architectures
        LIST_DIRECTORIES TRUE
        RELATIVE "${CONNEXTDDSMICRO_DIR}/lib"
        "${CONNEXTDDSMICRO_DIR}/lib/*"
    )
    if(architectures)
        list(GET architectures 0 CONNEXTDDSMICRO_ARCH)
    else()
        message(FATAL_ERROR
            "No installed architectures found: ${CONNEXTDDSMICRO_DIR}/lib"
        )
    endif()
endif()

message(STATUS "RTI Connext DDS Micro architecture: ${CONNEXTDDSMICRO_ARCH}")

# Get the flags/definitons... #####################################
if("${CONNEXTDDSMICRO_ARCH}" MATCHES "Darwin")
    if(NOT CONNEXTDDSMICRO_DEFINITIONS)
        set(CONNEXTDDSMICRO_DEFINITIONS
            RTI_UNIX
            RTI_DARWIN
            RTI_POSIX_THREADS
        )
    endif()

    if(NOT CONNEXTDDSMICRO_EXTERNAL_LIBS)
        set(CONNEXTDDSMICRO_EXTERNAL_LIBS)
    endif()

    if(NOT CONNEXTDDSMICRO_LINK_FLAGS)
        set(CONNEXTDDSMICRO_LINK_FLAGS)
    endif()
elseif("${CONNEXTDDSMICRO_ARCH}" MATCHES "Linux")
    if(NOT CONNEXTDDSMICRO_DEFINITIONS)
        set(CONNEXTDDSMICRO_DEFINITIONS
            RTI_UNIX
            RTI_LINUX
            RTI_POSIX_THREADS
        )
    endif()

    if(NOT CONNEXTDDSMICRO_EXTERNAL_LIBS)
        set(CONNEXTDDSMICRO_EXTERNAL_LIBS
            -ldl
            -lnsl
            -lm
            -lpthread
            -lrt
        )
    endif()

    if(NOT CONNEXTDDSMICRO_LINK_FLAGS)
        set(CONNEXTDDSMICRO_LINK_FLAGS -static-libgcc)
    endif()
elseif("${CONNEXTDDSMICRO_ARCH}" MATCHES "Win")
    if(NOT CONNEXTDDSMICRO_DEFINITIONS)
        set(CONNEXTDDSMICRO_DEFINITIONS
            WIN32_LEAN_AND_MEAN
            WIN32
            RTI_WIN32
            _CRT_SECURE_NO_WARNINGS
        )
        if(BUILD_SHARED_LIBS)
            set(CONNEXTDDSMICRO_DEFINITIONS
                RTIME_DLL_VARIABLE
                ${CONNEXTDDSMICRO_DEFINITIONS}
            )
        endif()
    endif()

    if(NOT CONNEXTDDSMICRO_EXTERNAL_LIBS)
        set(CONNEXTDDSMICRO_EXTERNAL_LIBS
            netapi32.lib
            advapi32.lib
            user32.lib
            winmm.lib
            WS2_32.lib
        )
    endif()

    if(NOT CONNEXTDDSMICRO_LINK_FLAGS)
        set(CONNEXTDDSMICRO_LINK_FLAGS)
    endif()
endif()

# Find the ConnextDDS Micro version
_get_connextdds_micro_version()

create_connext_micro_imported_target(
    TARGET
        rti_me
    LIB
        "rti_me"    
)

target_include_directories(RTIConnextDDSMicro::rti_me
    INTERFACE
        "${CONNEXTDDSMICRO_DIR}/include"
)

target_compile_definitions(RTIConnextDDSMicro::rti_me
    INTERFACE
        ${CONNEXTDDSMICRO_DEFINITIONS}
)

target_link_libraries(RTIConnextDDSMicro::rti_me
    INTERFACE
        ${CONNEXTDDSMICRO_EXTERNAL_LIBS}
)

target_link_options(RTIConnextDDSMicro::rti_me
    INTERFACE
        ${CONNEXTDDSMICRO_LINK_FLAGS}
)


create_connext_micro_imported_target(
    TARGET
        netiosdm
    LIB
        "rti_me_netiosdm"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)

create_connext_micro_imported_target(
    TARGET
        discdpse
    LIB
        "rti_me_discdpse"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)

create_connext_micro_imported_target(
    TARGET
        discdpde
    LIB
        "rti_me_discdpde"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)

create_connext_micro_imported_target(
    TARGET
        rhsm
    LIB
        "rti_me_rhsm"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)

create_connext_micro_imported_target(
    TARGET
        whsm
    LIB
        "rti_me_whsm"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)

create_connext_micro_imported_target(
    TARGET
        ddssecurity
    seccore
        "rti_me_ddssecurity"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)

create_connext_micro_imported_target(
    TARGET
        seccore
    seccore
        "rti_me_seccore"
    DEPENDENCIES
        RTIConnextDDSMicro::discdpse
        RTIConnextDDSMicro::discdpde
        RTIConnextDDSMicro::rhsm
        RTIConnextDDSMicro::whsm
        RTIConnextDDSMicro::ddssecurity
)

create_connext_micro_imported_target(
    TARGET
        netioshmem
    seccore
        "rti_me_netioshmem"
    DEPENDENCIES
        RTIConnextDDSMicro::rti_me
)


create_connext_micro_imported_target(
    TARGET
        cpp
    seccore
        "rti_me_cpp"
    DEPENDENCIES
        RTIConnextDDSMicro::discdpse
        RTIConnextDDSMicro::discdpde
        RTIConnextDDSMicro::rhsm
        RTIConnextDDSMicro::whsm
        RTIConnextDDSMicro::netioshmem
)

create_connext_micro_imported_target(
    TARGET
        appgen
    seccore
        "rti_me_appgen"
    DEPENDENCIES
        RTIConnextDDSMicro::discdpse
        RTIConnextDDSMicro::discdpde
        RTIConnextDDSMicro::rhsm
        RTIConnextDDSMicro::whsm
)
