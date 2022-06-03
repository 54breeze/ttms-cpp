//
// Created by breeze on 2022/5/19.
//

#ifndef TTMS_BASESTUDIOSERVER_HPP
#define TTMS_BASESTUDIOSERVER_HPP

#include "dto/StudioDto.hpp"
#include "dto/MessageDto.hpp"
#include "db/TTMSDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class BaseStudioServer {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<TTMSDb>, m_database); // Inject database component
public:
    //    添加演出厅
    oatpp::Object<StudioDto> createStudio(const oatpp::Object<StudioDto> &dto);

    //    更新演出厅信息
    oatpp::Object<StudioDto> updateStudio(const oatpp::Object<StudioDto> &dto);

    //    通过演出厅id获取演出厅信息
    oatpp::Object<StudioDto> getStudioById(const oatpp::Int32 &studioId,
                                             const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);

    //    获取全部演出厅信息
    oatpp::Object<StudioDtoList> getAllStudios();

    //    获取id剧院全部演出厅信息
    oatpp::Object<StudioDtoList> getStudiosByTheaterId(const oatpp::Int32 &theaterId);

    //    删除演出厅
    oatpp::Object<MessageDto> deleteStudioById(const oatpp::Int32 &studioId);

    //    通过剧院id删除演出厅
    oatpp::Object<MessageDto> deleteStudiosByTheaterId(const oatpp::Int32 &theaterId);
};


#endif //TTMS_BASESTUDIOSERVER_HPP
