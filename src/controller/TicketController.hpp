//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_TICKETCONTROLLER_HPP
#define TTMS_TICKETCONTROLLER_HPP

#include "service/ApiService/ApiTicketServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class TicketController : public oatpp::web::server::api::ApiController {
public:
    TicketController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiTicketServer m_server;
public:
    static std::shared_ptr<TicketController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<TicketController>(objectMapper);
    }
    ENDPOINT("PUT", "v0/tickets/{ticketId}", updateTicket, PATH(Int32, ticketId),
             BODY_DTO(Object < TicketDto > , ticketDto)) {
        ticketDto->ticketId = ticketId;
        return createDtoResponse(Status::CODE_200, m_server.updateTicket(ticketDto));
    }

    ENDPOINT("GET", "v0/tickets/{ticketId}", getTicketById, PATH(Int32, ticketId)) {
        return createDtoResponse(Status::CODE_200, m_server.getTicketById(ticketId));
    }

    ENDPOINT("GET", "v0/tickets", getTicketsByOtherId, QUERY(Int32, studioId), QUERY(Int32, userId),
             QUERY(Int32, playId)) {
        if (studioId != 0 && userId == 0 && playId == 0)
            return createDtoResponse(Status::CODE_200, m_server.getTicketsByStudioId(studioId));
        else if (userId != 0 && studioId == 0 && playId == 0)
            return createDtoResponse(Status::CODE_200, m_server.getTicketsByUserId(userId));
        else if (playId != 0 && userId == 0 && studioId == 0)
            return createDtoResponse(Status::CODE_200, m_server.getTicketsByPlayId(playId));
        else
            return createResponse(Status::CODE_500, "Only one of userId studioId and playId can be true");
    }

    ENDPOINT("DELETE", "v0/tickets/{ticketId}", deleteTicketById, PATH(Int32, ticketId)) {
        return createDtoResponse(Status::CODE_200, m_server.deleteTicketById(ticketId));
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_TICKETCONTROLLER_HPP
