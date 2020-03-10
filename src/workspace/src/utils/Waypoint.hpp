
#ifndef WAYPOINT_HPP
#define WAYPOINT_HPP

#include "ros/ros.h"



#include "Goal.hpp"


#include "haversine.hpp"


class Waypoint : public Goal 
{

public:

    Waypoint( const double latitude, const double longitude, 
                const double distanceForWaypointReached, 
                ros::Publisher & waypointTopic ) 
 /*   Waypoint( const double latitude, const double longitude, 
                const double distanceForWaypointReached, 
                ros::NodeHandle & node )*/

        : latitude( latitude ), longitude( longitude ),
            distanceForWaypointReached( distanceForWaypointReached ),
            waypointTopic( waypointTopic )
            // node( node )
    {        
    }

    virtual ~Waypoint() {}


    virtual void start() override {

        goal_planner::Waypoint waypointMessage;

        waypointMessage.latitude = latitude;
        waypointMessage.longitude = longitude;
        waypointMessage.pilotActive = 1;
                       
        waypointTopic.publish( waypointMessage );

        std::cout << "\nWaypoint::start(), after publish\n" << std::endl;  

/*
        // ros::Publisher 
        waypointTopic = node.advertise<goal_planner::Waypoint>("waypoint", 1000);

        goal_planner::Waypoint waypointMessage;

        waypointMessage.latitude = latitude;
        waypointMessage.longitude = longitude;
        waypointMessage.pilotActive = 1;
                       
        waypointTopic.publish( waypointMessage );

        std::cout << "\nWaypoint::start(), after publish\n" << std::endl;  

*/
    }



/*
    Waypoint getGoal() const override {
        Waypoint waypoint( latitude, longitude );
        return waypoint;
    }
*/


    bool execute( const double currentLatitude, 
                    const double currentLongitude ) {

		// If currentPosition from the state_contoller 
		// is close enough to the currentWaypoint 
        // (MBES-lib: src/math/Distance.hpp, function haversine)
		if ( haversine( longitude, latitude, 
                        currentLongitude, currentLatitude ) 
                <= distanceForWaypointReached )
        {
            return true;
        } else {
            return false;
        }
    }

    double getLatitude() const {
        return latitude;
    }

    double getlongitude() const {
        return longitude;
    }


private:
    virtual void junkFunctionForPureVirtual() override {} 

    const double latitude;
    const double longitude;

    const double distanceForWaypointReached;

    ros::Publisher & waypointTopic;

    //ros::NodeHandle & node;

    //ros::Publisher waypointTopic;


};

#endif
