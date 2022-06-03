//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_SCHEDULECONTROLLER_HPP
#define TTMS_SCHEDULECONTROLLER_HPP

#include "service/ApiService/ApiScheduleServer.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class ScheduleController : public oatpp::web::server::api::ApiController {
public:
    ScheduleController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    ApiScheduleServer m_server;
public:
    static std::shared_ptr<ScheduleController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<ScheduleController>(objectMapper);
    }
    ENDPOINT("POST", "v0/schedules", createSchedule, BODY_DTO(Object < ScheduleDto > , scheduleDto)) {
        return createDtoResponse(Status::CODE_200, m_server.createSchedule(scheduleDto));
    }

    ENDPOINT("GET", "v0/schedules/{scheduleId}", getScheduleById, PATH(Int32, scheduleId)) {
        return createDtoResponse(Status::CODE_200, m_server.getScheduleById(scheduleId));
    }

    ENDPOINT("GET", "v0/schedules", getSchedulesByTheaterId, QUERY(Int32, theaterId)) {
        return createDtoResponse(Status::CODE_200, m_server.getSchedulesByTheaterId(theaterId));
    }

    ENDPOINT("DELETE", "v0/schedules/{scheduleId}", deleteScheduleById, PATH(Int32, scheduleId)) {
        return createDtoResponse(Status::CODE_200, m_server.deleteScheduleById(scheduleId));
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //TTMS_SCHEDULECONTROLLER_HPP
