#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <complex>
#include <vector>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class FilterWidget; }
QT_END_NAMESPACE

/**
 * @brief Filter Visualizer Widget
 * 
 */
class FilterWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Filter Widget object
     * 
     * @param parent Parent widget, if any
     */
    FilterWidget(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Filter Widget object
     * 
     */
    ~FilterWidget();

    /**
     * @brief 
     * 
     * @param freq Frequency axis (Hz)
     * @param mag_db Magnitude of the frequency response (dB)
     * @param phase_rad Phase of the frequency response (rad)
     * @param logx Boolean to enable logaritmic frequency axis
     * @param id Name/ID of the filter (for the title)
     * @return int Return 0 if OK
     */
    int plotFreqResp(std::vector<double> freq, std::vector<double> mag_db, 
        std::vector<double> phase_rad, bool logx, char *id);

private:
    Ui::FilterWidget *ui;
};

#endif // FILTERWIDGET_H
