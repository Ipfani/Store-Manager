cmake_minimum_required(VERSION 3.5)

project(Store VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Added for network
find_package(Qt6 REQUIRED COMPONENTS Network)
#XML
find_package(Qt6 REQUIRED COMPONENTS Xml)

set(PROJECT_SOURCES
        main.cpp
        store.cpp
        store.h
        stock.cpp stock.h
        magazine.cpp magazine.h
        books.cpp books.h
        stockfactory.cpp stockfactory.h
        stocklist.cpp stocklist.h
        customers.cpp customers.h
        customerlist.cpp customerlist.h
        additem.cpp additem.h
        addcustomers.cpp addcustomers.h         #Customer widget
        addtransaction.cpp addtransaction.h     #Transaction widget
        transaction.cpp transaction.h           #Transaction Class
        xmlwritter.cpp xmlwritter.h             #Write to xml before Broadcast
        about.cpp about.h                       #My about widget
        broadcastthread.cpp broadcastthread.h   #for my thread

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Store
        resource.qrc #I am here
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Store APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Store SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Store
            ${PROJECT_SOURCES}  
        )
    endif()
endif()

target_link_libraries(Store PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Added for network
target_link_libraries(Store PRIVATE Qt6::Network)
#XML
target_link_libraries(Store PRIVATE Qt6::Xml)

set_target_properties(Store PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Store
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Store)
endif()
