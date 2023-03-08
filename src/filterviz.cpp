#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <QApplication>
#include "filterviz.h"

using namespace std;

template <class T>
FilterViz<T>::FilterViz(T *b, T *a, int length, int fs, char *id, int nfft, bool logx)
    : b(b), a(a), filter_length(length), id(id)
{
    // Parse settings
    settings.fs = fs;
    settings.nfft = nfft;
    settings.logx = logx;

    // Create Qt application (we "fake" argc and argv...)
    int argc{1};
    char *argv[] = {id};
    QApplication app(argc, argv);

    // Create widget
    w = new FilterWidget();

    // Plot filter
    visualize();

    app.exec();
}

template <class T>
FilterViz<T>::~FilterViz()
{
    delete w;
}

template <class T>
int FilterViz<T>::visualize()
{
    // Compute frequency response of the filter
    computeFreqResponse();
    w->plotFreqResp(freq_response.freq_axis, freq_response.magnitude_db,
                    freq_response.phase_rad, settings.logx, id);
    w->show();
    return 0;
}

template <class T>
int FilterViz<T>::computeFreqResponse()
{
    // Clear vectors
    freq_response.magnitude_db.clear();
    freq_response.phase_rad.clear();
    freq_response.freq_axis.clear();

    // Auxiliar constants
    const int numUniquePts{(int)ceil(((float)settings.nfft + 1) / 2)};
    const complex<double> jj(0.0l, -1.0l); // imaginary unit (negative)

    for (size_t i = 0; i < numUniquePts; i++)
    {
        // Frequency axis (in Hz)
        freq_response.freq_axis.push_back((double)i * settings.fs / settings.nfft);

        // Frequency response: magnitude and phase
        double w{i * M_PI / (numUniquePts - 1)};
        complex<double> num(0.0l, 0.0l);
        complex<double> den(0.0l, 0.0l);
        for (size_t j = 0; j < filter_length; j++)
        {
            complex<double> e{exp(jj * (double)j * w)};
            num += (double)b[j] * e;
            if (a) {
                den += (double)a[j] * e;
            }
        }
        complex<double> result{num};;

        if (a) {
            result /= den;
        }
        
        // To avoid log10(0)
        double mag{abs(result)};
        if (mag < 1e-12)
        {
            mag = 1e-12;
        }

        freq_response.magnitude_db.push_back(20.0 * log10(mag));
        freq_response.phase_rad.push_back(arg(result));
    }

    return 0;
}

// Export classes
LIBRARY_EXTERN template class LIBRARY_EXPORT FilterViz<double>;
LIBRARY_EXTERN template class LIBRARY_EXPORT FilterViz<float>;
