//#include "controller/TTMSController.hpp"
#include "controller/UserController.hpp"
#include "controller/TheaterController.hpp"
#include "controller/StudioController.hpp"
#include "controller/SeatController.hpp"
#include "controller/PlayController.hpp"
#include "controller/ScheduleController.hpp"
#include "controller/TicketController.hpp"
#include "controller/LogController.hpp"

#include "AppComponent.hpp"

#include "oatpp/network/Server.hpp"

void run() {

    /* Register Components in scope of run() method */
    AppComponent components;

    /* Get router component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Create MyController and add all of its endpoints to router */
    oatpp::web::server::api::Endpoints docEndpoints;
//    docEndpoints.append(router->addController(TTMSController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(UserController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(TheaterController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(StudioController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(SeatController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(PlayController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(ScheduleController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(TicketController::createShared())->getEndpoints());
    docEndpoints.append(router->addController(LogController::createShared())->getEndpoints());

    /* Get connection handler component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

    /* Get connection provider component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    /* Create baseServer which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Priny info about baseServer port */
    OATPP_LOGI("TTMS", "baseServer running on port %s", connectionProvider->getProperty("port").getData());

    /* Run baseServer */
    server.run();

}

int main(int argc, const char *argv[]) {

    /* Init oatpp Environment */
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();

    return 0;
}