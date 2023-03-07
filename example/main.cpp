#include <iostream>
#include "filterviz.h"

using namespace std;

int main(int argc, char *argv[])
{
    // example with single precision
    float lp_b[]{0.0417600537496988, 0.106497251809208, 0.194764402275145, 0.225084576933262, 0.194764402275145, 0.106497251809208, 0.0417600537496988};
    float lp_a[]{1, -1.41571338844594, 2.67964150899449, -2.43941611535676, 2.07854381362449, -1.0305850937804, 0.414531772470301};
    char id1[] = "Filter 1";

    FilterViz v(lp_b, lp_a, 7, 16000, id1, 1024);

    // example with double precision
    double lp_b2[]{0.0417600537496988, 0.106497251809208, 0.194764402275145, 0.225084576933262, 0.194764402275145, 0.106497251809208, 0.0417600537496988};
    double lp_a2[]{1, -1.41571338844594, 2.67964150899449, -2.43941611535676, 2.07854381362449, -1.0305850937804, 0.414531772470301};
    char id2[] = "Filter 2";

    FilterViz v2(lp_b2, lp_a2, 7, 16000, id2, 512, true);

    // example with a FIR filter
    double ir[]{1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double *n = nullptr;
    char id3[] = "FIR";

    FilterViz v3(ir, n, 7, 16000, id3, 512);

    return 0;
}
