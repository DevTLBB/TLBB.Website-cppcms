#include "web.h"

namespace routes
{
  Web::Web(cppcms::service &s) : cppcms::application(s)
  {
    // attach();
  }

  void Web::main(std::string path)
  {
    try
    {
      cppcms::application::main(path);
    }
    catch(std::exception &e)
    {

    }
  }
}
