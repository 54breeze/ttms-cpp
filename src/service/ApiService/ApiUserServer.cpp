//
// Created by breeze on 2022/5/20.
//

#include "ApiUserServer.hpp"

oatpp::Object<UserDto> ApiUserServer::createUser(const oatpp::Object<UserDto> &dto) {
    dto->createTime = std::time(nullptr);
    dto->updateTime = std::time(nullptr);
    return userToOutput(m_server.createUser(dto));
}

oatpp::Object<UserDto> ApiUserServer::updateUser(const oatpp::Object<UserDto> &dto) {
    dto->updateTime = std::time(nullptr);
    return userToOutput(m_server.updateUser(dto));
}

oatpp::Object<UserDto> ApiUserServer::getUserById(const oatpp::Int32 &userId) {
    return userToOutput(m_server.getUserById(userId));
}

oatpp::Object<UserDtoList> ApiUserServer::getAllUsers() {
    auto temp = m_server.getAllUsers();
    for (auto &item : *temp->items)
        userToOutput(item);
    return temp;
}

const oatpp::Object<UserDto> &ApiUserServer::userToOutput(const oatpp::Object<UserDto> &dto) {
    time_t temp = dto->createTime;
    struct tm *pt = localtime(&temp);
    dto->create_year = pt->tm_year + 1900;
    dto->create_mon = pt->tm_mon + 1;
    dto->create_mday = pt->tm_mday;
    dto->create_hour = pt->tm_hour;
    dto->create_min = pt->tm_min;
    dto->create_sec = pt->tm_sec;

    time_t temp1 = dto->updateTime;
    struct tm *pt1 = localtime(&temp1);
    dto->update_year = pt1->tm_year + 1900;
    dto->update_mon = pt1->tm_mon + 1;
    dto->update_mday = pt1->tm_mday;
    dto->update_hour = pt1->tm_hour;
    dto->update_min = pt1->tm_min;
    dto->update_sec = pt1->tm_sec;
    return dto;
}