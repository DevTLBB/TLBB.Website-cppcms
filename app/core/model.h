#ifndef APP_CORE_MODEL_H_
#define APP_CORE_MODEL_H_
#include <cppcms/application.h>

namespace app
{
  namespace core
  {
    class Model : public cppcms::application
    {
      public:
        Model(cppcms::service &s);
        // virtual void main(std::string path);
      public:
        std::string web;
    };
  }
}
#endif
