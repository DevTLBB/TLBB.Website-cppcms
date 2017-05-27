#include "router.h"
#include <iostream>
#include <cppcms/http_request.h>

#include "../../routes/web.h"
#include "../../routes/api.h"

namespace app
{
  namespace core
  {
    Router::Router(cppcms::service &s) : cppcms::application(s)
    {
      attach(new routes::API(s),
        "api",
        "/api{1}",
        "/api((/?.*))",
        1);
      // Web Route must be set at last of Router Lists.
      attach(new routes::Web(s),
        "web",
        "{1}",
        "((/?.*))",
        1);
    }

    void Router::main(std::string path)
    {
      try
      {
        cppcms::application::main(path);
      }
      catch(std::exception const &e)
      {
        std::cerr << "Failed: " << e.what() << std::endl;
        std::cerr << booster::trace(e) << std::endl;
      }
      // Write Logs
      
      std::cout << "============== Connection Info ===============" << std::endl;
      std::cout << "IP: " << request().remote_host() << std::endl;
      std::cout << "Path: " << path << std::endl;
    }
  }
}
