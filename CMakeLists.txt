cmake_minimum_required(VERSION 3.5)

project(bentomark VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        views/mainview/mainwindow.cpp
        views/mainview/mainwindow.h
        views/mainview/mainwindow.ui
        views/entryview/entryview.h
        views/entryview/entryview.cpp
        views/entryview/entryview.ui
        views/newton-raphson/newtonraphsonview.h
        views/newton-raphson/newtonraphsonview.cpp
        views/newton-raphson/newtonraphsonview.ui
        views/modified-newton/modifiednewtonview.h
        views/modified-newton/modifiednewtonview.cpp
        views/modified-newton/modifiednewtonview.ui
        views/secant/secantview.h
        views/secant/secantview.cpp
        views/secant/secantview.ui
        views/clash/clashview.h
        views/clash/clashview.cpp
        views/clash/clashview.ui
        views/clash/bentomarkwidget.h
        views/clash/bentomarkwidget.cpp
        views/clash/bentomarkwidget.ui
        views/shared/sharedmethodpagewidget.h
        views/shared/sharedmethodpagewidget.cpp 
        views/shared/sharedmethodpagewidget.ui
        controllers/Function.cpp
        controllers/Function.h
        controllers/Model.cpp
        controllers/Model.h
        controllers/ModelResult.cpp
        controllers/ModelResult.h
        controllers/Secant.cpp
        controllers/Secant.h
        controllers/Newton.cpp
        controllers/Newton.h
        controllers/NewtonModified.h
        controllers/NewtonModified.cpp
        resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(bentomark
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET bentomark APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(bentomark SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(bentomark
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(bentomark PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.bentomark)
endif()
set_target_properties(bentomark PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS bentomark
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(bentomark)
endif()
