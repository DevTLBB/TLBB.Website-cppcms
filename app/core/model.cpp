#include "model.h"
#include <cppcms/service.h>

namespace app
{
  namespace core
  {
    Model::Model(cppcms::service &s) : cppcms::application(s)
    {
      this->web = settings().get<std::string>("app.db.web.connection_string");
    }
    
  }
}
