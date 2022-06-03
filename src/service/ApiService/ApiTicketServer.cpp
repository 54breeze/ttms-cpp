//
// Created by breeze on 2022/5/20.
//

#include "ApiTicketServer.hpp"

oatpp::Object<TicketDto> ApiTicketServer::updateTicket(const oatpp::Object<TicketDto> &dto) {
    auto ticket = m_server.getTicketById(dto->ticketId);
    auto user = m_userServer.getUserById(dto->userId);
    dto->userName = user->userName;
    if (ticket->ticketStatus == 1) {//判断票是否已卖出
        if (dto->ticketStatus == 0) {
            ticket->userId = dto->userId;
            ticket->userName = dto->userName;
            ticket->ticketStatus = dto->ticketStatus;
            auto log = oatpp::Object<LogDto>::createShared();
            log->ticketId = ticket->ticketId;
            log->scheduleId = ticket->scheduleId;
            log->price = ticket->price;
            log->playName = ticket->playName;
            log->userId = ticket->userId;
            log->playId = ticket->playId;
            m_logServer.createLog(log);
        }
        return ticketToOutput(m_server.updateTicket(ticket));
    } else if (ticket->ticketStatus == 0 && ticket->userId == dto->userId) {
        if (dto->ticketStatus == 1) {
            ticket->ticketStatus = dto->ticketStatus;
            auto log = oatpp::Object<LogDto>::createShared();
            log->ticketId = ticket->ticketId;
            log->scheduleId = ticket->scheduleId;
            log->price = -ticket->price;
            log->playName = ticket->playName;
            log->userId = ticket->userId;
            log->playId = ticket->playId;
            m_logServer.createLog(log);
        }
        return ticketToOutput(m_server.updateTicket(ticket));
    } else OATPP_ASSERT_HTTP(0, Status::CODE_500, "This ticket has already been sold")
}

oatpp::Object<TicketDto> ApiTicketServer::getTicketById(const oatpp::Int32 &ticketId) {
    return ticketToOutput(m_server.getTicketById(ticketId));
}

oatpp::Object<TicketDtoList> ApiTicketServer::getTicketsByStudioId(const oatpp::Int32 &studioId) {
    auto temp = m_server.getTicketsByStudioId(studioId);
    for (auto & item : *temp->items) {
        ticketToOutput(item);
    }
    return temp;
}

oatpp::Object<TicketDtoList> ApiTicketServer::getTicketsByUserId(const oatpp::Int32 &userId) {
    auto temp = m_server.getTicketsByUserId(userId);
    for (auto & item : *temp->items) {
        ticketToOutput(item);
    }
    return temp;
}

oatpp::Object<TicketDtoList> ApiTicketServer::getTicketsByPlayId(const oatpp::Int32 &playId) {
    auto temp = m_server.getTicketsByPlayId(playId);
    for (auto & item : *temp->items) {
        ticketToOutput(item);
    }
    return temp;
}

oatpp::Object<MessageDto> ApiTicketServer::deleteTicketById(const oatpp::Int32 &ticketId) {
    return m_server.deleteTicketById(ticketId);
}

const oatpp::Object<TicketDto> &ApiTicketServer::ticketToOutput(const oatpp::Object<TicketDto> &dto) {
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