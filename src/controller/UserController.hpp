//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_USERCONTROLLER_HPP
#define TTMS_USERCONTROLLER_HPP

#include "service/ApiService/ApiUserServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class UserController : public oatpp::web::server::api::ApiController {
public:
    UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiUserServer m_server;
public:
    static std::shared_ptr<UserController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<UserController>(objectMapper);
    }

    ENDPOINT("POST", "v0/users", createUser, BODY_DTO(Object < UserDto > , usersDto)) {
        return createDtoResponse(Status::CODE_200, m_server.createUser(usersDto));
    }

    ENDPOINT("PUT", "v0/users/{userId}", updateUser, PATH(Int32, userId), BODY_DTO(Object < UserDto > , userDto)) {
        userDto->userId = userId;
        return createDtoResponse(Status::CODE_200, m_server.updateUser(userDto));
    }

    ENDPOINT("GET", "v0/users/{userId}", getUserById, PATH(Int32, userId)) {
        return createDtoResponse(Status::CODE_200, m_server.getUserById(userId));
    }

    ENDPOINT("GET", "v0/users", getAllUsers) {
        return createDtoResponse(Status::CODE_200, m_server.getAllUsers());
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_USERCONTROLLER_HPP
