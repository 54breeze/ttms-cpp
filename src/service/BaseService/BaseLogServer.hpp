//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_BASELOGSERVER_HPP
#define TTMS_BASELOGSERVER_HPP

#include "dto/LogDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseLogServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加记录
    oatpp::Object<LogDto> createLog(const oatpp::Object<LogDto> &dto);

    //    更新记录
    oatpp::Object<LogDto> updateLog(const oatpp::Object<LogDto> &dto);

    //    通过id获取记录
    oatpp::Object<LogDto> getLogById(const oatpp::Int32 &logId,
                                     const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部记录
    oatpp::Object<LogDtoList> getAllLogs();

    //    通过剧目id获取记录
    oatpp::Object<LogDtoList> getLogsByPlayId(const oatpp::Int32 &playId);

    //    通过用户id获取记录
    oatpp::Object<LogDtoList> getLogsByUserId(const oatpp::Int32 &userId);

    //    删除记录
    oatpp::Object<MessageDto> deleteLogById(const oatpp::Int32 &logId);
};


#endif //TTMS_BASELOGSERVER_HPP
