//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_TTMSCONTROLLER_HPP
#define TTMS_TTMSCONTROLLER_HPP

#include "service/ApiService/ApiUserServer.hpp"
#include "service/ApiService/ApiTheaterServer.hpp"
#include "service/ApiService/ApiStudioServer.hpp"
#include "service/ApiService/ApiSeatServer.hpp"
#include "service/ApiService/ApiPlayServer.hpp"
#include "service/ApiService/ApiScheduleServer.hpp"
#include "service/ApiService/ApiTicketServer.hpp"
#include "service/ApiService/ApiLogServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class TTMSController : public oatpp::web::server::api::ApiController {
public:
    TTMSController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiUserServer m_userServer;
    ApiTheaterServer m_theaterServer;
    ApiStudioServer m_studioServer;
    ApiSeatServer m_seatServer;
    ApiPlayServer m_playServer;
    ApiScheduleServer m_scheduleServer;
    ApiTicketServer m_ticketServer;
    ApiLogServer m_logServer;
public:
    static std::shared_ptr<TTMSController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<TTMSController>(objectMapper);
    }

    ENDPOINT("POST", "v0/users", createUser, BODY_DTO(Object < UserDto > , usersDto)) {
        return createDtoResponse(Status::CODE_200, m_userServer.createUser(usersDto));
    }

    ENDPOINT("PUT", "v0/users/{userId}", updateUser, PATH(Int32, userId), BODY_DTO(Object < UserDto > , userDto)) {
        userDto->userId = userId;
        return createDtoResponse(Status::CODE_200, m_userServer.updateUser(userDto));
    }

    ENDPOINT("GET", "v0/users/{userId}", getUserById, PATH(Int32, userId)) {
        return createDtoResponse(Status::CODE_200, m_userServer.getUserById(userId));
    }

    ENDPOINT("GET", "v0/users", getAllUsers) {
        return createDtoResponse(Status::CODE_200, m_userServer.getAllUsers());
    }

    ENDPOINT("POST", "v0/theaters", createTheater, BODY_DTO(Object < TheaterDto > , theaterDto)) {
        return createDtoResponse(Status::CODE_200, m_theaterServer.createTheater(theaterDto));
    }

    ENDPOINT("PUT", "v0/theaters/{theaterId}", updateTheater, PATH(Int32, theaterId),
             BODY_DTO(Object < TheaterDto > , theaterDto)) {
        theaterDto->theaterId = theaterId;
        return createDtoResponse(Status::CODE_200, m_theaterServer.updateTheater(theaterDto));
    }

    ENDPOINT("GET", "v0/theaters/{theaterId}", getTheaterById, PATH(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_theaterServer.getTheaterById(theaterId));
    }

    ENDPOINT("GET", "v0/theaters", getAllTheaters) {
        return createDtoResponse(Status::CODE_200, m_theaterServer.getAllTheaters());
    }

    ENDPOINT("DELETE", "v0/theaters/{theaterId}", deleteTheater, PATH(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_theaterServer.deleteTheaterById(theaterId));
    }

    ENDPOINT("POST", "v0/studios", createStudio, BODY_DTO(Object < StudioDto > , studioDto)) {
        return createDtoResponse(Status::CODE_200, m_studioServer.createStudio(studioDto));
    }

    ENDPOINT("PUT", "v0/studios/{studioId}", updateStudio, PATH(Int32, studioId),
             BODY_DTO(Object < StudioDto > , studioDto)) {
        studioDto->studioId = studioId;
        return createDtoResponse(Status::CODE_200, m_studioServer.updateStudio(studioDto));
    }

    ENDPOINT("GET", "v0/studios/{studioId}", getStudioById, PATH(Int32, studioId)) {
        return createDtoResponse(Status::CODE_200, m_studioServer.getStudioById(studioId));
    }

    ENDPOINT("GET", "v0/studios", getStudiosByTheaterId, QUERY(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_studioServer.getStudiosByTheaterId(theaterId));
    }

    ENDPOINT("DELETE", "v0/studios/{studioId}", deleteStudioById, PATH(Int32, studioId)) {
        return createDtoResponse(Status::CODE_200, m_studioServer.deleteStudioById(studioId));
    }

    ENDPOINT("POST", "v0/seats", createSeat, BODY_DTO(Object < SeatDto > , seatDto)) {
        return createDtoResponse(Status::CODE_200, m_seatServer.createSeat(seatDto));
    }

    ENDPOINT("PUT", "v0/seats/{seatId}", updateSeat, PATH(Int32, seatId), BODY_DTO(Object < SeatDto > , seatDto)) {
        seatDto->seatId = seatId;
        return createDtoResponse(Status::CODE_200, m_seatServer.updateSeat(seatDto));
    }

    ENDPOINT("GET", "v0/seats", getSeatsByStudioId, QUERY(Int32, studioId)) {
        return createDtoResponse(Status::CODE_200, m_seatServer.getSeatsByStudioId(studioId));
    }

    ENDPOINT("DELETE", "v0/seats/{seatId}", deleteSeatById, PATH(Int32, seatId)) {
        return createDtoResponse(Status::CODE_200, m_seatServer.deleteSeatById(seatId));
    }

    ENDPOINT("POST", "v0/plays", createPlay, BODY_DTO(Object < PlayDto > , playDto)) {
        return createDtoResponse(Status::CODE_200, m_playServer.createPlay(playDto));
    }

    ENDPOINT("PUT", "v0/plays/{playId}", updatePlay, PATH(Int32, playId), BODY_DTO(Object < PlayDto > , playDto)) {
        playDto->playId = playId;
        return createDtoResponse(Status::CODE_200, m_playServer.updatePlay(playDto));
    }

    ENDPOINT("GET", "v0/plays/{playId}", getPlayById, PATH(Int32, playId)) {
        return createDtoResponse(Status::CODE_200, m_playServer.getPlayById(playId));
    }

    ENDPOINT("GET", "v0/plays", getAllPlays) {
        return createDtoResponse(Status::CODE_200, m_playServer.getAllPlays());
    }

    ENDPOINT("POST", "v0/schedules", createSchedule, BODY_DTO(Object < ScheduleDto > , scheduleDto)) {
        return createDtoResponse(Status::CODE_200, m_scheduleServer.createSchedule(scheduleDto));
    }

    ENDPOINT("GET", "v0/schedules/{scheduleId}", getScheduleById, PATH(Int32, scheduleId)) {
        return createDtoResponse(Status::CODE_200, m_scheduleServer.getScheduleById(scheduleId));
    }

    ENDPOINT("GET", "v0/schedules", getSchedulesByTheaterId, QUERY(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_scheduleServer.getSchedulesByTheaterId(theaterId));
    }

    ENDPOINT("DELETE", "v0/schedules/{scheduleId}", deleteScheduleById, PATH(Int32, scheduleId)) {
        return createDtoResponse(Status::CODE_200, m_scheduleServer.deleteScheduleById(scheduleId));
    }

    ENDPOINT("PUT", "v0/tickets/{ticketId}", updateTicket, PATH(Int32, ticketId),
             BODY_DTO(Object < TicketDto > , ticketDto)) {
        ticketDto->ticketId = ticketId;
        return createDtoResponse(Status::CODE_200, m_ticketServer.updateTicket(ticketDto));
    }

    ENDPOINT("GET", "v0/tickets/{ticketId}", getTicketById, PATH(Int32, ticketId)) {
        return createDtoResponse(Status::CODE_200, m_ticketServer.getTicketById(ticketId));
    }

    ENDPOINT("GET", "v0/tickets", getTicketsByOtherId, QUERY(Int32, studioId), QUERY(Int32, userId),
             QUERY(Int32, playId)) {
        if (studioId != 0 && userId == 0 && playId == 0)
            return createDtoResponse(Status::CODE_200, m_ticketServer.getTicketsByStudioId(studioId));
        else if (userId != 0 && studioId == 0 && playId == 0)
            return createDtoResponse(Status::CODE_200, m_ticketServer.getTicketsByUserId(userId));
        else if (playId != 0 && userId == 0 && studioId == 0)
            return createDtoResponse(Status::CODE_200, m_ticketServer.getTicketsByPlayId(playId));
        else
            return createResponse(Status::CODE_500, "Only one of userId studioId and playId can be true");
    }

    ENDPOINT("DELETE", "v0/tickets/{ticketId}", deleteTicketById, PATH(Int32, ticketId)) {
        return createDtoResponse(Status::CODE_200, m_ticketServer.deleteTicketById(ticketId));
    }

    ENDPOINT("GET", "v0/logs/{logId}", getLogById, PATH(Int32, logId)) {
        return createDtoResponse(Status::CODE_200, m_logServer.getLogById(logId));
    }

    ENDPOINT("GET", "v0/logs", getLogs, QUERY(Int32, playId), QUERY(Int32, userId)) {
        if (userId != 0 && playId == 0)
            return createDtoResponse(Status::CODE_200, m_logServer.getLogsByUserId(userId));
        else if (playId != 0 && userId == 0)
            return createDtoResponse(Status::CODE_200, m_logServer.getLogsByPlayId(playId));
        else if (playId == 0 && userId == 0)
            return createDtoResponse(Status::CODE_200, m_logServer.getAllLogs());
        else
            return createResponse(Status::CODE_500, "userid and playId cannot be true at the same time");
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_TTMSCONTROLLER_HPP
