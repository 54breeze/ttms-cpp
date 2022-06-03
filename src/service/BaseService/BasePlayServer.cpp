//
// Created by breeze on 2022/5/20.
//

#include "BasePlayServer.hpp"

oatpp::Object<PlayDto> BasePlayServer::createPlay(const oatpp::Object<PlayDto> &dto) {
    auto dbResult = m_database->createPlay(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getPlayById((v_int32) id);
}

oatpp::Object<PlayDto> BasePlayServer::updatePlay(const oatpp::Object<PlayDto> &dto) {
    auto dbResult = m_database->updatePlay(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getPlayById(dto->playId);
}

oatpp::Object<PlayDto> BasePlayServer::getPlayById(const oatpp::Int32 &playId,
                                               const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getPlayById(playId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Play not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PlayDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<PlayDtoList> BasePlayServer::getAllPlays() {
    auto dbResult = m_database->getAllPlays();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<PlayDto>>>();
    auto list = PlayDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BasePlayServer::deletePlayById(const oatpp::Int32 &playId) {
    auto dbResult = m_database->deletePlayById(playId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "Play was successfully deleted";
    return status;
}