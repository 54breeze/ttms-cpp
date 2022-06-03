//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_BASETICKETSERVER_HPP
#define TTMS_BASETICKETSERVER_HPP

#include "dto/TicketDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseTicketServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加演出票
    oatpp::Object<TicketDto> createTicket(const oatpp::Object<TicketDto> &dto);

    //    更新演出票
    oatpp::Object<TicketDto> updateTicket(const oatpp::Object<TicketDto> &dto);

    //    通过id查询演出票
    oatpp::Object<TicketDto> getTicketById(const oatpp::Int32 &ticketId,
                                           const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部演出票
    oatpp::Object<TicketDtoList> getAllTickets();

    //    通过演出厅id获取演出票
    oatpp::Object<TicketDtoList> getTicketsByStudioId(const oatpp::Int32 &studioId);

    //    通过用户id获取演出票
    oatpp::Object<TicketDtoList> getTicketsByUserId(const oatpp::Int32 &userId);

    //    通过节目id获取演出票
    oatpp::Object<TicketDtoList> getTicketsByPlayId(const oatpp::Int32 &playId);

    //    删除演出票
    oatpp::Object<MessageDto> deleteTicketById(const oatpp::Int32 &ticketId);

    //    根据演出计划id删除演出票
    oatpp::Object<MessageDto> deleteTicketsByScheduleId(const oatpp::Int32 &scheduleId);

};


#endif //TTMS_BASETICKETSERVER_HPP
