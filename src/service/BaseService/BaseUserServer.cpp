//
// Created by breeze on 2022/5/19.
//

#include "BaseUserServer.hpp"

oatpp::Object<UserDto> BaseUserServer::createUser(const oatpp::Object<UserDto> &dto) {
    auto dbResult = m_database->createUser(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage())
    auto id = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getUserById((v_int32) id);
}

oatpp::Object<UserDto> BaseUserServer::updateUser(const oatpp::Object<UserDto> &dto) {
    auto dbResult = m_database->updateUser(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return getUserById(dto->userId);
}

oatpp::Object<UserDto> BaseUserServer::getUserById(const oatpp::Int32 &userId,
                                               const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection) {
    auto dbResult = m_database->getUserById(userId, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");
    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];
}

oatpp::Object<UserDtoList> BaseUserServer::getAllUsers() {
    auto dbResult = m_database->getAllUsers();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDto>>>();
    auto list = UserDtoList::createShared();
    list->items = items;
    return list;
}

oatpp::Object<MessageDto> BaseUserServer::deleteUserById(const oatpp::Int32 &userId) {
    auto dbResult = m_database->deleteUserById(userId);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    auto status = MessageDto::createShared();
    status->status = "OK";
    status->code = 200;
    status->message = "User was successfully deleted";
    return status;
}