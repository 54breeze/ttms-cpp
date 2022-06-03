//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APISCHEDULESERVER_HPP
#define TTMS_APISCHEDULESERVER_HPP

#include "service/BaseService/BaseScheduleServer.hpp"
#include "service/BaseService/BasePlayServer.hpp"
#include "service/BaseService/BaseSeatServer.hpp"
#include "service/BaseService/BaseTicketServer.hpp"

class ApiScheduleServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
    BaseScheduleServer m_server;
    BasePlayServer m_playServer;
    BaseSeatServer m_seatServer;
    BaseTicketServer m_ticketServer;
public:
    //    添加演出计划
    oatpp::Object<ScheduleDto> createSchedule(const oatpp::Object<ScheduleDto> &dto);

    //    通过id查询演出计划
    oatpp::Object<ScheduleDto> getScheduleById(const oatpp::Int32 &scheduleId);

    //    通过剧院id获取演出计划
    oatpp::Object<ScheduleDtoList> getSchedulesByTheaterId(const oatpp::Int32 &theaterId);

    //    删除演出计划
    oatpp::Object<MessageDto> deleteScheduleById(const oatpp::Int32 &scheduleId);

private:
    static int playToSec(const oatpp::Object<PlayDto> &dto);

    static const oatpp::Object<ScheduleDto> &scheduleToOutput(const oatpp::Object<ScheduleDto> &dto);

    static const oatpp::Object<ScheduleDto> &inputToSchedule(const oatpp::Object<ScheduleDto> &dto);
};


#endif //TTMS_APISCHEDULESERVER_HPP
