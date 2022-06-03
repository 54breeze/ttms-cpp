cmake_minimum_required(VERSION 3.1)
project(ttms)

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME}-lib
        src/db/TTMSDb.hpp
        src/dto/DTO.hpp
        src/dto/MessageDto.hpp
        src/dto/UserDto.hpp
        src/dto/TheaterDto.hpp
        src/dto/StudioDto.hpp
        src/dto/SeatDto.hpp
        src/dto/PlayDto.hpp
        src/dto/ScheduleDto.hpp
        src/dto/TicketDto.hpp
        src/dto/LogDto.hpp
        src/service/BaseService/BaseUserServer.cpp
        src/service/BaseService/BaseUserServer.hpp
        src/service/BaseService/BaseTheaterServer.cpp
        src/service/BaseService/BaseTheaterServer.hpp
        src/service/BaseService/BaseStudioServer.cpp
        src/service/BaseService/BaseStudioServer.hpp
        src/service/BaseService/BaseSeatServer.cpp
        src/service/BaseService/BaseSeatServer.hpp
        src/service/BaseService/BasePlayServer.cpp
        src/service/BaseService/BasePlayServer.hpp
        src/service/BaseService/BaseScheduleServer.cpp
        src/service/BaseService/BaseScheduleServer.hpp
        src/service/BaseService/BaseTicketServer.cpp
        src/service/BaseService/BaseTicketServer.hpp
        src/service/BaseService/BaseLogServer.cpp
        src/service/BaseService/BaseLogServer.hpp
        src/service/ApiService/ApiUserServer.cpp
        src/service/ApiService/ApiUserServer.hpp
        src/service/ApiService/ApiTheaterServer.cpp
        src/service/ApiService/ApiTheaterServer.hpp
        src/service/ApiService/ApiStudioServer.cpp
        src/service/ApiService/ApiStudioServer.hpp
        src/service/ApiService/ApiSeatServer.cpp
        src/service/ApiService/ApiSeatServer.hpp
        src/service/ApiService/ApiPlayServer.cpp
        src/service/ApiService/ApiPlayServer.hpp
        src/service/ApiService/ApiScheduleServer.cpp
        src/service/ApiService/ApiScheduleServer.hpp
        src/service/ApiService/ApiTicketServer.cpp
        src/service/ApiService/ApiTicketServer.hpp
        src/service/ApiService/ApiLogServer.cpp
        src/service/ApiService/ApiLogServer.hpp
#        src/controller/TTMSController.hpp
        src/controller/UserController.hpp
        src/controller/TheaterController.hpp
        src/controller/StudioController.hpp
        src/controller/SeatController.hpp
        src/controller/PlayController.hpp
        src/controller/ScheduleController.hpp
        src/controller/TicketController.hpp
        src/controller/LogController.hpp
        )

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-sqlite 1.3.0 REQUIRED)
find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-sqlite
        PUBLIC SQLite::SQLite3
        )

add_definitions(
        ## SQLite database file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

target_include_directories(${PROJECT_NAME}-lib PUBLIC src)
## add executables

add_executable(${PROJECT_NAME}-exe src/App.cpp)

target_link_libraries(${PROJECT_NAME}-exe PRIVATE ${PROJECT_NAME}-lib)


