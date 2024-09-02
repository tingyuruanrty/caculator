cmake_minimum_required(VERSION 3.16)

project(caculator VERSION 0.2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(caculator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        caculator.h caculator.cpp
    )

# Define target properties for Android with Qt 6 as:
#    set_property(TARGET caculator APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(caculator SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(caculator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(caculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.caculator)
endif()
set_target_properties(caculator PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS caculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(caculator)
endif()





include(CPack)

set(CPACK_PACKAGE_NAME "Calculator")
set(CPACK_PACKAGE_VERSION "0.2")
set(CPACK_PACKAGE_CONTACT "tingyuruanrty@gmail.com")

# Optionally set more information about the package
# set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A simple calculator application")
# set(CPACK_PACKAGE_VENDOR "Your Name")
# set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

# Specify the installation directory for the package
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Calculator ${CPACK_PACKAGE_VERSION}")

# Define the package generators (e.g., ZIP, TGZ, NSIS, etc.)
set(CPACK_GENERATOR "ZIP;TGZ;NSIS")  # Adjust as needed

# If you're targeting Windows, add NSIS configuration (optional)
if(WIN32)
    set(CPACK_NSIS_DISPLAY_NAME "Calculator Installer")
    set(CPACK_NSIS_HELP_LINK "http://www.example.com")
    set(CPACK_NSIS_URL_INFO_ABOUT "http://www.example.com/about")
    set(CPACK_NSIS_CONTACT "youremail@example.com")
    set(CPACK_NSIS_MODIFY_PATH ON)  # Add the installation directory to the PATH environment variable
endif()

# Optionally, add macOS-specific settings (optional)
if(APPLE)
    set(CPACK_BUNDLE_NAME "Calculator")
    set(CPACK_BUNDLE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/Resources/Icon.icns")
    set(CPACK_BUNDLE_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist")
    set(CPACK_DMG_VOLUME_NAME "Calculator Installer")
    set(CPACK_DMG_BACKGROUND_IMAGE "${CMAKE_CURRENT_SOURCE_DIR}/Resources/background.png")
endif()

# Optionally, add Linux-specific settings (optional)
if(UNIX AND NOT APPLE)
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "qt5-default, libqt5widgets5")
endif()
