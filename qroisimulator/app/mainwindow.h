//
// mainwindow.h
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SIMULATION

// Qt
#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QMutex>

#include "viewmainpage.h"
#include "camcapture.h"
#include "imgprocbase.h"
#include "outwidget.h"

class QModelIndex;
class QUrl;

class DialogEdge;

using namespace Qroilib;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

public:

    /**
     * Defines the url to display when the window is shown for the first time.
     */
    void setInitialUrl(const QUrl&);

    ViewMainPage* viewMainPage() const;
    DocumentView* currentView() const;

protected:
    void closeEvent(QCloseEvent *event);

private:
    struct Private;
    MainWindow::Private* const d;
    CamCapture* myCamCapture;
    CImgProcBase base;

public  Q_SLOTS:
    void setSaveImage();
    void setReadImage();
    void setDialogcamera();
    void finishNewRoiObject();

    void setGrayImage();
    void setThreshold();
    void setmorphology();
    void setEdge();
    void setBlob();
    void setContour();
    void setArithmeticlogic();
    void setLineFit();
    void setCircle();

    void setApplication();
    void setApiTest();

public:
    QVector<OutWidget*> vecOutWidget;
public:
    void outWidget(QString title, IplImage* iplImg);
};

extern MainWindow* theMainWindow;

#endif /* MAINWINDOW_H */
