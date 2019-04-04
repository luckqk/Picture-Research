/********************************************************************************
** Form generated from reading UI file 'PictureResearch.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURERESEARCH_H
#define UI_PICTURERESEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureResearchClass
{
public:
    QAction *actOpen;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabBitmapFileHeader;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelBfType;
    QLabel *labelBfSize;
    QLabel *labelBfReserved2;
    QLabel *labelBfReserved1;
    QLabel *labelBfOffBits;
    QLineEdit *lineEtBfType;
    QLineEdit *lineEtBfSize;
    QLineEdit *lineEtBfReserved1;
    QLineEdit *lineEtBfReserved2;
    QLineEdit *lineEtBfOffBits;
    QWidget *tabBitmapInfoHeader;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *labelBiWidth;
    QLabel *labelBiSize;
    QLabel *labelBiHeight;
    QLabel *labelBiCompression;
    QLineEdit *lineEtBiBitCnt;
    QLineEdit *lineEtBiWidth;
    QLabel *labelBiPlane;
    QLineEdit *lineEtBiSize;
    QLineEdit *lineEtBiPlane;
    QLineEdit *lineEtBiHeight;
    QLabel *labelBiBitCnt;
    QLabel *labelBiSizImg;
    QLabel *labelBiClrUsed;
    QLabel *labelBiXPelsPerM;
    QLineEdit *lineEtBiCompression;
    QLabel *labelBiYPelsPerM;
    QLabel *labelBiClrImportant;
    QLineEdit *lineEtBiSizImg;
    QLineEdit *lineEtBiXPelsPerM;
    QLineEdit *lineEtBiYPelsPerM;
    QLineEdit *lineEtBiClrUsed;
    QLineEdit *lineEtBiClrImportant;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *LabPicture;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PictureResearchClass)
    {
        if (PictureResearchClass->objectName().isEmpty())
            PictureResearchClass->setObjectName(QStringLiteral("PictureResearchClass"));
        PictureResearchClass->resize(996, 576);
        actOpen = new QAction(PictureResearchClass);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/img/open3.bmp"), QSize(), QIcon::Normal, QIcon::On);
        actOpen->setIcon(icon);
        centralWidget = new QWidget(PictureResearchClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 461, 481));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(horizontalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabBitmapFileHeader = new QWidget();
        tabBitmapFileHeader->setObjectName(QStringLiteral("tabBitmapFileHeader"));
        tabBitmapFileHeader->setCursor(QCursor(Qt::ArrowCursor));
        gridLayoutWidget = new QWidget(tabBitmapFileHeader);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 60, 251, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelBfType = new QLabel(gridLayoutWidget);
        labelBfType->setObjectName(QStringLiteral("labelBfType"));
        labelBfType->setCursor(QCursor(Qt::ArrowCursor));
        labelBfType->setFocusPolicy(Qt::NoFocus);
        labelBfType->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBfType, 0, 0, 1, 1);

        labelBfSize = new QLabel(gridLayoutWidget);
        labelBfSize->setObjectName(QStringLiteral("labelBfSize"));
        labelBfSize->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBfSize, 1, 0, 1, 1);

        labelBfReserved2 = new QLabel(gridLayoutWidget);
        labelBfReserved2->setObjectName(QStringLiteral("labelBfReserved2"));
        labelBfReserved2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBfReserved2, 3, 0, 1, 1);

        labelBfReserved1 = new QLabel(gridLayoutWidget);
        labelBfReserved1->setObjectName(QStringLiteral("labelBfReserved1"));
        labelBfReserved1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBfReserved1, 2, 0, 1, 1);

        labelBfOffBits = new QLabel(gridLayoutWidget);
        labelBfOffBits->setObjectName(QStringLiteral("labelBfOffBits"));
        labelBfOffBits->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelBfOffBits, 4, 0, 1, 1);

        lineEtBfType = new QLineEdit(gridLayoutWidget);
        lineEtBfType->setObjectName(QStringLiteral("lineEtBfType"));

        gridLayout->addWidget(lineEtBfType, 0, 1, 1, 1);

        lineEtBfSize = new QLineEdit(gridLayoutWidget);
        lineEtBfSize->setObjectName(QStringLiteral("lineEtBfSize"));
        lineEtBfSize->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lineEtBfSize, 1, 1, 1, 1);

        lineEtBfReserved1 = new QLineEdit(gridLayoutWidget);
        lineEtBfReserved1->setObjectName(QStringLiteral("lineEtBfReserved1"));

        gridLayout->addWidget(lineEtBfReserved1, 2, 1, 1, 1);

        lineEtBfReserved2 = new QLineEdit(gridLayoutWidget);
        lineEtBfReserved2->setObjectName(QStringLiteral("lineEtBfReserved2"));

        gridLayout->addWidget(lineEtBfReserved2, 3, 1, 1, 1);

        lineEtBfOffBits = new QLineEdit(gridLayoutWidget);
        lineEtBfOffBits->setObjectName(QStringLiteral("lineEtBfOffBits"));

        gridLayout->addWidget(lineEtBfOffBits, 4, 1, 1, 1);

        tabWidget->addTab(tabBitmapFileHeader, QString());
        tabBitmapInfoHeader = new QWidget();
        tabBitmapInfoHeader->setObjectName(QStringLiteral("tabBitmapInfoHeader"));
        gridLayoutWidget_2 = new QWidget(tabBitmapInfoHeader);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 431, 431));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelBiWidth = new QLabel(gridLayoutWidget_2);
        labelBiWidth->setObjectName(QStringLiteral("labelBiWidth"));

        gridLayout_2->addWidget(labelBiWidth, 1, 0, 1, 1);

        labelBiSize = new QLabel(gridLayoutWidget_2);
        labelBiSize->setObjectName(QStringLiteral("labelBiSize"));

        gridLayout_2->addWidget(labelBiSize, 0, 0, 1, 1);

        labelBiHeight = new QLabel(gridLayoutWidget_2);
        labelBiHeight->setObjectName(QStringLiteral("labelBiHeight"));

        gridLayout_2->addWidget(labelBiHeight, 2, 0, 1, 1);

        labelBiCompression = new QLabel(gridLayoutWidget_2);
        labelBiCompression->setObjectName(QStringLiteral("labelBiCompression"));

        gridLayout_2->addWidget(labelBiCompression, 5, 0, 1, 1);

        lineEtBiBitCnt = new QLineEdit(gridLayoutWidget_2);
        lineEtBiBitCnt->setObjectName(QStringLiteral("lineEtBiBitCnt"));

        gridLayout_2->addWidget(lineEtBiBitCnt, 4, 1, 1, 1);

        lineEtBiWidth = new QLineEdit(gridLayoutWidget_2);
        lineEtBiWidth->setObjectName(QStringLiteral("lineEtBiWidth"));

        gridLayout_2->addWidget(lineEtBiWidth, 1, 1, 1, 1);

        labelBiPlane = new QLabel(gridLayoutWidget_2);
        labelBiPlane->setObjectName(QStringLiteral("labelBiPlane"));

        gridLayout_2->addWidget(labelBiPlane, 3, 0, 1, 1);

        lineEtBiSize = new QLineEdit(gridLayoutWidget_2);
        lineEtBiSize->setObjectName(QStringLiteral("lineEtBiSize"));

        gridLayout_2->addWidget(lineEtBiSize, 0, 1, 1, 1);

        lineEtBiPlane = new QLineEdit(gridLayoutWidget_2);
        lineEtBiPlane->setObjectName(QStringLiteral("lineEtBiPlane"));

        gridLayout_2->addWidget(lineEtBiPlane, 3, 1, 1, 1);

        lineEtBiHeight = new QLineEdit(gridLayoutWidget_2);
        lineEtBiHeight->setObjectName(QStringLiteral("lineEtBiHeight"));

        gridLayout_2->addWidget(lineEtBiHeight, 2, 1, 1, 1);

        labelBiBitCnt = new QLabel(gridLayoutWidget_2);
        labelBiBitCnt->setObjectName(QStringLiteral("labelBiBitCnt"));

        gridLayout_2->addWidget(labelBiBitCnt, 4, 0, 1, 1);

        labelBiSizImg = new QLabel(gridLayoutWidget_2);
        labelBiSizImg->setObjectName(QStringLiteral("labelBiSizImg"));

        gridLayout_2->addWidget(labelBiSizImg, 0, 2, 1, 1);

        labelBiClrUsed = new QLabel(gridLayoutWidget_2);
        labelBiClrUsed->setObjectName(QStringLiteral("labelBiClrUsed"));

        gridLayout_2->addWidget(labelBiClrUsed, 3, 2, 1, 1);

        labelBiXPelsPerM = new QLabel(gridLayoutWidget_2);
        labelBiXPelsPerM->setObjectName(QStringLiteral("labelBiXPelsPerM"));

        gridLayout_2->addWidget(labelBiXPelsPerM, 1, 2, 1, 1);

        lineEtBiCompression = new QLineEdit(gridLayoutWidget_2);
        lineEtBiCompression->setObjectName(QStringLiteral("lineEtBiCompression"));

        gridLayout_2->addWidget(lineEtBiCompression, 5, 1, 1, 1);

        labelBiYPelsPerM = new QLabel(gridLayoutWidget_2);
        labelBiYPelsPerM->setObjectName(QStringLiteral("labelBiYPelsPerM"));

        gridLayout_2->addWidget(labelBiYPelsPerM, 2, 2, 1, 1);

        labelBiClrImportant = new QLabel(gridLayoutWidget_2);
        labelBiClrImportant->setObjectName(QStringLiteral("labelBiClrImportant"));

        gridLayout_2->addWidget(labelBiClrImportant, 4, 2, 1, 1);

        lineEtBiSizImg = new QLineEdit(gridLayoutWidget_2);
        lineEtBiSizImg->setObjectName(QStringLiteral("lineEtBiSizImg"));

        gridLayout_2->addWidget(lineEtBiSizImg, 0, 3, 1, 1);

        lineEtBiXPelsPerM = new QLineEdit(gridLayoutWidget_2);
        lineEtBiXPelsPerM->setObjectName(QStringLiteral("lineEtBiXPelsPerM"));

        gridLayout_2->addWidget(lineEtBiXPelsPerM, 1, 3, 1, 1);

        lineEtBiYPelsPerM = new QLineEdit(gridLayoutWidget_2);
        lineEtBiYPelsPerM->setObjectName(QStringLiteral("lineEtBiYPelsPerM"));

        gridLayout_2->addWidget(lineEtBiYPelsPerM, 2, 3, 1, 1);

        lineEtBiClrUsed = new QLineEdit(gridLayoutWidget_2);
        lineEtBiClrUsed->setObjectName(QStringLiteral("lineEtBiClrUsed"));

        gridLayout_2->addWidget(lineEtBiClrUsed, 3, 3, 1, 1);

        lineEtBiClrImportant = new QLineEdit(gridLayoutWidget_2);
        lineEtBiClrImportant->setObjectName(QStringLiteral("lineEtBiClrImportant"));

        gridLayout_2->addWidget(lineEtBiClrImportant, 4, 3, 1, 1);

        tabWidget->addTab(tabBitmapInfoHeader, QString());

        horizontalLayout->addWidget(tabWidget);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(490, 10, 491, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 487, 477));
        LabPicture = new QLabel(scrollAreaWidgetContents);
        LabPicture->setObjectName(QStringLiteral("LabPicture"));
        LabPicture->setGeometry(QRect(20, 30, 441, 441));
        LabPicture->setPixmap(QPixmap(QString::fromUtf8(":/images/img/spiderman.jpg")));
        LabPicture->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        PictureResearchClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PictureResearchClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 996, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        PictureResearchClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PictureResearchClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PictureResearchClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PictureResearchClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PictureResearchClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actOpen);

        retranslateUi(PictureResearchClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PictureResearchClass);
    } // setupUi

    void retranslateUi(QMainWindow *PictureResearchClass)
    {
        PictureResearchClass->setWindowTitle(QApplication::translate("PictureResearchClass", "PictureResearch", Q_NULLPTR));
        actOpen->setText(QApplication::translate("PictureResearchClass", "\346\211\223\345\274\200...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("PictureResearchClass", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actOpen->setShortcut(QApplication::translate("PictureResearchClass", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        labelBfType->setText(QApplication::translate("PictureResearchClass", "\346\226\207\344\273\266\347\261\273\345\236\213", Q_NULLPTR));
        labelBfSize->setText(QApplication::translate("PictureResearchClass", "\346\226\207\344\273\266\345\244\247\345\260\217", Q_NULLPTR));
        labelBfReserved2->setText(QApplication::translate("PictureResearchClass", "\344\277\235\347\225\231\345\200\2742", Q_NULLPTR));
        labelBfReserved1->setText(QApplication::translate("PictureResearchClass", "\344\277\235\347\225\231\345\200\2741", Q_NULLPTR));
        labelBfOffBits->setText(QApplication::translate("PictureResearchClass", " \350\267\235\345\233\276\345\203\217\346\225\260\346\215\256\n"
"\347\232\204\345\201\217\347\247\273\351\207\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabBitmapFileHeader), QApplication::translate("PictureResearchClass", "\344\275\215\345\233\276\345\244\264\346\226\207\344\273\266\346\225\260\346\215\256", Q_NULLPTR));
        labelBiWidth->setText(QApplication::translate("PictureResearchClass", "\345\233\276\345\203\217\345\256\275\345\272\246", Q_NULLPTR));
        labelBiSize->setText(QApplication::translate("PictureResearchClass", "\344\275\215\345\233\276\344\277\241\346\201\257\346\225\260\346\215\256\n"
"\345\244\247\345\260\217", Q_NULLPTR));
        labelBiHeight->setText(QApplication::translate("PictureResearchClass", "\345\233\276\345\203\217\351\253\230\345\272\246", Q_NULLPTR));
        labelBiCompression->setText(QApplication::translate("PictureResearchClass", "\345\216\213\347\274\251\347\261\273\345\236\213", Q_NULLPTR));
        labelBiPlane->setText(QApplication::translate("PictureResearchClass", "\344\275\215\351\235\242\346\225\260", Q_NULLPTR));
        labelBiBitCnt->setText(QApplication::translate("PictureResearchClass", "\351\242\234\350\211\262\344\275\215\346\225\260", Q_NULLPTR));
        labelBiSizImg->setText(QApplication::translate("PictureResearchClass", "\345\233\276\345\203\217\345\256\236\351\231\205\345\244\247\345\260\217", Q_NULLPTR));
        labelBiClrUsed->setText(QApplication::translate("PictureResearchClass", "\351\242\234\350\211\262\347\264\242\345\274\225\346\225\260", Q_NULLPTR));
        labelBiXPelsPerM->setText(QApplication::translate("PictureResearchClass", "\346\260\264\345\271\263\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        labelBiYPelsPerM->setText(QApplication::translate("PictureResearchClass", "\345\236\202\347\233\264\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        labelBiClrImportant->setText(QApplication::translate("PictureResearchClass", "\351\207\215\350\246\201\351\242\234\350\211\262\347\264\242\345\274\225\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabBitmapInfoHeader), QApplication::translate("PictureResearchClass", "\344\275\215\345\233\276\344\277\241\346\201\257\346\225\260\346\215\256", Q_NULLPTR));
        LabPicture->setText(QString());
        menu->setTitle(QApplication::translate("PictureResearchClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PictureResearchClass: public Ui_PictureResearchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURERESEARCH_H
