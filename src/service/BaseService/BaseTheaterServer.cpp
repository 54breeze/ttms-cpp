//
// Created by breeze on 2022/5/19.
//

#include "BaseTheaterServer.hpp"

oatpp::Object<TheaterDto> BaseTheaterServer::createTheater(const oatpp::Object<TheaterDto> &dto) {
    auto dbResult = m_database->createTheater(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getTheaterById((v_int32) id);
}

oatpp::Object<TheaterDto> BaseTheaterServer::updateTheater(const oatpp::Object<TheaterDto> &dto) {
    auto dbResult = m_database->updateTheater(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getTheaterById(dto->theaterId);
}

oatpp::Object<TheaterDto> BaseTheaterServer::getTheaterById(const oatpp::Int32 &theaterId,
                                                     const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getTheaterById(theaterId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Theater not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<TheaterDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<TheaterDtoList> BaseTheaterServer::getAllTheaters() {
    auto dbResult = m_database->getAllTheaters();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<TheaterDto>>>();
    auto list = TheaterDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseTheaterServer::deleteTheaterById(const oatpp::Int32 &theaterId) {
    auto dbResult = m_database->deleteTheaterById(theaterId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Theater was successfully deleted";
    return status;
}