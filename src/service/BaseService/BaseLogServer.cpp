//
// Created by breeze on 2022/5/20.
//

#include "BaseLogServer.hpp"

oatpp::Object<LogDto> BaseLogServer::createLog(const oatpp::Object<LogDto> &dto) {
    auto dbResult = m_database->createLog(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getLogById((v_int32) id);
}

oatpp::Object<LogDto> BaseLogServer::updateLog(const oatpp::Object<LogDto> &dto) {
    auto dbResult = m_database->updateLog(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getLogById(dto->logId);
}

oatpp::Object<LogDto> BaseLogServer::getLogById(const oatpp::Int32 &logId,
                                             const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getLogById(logId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Log not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<LogDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<LogDtoList> BaseLogServer::getAllLogs() {
    auto dbResult = m_database->getAllLogs();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<LogDto>>>();
    auto list = LogDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<LogDtoList> BaseLogServer::getLogsByPlayId(const oatpp::Int32 &playId) {
    auto dbResult = m_database->getLogsByPlayId(playId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<LogDto>>>();
    auto list = LogDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<LogDtoList> BaseLogServer::getLogsByUserId(const oatpp::Int32 &userId) {
    auto dbResult = m_database->getLogsByUserId(userId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<LogDto>>>();
    auto list = LogDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseLogServer::deleteLogById(const oatpp::Int32 &logId) {
    auto dbResult = m_database->deleteLogById(logId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Log was successfully deleted";
    return status;
}