//
// Created by breeze on 2022/5/20.
//

#include "ApiScheduleServer.hpp"

oatpp::Object<ScheduleDto> ApiScheduleServer::createSchedule(const oatpp::Object<ScheduleDto> &dto) {
    inputToSchedule(dto);
    auto play = m_playServer.getPlayById(dto->playId);
    dto->endTime = dto->startTime + playToSec(play);
    //检测当前时段是否有演出计划
    auto schedules = m_server.getSchedulesByStudioId(dto->studioId);
    for (auto &item : *schedules->items) {
        if (dto->endTime < item->startTime || dto->startTime > item->endTime)
            continue;
        else OATPP_ASSERT_HTTP(0, Status::CODE_500, "There are performances planned for the current period");
    }
    //生成演出票
    auto temp = m_server.createSchedule(dto);
    auto seats = m_seatServer.getSeatsByStudioId(dto->studioId);
    for (auto &item : *seats->items) {
        if (item->seatStatus == oatpp::Int32(1))
            continue;//检查座位是否损坏
        auto ticketDto = TicketDto::createShared();
        ticketDto->scheduleId = temp->scheduleId;
        ticketDto->studioId = temp->studioId;
        ticketDto->playId = temp->playId;
        ticketDto->playName = play->playName;
        ticketDto->startTime = temp->startTime;
        ticketDto->endTime = temp->endTime;
        ticketDto->seatId = item->seatId;
        ticketDto->seatX = item->seatX;
        ticketDto->seatY = item->seatY;
        ticketDto->price = temp->price;
        m_ticketServer.createTicket(ticketDto);
    }
    return scheduleToOutput(temp);
}

oatpp::Object<ScheduleDto> ApiScheduleServer::getScheduleById(const oatpp::Int32 &scheduleId) {
    return scheduleToOutput(m_server.getScheduleById(scheduleId));
}

oatpp::Object<ScheduleDtoList> ApiScheduleServer::getSchedulesByTheaterId(const oatpp::Int32 &theaterId) {
    auto temp = m_server.getSchedulesByTheaterId(theaterId);
    for (auto & item : *temp->items) {
        scheduleToOutput(item);
    }
    return temp;
}

oatpp::Object<MessageDto> ApiScheduleServer::deleteScheduleById(const oatpp::Int32 &scheduleId) {
    m_ticketServer.deleteTicketsByScheduleId(scheduleId);
    return m_server.deleteScheduleById(scheduleId);
}

int ApiScheduleServer::playToSec(const oatpp::Object<PlayDto> &dto) {
    return dto->playHour * 3600 + dto->playMin * 60 + dto->playSec;
}

const oatpp::Object<ScheduleDto> &ApiScheduleServer::scheduleToOutput(const oatpp::Object<ScheduleDto> &dto) {
    time_t temp = dto->startTime;
    struct tm *pt = localtime(&temp);
    dto->start_year = pt->tm_year + 1900;
    dto->start_mon = pt->tm_mon + 1;
    dto->start_mday = pt->tm_mday;
    dto->start_hour = pt->tm_hour;
    dto->start_min = pt->tm_min;
    dto->start_sec = pt->tm_sec;

    time_t temp1 = dto->endTime;
    struct tm *pt1 = localtime(&temp1);
    dto->end_year = pt1->tm_year + 1900;
    dto->end_mon = pt1->tm_mon + 1;
    dto->end_mday = pt1->tm_mday;
    dto->end_hour = pt1->tm_hour;
    dto->end_min = pt1->tm_min;
    dto->end_sec = pt1->tm_sec;
    return dto;
}

const oatpp::Object<ScheduleDto> &ApiScheduleServer::inputToSchedule(const oatpp::Object<ScheduleDto> &dto) {
    struct tm pt{};
    pt.tm_year = dto->start_year - 1900;
    pt.tm_mon = dto->start_mon - 1;
    pt.tm_mday = dto->start_mday;
    pt.tm_hour = dto->start_hour;
    pt.tm_min = dto->start_min;
    pt.tm_sec = dto->start_sec;
    pt.tm_isdst = 0;
    pt.tm_zone = "CST";
    time_t temp = mktime(&pt);
    dto->startTime = temp;
    return dto;
}