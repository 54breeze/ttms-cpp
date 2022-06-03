//
// Created by breeze on 2022/5/20.
//

#include "BaseScheduleServer.hpp"

oatpp::Object<ScheduleDto> BaseScheduleServer::createSchedule(const oatpp::Object<ScheduleDto> &dto) {
    auto dbResult = m_database->createSchedule(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getScheduleById((v_int32) id);
}

oatpp::Object<ScheduleDto> BaseScheduleServer::updateSchedule(const oatpp::Object<ScheduleDto> &dto) {
    auto dbResult = m_database->updateSchedule(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getScheduleById(dto->scheduleId);
}

oatpp::Object<ScheduleDto> BaseScheduleServer::getScheduleById(const oatpp::Int32 &scheduleId,
                                                   const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getScheduleById(scheduleId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Schedule not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<ScheduleDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<ScheduleDtoList> BaseScheduleServer::getAllSchedules() {
    auto dbResult = m_database->getAllSchedules();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ScheduleDto>>>();
    auto list = ScheduleDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<ScheduleDtoList> BaseScheduleServer::getSchedulesByTheaterId(const oatpp::Int32 &theaterId) {
    auto dbResult = m_database->getSchedulesByTheaterId(theaterId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ScheduleDto>>>();
    auto list = ScheduleDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<ScheduleDtoList> BaseScheduleServer::getSchedulesByStudioId(const oatpp::Int32 &studioId) {
    auto dbResult = m_database->getSchedulesByStudioId(studioId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<ScheduleDto>>>();
    auto list = ScheduleDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseScheduleServer::deleteScheduleById(const oatpp::Int32 &scheduleId) {
    auto dbResult = m_database->deleteScheduleById(scheduleId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Schedule was successfully deleted";
    return status;
}