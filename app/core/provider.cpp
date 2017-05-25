#include <iostream>
#include "provider.h"

#include <stdio.h>
#include <cppcms/http_request.h>

namespace app
{
  namespace core
  {
    Provider::Provider(Router &s) : cppcms::application(s),
                                             Route(s)
    {
    }

    void Provider::main(std::string path)
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
      printf("============== Connection Info ===============\n");
      printf("IP: %s\n", request().remote_host().c_str());
      printf("Path: %s\n", path.c_str());
    }
  }
}