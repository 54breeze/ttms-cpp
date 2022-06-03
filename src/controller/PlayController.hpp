//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_PLAYCONTROLLER_HPP
#define TTMS_PLAYCONTROLLER_HPP

#include "service/ApiService/ApiPlayServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class PlayController : public oatpp::web::server::api::ApiController {
public:
    PlayController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiPlayServer m_server;
public:
    static std::shared_ptr<PlayController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<PlayController>(objectMapper);
    }
    ENDPOINT("POST", "v0/plays", createPlay, BODY_DTO(Object < PlayDto > , playDto)) {
        return createDtoResponse(Status::CODE_200, m_server.createPlay(playDto));
    }

    ENDPOINT("PUT", "v0/plays/{playId}", updatePlay, PATH(Int32, playId), BODY_DTO(Object < PlayDto > , playDto)) {
        playDto->playId = playId;
        return createDtoResponse(Status::CODE_200, m_server.updatePlay(playDto));
    }

    ENDPOINT("GET", "v0/plays/{playId}", getPlayById, PATH(Int32, playId)) {
        return createDtoResponse(Status::CODE_200, m_server.getPlayById(playId));
    }

    ENDPOINT("GET", "v0/plays", getAllPlays) {
        return createDtoResponse(Status::CODE_200, m_server.getAllPlays());
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_PLAYCONTROLLER_HPP
