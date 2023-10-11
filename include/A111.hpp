#ifndef A111_H
#define A111_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


#include <acc_rss.h>
#include <acc_detector_distance.h>
#include <acc_hal_definitions.h>
#include <acc_hal_integration.h>
#include "acc_version.h"

//Constants
static const float EXAMPLE_START_M = 0.2f;
static const float EXAMPLE_LENGTH_M = 0.4f;
static const acc_service_profile_t EXAMPLE_PROFILE = ACC_SERVICE_PROFILE_2;
static const int EXAMPLE_HWAAS = 63;


class A111 {
    
public:
    

    // Properties
    const acc_hal_t *hal;
    acc_detector_distance_configuration_t distance_configuration;
    acc_detector_distance_handle_t distance_handle;
    uint16_t num_of_peaks;
    



    // Constructor
    A111();

    // Destructor
    ~A111();

    //Methoden
    void startDistanceDetector();
    void endDistanceDetector();


private:
    //Properties

    //Methoden
    bool initDistanceDetector();
    void print_results();

    //Static Functions
    static void set_config(acc_detector_distance_configuration_t distance_configuration);

};






#endif // A111_H
