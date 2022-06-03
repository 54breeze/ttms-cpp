//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APIUSERSERVER_HPP
#define TTMS_APIUSERSERVER_HPP

#include "service/BaseService/BaseUserServer.hpp"

class ApiUserServer {
private:
    BaseUserServer m_server;
public:
    //    创建新用户
    oatpp::Object<UserDto> createUser(const oatpp::Object<UserDto> &dto);

    //    更新用户信息
    oatpp::Object<UserDto> updateUser(const oatpp::Object<UserDto> &dto);

    //    通过用户id获取用户信息
    oatpp::Object<UserDto> getUserById(const oatpp::Int32 &userId);

    //    获取全部用户信息
    oatpp::Object<UserDtoList> getAllUsers();

private:
    static const oatpp::Object<UserDto> &userToOutput(const oatpp::Object<UserDto> &dto);
};


#endif //TTMS_APIUSERSERVER_HPP
