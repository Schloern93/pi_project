#include "A111.hpp"



//Constructor
A111::A111()
{     
     
}

A111::~A111()
{
}
//Methoden

void A111::printA111Version()
{
    printf("Acconeer software version %s\n", acc_version_get());
}


void A111::startDistanceDetector()
{
    if (!A111::initDistanceDetector())
    {
        // Try to activate distance handler
        if (!acc_detector_distance_activate(distance_handle))
        {
            printf("Starting doesent work!!!");
            acc_detector_distance_destroy(&distance_handle);
            acc_rss_deactivate();
            return;
        }
        printf("Starting was sucessfull");        
    }
    else
    {
        printf("Init was noch sucesfull. Stating not possible!");
        return;
    }
}

void A111::endDistanceDetector()
{
    acc_detector_distance_deactivate(distance_handle);
    acc_detector_distance_destroy(&distance_handle);
    acc_rss_deactivate();

    printf("Application finished OK\n");
}

bool A111::initDistanceDetector()
{   
    //Initialisiere RSS
    A111::hal = acc_hal_integration_get_implementation();
    //Check if RSS working
    if (!acc_rss_activate(hal))
    {
        printf("Activation RSS Failed!!!");
        acc_rss_deactivate();
        return 0;
    }    

    // Create a configuration File for the detector (Default parameters)
    distance_configuration = acc_detector_distance_configuration_create();

    // Check if distance configuration file is created
    if (distance_configuration == NULL)
    {
        printf("Creating Configuration File failed!!!!");
        acc_detector_distance_configuration_destroy(&distance_configuration);
        acc_rss_deactivate();
        return 0;
    }

    // Set the configuration File
    set_config(distance_configuration);

    //create a distance Handler
    distance_handle = acc_detector_distance_create(distance_configuration);
    // CHeck is distance handler avaiable
    if (distance_handle == NULL)
    {
        printf("Creating Distance Handler failed!!!!");
        acc_detector_distance_configuration_destroy(&distance_configuration);
        acc_rss_deactivate();
        return 0;
    }

    printf("initialication was succesfull");
    return true;    
}

void A111::print_results()
{
    num_of_peaks = 10;
    bool success; // True is data from sensor are valid
    acc_detector_distance_result_t      result[num_of_peaks];
    acc_detector_distance_result_info_t result_info;

    for (size_t i = 0; i < 20; i++)
    {
        success = acc_detector_distance_get_next(distance_handle, result, num_of_peaks, &result_info);

        if (!success)
        {
            printf("print was not possbile becouse no valid data");
            break;
        }

        // Print values
        printf("Num of Peaks:", (unsigned int)result_info.number_of_peaks, "/n");

        for (size_t k = 0; k < result_info.number_of_peaks; k++)
        {
            printf("Amplitude: ", (unsigned int)result[k].amplitude);
            printf("Amplitude: ", (unsigned int)result[k].distance_m);
        }
    }
}

void A111::set_config(acc_detector_distance_configuration_t distance_configuration)
{
    acc_detector_distance_configuration_requested_start_set(distance_configuration, EXAMPLE_START_M);
    acc_detector_distance_configuration_requested_length_set(distance_configuration, EXAMPLE_LENGTH_M);
    acc_detector_distance_configuration_service_profile_set(distance_configuration, EXAMPLE_PROFILE);
    acc_detector_distance_configuration_hw_accelerated_average_samples_set(distance_configuration, EXAMPLE_HWAAS);
}
