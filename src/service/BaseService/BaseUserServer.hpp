//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_BASEUSERSERVER_HPP
#define TTMS_BASEUSERSERVER_HPP

#include "dto/UserDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseUserServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    创建新用户
    oatpp::Object<UserDto> createUser(const oatpp::Object<UserDto> &dto);

    //    更新用户信息
    oatpp::Object<UserDto> updateUser(const oatpp::Object<UserDto> &dto);

    //    通过用户id获取用户信息
    oatpp::Object<UserDto> getUserById(const oatpp::Int32 &userId,
                                       const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部用户信息
    oatpp::Object<UserDtoList> getAllUsers();

    //    删除用户
    oatpp::Object<MessageDto> deleteUserById(const oatpp::Int32 &userId);
};


#endif //TTMS_BASEUSERSERVER_HPP
