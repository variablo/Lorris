# -------------------------------------------------
# Project created by QtCreator 2011-05-30T19:16:22
# -------------------------------------------------
QT += gui core network script
TARGET = Lorris
CONFIG += uitools
CONFIG(debug, debug|release):DESTDIR = $$PWD/bin/debug
else:DESTDIR = $$PWD/bin/release
OBJECTS_DIR = $$PWD/obj
MOC_DIR = $$PWD/moc
UI_DIR = $$PWD/ui
CONFIG += qwt
LIBS += -L"$$PWD/dep/qwt/lib"
LIBS += -L"$$PWD/dep/qextserialport/lib"
TRANSLATIONS = translations/Lorris.cs_CZ.ts
TEMPLATE = app
INCLUDEPATH += dep/qwt/src
INCLUDEPATH += dep/qserialdevice/src
INCLUDEPATH += dep/qhexedit2/src
INCLUDEPATH += src ui src/shared dep src/LorrisAnalyzer
INCLUDEPATH += dep/qextserialport/src
SOURCES += src/ui/mainwindow.cpp \
    src/main.cpp \
    src/ui/HomeTab.cpp \
    src/WorkTab/WorkTab.cpp \
    src/WorkTab/WorkTabMgr.cpp \
    src/WorkTab/WorkTabInfo.cpp \
    src/connection/connectionmgr.cpp \
    src/ui/tabdialog.cpp \
    src/LorrisTerminal/lorristerminal.cpp \
    src/LorrisTerminal/lorristerminalinfo.cpp \
    src/connection/connection.cpp \
    src/connection/serialport.cpp \
    src/LorrisTerminal/eeprom.cpp \
    src/LorrisAnalyzer/lorrisanalyzerinfo.cpp \
    src/LorrisAnalyzer/lorrisanalyzer.cpp \
    src/LorrisAnalyzer/sourcedialog.cpp \
    src/utils.cpp \
    src/LorrisAnalyzer/labellayout.cpp \
    src/LorrisAnalyzer/packet.cpp \
    src/LorrisAnalyzer/analyzerdatastorage.cpp \
    src/LorrisAnalyzer/devicetabwidget.cpp \
    src/LorrisAnalyzer/cmdtabwidget.cpp \
    src/connection/fileconnection.cpp \
    src/LorrisAnalyzer/analyzerdataarea.cpp \
    src/LorrisAnalyzer/DataWidgets/datawidget.cpp \
    src/LorrisAnalyzer/DataWidgets/numberwidget.cpp \
    src/LorrisAnalyzer/DataWidgets/barwidget.cpp \
    src/LorrisAnalyzer/sourceselectdialog.cpp \
    src/LorrisShupito/lorrisshupito.cpp \
    src/LorrisShupito/lorrisshupitoinfo.cpp \
    src/LorrisShupito/shupito.cpp \
    src/LorrisShupito/shupitodesc.cpp \
    src/LorrisAnalyzer/analyzerdatafile.cpp \
    src/LorrisAnalyzer/DataWidgets/colorwidget.cpp \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphwidget.cpp \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graph.cpp \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphdialogs.cpp \
    src/connection/shupitotunnel.cpp \
    src/config.cpp \
    dep/qhexedit2/src/xbytearray.cpp \
    dep/qhexedit2/src/qhexedit_p.cpp \
    dep/qhexedit2/src/qhexedit.cpp \
    dep/qhexedit2/src/commands.cpp \
    src/LorrisShupito/fusewidget.cpp \
    src/shared/hexfile.cpp \
    src/shared/chipdefs.cpp \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphdata.cpp \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphcurve.cpp \
    src/connection/serialportthread.cpp \
    src/LorrisShupito/flashbuttonmenu.cpp \
    src/LorrisShupito/modes/shupitospi.cpp \
    src/LorrisShupito/modes/shupitopdi.cpp \
    src/LorrisShupito/modes/shupitomode.cpp \
    src/LorrisShupito/modes/shupitocc25xx.cpp \
    src/LorrisShupito/shupitopacket.cpp \
    src/connection/tcpsocket.cpp \
    src/LorrisProxy/lorrisproxyinfo.cpp \
    src/LorrisProxy/lorrisproxy.cpp \
    src/LorrisProxy/tcpserver.cpp \
    src/LorrisShupito/progressdialog.cpp \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scriptwidget.cpp \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scriptenv.cpp \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scripteditor.cpp \
    src/shared/terminal.cpp \
    dep/qscriptsyntaxhighlighter.cpp \
    src/LorrisAnalyzer/playback.cpp \
    src/LorrisAnalyzer/DataWidgets/inputwidget.cpp \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scriptagent.cpp \
    src/ui/maintabwidget.cpp \
    src/shared/rotatebutton.cpp \
    src/LorrisShupito/reloaddialog.cpp
HEADERS += src/ui/mainwindow.h \
    src/revision.h \
    src/ui/HomeTab.h \
    src/WorkTab/WorkTab.h \
    src/WorkTab/WorkTabMgr.h \
    src/WorkTab/WorkTabInfo.h \
    src/connection/connectionmgr.h \
    src/ui/tabdialog.h \
    src/singleton.h \
    src/LorrisTerminal/lorristerminal.h \
    src/LorrisTerminal/lorristerminalinfo.h \
    src/connection/connection.h \
    src/connection/serialport.h \
    src/LorrisTerminal/eeprom.h \
    src/LorrisAnalyzer/lorrisanalyzer.h \
    src/LorrisAnalyzer/lorrisanalyzerinfo.h \
    src/LorrisAnalyzer/lorrisanalyzer.h \
    src/common.h \
    src/LorrisAnalyzer/sourcedialog.h \
    src/utils.h \
    src/LorrisAnalyzer/labellayout.h \
    src/LorrisAnalyzer/packet.h \
    src/LorrisAnalyzer/analyzerdatastorage.h \
    src/LorrisAnalyzer/devicetabwidget.h \
    src/LorrisAnalyzer/cmdtabwidget.h \
    src/connection/fileconnection.h \
    src/LorrisAnalyzer/analyzerdataarea.h \
    src/LorrisAnalyzer/DataWidgets/datawidget.h \
    src/LorrisAnalyzer/DataWidgets/numberwidget.h \
    src/LorrisAnalyzer/DataWidgets/barwidget.h \
    src/LorrisAnalyzer/sourceselectdialog.h \
    src/LorrisShupito/lorrisshupito.h \
    src/LorrisShupito/lorrisshupitoinfo.h \
    src/LorrisShupito/shupito.h \
    src/LorrisShupito/shupitodesc.h \
    src/LorrisAnalyzer/analyzerdatafile.h \
    src/LorrisAnalyzer/DataWidgets/colorwidget.h \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphwidget.h \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graph.h \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphdialogs.h \
    src/connection/shupitotunnel.h \
    src/config.h \
    dep/qhexedit2/src/xbytearray.h \
    dep/qhexedit2/src/qhexedit_p.h \
    dep/qhexedit2/src/qhexedit.h \
    dep/qhexedit2/src/commands.h \
    src/LorrisShupito/fusewidget.h \
    src/shared/hexfile.h \
    src/shared/chipdefs.h \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphdata.h \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphcurve.h \
    src/connection/serialportthread.h \
    src/LorrisShupito/flashbuttonmenu.h \
    src/LorrisShupito/modes/shupitospi.h \
    src/LorrisShupito/modes/shupitopdi.h \
    src/LorrisShupito/modes/shupitomode.h \
    src/LorrisShupito/modes/shupitocc25xx.h \
    src/LorrisShupito/shupitopacket.h \
    src/connection/tcpsocket.h \
    src/LorrisProxy/lorrisproxyinfo.h \
    src/LorrisProxy/lorrisproxy.h \
    src/LorrisProxy/tcpserver.h \
    src/LorrisShupito/progressdialog.h \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scriptwidget.h \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scriptenv.h \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scripteditor.h \
    src/shared/terminal.h \
    dep/qscriptsyntaxhighlighter_p.h \
    src/LorrisAnalyzer/playback.h \
    src/LorrisAnalyzer/DataWidgets/inputwidget.h \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scriptagent.h \
    src/ui/maintabwidget.h \
    src/shared/rotatebutton.h \
    src/LorrisShupito/reloaddialog.h

win32 {
    DEFINES += QT_DLL QWT_DLL
    QMAKE_LFLAGS = -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc

    CONFIG(debug, debug|release):LIBS += -lqwtd -lqextserialportd1
    else:LIBS += -lqwt -lqextserialport1
}
unix:!macx:!symbian {
    LIBS += -lqwt -ludev -lqextserialport
    QMAKE_POST_LINK = mkdir \
        "$$DESTDIR/translations" \
        & \
        cp \
        translations/*.qm \
        "$$DESTDIR/translations/"
}
macx {
    LIBS += -lqwt -lqextserialport1
    QMAKE_POST_LINK = mkdir \
        "$$DESTDIR/translations" \
        & \
        cp \
        translations/*.qm \
        "$$DESTDIR/translations/"
}

FORMS += \
    src/LorrisAnalyzer/sourcedialog.ui \
    src/LorrisAnalyzer/lorrisanalyzer.ui \
    src/LorrisAnalyzer/DataWidgets/rangeselectdialog.ui \
    src/LorrisAnalyzer/sourceselectdialog.ui \
    src/LorrisShupito/lorrisshupito.ui \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphcurveadddialog.ui \
    src/LorrisAnalyzer/DataWidgets/GraphWidget/graphcurveeditwidget.ui \
    src/LorrisTerminal/lorristerminal.ui \
    src/ui/hometab.ui \
    src/LorrisProxy/lorrisproxy.ui \
    src/ui/tabdialog.ui \
    src/LorrisAnalyzer/DataWidgets/ScriptWidget/scripteditor.ui \
    src/LorrisAnalyzer/playback.ui \
    src/LorrisShupito/reloaddialog.ui

RESOURCES += \
    src/LorrisAnalyzer/DataWidgetIcons.qrc \
    src/LorrisShupito/shupitoicons.qrc \
    src/icons.qrc

RC_FILE = src/winicon.rc
