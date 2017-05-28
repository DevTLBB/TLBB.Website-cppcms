#ifndef APP_CORE_PROVIDER_H_
#define APP_CORE_PROVIDER_H_
#include <cppcms/application.h>
#include "model.h"

namespace app
{
  namespace core
  {
    class Provider : public cppcms::application
    {
      public:
        Model model;
      public:
        Provider(cppcms::service &s);
        // virtual void main(std::string path);
    };
  }
}
#endif
