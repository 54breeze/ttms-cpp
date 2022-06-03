//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_LOGCONTROLLER_HPP
#define TTMS_LOGCONTROLLER_HPP

#include "service/ApiService/ApiLogServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class LogController : public oatpp::web::server::api::ApiController {
public:
    LogController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiLogServer m_server;
public:
    static std::shared_ptr<LogController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<LogController>(objectMapper);
    }
    ENDPOINT("GET", "v0/logs/{logId}", getLogById, PATH(Int32, logId)) {
        return createDtoResponse(Status::CODE_200, m_server.getLogById(logId));
    }

    ENDPOINT("GET", "v0/logs", getLogs, QUERY(Int32, playId), QUERY(Int32, userId)) {
        if (userId != 0 && playId == 0)
            return createDtoResponse(Status::CODE_200, m_server.getLogsByUserId(userId));
        else if (playId != 0 && userId == 0)
            return createDtoResponse(Status::CODE_200, m_server.getLogsByPlayId(playId));
        else if (playId == 0 && userId == 0)
            return createDtoResponse(Status::CODE_200, m_server.getAllLogs());
        else
            return createResponse(Status::CODE_500, "userid and playId cannot be true at the same time");
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_LOGCONTROLLER_HPP
