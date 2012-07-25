/**********************************************
**    This file is part of Lorris
**    http://tasssadar.github.com/Lorris/
**
**    See README and COPYING
***********************************************/

#include <QCloseEvent>
#include <QCloseEvent>
#include <QStatusBar>

#include "mainwindow.h"
#include "../WorkTab/WorkTab.h"
#include "../WorkTab/WorkTabMgr.h"
#include "../WorkTab/WorkTabInfo.h"
#include "../revision.h"
#include "../misc/config.h"
#include "HomeTab.h"
#include "../misc/datafileparser.h"

MainWindow::MainWindow(quint32 id, QWidget *parent) :
    QMainWindow(parent)
{
    m_id = id;
    m_hometab = NULL;

    setWindowTitle(getVersionString());
    setMinimumSize(600, 500);
    setWindowIcon(QIcon(":/icons/icon.png"));
    setAttribute(Qt::WA_DeleteOnClose);
    loadWindowParams();

    QApplication::setFont(Utils::getFontFromString(sConfig.get(CFG_STRING_APP_FONT)));

    setStatusBar(new QStatusBar(this));

    m_tabView = new TabView(this);
    connect(m_tabView, SIGNAL(statusBarMsg(QString,int)), statusBar(), SLOT(showMessage(QString,int)));
    connect(m_tabView, SIGNAL(closeWindow()),                          SLOT(close()));
    connect(m_tabView, SIGNAL(openHomeTab()),                          SLOT(openHomeTab()));
    connect(m_tabView, SIGNAL(closeHomeTab()),                         SLOT(closeHomeTab()));

    setCentralWidget(m_tabView);
    openHomeTab();
}

MainWindow::~MainWindow()
{

}

void MainWindow::show(const QStringList& openFiles)
{
    QMainWindow::show();

    for(QStringList::const_iterator itr = openFiles.begin(); itr != openFiles.end(); ++itr)
        sWorkTabMgr.openTabWithFile(*itr, this);
}

QString MainWindow::getVersionString()
{
    QString ver = "Lorris v" + QString::number(REVISION);
    return ver;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!sWorkTabMgr.onTabsClose(getId()))
        event->ignore();
    else
    {
        saveWindowParams();
        event->accept();
    }
}

void MainWindow::saveWindowParams()
{
    sConfig.set(CFG_STRING_WINDOW_PARAMS, Utils::saveWindowParams(this));
}

void MainWindow::loadWindowParams()
{
    Utils::loadWindowParams(this, sConfig.get(CFG_STRING_WINDOW_PARAMS));
}

void MainWindow::openHomeTab()
{
    Q_ASSERT(!m_hometab);
    if(m_hometab)
        return;

    m_hometab = new HomeTab(this);
    m_hometab->setWindowId(m_id);
    m_tabView->getActiveWidget()->addTab(m_hometab, tr("Home"));
}

void MainWindow::closeHomeTab()
{
    if(!m_hometab)
        return;

    delete m_hometab;
    m_hometab = NULL;
}

void MainWindow::saveData(DataFileParser *file)
{
    file->writeBlockIdentifier("windowInfo");
    file->writeString(Utils::saveWindowParams(this));
    m_tabView->saveData(file);
}

void MainWindow::loadData(DataFileParser *file)
{
    if(!file->seekToNextBlock("windowInfo", 0))
        return;

    Utils::loadWindowParams(this, file->readString());
    m_tabView->loadData(file);
}
