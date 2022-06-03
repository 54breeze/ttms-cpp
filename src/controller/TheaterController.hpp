//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_THEATERCONTROLLER_HPP
#define TTMS_THEATERCONTROLLER_HPP

#include "service/ApiService/ApiTheaterServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class TheaterController : public oatpp::web::server::api::ApiController {
public:
    TheaterController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiTheaterServer m_server;
public:
    static std::shared_ptr<TheaterController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<TheaterController>(objectMapper);
    }
    ENDPOINT("POST", "v0/theaters", createTheater, BODY_DTO(Object < TheaterDto > , theaterDto)) {
        return createDtoResponse(Status::CODE_200, m_server.createTheater(theaterDto));
    }

    ENDPOINT("PUT", "v0/theaters/{theaterId}", updateTheater, PATH(Int32, theaterId),
             BODY_DTO(Object < TheaterDto > , theaterDto)) {
        theaterDto->theaterId = theaterId;
        return createDtoResponse(Status::CODE_200, m_server.updateTheater(theaterDto));
    }

    ENDPOINT("GET", "v0/theaters/{theaterId}", getTheaterById, PATH(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_server.getTheaterById(theaterId));
    }

    ENDPOINT("GET", "v0/theaters", getAllTheaters) {
        return createDtoResponse(Status::CODE_200, m_server.getAllTheaters());
    }

    ENDPOINT("DELETE", "v0/theaters/{theaterId}", deleteTheater, PATH(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_server.deleteTheaterById(theaterId));
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_THEATERCONTROLLER_HPP
