//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_SEATCONTROLLER_HPP
#define TTMS_SEATCONTROLLER_HPP

#include "service/ApiService/ApiSeatServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class SeatController : public oatpp::web::server::api::ApiController {
public:
    SeatController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiSeatServer m_server;
public:
    static std::shared_ptr<SeatController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<SeatController>(objectMapper);
    }
    ENDPOINT("POST", "v0/seats", createSeat, BODY_DTO(Object < SeatDto > , seatDto)) {
        return createDtoResponse(Status::CODE_200, m_server.createSeat(seatDto));
    }

    ENDPOINT("PUT", "v0/seats/{seatId}", updateSeat, PATH(Int32, seatId), BODY_DTO(Object < SeatDto > , seatDto)) {
        seatDto->seatId = seatId;
        return createDtoResponse(Status::CODE_200, m_server.updateSeat(seatDto));
    }

    ENDPOINT("GET", "v0/seats", getSeatsByStudioId, QUERY(Int32, studioId)) {
        return createDtoResponse(Status::CODE_200, m_server.getSeatsByStudioId(studioId));
    }

    ENDPOINT("DELETE", "v0/seats/{seatId}", deleteSeatById, PATH(Int32, seatId)) {
        return createDtoResponse(Status::CODE_200, m_server.deleteSeatById(seatId));
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_SEATCONTROLLER_HPP
