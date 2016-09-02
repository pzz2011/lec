#ifndef MUSKETEER_DAEMON_H
#define MUSKETEER_DAEMON_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

#include "base/common.h"
#include "core/daemon_connection.h"

namespace musketeer { 
namespace core {

class Daemon { 
public:
  Daemon(boost::asio:)

private:
  void startAccept();
  void handleAccept(shared_ptr<DaemonConnection> new_connection,
                    const boost::system::error_code& error);

  boost::asio::ip::tcp::acceptor acceptor_;
  SchedulerInterface* scheduler_;
};


} // namespace core
} // namespace musketeer 

#endif
