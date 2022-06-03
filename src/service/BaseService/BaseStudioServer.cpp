//
// Created by breeze on 2022/5/19.
//

#include "BaseStudioServer.hpp"

oatpp::Object<StudioDto> BaseStudioServer::createStudio(const oatpp::Object<StudioDto> &dto) {
    auto dbResult = m_database->createStudio(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getStudioById((v_int32) id);
}

oatpp::Object<StudioDto> BaseStudioServer::updateStudio(const oatpp::Object<StudioDto> &dto) {
    auto dbResult = m_database->updateStudio(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getStudioById(dto->studioId);
}

oatpp::Object<StudioDto> BaseStudioServer::getStudioById(const oatpp::Int32 &studioId,
                                                     const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getStudioById(studioId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Studio not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<StudioDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<StudioDtoList> BaseStudioServer::getAllStudios() {
    auto dbResult = m_database->getAllStudios();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<StudioDto>>>();
    auto list = StudioDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<StudioDtoList> BaseStudioServer::getStudiosByTheaterId(const oatpp::Int32 &theaterId) {
    auto dbResult = m_database->getStudiosByTheaterId(theaterId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<StudioDto>>>();
    auto list = StudioDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseStudioServer::deleteStudioById(const oatpp::Int32 &studioId) {
    auto dbResult = m_database->deleteStudioById(studioId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Studio was successfully deleted";
    return status;
}

oatpp::Object<MessageDto> BaseStudioServer::deleteStudiosByTheaterId(const oatpp::Int32 &theaterId) {
    auto dbResult = m_database->deleteStudiosByTheaterId(theaterId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Studios was successfully deleted";
    return status;
}