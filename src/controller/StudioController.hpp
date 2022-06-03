//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_STUDIOCONTROLLER_HPP
#define TTMS_STUDIOCONTROLLER_HPP

#include "service/ApiService/ApiStudioServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class StudioController : public oatpp::web::server::api::ApiController {
public:
    StudioController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiStudioServer m_server;
public:
    static std::shared_ptr<StudioController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<StudioController>(objectMapper);
    }

    ENDPOINT("POST", "v0/studios", createStudio, BODY_DTO(Object < StudioDto > , studioDto)) {
        return createDtoResponse(Status::CODE_200, m_server.createStudio(studioDto));
    }

    ENDPOINT("PUT", "v0/studios/{studioId}", updateStudio, PATH(Int32, studioId),
             BODY_DTO(Object < StudioDto > , studioDto)) {
        studioDto->studioId = studioId;
        return createDtoResponse(Status::CODE_200, m_server.updateStudio(studioDto));
    }

    ENDPOINT("GET", "v0/studios/{studioId}", getStudioById, PATH(Int32, studioId)) {
        return createDtoResponse(Status::CODE_200, m_server.getStudioById(studioId));
    }

    ENDPOINT("GET", "v0/studios", getStudiosByTheaterId, QUERY(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_server.getStudiosByTheaterId(theaterId));
    }

    ENDPOINT("DELETE", "v0/studios/{studioId}", deleteStudioById, PATH(Int32, studioId)) {
        return createDtoResponse(Status::CODE_200, m_server.deleteStudioById(studioId));
    }

};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_STUDIOCONTROLLER_HPP
