cmake_minimum_required(VERSION 3.22)
project(cppTask2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cppTask2
        Asset.cpp
        Asset.h
        Client.cpp
        Client.h
        cppTask2.cpp
        Date.cpp
        Date.h
        Milk.cpp
        Milk.h
        Product.cpp
        Product.h
        RetailClient.cpp
        RetailClient.h
        Seller.cpp
        Seller.h
        Shop.cpp
        Shop.h
        Towel.cpp
        Towel.h
        TradeOrganization.cpp
        TradeOrganization.h
        Warehouse.cpp
        Warehouse.h
        WholesaleClient.cpp
        WholesaleClient.h)
