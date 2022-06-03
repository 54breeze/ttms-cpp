//
// Created by breeze on 2022/5/20.
//

#ifndef TTMS_BASESCHEDULESERVER_HPP
#define TTMS_BASESCHEDULESERVER_HPP

#include "dto/ScheduleDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseScheduleServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加演出计划
    oatpp::Object<ScheduleDto> createSchedule(const oatpp::Object<ScheduleDto> &dto);

    //    更新演出计划
    oatpp::Object<ScheduleDto> updateSchedule(const oatpp::Object<ScheduleDto> &dto);

    //    通过id查询演出计划
    oatpp::Object<ScheduleDto> getScheduleById(const oatpp::Int32 &scheduleId,
                                           const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部演出计划
    oatpp::Object<ScheduleDtoList> getAllSchedules();

    //    通过剧院id查询演出计划
    oatpp::Object<ScheduleDtoList> getSchedulesByTheaterId(const oatpp::Int32 &theaterId);

    //    通过演出厅id查询演出计划
    oatpp::Object<ScheduleDtoList> getSchedulesByStudioId(const oatpp::Int32 &studioId);

    //    删除演出计划
    oatpp::Object<MessageDto> deleteScheduleById(const oatpp::Int32 &scheduleId);
};


#endif //TTMS_BASESCHEDULESERVER_HPP
