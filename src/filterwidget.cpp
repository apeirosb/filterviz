#define _USE_MATH_DEFINES
#include <cmath>
#include <QtCharts>
#include "filterwidget.h"
#include "ui_filterwidget.h"

using namespace std;

FilterWidget::FilterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FilterWidget)
{
    ui->setupUi(this);
}

FilterWidget::~FilterWidget()
{
    delete ui;
}

int FilterWidget::plotFreqResp(vector<double> freq, vector<double> mag_db, 
    vector<double> phase_rad, bool logx, char *id){

    // data
    QLineSeries *series_freqresp_mag = new QLineSeries();
    QLineSeries *series_freqresp_phase = new QLineSeries();
    for(int i=1; i<freq.size(); i++) // From 1 since we do not want DC
    {
        series_freqresp_mag->append(freq[i], mag_db[i]);
        series_freqresp_phase->append(freq[i], phase_rad[i]);
    }

    // charts
    QChart *chart_freqresp_mag = new QChart();
    QChart *chart_freqresp_phase = new QChart();
    chart_freqresp_mag->legend()->hide();
    chart_freqresp_phase->legend()->hide();
    chart_freqresp_mag->layout()->setContentsMargins(2, 2, 2, 2);
    chart_freqresp_phase->layout()->setContentsMargins(2, 2, 2, 2);
    chart_freqresp_mag->addSeries(series_freqresp_mag);
    chart_freqresp_phase->addSeries(series_freqresp_phase);
    QMargins margin {4,4,4,4};
    chart_freqresp_mag->setMargins(margin);
    chart_freqresp_phase->setMargins(margin);

    // title
    chart_freqresp_mag->setTitle(id);
    QFont title;
    title.setBold(true);
    title.setPointSize(10);
    chart_freqresp_mag->setTitleFont(title);

    // axes
    QFont faxis;
    faxis.setBold(false);

    if (logx) {
        QLogValueAxis *axisX_mag_log = new QLogValueAxis;
        axisX_mag_log->setBase(10.0);
        axisX_mag_log->setRange(10, freq.back());
        axisX_mag_log->setMinorGridLineVisible(true);
        axisX_mag_log->setMinorTickCount(-1);
        axisX_mag_log->setTitleText("Frequency (Hz)");
        axisX_mag_log->setTitleFont(faxis);
        chart_freqresp_mag->addAxis(axisX_mag_log, Qt::AlignBottom);
        series_freqresp_mag->attachAxis(axisX_mag_log);

        QLogValueAxis *axisX_phase_log = new QLogValueAxis;
        axisX_phase_log->setBase(10.0);
        axisX_phase_log->setRange(10, freq.back());
        axisX_phase_log->setMinorGridLineVisible(true);
        axisX_phase_log->setMinorTickCount(-1);
        axisX_phase_log->setTitleText("Frequency (Hz)");
        axisX_phase_log->setTitleFont(faxis);
        chart_freqresp_phase->addAxis(axisX_phase_log, Qt::AlignBottom);
        series_freqresp_phase->attachAxis(axisX_phase_log);

    } else {
        QValueAxis *axisX_mag_lin = new QValueAxis;
        axisX_mag_lin->setTitleText("Frequency (Hz)");
        axisX_mag_lin->setTitleFont(faxis);
        axisX_mag_lin->setRange(0,freq.back());
        chart_freqresp_mag->addAxis(axisX_mag_lin, Qt::AlignBottom);
        series_freqresp_mag->attachAxis(axisX_mag_lin);

        QValueAxis *axisX_phase_lin = new QValueAxis;
        axisX_phase_lin->setTitleText("Frequency (Hz)");
        axisX_phase_lin->setTitleFont(faxis);
        axisX_phase_lin->setRange(0,freq.back());
        chart_freqresp_phase->addAxis(axisX_phase_lin, Qt::AlignBottom);
        series_freqresp_phase->attachAxis(axisX_phase_lin);
    }
    
    QValueAxis *axisY_mag = new QValueAxis;
    QValueAxis *axisY_phase = new QValueAxis;
    axisY_mag->setTitleText("Magnitude (dB)");
    axisY_mag->setTitleFont(faxis);
    axisY_phase->setTitleText("Phase (rad)");
    axisY_phase->setTitleFont(faxis);
    // to give some extra margin for better visualization
    double max = *max_element(mag_db.begin(), mag_db.end());
    double min = *min_element(mag_db.begin(), mag_db.end());
    axisY_mag->setRange(min-10, max+10);
    axisY_phase->setRange(-M_PI, M_PI);
    chart_freqresp_mag->addAxis(axisY_mag, Qt::AlignLeft);
    chart_freqresp_phase->addAxis(axisY_phase, Qt::AlignLeft);
    series_freqresp_mag->attachAxis(axisY_mag);
    series_freqresp_phase->attachAxis(axisY_phase);

    // set chart
    ui->freqResp_mag->setChart(chart_freqresp_mag);
    ui->freqResp_phase->setChart(chart_freqresp_phase);

    return 0;
}
