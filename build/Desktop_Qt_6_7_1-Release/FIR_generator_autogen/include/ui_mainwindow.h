/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QWidget *centralwidget;
    QWidget *widget;
    QGroupBox *parambox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *samp_freq;
    QTextEdit *fir_len;
    QTextEdit *samp_shitf;
    QLabel *label_4;
    QRadioButton *impulse_radio;
    QRadioButton *step_radio;
    QPushButton *designFilter;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *low_freq;
    QTextEdit *hi_freq;
    QLabel *label_8;
    QComboBox *win_func_box;
    QComboBox *display_box;
    QGroupBox *filtertypebox;
    QRadioButton *lp_radio;
    QRadioButton *hp_radio;
    QRadioButton *bp_radio;
    QRadioButton *bs_radio;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(961, 734);
        MainWindow->setMaximumSize(QSize(1000, 800));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 10, 921, 521));
        widget->setMaximumSize(QSize(1000, 700));
        parambox = new QGroupBox(centralwidget);
        parambox->setObjectName("parambox");
        parambox->setGeometry(QRect(20, 540, 921, 151));
        label = new QLabel(parambox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 151, 16));
        label_2 = new QLabel(parambox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 151, 16));
        label_3 = new QLabel(parambox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 151, 16));
        samp_freq = new QTextEdit(parambox);
        samp_freq->setObjectName("samp_freq");
        samp_freq->setGeometry(QRect(160, 30, 91, 31));
        fir_len = new QTextEdit(parambox);
        fir_len->setObjectName("fir_len");
        fir_len->setGeometry(QRect(160, 70, 91, 31));
        samp_shitf = new QTextEdit(parambox);
        samp_shitf->setObjectName("samp_shitf");
        samp_shitf->setGeometry(QRect(160, 110, 91, 31));
        label_4 = new QLabel(parambox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 40, 121, 16));
        impulse_radio = new QRadioButton(parambox);
        impulse_radio->setObjectName("impulse_radio");
        impulse_radio->setGeometry(QRect(700, 50, 71, 22));
        impulse_radio->setChecked(true);
        step_radio = new QRadioButton(parambox);
        step_radio->setObjectName("step_radio");
        step_radio->setGeometry(QRect(700, 80, 71, 22));
        designFilter = new QPushButton(parambox);
        designFilter->setObjectName("designFilter");
        designFilter->setGeometry(QRect(780, 40, 131, 91));
        label_5 = new QLabel(parambox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(260, 80, 121, 16));
        label_6 = new QLabel(parambox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 120, 121, 16));
        low_freq = new QTextEdit(parambox);
        low_freq->setObjectName("low_freq");
        low_freq->setEnabled(false);
        low_freq->setGeometry(QRect(390, 30, 91, 31));
        hi_freq = new QTextEdit(parambox);
        hi_freq->setObjectName("hi_freq");
        hi_freq->setGeometry(QRect(390, 70, 91, 31));
        label_8 = new QLabel(parambox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(520, 100, 71, 21));
        win_func_box = new QComboBox(parambox);
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->addItem(QString());
        win_func_box->setObjectName("win_func_box");
        win_func_box->setGeometry(QRect(380, 120, 121, 24));
        display_box = new QComboBox(parambox);
        display_box->addItem(QString());
        display_box->addItem(QString());
        display_box->addItem(QString());
        display_box->setObjectName("display_box");
        display_box->setGeometry(QRect(570, 100, 131, 24));
        filtertypebox = new QGroupBox(parambox);
        filtertypebox->setObjectName("filtertypebox");
        filtertypebox->setGeometry(QRect(520, 30, 121, 61));
        lp_radio = new QRadioButton(filtertypebox);
        lp_radio->setObjectName("lp_radio");
        lp_radio->setGeometry(QRect(20, 20, 41, 22));
        lp_radio->setChecked(true);
        hp_radio = new QRadioButton(filtertypebox);
        hp_radio->setObjectName("hp_radio");
        hp_radio->setGeometry(QRect(70, 20, 41, 22));
        bp_radio = new QRadioButton(filtertypebox);
        bp_radio->setObjectName("bp_radio");
        bp_radio->setGeometry(QRect(20, 40, 41, 22));
        bs_radio = new QRadioButton(filtertypebox);
        bs_radio->setObjectName("bs_radio");
        bs_radio->setGeometry(QRect(70, 40, 41, 22));
        MainWindow->setCentralWidget(centralwidget);
        parambox->raise();
        widget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 961, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSave);

        retranslateUi(MainWindow);

        win_func_box->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "FIR Filter", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        parambox->setTitle(QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sampling Frequency (Hz):", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Filter Length:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Shift Samples:", nullptr));
        samp_freq->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1000</p></body></html>", nullptr));
        fir_len->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">160</p></body></html>", nullptr));
        samp_shitf->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">80</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Low Frequency (Hz):", nullptr));
        impulse_radio->setText(QCoreApplication::translate("MainWindow", "Impulse", nullptr));
        step_radio->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        designFilter->setText(QCoreApplication::translate("MainWindow", "Design Filter", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "High Frequency (Hz):", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Window Function:", nullptr));
        low_freq->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10</p></body></html>", nullptr));
        hi_freq->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">100</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Display:", nullptr));
        win_func_box->setItemText(0, QCoreApplication::translate("MainWindow", "Rectangular", nullptr));
        win_func_box->setItemText(1, QCoreApplication::translate("MainWindow", "Triangular", nullptr));
        win_func_box->setItemText(2, QCoreApplication::translate("MainWindow", "Welch", nullptr));
        win_func_box->setItemText(3, QCoreApplication::translate("MainWindow", "Sine", nullptr));
        win_func_box->setItemText(4, QCoreApplication::translate("MainWindow", "Hann", nullptr));
        win_func_box->setItemText(5, QCoreApplication::translate("MainWindow", "Hamming", nullptr));
        win_func_box->setItemText(6, QCoreApplication::translate("MainWindow", "Blackman", nullptr));
        win_func_box->setItemText(7, QCoreApplication::translate("MainWindow", "Nuttall", nullptr));
        win_func_box->setItemText(8, QCoreApplication::translate("MainWindow", "BlackmanNuttall", nullptr));
        win_func_box->setItemText(9, QCoreApplication::translate("MainWindow", "BlackmanHarris", nullptr));
        win_func_box->setItemText(10, QCoreApplication::translate("MainWindow", "FlatTop", nullptr));

        display_box->setItemText(0, QCoreApplication::translate("MainWindow", "Both", nullptr));
        display_box->setItemText(1, QCoreApplication::translate("MainWindow", "Both2", nullptr));
        display_box->setItemText(2, QCoreApplication::translate("MainWindow", "Both3", nullptr));

        filtertypebox->setTitle(QCoreApplication::translate("MainWindow", "Filter Type", nullptr));
        lp_radio->setText(QCoreApplication::translate("MainWindow", "LP", nullptr));
        hp_radio->setText(QCoreApplication::translate("MainWindow", "HP", nullptr));
        bp_radio->setText(QCoreApplication::translate("MainWindow", "BP", nullptr));
        bs_radio->setText(QCoreApplication::translate("MainWindow", "BS", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
