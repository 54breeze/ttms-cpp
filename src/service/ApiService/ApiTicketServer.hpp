//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_APITICKETSERVER_HPP
#define TTMS_APITICKETSERVER_HPP

#include "service/BaseService/BaseTicketServer.hpp"
#include "service/BaseService/BaseUserServer.hpp"
#include "service/BaseService/BaseLogServer.hpp"

class ApiTicketServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
    BaseTicketServer m_server;
    BaseUserServer m_userServer;
    BaseLogServer m_logServer;
public:
    //    更新演出票
    oatpp::Object<TicketDto> updateTicket(const oatpp::Object<TicketDto> &dto);

    //    通过id查询演出票
    oatpp::Object<TicketDto> getTicketById(const oatpp::Int32 &ticketId);

    //    根据演出厅id获取演出票
    oatpp::Object<TicketDtoList> getTicketsByStudioId(const oatpp::Int32 &studioId);

    //    根据用户id获取演出票
    oatpp::Object<TicketDtoList> getTicketsByUserId(const oatpp::Int32 &userId);

    //    根据节目id获取演出票
    oatpp::Object<TicketDtoList> getTicketsByPlayId(const oatpp::Int32 &playId);

    //    删除演出票
    oatpp::Object<MessageDto> deleteTicketById(const oatpp::Int32 &ticketId);

private:
    static const oatpp::Object<TicketDto> &ticketToOutput(const oatpp::Object<TicketDto> &dto);
};


#endif //TTMS_APITICKETSERVER_HPP
