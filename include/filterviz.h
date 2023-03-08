#ifndef FILTERVIZ_H
#define FILTERVIZ_H

#include "filterviz_global.h"
#include "filterwidget.h"

/**
 * @brief To store the visualizer settings
 *
 */
struct Settings
{
    bool logx;
    int fs;
    int nfft;
};

/**
 * @brief To store the frequency response data
 *
 */
struct FreqResponse
{
    std::vector<double> magnitude_db;
    std::vector<double> phase_rad;
    std::vector<double> freq_axis;
};

/**
 * @brief Main class of the Filter Visualizer
 *
 * @tparam T Type of filter coefficients (mainly float or double)
 */
template <class T>
class FilterViz
{
public:
    /**
     * @brief Construct a new Filter Viz object
     *
     * @param b Filter coefficients
     * @param a Filter coefficients
     * @param length Length of the filter (number of taps)
     * @param fs Sampling frequency (Hz)
     * @param id Name/ID of the filter (for plots only)
     * @param nfft Number of bins of the frequency response
     * @param logx Boolean to enable logaritmic frequency axis
     */
    FilterViz(T *b, T *a, int length, int fs, char *id, int nfft = 512, bool logx = false);

    /**
     * @brief Destroy the Filter Viz object
     *
     */
    ~FilterViz();

private:
    // Filter data
    char *id;
    T *b;
    T *a;
    int filter_length;
    // Visualization widget
    Settings settings;
    FilterWidget *w;
    // Computations
    FreqResponse freq_response;

    /**
     * @brief Run visualization widget (including required computations)
     *
     * @return int Return 0 if OK
     */
    int visualize();

    /**
     * @brief Compute frequency response from filter coefficients
     *
     * @return int Return 0 if OK
     */
    int computeFreqResponse();
};

#endif // FILTERVIZ_H
