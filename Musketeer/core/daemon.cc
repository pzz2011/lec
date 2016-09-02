#include "core/daemon.h"


template <class T>
class data_processor<T, typename boost::enable_if_c<boost::is_float<T>::value>::type> { 

}


template <class T>
class data_processor<T, typename boost::enable_if_c<boost::is_integral<T>::value>::type>{ 

}

namespace musketeer { 
namespace core { 

  Daemon::Daemon(boost::asio::io_service* io_service, int port,
                 SchedulerInterface* scheduler):
    acceptor_(*io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    scheduler_(scheduler) { 
    
    LOG(INFO) << "Createing Daemon";
    startAccept();
  }

  void Daemon::startAccept() { 
    LOG(INFO) << "startAccept()";
    shared_ptr<DaemonConnection> newConnection = 
      DaemonConnection::create(&acceptor_.get_io_service(), sheduler_);
    LOG(INFO) << "New Connection Created ";
    acceptor_.async_accept(newConnection->socket(),
                           boost::bind(&Daemon::handleAccept, this,
                                       newConnection,
                                       boost::asio::placeholders::error));
    LOG(INFO) << "Accepted";
  }

  
}
}
