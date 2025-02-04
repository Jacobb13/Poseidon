#pragma once

/* Packet types */

#define PACKET_POSITION 1
#define PACKET_ATTITUDE 2
#define PACKET_DEPTH    3


/* Packet structs */
#pragma pack(1)
typedef struct {
        uint8_t   packetType;
        uint64_t  packetSize;
        uint64_t  packetTimestamp;
} PacketHeader;
#pragma pack()

#pragma pack(1)
typedef struct{
/*      GNSS Status:

        int8 STATUS_NO_FIX =  -1        # unable to fix position
        int8 STATUS_FIX =      0        # unaugmented fix
        int8 STATUS_SBAS_FIX = 1        # with satellite-based augmentation
        int8 STATUS_GBAS_FIX = 2        # with ground-based augmentation
*/
        int8_t   status;

/*
        GNSS Service

        uint16 SERVICE_GPS =     1
        uint16 SERVICE_GLONASS = 2
        uint16 SERVICE_COMPASS = 4      # includes BeiDou.
        uint16 SERVICE_GALILEO = 8
*/
        uint16_t service;

        double latitude;
        double longitude;
        double altitude;

        double covariance[9];

/*
        Covariance matrix type
        uint8 COVARIANCE_TYPE_UNKNOWN = 0
        uint8 COVARIANCE_TYPE_APPROXIMATED = 1
        uint8 COVARIANCE_TYPE_DIAGONAL_KNOWN = 2
        uint8 COVARIANCE_TYPE_KNOWN = 3 
*/
        uint8_t covarianceType;

} PositionPacket;
#pragma pack()

#pragma pack(1)
typedef struct{
        /* Orientation quaternion */
        double orientation_w;
        double orientation_x;
        double orientation_y;
        double orientation_z;

        double orientation_covariance[9];

        double angular_velocity_x;
        double angular_velocity_y;
        double angular_velocity_z;

        double angular_velocity_covariance[9];

        double linear_acceleration_x;
        double linear_acceleration_y;
        double linear_acceleration_z;

        double linear_acceleration_covariance[9];
} AttitudePacket;
#pragma pack()

#pragma pack(1)
typedef struct {
        double depth_x;
        double depth_y;
        double depth_z;
} DepthPacket;
#pragma pack()
